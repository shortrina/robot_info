#include "./robot_info_class.hpp"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/publisher.h"


class AgvRobotInfo : public RobotInfo
{
public:
    ros::NodeHandle *nh;
    //ros::ServiceServer robot_info_srv;
#if 0    
    struct robotInfo m_robot_info;
    ros::Subscriber info_sub_;
    ros::Publisher info_pub_;
    robotinfo_msgs::RobotInfo10Fields info_data_;
    std::string info_topic_name = "/robot_info_sub";
#endif

    AgvRobotInfo(ros::NodeHandle *node_handle);
    ~AgvRobotInfo();
    void publish_data();
    void infoCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &imsg);
    //bool trigger_srv_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
protected:
    std::string maximum_payload = "maximum_payload: 100 kg";
};