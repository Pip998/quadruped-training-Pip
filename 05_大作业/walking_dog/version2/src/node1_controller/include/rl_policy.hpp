#ifndef RL_POLICY_HPP
#define RL_POLICY_HPP

#include <torch/script.h>
#include <vector>
#include <deque>
#include <string>
#include <array>
#include <mutex>

class RLPolicy {
public:
    RLPolicy() = default;

    // 加载 config.yaml 和 best.pt
    bool init(const std::string& config_path, const std::string& pt_path);

    // 输入一帧原始状态，内部做缩放 + 6 帧堆叠 + 推理
    // 输入顺序为仿真顺序 FL-FR-RR-RL（内部会重映射为 FL-FR-RL-RR）
    // 输出顺序为仿真顺序 FL-FR-RR-RL（内部会重映射回来）
    std::vector<double> infer(
        const std::vector<double>& q_sim,       // 12, 仿真顺序
        const std::vector<double>& dq_sim,      // 12, 仿真顺序
        const std::vector<double>& omega_body,  // 3,  机体系角速度
        const std::vector<double>& gravity_body,// 3,  重力机体系投影
        const std::vector<double>& commands     // 3,  [vx, vy, wz]
    );

    // 供 controller 使用
    const std::vector<double>& defaultDofPos() const { return default_dof_pos_; }
    const std::vector<double>& rlKp() const { return rl_kp_; }
    const std::vector<double>& rlKd() const { return rl_kd_; }
    const std::vector<double>& actionScale() const { return action_scale_; }

    // 清空历史（每次进入 RL 模式时调用）
    void resetHistory();

private:
    // 索引重映射：mujoco中 FL-FR-RR-RL  <->  policy中 FL-FR-RL-RR
    static std::vector<double> remapSimToPolicy(const std::vector<double>& v);
    static std::vector<double> remapPolicyToSim(const std::vector<double>& v);

    torch::jit::script::Module module_;
    bool loaded_ = false;

    // config 缩放参数
    std::vector<double> default_dof_pos_;
    std::vector<double> rl_kp_;
    std::vector<double> rl_kd_;
    std::vector<double> action_scale_;
    std::vector<double> commands_scale_;   // [vx, vy, wz]
    double ang_vel_scale_ = 1.0;
    double dof_pos_scale_ = 1.0;
    double dof_vel_scale_ = 1.0;
    int    num_obs_ = 45;
    int    history_len_ = 6;

    // 6 帧历史（每帧 45 维）
    std::deque<std::vector<float>> obs_history_;
    // 上一帧动作（策略顺序，未缩放）
    std::vector<float> last_action_;

    std::mutex mtx_;
};

#endif