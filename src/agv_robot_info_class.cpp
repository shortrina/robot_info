#include "../include/robot_info/agv_robot_info_class.hpp"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <std_msgs/String.h>
#include "robot_info/robot_info_class.hpp"
#include "robotinfo_msgs/RobotInfo10Fields.h"


AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle) : RobotInfo(node_handle)
{
    RobotInfo *robot_info = new RobotInfo(node_handle);
}


AGVRobotInfo::~AGVRobotInfo()
{
}

void AGVRobotInfo::publish_data()
{
    info_data_.data_field_01 = m_robot_info.robot_description;
    info_data_.data_field_02 = m_robot_info.robot_serial_number;
    info_data_.data_field_03 = m_robot_info.robot_ip_address;
    info_data_.data_field_04 = m_robot_info.robot_firmware_version;
    info_data_.data_field_05 = maximum_payload;
    info_pub_.publish(info_data_);
}

void AGVRobotInfo::infoCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &imsg)
{
  info_data_ = *imsg;
  ROS_INFO("info_data: %s", imsg->data_field_01.c_str() );
  ROS_INFO("info_data: %s", imsg->data_field_02.c_str() );
  ROS_INFO("info_data: %s", imsg->data_field_03.c_str() );
  ROS_INFO("info_data: %s", imsg->data_field_04.c_str() );
  ROS_INFO("info_data: %s", imsg->data_field_05.c_str() );
  ROS_INFO("info_data: %s", imsg->data_field_06.c_str() );
  ROS_INFO("info_data: %s", imsg->data_field_07.c_str() );
  ROS_INFO("info_data: %s", imsg->data_field_08.c_str() );
  ROS_INFO("info_data: %s", imsg->data_field_09.c_str() );
  ROS_INFO("info_data: %s", imsg->data_field_10.c_str() );
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "agv_robot_info_class");
    ros::NodeHandle nh;
    AGVRobotInfo robot_info(&nh);

    while(ros::ok())
    {
        robot_info.publish_data();
        ros::Duration(1.0).sleep();
        ros::spinOnce();
    }
    
    ros::spin();
    return 0;
}