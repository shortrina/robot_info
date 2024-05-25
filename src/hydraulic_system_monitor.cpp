#include "../include/robot_info/agv_robot_info_class.hpp"
#include "../include/robot_info/robot_info_class.hpp"
#include <string>

#if 0
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
#endif