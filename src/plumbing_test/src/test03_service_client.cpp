#include "ros/ros.h"
#include "turtlesim/Spawn.h"
/*
    需求：向服务端发送请求，生成一只新的乌龟
        话题：/Spawn
        消息：turtlesim/Spawn
*/
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"service_call");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 4.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";
    //判断服务器状态，用下面其中一条语句即可
    //ros::service::waitForService("/spawn");
    client.waitForExistence();
    bool flag = client.call(spawn);
    if (flag)
    {
       ROS_INFO("乌龟生成成功，新乌龟叫：%s",spawn.response.name.c_str());
    }
    else{
        ROS_INFO("请求失败！！！");
    }
    return 0;
}
