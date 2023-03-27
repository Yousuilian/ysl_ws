#include "ros/ros.h"//1.ros头文件
#include "std_msgs/String.h"//发布的数据是string类型的

void doMsg(const std_msgs::String::ConstPtr &msg){//回调函数，订阅到的数据的入口参数是string类型的,参数类型是常量指针的引用
    ROS_INFO("Sub订阅的数据：%s" , msg->data.c_str());//通过msg获取并操作订阅到的数据
}
int main(int argc, char *argv[])//main函数框架
{
    setlocale(LC_ALL,"");//打印的数据有中文避免乱码
    //2.ROS节点初始化，注意节点名称不能重名
    ros::init(argc,argv,"Sub");
    //3.创建节点句柄
    ros::NodeHandle nh;
    //4.创建订阅者对象
    ros::Subscriber sub = nh.subscribe("fang",10,doMsg);
    //5.处理订阅到的数据,spin作用，使回调函数重复执行
    ros::spin();

    return 0;
}