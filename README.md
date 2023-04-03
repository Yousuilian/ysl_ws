# 仓库简介：

本仓库用来学习b站[Autolabor官方视频](https://space.bilibili.com/194110480)的代码记录

# 事记：

202303290334修改仓库为private

# 常用指令&网站

```bash
sudo chmod 777 ××× （每个人都有读和写以及执行的权限）
sudo chmod -R 777 ysl/  （将ysl文件里面的所有文件都有读和写以及执行的权限）
wget http://fishros.com/install -O fishros && bash fishros
https://github.com/Yousuilian/ysl_ws
git --version
git config --global user.name "Mike Li"
git config --global user.email "1726582664@qq.com"
git config user.name
git config user.email
ssh-keygen -t rsa -C "1726582664@qq.com"
git push -u origin master
sudo rm /var/cache/apt/archives/lock
sudo rm /var/lib/dpkg/lock
catkin_make
rosrun teleop_twist_keyboard teleop_twist_keyboard.py   （比较好用的键盘控制）
sudo apt-get install ros-melodic-teleop-twist-keyboard （18.04对应melodic)
rqt_graph  (计算图)
rosnode cleanup  (清除节点)
rosrun turtlesim turtlesim_node （启动乌龟节点)
sudo apt install ros-melodic-tf2-geometry-msgs (安装相应的包)
```

# VSCode快捷键

```bash
    Ctrl + Shift + a（文本文件里面快速输入 
    Ctrl + Shift + b（编译快捷键）
    输入/*                （直接输出/**/）
    Alt + up             （代码上移）
```

# 笔记：（记录一些即时笔记）

## 10.红绿蓝XYZ轴偏移方向

## 9.roscore没关闭就关发布程序会导致终端无法继续运行

## 8.有红色波浪号可以等一会、保存、编译都行

## 7.点头pitch，摇头yaw，roll是横滚

## 6.dpkg问题使得无法安装一些包（待解决）

## 5.Ctrl + Shift + b（编译快捷键）问题也自动好了

## 4.中文输入法未输入之前有待选汉字问题重启之后被解决了

## 3.使用超链接的句子前面不加Tab

## 2.关于ROS时间的运用

    demo03_apis_time对时间的操作可以更加方便的debug

## 1.ROS_INFO的数字

    ROS_INFO里面的数字是距离参考系时间1970年01月01日 00：00：00逝去的时间[ INFO] [1680112215.277143796]换算就是53.276年
