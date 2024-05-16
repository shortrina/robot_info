#include "../include/robot_info/robot_info_class.hpp"
#include <std_msgs/String.h>
RobotInfo::RobotInfo(ros::NodeHandle *node_handle)
{
    nh = node_handle;
    info_sub_ = nh->subscribe(info_topic_name, 10000, &RobotInfo::infoCallback, this);
    info_pub_ = nh->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10000);

    m_robot_info.robot_description = "robot_description:Mir100";
    m_robot_info.robot_serial_number = "serial_number:567A359";
    m_robot_info.robot_ip_address = "ip_address:169.254.5.180";
    m_robot_info.robot_firmware_version="firmware_version:3.5.8";

}

RobotInfo::~RobotInfo()
{
}

void RobotInfo::publish_data()
{
    info_data_.data_field_01 = m_robot_info.robot_description;
    info_data_.data_field_02 = m_robot_info.robot_serial_number;
    info_data_.data_field_03 = m_robot_info.robot_ip_address;
    info_data_.data_field_04 = m_robot_info.robot_firmware_version;
    info_pub_.publish(info_data_);
}

void RobotInfo::infoCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &imsg)
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

#if 0
bool RobotInfoClass::trigger_srv_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res)
{
    publish_data();
    res.success = true;
    return true;
}
#endif