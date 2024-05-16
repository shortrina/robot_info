#include "./robot_info_class.hpp"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/publisher.h"


class AGVRobotInfo : public RobotInfo
{
public:
    ros::NodeHandle *nh;

    AGVRobotInfo(ros::NodeHandle *node_handle);
    ~AGVRobotInfo();
    void publish_data();
    void infoCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &imsg);
    
protected:
    std::string maximum_payload = "maximum_payload: 100 kg";
};