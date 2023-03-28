#include "ros/ros.h"
#include "turtlesim/Pose.h"
/*
    需求:订阅乌龟的位姿，并输出到控制台
*/
void doPose(const turtlesim::Pose::ConstPtr &pose){
    ROS_INFO("乌龟的位姿信息：坐标(%.2f),朝向(%.2f),线速度(%.2f),角速度(%.2f)",
    pose->x,pose->y,pose->theta,pose->linear_velocity,pose->angular_velocity);
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub_pose");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100,doPose);
    ros::spin();
    return 0;
}
