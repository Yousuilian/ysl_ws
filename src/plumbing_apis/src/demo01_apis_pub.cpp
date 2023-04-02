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
    /*
        作用：创建发布者对象

        模板：被发布的消息类型

        参数：
            1.话题名称
            2.队列长度
            3.latch（可选） 如果设置为true，会保存发布方的最后一条消息，并且
              新的订阅对象连接到发布方时，发布方会将这条消息发送给订阅者 
        使用：
            latch 设置为 true 的作用？
            以静态地图发布为例，
            方案1：可以使用固定频率发送地图数据，但是效率低
            方案2：可以将地图发布对象的latch 设置为true，并且发布方只发送一次数据，
            每当订阅者连接时，将地图数据发送给订阅者（只发送一次），这样提高了数据发送的效率
            (advertise的第三个参数latch的使用，也就是说发布方发完10个数据后再去订阅订阅不到，
            但是将latch设置为true的时候，发布方发完10个数据后再订阅，因为最后一个数据被保存了
            所以可以订阅到最后一条数据)
    */
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10,true);
    std_msgs::String msg;
    ros::Rate rate(2);
    int count = 0;
    ros::Duration(3).sleep();
    while (ros::ok())
    {
        // if (count >= 10)
        // {
        //     ros::shutdown();
        // }
        count++;
        std::stringstream ss;
        ss << "hello --->"<< count;
        msg.data = ss.str();
        if (count <= 20)
        {
            pub.publish(msg);
            ROS_INFO("发布的数据是：%s",ss.str().c_str());
        }
        rate.sleep();
        ros::spinOnce();//每执行一次就跳转到回调函数一次然后回来继续往下执行
        ROS_INFO("一轮回调执行完毕......");
    }
    return 0;
}