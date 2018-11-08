# HTML游戏2

## 一.成果展示    

![](https://upload.cc/i1/2018/11/08/fkyP6T.gif)

##二.游戏简介

该游戏的设计思路是利用construct 2 中预设的物理系统来设计一个发射炮弹的游戏。    
![](https://upload.cc/i1/2018/11/08/WNjtoU.jpg)

## 三.游戏策划

既然需要制作这样一个游戏，首先要准备插图部分，这里包含了5部分插图：炮弹，炮筒，底座，背景地和箱子。由于游戏图片素材均来源于网上，所以可能会出现裁剪不恰当的问题。    
紧接着要植入物理效果。我们利用physics这一behavior来设置每一个物体，使其产生物理效果。    
接着就是事件的描述。例如让炮筒跟随鼠标旋转，设置imagepoint等等。    

## 四.游戏设计    
Object:cannon    
Attribute:picture position    
Collaborator|Events&Actions
- |:-:| -
ball | being sprawed


    
object:ball    
Attribute:position picture    
Collaborator|Events&Actions
- |:-:| -
boxes | collapsed and broked 
