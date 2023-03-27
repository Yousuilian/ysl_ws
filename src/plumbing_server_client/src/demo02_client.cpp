/*
    客户端：提交两个整数，并处理响应的结果

        1.包含头文件
        2.初始化 ROS 节点
        3.创建节点句柄
        4.创建客户端对象
        5.提交请求并处理响应
*/
// 1.包含头文件
#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ROS 节点
    ros::init(argc,argv,"daBao");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建客户端对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    // 5.提交请求并处理响应
    plumbing_server_client::AddInts ai;
    //5.1组织请求
    ai.request.num1 = 100;
    ai.request.num2 = 200;
    //5.2处理响应
    bool flag = client.call(ai);
    if(flag){
        ROS_INFO("响应成功!");
        //获取结果
        ROS_INFO("响应结果 = %d",ai.response.sum);
    }
    else{
        ROS_INFO("响应失败...");
    }
    return 0;
}

