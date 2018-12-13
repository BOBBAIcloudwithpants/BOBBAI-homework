# 智能蛇实验报告

## 环境配置：
我的电脑操作系统为os。因此我下载了VMwareFusion虚拟机，下载了Ubuntu的18镜像，利用镜像成功安装。效果如下：
![](https://upload.cc/i1/2018/12/12/XpZr6a.png)

之后配置c的编译环境和gcc    
在终端中输入
> sudo apt-get install build-essential
>sudo apt-get install vim-gtk

即可

## 开始编程

在终端中输入：
>touch main.cpp

即可新建cpp文件。
紧接着输入：
>vim main.cpp
![](https://upload.cc/i1/2018/12/12/SgudQa.png)

输入‘i’进入insert模式，结束后按esc然后输入:wq即可

    
编译阶段只需输入：
![](https://upload.cc/i1/2018/12/12/Lm1feU.png)
若编译成功，输入文件名：main.cpp即可开始运行。    

## 代码实现
相比贪吃蛇，智能蛇只需让蛇在每一步的移动之中测量食物距离蛇头的位置即可，即设计函数“wheregonext”即可，函数原型如下：
>![](https://upload.cc/i1/2018/12/12/zKlkFf.png)

## 思考
由于该程序并未使用回溯的算法，即如果下一步撞上墙则采取其他方案的方法，导致蛇比较容易因为距离事物的距离问题从而做出错误的决策导致游戏结束，因此长度为五的墙可以限制该蛇的移动。