#include "../include/robot_info/agv_robot_info_class.hpp"
#include "robot_info/robot_info_class.hpp"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/console.h"
#include <cmath>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_srvs/Trigger.h>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle)
    : RobotInfo(node_handle) {
  robot_info = new RobotInfo(node_handle);
  // m_hydraulic_system_monitor = HydraulicSystemMonitor();
}

AGVRobotInfo::~AGVRobotInfo() {}

void AGVRobotInfo::publish_data() {
  info_data_.data_field_05 = maximum_payload;
#if 0    
    info_data_.data_field_06 = m_hydraulic_system_monitor.hydraulic_oil_temperature;
    info_data_.data_field_07 = m_hydraulic_system_monitor.hydraulic_oil_tank_fill_level;
    info_data_.data_field_08 = m_hydraulic_system_monitor.hydraulic_oil_pressure;
#endif
  info_pub_.publish(info_data_);
}

void AGVRobotInfo::infoCallback(
    const robotinfo_msgs::RobotInfo10Fields::ConstPtr &imsg) {

  ROS_INFO(imsg->data_field_05.c_str());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_class");
  ros::NodeHandle nh;

  AGVRobotInfo agv_robot_info(&nh);

  while (ros::ok()) {
    agv_robot_info.publish_data();
    ros::Duration(1.0).sleep();
    ros::spinOnce();
  }

  ros::spin();
  return 0;
}
