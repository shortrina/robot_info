#include "./robot_info_class.hpp"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/publisher.h"

class HydraulicSystemMonitor
{
public:
    std::string hydraulic_oil_temperature =" hydraulic_oil_temperature: 45C ";
    std::string hydraulic_oil_tank_fill_level =" hydraulic_oil_tank_fill_level: 100% ";
    std::string hydraulic_oil_pressure =" hydraulic_oil_pressure: 250 bar ";

};
class AGVRobotInfo : public RobotInfo
{
public:    
    AGVRobotInfo(ros::NodeHandle *node_handle);
    ~AGVRobotInfo();
    void publish_data();
    void infoCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &imsg);
        
protected:
    HydraulicSystemMonitor m_hydraulic_system_monitor;
    std::string maximum_payload = " maximum_payload: 100 kg";
};


