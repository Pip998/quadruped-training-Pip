#include "rl_policy.hpp"
#include <yaml-cpp/yaml.h>
#include <iostream>
#include <stdexcept>

// 关节索引重映射
// 仿真：FL-FR-RR-RL
// 策略：FL-FR-RL-RR
std::vector<double> RLPolicy::remapSimToPolicy(const std::vector<double>& v) {
    if (v.size() != 12) throw std::runtime_error("remap: size != 12");
    std::vector<double> out(12);
    // 0-5 不变
    for (int i = 0; i < 6; ++i) out[i] = v[i];
    // mujoco RR(6-8) -> policy RR(9-11)
    for (int i = 0; i < 3; ++i) out[9 + i] = v[6 + i];
    // mujoco RL(9-11) -> policy RL(6-8)
    for (int i = 0; i < 3; ++i) out[6 + i] = v[9 + i];
    return out;
}

std::vector<double> RLPolicy::remapPolicyToSim(const std::vector<double>& v) {
    if (v.size() != 12) throw std::runtime_error("remap: size != 12");
    std::vector<double> out(12);
    for (int i = 0; i < 6; ++i) out[i] = v[i];
    // 策略 RL(6-8) -> 仿真 RL(9-11)
    for (int i = 0; i < 3; ++i) out[9 + i] = v[6 + i];
    // 策略 RR(9-11) -> 仿真 RR(6-8)
    for (int i = 0; i < 3; ++i) out[6 + i] = v[9 + i];
    return out;
}

// ---- 初始化 ----
bool RLPolicy::init(const std::string& config_path, const std::string& pt_path) {
    try {
        module_ = torch::jit::load(pt_path);
        module_.eval();
        loaded_ = true;
    } catch (const c10::Error& e) {
        std::cerr << "[RLPolicy] load pt failed: " << e.what() << std::endl;
        return false;
    }

    YAML::Node cfg = YAML::LoadFile(config_path);

    num_obs_     = cfg["num_observations"].as<int>(45);
    history_len_ = cfg["observations_history"].as<std::vector<int>>().size();

    default_dof_pos_ = cfg["default_dof_pos"].as<std::vector<double>>();
    rl_kp_           = cfg["rl_kp"].as<std::vector<double>>();
    rl_kd_           = cfg["rl_kd"].as<std::vector<double>>();
    action_scale_    = cfg["action_scale"].as<std::vector<double>>();

    ang_vel_scale_  = cfg["ang_vel_scale"].as<double>(1.0);
    dof_pos_scale_  = cfg["dof_pos_scale"].as<double>(1.0);
    dof_vel_scale_  = cfg["dof_vel_scale"].as<double>(1.0);

    // commands_scale: [vx, vy, wz]
    auto cs = cfg["commands_scale"].as<std::vector<double>>();
    if (cs.size() != 3) throw std::runtime_error("commands_scale must be 3");
    commands_scale_ = cs;

    // 清空历史，填充 6 帧零观测
    last_action_.assign(12, 0.0f);
    resetHistory();

    std::cout << "[RLPolicy] init ok. num_obs=" << num_obs_
              << " history=" << history_len_ << std::endl;
    return true;
}

void RLPolicy::resetHistory() {
    std::lock_guard<std::mutex> lock(mtx_);
    obs_history_.clear();
    std::vector<float> zero_obs(num_obs_, 0.0f);
    for (int i = 0; i < history_len_; ++i) {
        obs_history_.push_back(zero_obs);
    }
    last_action_.assign(12, 0.0f);
}

// ---- 单次推理 ----
std::vector<double> RLPolicy::infer(
    const std::vector<double>& q_sim,
    const std::vector<double>& dq_sim,
    const std::vector<double>& omega_body,
    const std::vector<double>& gravity_body,
    const std::vector<double>& commands)
{
    if (!loaded_) throw std::runtime_error("[RLPolicy] not loaded");
    if (q_sim.size() != 12 || dq_sim.size() != 12)
        throw std::runtime_error("[RLPolicy] q/dq size != 12");
    if (omega_body.size() != 3 || gravity_body.size() != 3 || commands.size() != 3)
        throw std::runtime_error("[RLPolicy] omega/gravity/commands size != 3");

    std::lock_guard<std::mutex> lock(mtx_);

    // 1) 关节重映射：仿真 FL-FR-RR-RL -> 策略 FL-FR-RL-RR
    auto q_pol  = remapSimToPolicy(q_sim);
    auto dq_pol = remapSimToPolicy(dq_sim);

    // 2) 组装一帧 45 维观测
    std::vector<float> obs(num_obs_, 0.0f);
    int k = 0;

    // [0-2] commands  (已缩放)
    for (int i = 0; i < 3; ++i)
        obs[k++] = static_cast<float>(commands[i] * commands_scale_[i]);

    // [3-5] 机体系角速度 * ang_vel_scale
    for (int i = 0; i < 3; ++i)
        obs[k++] = static_cast<float>(omega_body[i] * ang_vel_scale_);

    // [6-8] 重力投影 (scale 1.0)
    for (int i = 0; i < 3; ++i)
        obs[k++] = static_cast<float>(gravity_body[i]);

    // [9-20] (q - default_dof_pos) * dof_pos_scale
    for (int i = 0; i < 12; ++i)
        obs[k++] = static_cast<float>(
            (q_pol[i] - default_dof_pos_[i]) * dof_pos_scale_);

    // [21-32] dq * dof_vel_scale
    for (int i = 0; i < 12; ++i)
        obs[k++] = static_cast<float>(dq_pol[i] * dof_vel_scale_);

    // [33-44] 上一帧动作（未缩放，策略顺序）
    for (int i = 0; i < 12; ++i)
        obs[k++] = last_action_[i];

    // 3) 推入历史，丢弃最旧一帧
    obs_history_.push_back(obs);
    while ((int)obs_history_.size() > history_len_)
        obs_history_.pop_front();

    // 4) 拼成 1 x (6*45) 输入张量。obs_history_[0] 是旧帧
    //    说明：config 中 observations_history = [0,1,2,3,4,5]，
    //    0 表示最新，5 表示最旧。我们送入网络时按 [最新, 次新, ..., 最旧]
    //    的顺序拼接，与训练一致。
    std::vector<float> stacked;
    stacked.reserve(num_obs_ * history_len_);
    for (int h = 0; h < history_len_; ++h) {
        // obs_history_ 尾部是最新帧，所以从后往前取
        const auto& frame = obs_history_[obs_history_.size() - 1 - h];
        stacked.insert(stacked.end(), frame.begin(), frame.end());
    }

    auto input_tensor = torch::from_blob(
        stacked.data(),
        {1, (long)(num_obs_ * history_len_)},
        torch::kFloat32
    ).clone();

    // 5) 推理
    std::vector<torch::jit::IValue> inputs;
    inputs.push_back(input_tensor);
    at::Tensor out = module_.forward(inputs).toTensor();  // [1, 12]
    out = out.detach().cpu().contiguous();

    // 6) 输出动作增量（策略顺序）
    std::vector<float> action_pol(12);
    for (int i = 0; i < 12; ++i)
        action_pol[i] = out[0][i].item<float>();

    // 记录作为下一帧的 last_action
    last_action_ = action_pol;

    // 7) 换算成目标关节位置（策略顺序），再重映射回仿真顺序
    std::vector<double> q_target_pol(12);
    for (int i = 0; i < 12; ++i) {
        q_target_pol[i] = default_dof_pos_[i]
                        + static_cast<double>(action_pol[i]) * action_scale_[i];
    }
    return remapPolicyToSim(q_target_pol);
}