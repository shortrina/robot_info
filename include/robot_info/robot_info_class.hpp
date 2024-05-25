#pragma once
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "std_srvs/Trigger.h"

class RobotInfo {
protected:
  struct robotInfo {
    std::string robot_description;
    std::string serial_number;
    std::string ip_address;
    std::string firmware_version;
  };

public:
  ros::NodeHandle *nh;
  ros::Subscriber info_sub_;
  ros::Publisher info_pub_;
  robotinfo_msgs::RobotInfo10Fields info_data_;
  std::string info_topic_name = "/robot_info_sub";

  robotInfo m_robot_info;

  RobotInfo(ros::NodeHandle *node_handle);
  ~RobotInfo();

  virtual void publish_data();
  void infoCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &imsg);
};
