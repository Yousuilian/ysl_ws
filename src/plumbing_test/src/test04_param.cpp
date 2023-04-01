#include "ros/ros.h"
int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"change_bgColor");
    // //修改参数，法1,不一定需要节点句柄（和后续API有关）
    // ros::param::set("turtlesim/background_r",0);
    // ros::param::set("turtlesim/background_g",0);
    // ros::param::set("turtlesim/background_b",0);
    // //修改参数，法2,使用节点句柄
    // ros::NodeHandle nh("/turtlesim");
    // nh.setParam("background_r",255);
    // nh.setParam("background_g",255);
    // nh.setParam("background_b",255);
    //法3,句柄不声明命名空间，设置参数的时候加上命名空间
    ros::NodeHandle nh;
    nh.setParam("/turtlesim/background_r",0);
    nh.setParam("/turtlesim/background_g",50);
    nh.setParam("/turtlesim/background_b",100);
    return 0;
}
