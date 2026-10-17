#ifndef TELEOP_EXAMPLE
#define TELEOP_EXAMPLE

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <cmath>

/**
 * Teleoperation example
 * Applied Robotics
 */
class TeleopExample : public rclcpp::Node
{
public:
    /**
     * Main constructor
     */
    TeleopExample();

    /**
     * Destructor
     */
    ~TeleopExample() = default;

    /**
     * Main telemanipulation function. converts the joystick readings to a twist
     */
    void mainTelemanipulation();
    
private:

    /**
     * Callback for the /joy topic
     * @param msg the message on the /joy topic 
     */
    void joystickCallback(const sensor_msgs::msg::Joy& msg);

    // subscriber for joystick
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joystick_sub_;

    // publisher for twist
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr twist_publisher_;

    // twist message to publish
    geometry_msgs::msg::TwistStamped twist_msg_;

    double lin_gain_ = 0.05; // 50 mm/s max velocity
    double ang_gain_ = 20*M_PI/180.0; // 10 deg/s max velocity
    
};

#endif // TELEOP_EXAMPLE