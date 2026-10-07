#include <functional>
#include <algorithm>
#include <array>
#include <chrono> // 时序包 chronological
#include <memory> // 智能指针包
#include <string>
#include "rclcpp/rclcpp.hpp" // ros2接入
#include "dog_msgs/msg/controller_command.hpp" // 自定义dog消息
#include "dog_msgs/msg/motor_state.hpp" // 自定义dog消息
#include "sensor_msgs/msg/imu.hpp" // 引入imu传感器
#include "dog_msgs/srv/handle_command.hpp" // 也用service


using namespace std::chrono_literals;

class controller : public rclcpp::Node
{
    public:
    controller()
        : Node("node1_controller")
        {
            // 控制器～仿真
            publisher_ = this->create_publisher<dog_msgs::msg::ControllerCommand>(
                "controller_command",
                10 // 暂存消息数量
            );

            // 仿真～控制器
            subscriber1_ = 
                this->create_subscription<dog_msgs::msg::MotorState>(
                    "motor_state",
                    10,
                    std::bind(
                        &controller::motor_state_callback,
                        this,
                        std::placeholders::_1
                    )
                );
           
            subscriber2_ = 
                this->create_subscription<sensor_msgs::msg::Imu>(
                    "imu",
                    10,
                    std::bind(
                     &controller::imu_callback,
                    this,
                    std::placeholders::_1
                )
            );

            // 手柄～控制器
            service_ = this->create_service<dog_msgs::srv::HandleCommand>(
                "handle_command",
                std::bind(
                    &controller::
                    handle_command,
                    this,
                    std::placeholders::_1,
                    std::placeholders::_2
                )
            );

            init_commands();

            // 先把时间循环注释掉
            // timer_ = this->create_wall_timer(
            //    std::chrono::milliseconds(10),
            //    std::bind(
            //        &controller::publish_command,
            //        this
            //    )
            // );

            RCLCPP_INFO(this->get_logger(),"控制器节点激活～");
        }

    private:

        // 手柄～控制器
        void handle_command(
            const std::shared_ptr<dog_msgs::srv::HandleCommand::Request> request,
            std::shared_ptr<dog_msgs::srv::HandleCommand::Response> response
        )

        {
            if (request->command == 1)
            {
                RCLCPP_INFO(this->get_logger(),"切换为趴卧姿态");
                publisher_->publish(lay_command_);
                response->success = true;
            }

            else if (request->command == 2)
            {
                RCLCPP_INFO(this->get_logger(),"切换为站立姿态");
                publisher_->publish(stand_command_);
                response->success = true;
            }

            else
            {
                RCLCPP_WARN(
                    this->get_logger(),
                    "未知指令: %d",
                    request->command
                );
                response->success = false;
            }
        }

        void init_commands()
        // 照搬历史任务的数据————————————————————————
        {
            lay_command_.kp = {};           // 0
            lay_command_.kd = 
                            {
                            3.0, 3.0, 3.0,  // FL
                            3.0, 3.0, 3.0,  // FR
                            3.0, 3.0, 3.0,  // RR
                            3.0, 3.0, 3.0   // RL
                            };
            lay_command_.q = 
                            {
                            0.0,  0.7, -1.6,   // FL
                            0.0, -0.7,  1.6,   // FR
                            0.0, -0.7,  1.6,   // RR
                            0.0,  0.7, -1.6,   // RL
                            };
            lay_command_.w = {};               // 0
            lay_command_.tau = {};             // 0
            //分开两部分———————————————————————————————
            stand_command_.kp = 
                            {
                            50.0, 50.0, 30.0,
                            50.0, 50.0, 30.0,
                            50.0, 50.0, 50.0,
                            50.0, 50.0, 50.0,
                            };
            stand_command_.kd = 
                            {
                            3.0, 3.0, 1.5,
                            3.0, 3.0, 1.5,
                            3.0, 3.0, 1.5,
                            3.0, 3.0, 1.5,
                            };
            stand_command_.q = 
                            {
                            0.0,   0.5, -1.3,   // FL
                            0.0,  -0.5,  1.3,   // FR
                            0.0,  -0.6,  1.2,   // RR
                            0.0,   0.6, -1.2,   // RL
                            };
            stand_command_.w = {};              // 0
            stand_command_.tau = {};            // 0
        } //结束——————————————————————————————————————

        // 仿真～控制器
        void motor_state_callback(
            const dog_msgs::msg::MotorState::SharedPtr msg
        )

        {
            RCLCPP_INFO_THROTTLE(this->get_logger(),*this->get_clock(),1000,"已同步电机状态");
        }

        void imu_callback(
            const sensor_msgs::msg::Imu::SharedPtr msg
        )

        {
            RCLCPP_INFO_THROTTLE(this->get_logger(),*this->get_clock(),1000,"已同步imu数据");
        }
    
        dog_msgs::msg::ControllerCommand lay_command_;
        dog_msgs::msg::ControllerCommand stand_command_;

        rclcpp::Publisher<dog_msgs::msg::ControllerCommand>::SharedPtr publisher_;
        rclcpp::Subscription<dog_msgs::msg::MotorState>::SharedPtr subscriber1_;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscriber2_;
        rclcpp::Service<dog_msgs::srv::HandleCommand>::SharedPtr service_;
        // rclcpp::TimerBase::SharedPtr timer_; 这个时间循环也注释掉，先不用
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<controller>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
