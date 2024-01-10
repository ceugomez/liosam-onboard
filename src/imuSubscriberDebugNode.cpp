#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"

using std::placeholders::_1;


class IMUSubscriberDebugNode : public rclcpp::Node
{
public:
    IMUSubscriberDebugNode() : Node("imu_subscriber")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Imu>(
            "/imu_apps", 10,
            std::bind(&IMUSubscriberDebugNode::imu_callback, this, std::placeholders::_1));
    }

private:
    void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "Received IMU data: [%f, %f, %f]", 
                    msg->angular_velocity.x, 
                    msg->angular_velocity.y, 
                    msg->angular_velocity.z);
    }

    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<IMUSubscriberDebugNode>());
    rclcpp::shutdown();
    return 0;
}
