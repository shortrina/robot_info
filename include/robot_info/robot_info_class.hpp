#pragma once
#include "ros/ros.h"
#include "ros/node_handle.h"
#include "std_srvs/Trigger.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"

class RobotInfo
{

protected:
    struct robotInfo{
        std::string robot_description;
        std::string robot_serial_number;
        std::string robot_ip_address;
        std::string robot_firmware_version;
    };

public:
    ros::NodeHandle *nh;
    ros::Subscriber info_sub_;
    ros::Publisher info_pub_;
    robotinfo_msgs::RobotInfo10Fields info_data_;
    std::string info_topic_name = "/robot_info_sub";

    //ros::ServiceServer robot_info_srv;
    robotInfo m_robot_info;
    
    RobotInfo(ros::NodeHandle *node_handle);
    ~RobotInfo();

    void publish_data();
    void infoCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &imsg);
    //bool trigger_srv_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
};