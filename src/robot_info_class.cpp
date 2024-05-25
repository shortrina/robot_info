#include "../include/robot_info/robot_info_class.hpp"
#include <std_msgs/String.h>
RobotInfo::RobotInfo(ros::NodeHandle *node_handle) {
  nh = node_handle;
  info_sub_ =
      nh->subscribe(info_topic_name, 10000, &RobotInfo::infoCallback, this);
  info_pub_ =
      nh->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10000);

  m_robot_info.robot_description = "robot_description:Mir100";
  m_robot_info.serial_number = "serial_number:567A359";
  m_robot_info.ip_address = "ip_address:169.254.5.180";
  m_robot_info.firmware_version = "firmware_version:3.5.8";

  info_data_.data_field_01 = m_robot_info.robot_description;
  info_data_.data_field_02 = m_robot_info.serial_number;
  info_data_.data_field_03 = m_robot_info.ip_address;
  info_data_.data_field_04 = m_robot_info.firmware_version;
}

RobotInfo::~RobotInfo() {}

void RobotInfo::publish_data() { info_pub_.publish(info_data_); }

void RobotInfo::infoCallback(
    const robotinfo_msgs::RobotInfo10Fields::ConstPtr &imsg) {

  ROS_INFO(imsg->data_field_01.c_str());
}
