#include <ros.h>
#include <std_msgs/Byte.h>
#include <Servo.h>
#define SERVO_PIN 9
#define SERVO_MIN 0
#define SERVO_MAX 180

Servo grabber;
ros::NodeHandle nh;
std_msgs::uint8 grabber_msg;
void grabber_handler(const std_msgs::Byte& angle_msg);
ros::Subscriber<std_msgs::Byte> sub("grabber", grabber_handler );

// Init ROS node, subscribe and configure servo
void setup()
{
  nh.initNode();
  nh.subscribe(sub);
  grabber.attach(SERVO_PIN);
}

// ROS node loop
void loop()
{
  nh.spinOnce();
}

// Callback handler for message subscriber
void grabber_handler(const std_msgs::uint8& angle_msg) {
    byte angle = angle_msg.data;
    if(angle >= SERVO_MIN && angle <= SERVO_MAX) {
        grabber.write(angle);
    }
}
