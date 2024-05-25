#include "../include/robot_info/robot_info_class.hpp"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_class");
  ros::NodeHandle nh;
  RobotInfo robot_info(&nh);

  while (ros::ok()) {
    robot_info.publish_data();
    ros::spinOnce();
    ros::Duration(0.1).sleep();
  }

  ros::spin();
  return 0;
}