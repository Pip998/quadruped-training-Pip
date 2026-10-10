#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <mutex>
#include "rclcpp/rclcpp.hpp"
#include "dog_msgs/msg/controller_command.hpp"
#include "dog_msgs/msg/motor_state.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "dog_msgs/srv/handle_command.hpp"
#include "rl_policy.hpp"

using namespace std::chrono_literals;

class controller : public rclcpp::Node
{
public:
    controller() : Node("node1_controller")
    {
        publisher_ = this->create_publisher<dog_msgs::msg::ControllerCommand>(
            "controller_command", 10);

        subscriber1_ = this->create_subscription<dog_msgs::msg::MotorState>(
            "motor_state", 10,
            std::bind(&controller::motor_state_callback, this, std::placeholders::_1));

        subscriber2_ = this->create_subscription<sensor_msgs::msg::Imu>(
            "imu", 10,
            std::bind(&controller::imu_callback, this, std::placeholders::_1));

        service_ = this->create_service<dog_msgs::srv::HandleCommand>(
            "handle_command",
            std::bind(&controller::handle_command, this,
                      std::placeholders::_1, std::placeholders::_2));
        // 加载预姿态、rl
        init_commands();
        init_rl();

        RCLCPP_INFO(this->get_logger(), "控制器节点激活～");
    }

private:
    // RL初始化
    void init_rl()
    {
        std::string base = std::string(std::getenv("HOME"))
                         + "/robocon/03_ROS2_training/03_walking_dog/version1/"
                           "src/node1_controller/config/black";
        std::string cfg_path = base + "/config.yaml"; // 引入训练结果
        std::string pt_path  = base + "/best.pt";
        
        
        rl_policy_ = std::make_unique<RLPolicy>();
        if (!rl_policy_->init(cfg_path, pt_path)) {
            RCLCPP_ERROR(this->get_logger(), "RLPolicy 初始化失败");
            rl_policy_.reset();
        } else {
            RCLCPP_INFO(this->get_logger(), "RLPolicy 加载成功");
        }
    }

    // 服务回调
    void handle_command(
        const std::shared_ptr<dog_msgs::srv::HandleCommand::Request> request,
        std::shared_ptr<dog_msgs::srv::HandleCommand::Response> response)
    {
        std::lock_guard<std::mutex> lock(cmd_mtx_);

        if (request->command == 0) {
            // 停止运动：速度清零，如果不在 RL 模式则缓动保持站姿
            current_vx_ = 0.0;
            current_vy_ = 0.0;
            current_wz_ = 0.0;
            if (!rl_mode_ && has_motor_q_) {
                stand_slew_active_ = true;
                // 从当前姿态开始缓动
                std::copy(last_motor_q_.begin(), last_motor_q_.end(),
                          stand_target_.begin());
            }
            RCLCPP_INFO(this->get_logger(), "停止运动");
            response->success = true;
        }
        else if (request->command == 1) {
            rl_mode_ = false;
            stand_slew_active_ = false;
            RCLCPP_INFO(this->get_logger(), "切换为趴卧姿态");
            publisher_->publish(lay_command_);
            response->success = true;
        }
        else if (request->command == 2) {
            if (!has_motor_q_) {
                RCLCPP_WARN(this->get_logger(), "尚未收到电机状态，无法站立");
                response->success = false;
                return;
            }
            rl_mode_ = false;
            stand_slew_active_ = true;
            // 从当前姿态开始缓动
            std::copy(last_motor_q_.begin(), last_motor_q_.end(),
                      stand_target_.begin());
            RCLCPP_INFO(this->get_logger(), "开始站立缓动");
            response->success = true;
        }
        
        else if (request->command == 3) {
            if (!rl_policy_) {
                RCLCPP_ERROR(this->get_logger(), "RL 未加载，无法进入");
                response->success = false;
                return;
            }
            rl_policy_->resetHistory();
            first_rl_frame_ = true;
            rl_mode_ = true;
            stand_slew_active_ = false;

            current_vx_ = 1.2;  // 匀速直线运动
            current_vy_ = 0.0;
            current_wz_ = 0.0;

            RCLCPP_INFO(this->get_logger(), "RL 模式，前进 vx=0.8");
            response->success = true;
        }

        else if (request->command == 4) {   // 往回走
            if (!rl_policy_) {
                RCLCPP_ERROR(this->get_logger(), "RL 未加载，无法进入");
                response->success = false;
                return;
            }
            rl_policy_->resetHistory();
            first_rl_frame_ = true;
            rl_mode_ = true;
            stand_slew_active_ = false;

            current_vx_ = -1.0;  
            current_vy_ =  0.0;
            current_wz_ =  0.0;

            RCLCPP_INFO(this->get_logger(), "RL 模式，后退 vx=-0.8");
            response->success = true;
        }

        else if (request->command == 5) {   // 左转
            if (!rl_policy_) {
                RCLCPP_ERROR(this->get_logger(), "RL 未加载，无法进入");
                response->success = false;
                return;
            }
            rl_policy_->resetHistory();
            first_rl_frame_ = true;
            rl_mode_ = true;
            stand_slew_active_ = false;

            current_wz_ = 1.0;

            RCLCPP_INFO(this->get_logger(), "RL 模式，左转");
            response->success = true;
        }

        else if (request->command == 6) {   // 右转
            if (!rl_policy_) {
                RCLCPP_ERROR(this->get_logger(), "RL 未加载，无法进入");
                response->success = false;
                return;
            }
            rl_policy_->resetHistory();
            first_rl_frame_ = true;
            rl_mode_ = true;
            stand_slew_active_ = false;

            current_wz_ = -1.0;

            RCLCPP_INFO(this->get_logger(), "RL 模式，右转");
            response->success = true;
        }

        else {
            RCLCPP_WARN(this->get_logger(), "未知指令: %d", request->command);
            response->success = false;
        }
    }

    // 静态指令参数
        void init_commands()
    {
        lay_command_.kp.fill(0.0);
        lay_command_.kd.fill(2.5);
        lay_command_.q = {
            0.0,  0.7, -1.6,
            0.0, -0.7,  1.6,
            0.0, -0.7,  1.6,
            0.0,  0.7, -1.6
        };
        lay_command_.w.fill(0.0);
        lay_command_.tau.fill(0.0);

        stand_command_.kp = {
            50.0, 50.0, 30.0,
            50.0, 50.0, 30.0,
            50.0, 50.0, 50.0,
            50.0, 50.0, 50.0
        };
        stand_command_.kd.fill(2.0);
        stand_command_.q = {
            0.0,   0.5, -1.3,
            0.0,  -0.5,  1.3,
            0.0,  -0.6,  1.2,
            0.0,   0.6, -1.2
        };
        stand_command_.w.fill(0.0);
        stand_command_.tau.fill(0.0);

        stand_target_.fill(0.0);
    }

    // 回调
    void motor_state_callback(const dog_msgs::msg::MotorState::SharedPtr msg)
    {
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                             "已同步电机状态");

        // 缓存当前电机位置
        {
            std::lock_guard<std::mutex> lock(cmd_mtx_);
            std::copy(msg->q.begin(), msg->q.end(), last_motor_q_.begin());
            has_motor_q_ = true;
        }

        // ---- 站立缓动 ----
        if (stand_slew_active_) {
            std::lock_guard<std::mutex> lock(cmd_mtx_);
            for (size_t i = 0; i < 12; ++i) {
                stand_target_[i] +=
                    (stand_command_.q[i] - stand_target_[i]) * TARGET_SLEW_RATE;
            }
            dog_msgs::msg::ControllerCommand cmd;
            cmd.kp  = stand_command_.kp;
            cmd.kd  = stand_command_.kd;
            cmd.q   = stand_target_;  
            cmd.w   = stand_command_.w;
            cmd.tau = stand_command_.tau;
            publisher_->publish(cmd);
            return;
        }

        // RL函数输入
        if (!rl_mode_ || !rl_policy_) return;

        std::vector<double> q_sim(msg->q.begin(), msg->q.end());
        std::vector<double> dq_sim(msg->dq.begin(), msg->dq.end());

        std::vector<double> omega_body = has_imu_ ? omega_body_ : std::vector<double>{0,0,0};
        std::vector<double> gravity_body = has_imu_ ? gravity_body_ : std::vector<double>{0,0,-1};

        // 速度作为参数引入函数
        std::vector<double> commands = {current_vx_, current_vy_, current_wz_};
        std::vector<double> q_target_sim;
        try {
            q_target_sim = rl_policy_->infer(q_sim, dq_sim, omega_body, gravity_body, commands);
        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "RL infer 失败: %s", e.what());
            rl_mode_ = false;
            return;
        }
        // 函数输出指令
        dog_msgs::msg::ControllerCommand cmd;

        std::copy(rl_policy_->rlKp().begin(), rl_policy_->rlKp().end(),
                  cmd.kp.begin());
        std::copy(rl_policy_->rlKd().begin(), rl_policy_->rlKd().end(),
                  cmd.kd.begin());
        std::copy(q_target_sim.begin(), q_target_sim.end(),
                  cmd.q.begin());
        cmd.w.fill(0.0);
        cmd.tau.fill(0.0);

        publisher_->publish(cmd);

        if (first_rl_frame_) {
            RCLCPP_INFO(this->get_logger(), "RL 首帧指令已发送");
            first_rl_frame_ = false;
        }
    }

    // IMU回调
    void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                             "已同步 imu 数据");

        omega_body_ = { msg->angular_velocity.x,
                        msg->angular_velocity.y,
                        msg->angular_velocity.z };
        gravity_body_ = { msg->linear_acceleration.x,
                          msg->linear_acceleration.y,
                          msg->linear_acceleration.z };
        has_imu_ = true;
    }

    // 所有成员 
    dog_msgs::msg::ControllerCommand lay_command_;
    dog_msgs::msg::ControllerCommand stand_command_;

    rclcpp::Publisher<dog_msgs::msg::ControllerCommand>::SharedPtr publisher_;
    rclcpp::Subscription<dog_msgs::msg::MotorState>::SharedPtr subscriber1_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscriber2_;
    rclcpp::Service<dog_msgs::srv::HandleCommand>::SharedPtr service_;

    // rl引入
    std::unique_ptr<RLPolicy> rl_policy_;
    bool rl_mode_ = false;
    bool first_rl_frame_ = false;
    bool has_imu_ = false;
    bool has_motor_q_ = false;

    // 站立缓动
    const double TARGET_SLEW_RATE = 0.01; // 缓动
    bool stand_slew_active_ = false; // 开关
    std::array<double, 12> stand_target_{};      

    // 前进命令
    double current_vx_ = 0.0;
    double current_vy_ = 0.0;
    double current_wz_ = 0.0;

    // 缓存
    std::array<double, 12> last_motor_q_{};  
    std::vector<double> omega_body_ = {0, 0, 0};
    std::vector<double> gravity_body_ = {0, 0, -1};

    std::mutex cmd_mtx_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<controller>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}