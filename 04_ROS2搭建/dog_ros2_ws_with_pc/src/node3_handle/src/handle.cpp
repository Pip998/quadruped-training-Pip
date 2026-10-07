#include <functional>
#include <memory>
#include <thread>
#include <string>
#include <iostream>     // 用于 std::cin 和 std::cout
#include <chrono>
#include <csignal>      // 用于 raise
#include "rclcpp/rclcpp.hpp"
#include "dog_msgs/srv/handle_command.hpp" // 采用service通信

class handle : public rclcpp::Node
{
public:
    handle()
        : Node("node3_handle")
    {
        // 键盘～控制器（客户端）
        client_ = this->create_client<dog_msgs::srv::HandleCommand>(
            "handle_command"
        );
        RCLCPP_INFO(
            this->get_logger(),
            "键盘控制节点激活～"
        );
        RCLCPP_INFO(
            this->get_logger(),
            "请输入数字并按回车键：1 (趴卧)，2 (站立)，0/q/Q (退出程序)" // 添加保险
        );
        // 键盘读取线程
        keyboard_thread_ = std::thread(
            &handle::read_keyboard,
            this
        );
    }

    ~handle()
    {
        if (keyboard_thread_.joinable())
        {
            keyboard_thread_.join();
        }
    }

private:
    // 读取键盘
    void read_keyboard()
    {
        std::string input;

        while (rclcpp::ok())
        {
            // std::cin 会阻塞在这里，直到用户输入内容并按下回车
            if (std::cin >> input)
            {
                if (input == "1")
                {
                    send_command(1);
                }
                else if (input == "2")
                {
                    send_command(2);
                }
                else if (input == "0" || input == "q" || input == "Q")
                {
                    // 退出指令
                    std::cout << "收到退出指令，正在关闭节点..." << std::endl;
                    
                    // spin退出)
                    rclcpp::shutdown();
                    break;
                }
                else
                {
                    std::cout << "未知指令: " << input << "，请输入 1、2 或 0" << std::endl;
                }
            }
            else
            {
                break;
            }
        }
    }

    // 发送服务请求
    void send_command(int command)
    {
        if (!client_->wait_for_service(
                std::chrono::seconds(1)
            ))
        {
            RCLCPP_WARN(
                this->get_logger(),
                "控制器服务 /handle_command 不可用"
            );
            return;
        }

        auto request =
            std::make_shared<
                dog_msgs::srv::HandleCommand::Request
            >();

        request->command = command;

        RCLCPP_INFO(
            this->get_logger(),
            "发送指令：%d",
            command
        );

        client_->async_send_request(
            request,
            std::bind(
                &handle::service_callback,
                this,
                std::placeholders::_1
            )
        );
    }

    // 接收控制器的callback
    void service_callback(
        rclcpp::Client<
            dog_msgs::srv::HandleCommand
        >::SharedFuture future
    )
    {
        auto response = future.get();

        if (response->success)
        {
            RCLCPP_INFO(
                this->get_logger(),
                "控制器已接受指令"
            );
        }
        else
        {
            RCLCPP_WARN(
                this->get_logger(),
                "控制器未响应..."
            );
        }
    }

    rclcpp::Client<
        dog_msgs::srv::HandleCommand
    >::SharedPtr client_;

    std::thread keyboard_thread_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<handle>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}