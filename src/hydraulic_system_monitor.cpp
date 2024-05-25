#include "../include/robot_info/robot_info_class.hpp"
#include <string>

class HydraulicSystemMonitor {
public:
  std::string hydraulic_oil_temperature = "hydraulic_oil_temperature: 45C";
  std::string hydraulic_oil_tank_fill_level =
      "hydraulic_oil_tank_fill_level: 100%";
  std::string hydraulic_oil_pressure = "hydraulic_oil_pressure: 250 bar";

  HydraulicSystemMonitor(){};
  ~HydraulicSystemMonitor(){};
};
