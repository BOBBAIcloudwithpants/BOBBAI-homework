# 洗衣机算法研究

![](https://upload.cc/i1/2018/11/12/jBEAlT.jpg)    
**洗衣机**，作为宿舍中必不可少的用电器，为宿舍的洗衣问题做出了极大贡献，今天我们来对洗衣机的洗衣流程算法做一个简单的分析。    
***   
***

## Part 1:伪代码分解大块流程   
洗衣机的工作流程大致可以这样描述：    
打开上水开关，注水    
等到达到目标水量时，关闭上水开关，停止注水     
电机开始运转，衣物开始洗涤    
达到目标时间后停止转动，浸泡    
浸泡后漂洗洗去多余洗洁精    
甩干并脱水、排水    
结束洗衣      

## Part 2:语句以及细节实现  
```  
water_in_switch(open)    
get_water_volume(return)   
if(return==target)
water_in_switch(close)    
    

motor_run(left)for(set_time/10)times;
motor_run(right)for(set_time/10)times    
time_counter(return)    
if(return==set)       

water_out_switch(open)    
motor_run(left)    
motor_run(right)    
get_water_volume(return)    
if(return<standard)
water_out_switch(close)    
halt(success)
```  

## 正常洗衣与快速洗衣    
**用户目标上的异同：**    
相同点：洗涤衣物    
不同点：干净程度要求不同；清洗时间要求不同。    

**程序上的异同：**    
相同点：大体上看二者都有：注水、电机甩动、漂洗、排水等基础步骤    
不同点：每一个步骤的细节和时间长度不同。相比之下，快速洗衣在注水之后的电机缓解耗时更短。    

**有关改进意见：**    
这两种洗衣模式面对着不同需求的用户，然而对于那些既追求时间较短，又要增加清洁程度的用户则往往难以达到要求。因此，在维持注水量不变的前提下，增加电机在甩动过程中的速率能够提升洗衣效率，同时满足更多用户的需求。    

```
wait(time);
注水(volume,timeout);
排水(timeout);
电机转速(timein,mode);

water_in_switch(open)

if(注水(volume,timeout))
while(time_counter){
motor_run(电机转速(timein,mode))}

排水(timeout)

halt(success)

