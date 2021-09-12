#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

geometry_msgs::Twist cmd_vel;


void joy_callback(const sensor_msgs::Joy& msg){
  
  sensor_msgs::Joy joy_msgs = msg;
  cmd_vel.linear.x =joy_msgs.axes[1];

  cmd_vel.angular.z = joy_msgs.axes[0];

  ROS_INFO("cmd_vel.linear.x = %lf", cmd_vel.linear.x);
  ROS_INFO("cmd_vel.angular.z = %lf", cmd_vel.angular.z);
  
}
  
int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_joy");
  ros::NodeHandle nh;

  ros::Publisher cmd_vel_pub;
  ros::Subscriber joy_sub;

  //cmd_vel init
  cmd_vel.linear.x = 0.0;
  cmd_vel.linear.y = 0.0;
  cmd_vel.linear.z = 0.0;
  cmd_vel.angular.x = 0.0;
  cmd_vel.angular.y = 0.0;
  cmd_vel.angular.z = 0.0;
  
  //publisher
  cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);

  //subscriber
  joy_sub = nh.subscribe("joy", 10 , joy_callback);

  ros::Rate loop_rate(100); //10ms

  while(ros::ok()){
    cmd_vel_pub.publish(cmd_vel);
    ros::spinOnce(); //callback period
    loop_rate.sleep(); //10ms loop
  }

  return 0;
}
