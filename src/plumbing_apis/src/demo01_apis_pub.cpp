#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
/*
    2.初始化 ROS 节点

    作用：ROS初始化函数
    参数：
        1.argc    ----封装实参个数（n+1）
        2.argv    ----封装参数的数组
        3.name    ----为节点命名
        4.options ----节点启动选项
        返回值：void
    使用：
        1.argc与argv的使用
            如果按照ROS中的特定格式传入实参，那么ROS可以加以使用，比如用来设置全局参数、给节点重命名
        2.options的使用
            节点名称需要保持唯一，会导致一个问题：同一个节点不能同时启动
            结果：ROS中当有重名节点被启用时，之前的节点会被关闭
            需求：特定场景下，需要一个节点多次启动且能正常运行，怎么办？
            解决：设置启动项 ros::init_options::AnonymousName
                当创建ROS节点时，会在用户自定义的节点名称后缀随机数，从而避免重名问题
*/  
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //使用AnonymousName可以解决节点多次启动问题，否则启动第二个节点时第一个节点会shutdown
    ros::init(argc,argv,"Pub",ros::init_options::AnonymousName);
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);
    std_msgs::String msg;
    ros::Rate rate(5);
    int count = 0;
    ros::Duration(3).sleep();
    while (ros::ok)
    {
        count++;
        std::stringstream ss;
        ss << "hello --->"<< count;
        msg.data = ss.str();
        pub.publish(msg);
        ROS_INFO("发布的数据是：%s",ss.str().c_str());
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}