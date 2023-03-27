#include "ros/ros.h"//ros头文件
#include "std_msgs/String.h"//发布的数据是string类型的
#include <sstream>//字符拼接数字需要用到此头文件
int main(int argc, char *argv[])//main函数框架
{
    setlocale(LC_ALL,"");//打印的数据有中文避免乱码
    ros::init(argc,argv,"Pub");//ROS节点初始化
    ros::NodeHandle nh;//创建节点句柄
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);//创建发布者对象
    //编写发布逻辑并发布数据。
    //要求以 5HZ 的频率发布数据，并且文本后添加编号
    std_msgs::String msg;//创建被发布的消息
    ros::Rate rate(5);//发布频率
    int count = 0;//设置编号
    ros::Duration(3).sleep();
    while (ros::ok)//编写循环，循环中发布数据
    {
        count++;
        std::stringstream ss;//实现字符串拼接数字
        ss << "hello --->"<< count;
        msg.data = ss.str();
        pub.publish(msg);
        ROS_INFO("发布的数据是：%s",ss.str().c_str());//添加日志:
        rate.sleep();
        ros::spinOnce();//官方建议添加，处理回调函数
    }
    return 0;
}