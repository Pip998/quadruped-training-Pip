#include <functional>
#include <memory>
#include <thread>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <linux/joystick.h> // 引入linux手柄
#include "rclcpp/rclcpp.hpp"
#include "dog_msgs/srv/handle_command.hpp" // 采用service通信类型


class handle : public rclcpp::Node
{
    public:
    handle()
        : Node("node3_handle")
    {
        // 手柄～控制器
        client_ = this->create_client<dog_msgs::srv::HandleCommand>(
            "handle_command"
        );

        // 手柄设备
        joystick_fd_ = open("/dev/input/js0", O_RDONLY | O_NONBLOCK);

        if (joystick_fd_ < 0)
        {
            RCLCPP_ERROR(
                this->get_logger(),
                "无法打开手柄"
            );

            return;
        }

        RCLCPP_INFO(
            this->get_logger(),
            "手柄节点激活～"
        );

        RCLCPP_INFO(
            this->get_logger(),
            "B键：趴卧，A键：站立"
        );

        // 开启手柄读取线程
        joystick_thread_ = std::thread(
            &handle::read_joystick,
            this
        );
    }

    ~handle()
    {
        if (joystick_fd_ >= 0)
        {
            close(joystick_fd_);
        }

        if (joystick_thread_.joinable())
        {
            joystick_thread_.join();
        }
    }

    private:
    // 读取手柄
    void read_joystick()
    {
        struct js_event event;

        while (rclcpp::ok())
        {
            ssize_t bytes = read(
                joystick_fd_,
                &event,
                sizeof(event)
            );

            if (bytes != sizeof(event))
            {
                std::this_thread::sleep_for(
                    std::chrono::milliseconds(10)
                );
                continue;
            }

            // 只处理按键事件
            if (event.type == JS_EVENT_BUTTON)
            {
                if (event.value == 1)
                {
                    // B键
                    if (event.number == lay_button_)
                    {
                        send_command(1);
                    }

                    // A键
                    else if (event.number == stand_button_)
                    {
                        send_command(2);
                    }
                }
            }
        }
    }

    // 手柄～控制器，发送服务请求
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

    // 接收控制器的服务回复
    void service_callback(
        rclcpp::Client<
            dog_msgs::srv::HandleCommand
        >::SharedFuture future
    )
    {
        auto response = future.get();

        if (response->success) // callback
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
                "控制器拒绝了指令"
            );
        }
    }


    rclcpp::Client<
        dog_msgs::srv::HandleCommand
    >::SharedPtr client_;

    int joystick_fd_ = -1;

    std::thread joystick_thread_;

    // Xbox手柄按键编号
    int lay_button_ = 1;
    int stand_button_ = 0;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<handle>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
