#include "./robot_info_class.hpp"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/publisher.h"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>

class HydraulicSystemMonitor {
public:
  std::string hydraulic_oil_temperature = " hydraulic_oil_temperature: 45C ";
  std::string hydraulic_oil_tank_fill_level =
      " hydraulic_oil_tank_fill_level: 100% ";
  std::string hydraulic_oil_pressure = " hydraulic_oil_pressure: 250 bar ";
};

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle *node_handle);
  ~AGVRobotInfo();
  void publish_data() override;
  void infoCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &imsg);

protected:
  RobotInfo *robot_info;
  // HydraulicSystemMonitor m_hydraulic_system_monitor;
  std::string maximum_payload = "maximum_payload: 100kg";
};
