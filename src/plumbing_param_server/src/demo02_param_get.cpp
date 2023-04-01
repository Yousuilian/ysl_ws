/*
    演示参数查询
    实现：
        ros::NodeHandle -------------------------------------------------------------内置的一些函数
            param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            键是否存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached(键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

    ros::param -------------------------------------------------------------内置的一些函数
*/
#include "ros/ros.h"
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"get_param_c");
    ros::NodeHandle nh;
    // ros::NodeHandle
    //  1.param
    double radius = nh.param("radius",0.5);
    ROS_INFO("radius = %.2f",radius);
    
    double radius2 = 0.0;
    //2.getParam
    //bool result = nh.getParam("radius",radius2);
    //3.getParamCached与getParam类似，性能有所提升，因为基于RPC远程调用的性能不高，之前如果获取过直接从缓存里面获取
    bool result = nh.getParamCached("radius",radius2);
    if(result){
        ROS_INFO("获取的半径是：%.2f",radius2);
    }
    else{
        ROS_INFO("被查询的变量不存在。");
    }
    //4.getParamNames
    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto &&name : names){
            ROS_INFO("遍历的元素：%s",name.c_str());
    }
    //5.hasParam
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radiusxxx");
    ROS_INFO("radius 存在吗？%d",flag1);
    ROS_INFO("radiusxxx 存在吗？%d",flag2);
    //6.searchParam
    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("搜索结果：%s",key.c_str());
    //ros::param -------------------------------------------------------------内置的一些函数
    double  radius_param = ros::param::param("radius",100.5);
    ROS_INFO("radius_param = %.2f",radius_param);

    std::vector<std::string> names_param;
    ros::param::getParamNames(names_param);
    for(auto &&name : names_param){
        ROS_INFO("键：%s",name.c_str());
    }
    
    return 0;
}
