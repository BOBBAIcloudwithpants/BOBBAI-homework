#技术分享，我的c语言易错点分析和算法实例。
---
##First Part：C语言易错点    
**1.类型转换**    
（一）整型提升    
在可以使用int型或unsigned int型的表达式中，也可以使用有符号或无符号类型的char、short int、int位域，还可以使用枚举类型。    
无论哪种情况，如果使用int类型可以表示出原数据类型的所有数值，就将值转换为int型，否则转换为unsigned int型。    
>整形提升不会改变符号和数值。char型是否作为有符号类型来处理，由编译器而定。

（二）有符号整型和无符号整型    
*整数类数据*类型之间互相转换时，若原数值能用转换后的数据类型表示，则数值不会发生变化。
将有符号整数转换为位数相同或位数更多的无符号整数时，如果该有符号整数不为负数，则数值不会发生变化。    
否则，若无符号整数的位数较大，则先将有符号整数提升为与无符号整数长度相同的有符号整数。然后再于无符号整数类型可表示的最大数加1的值相加，将有符号整数转换为无符号整数。    
将整数类数据类型转换为位数更少的无符号整数时，除以比位数较少的数据类型可表示的最大无符号数大1的数，所得的非负余数就是转换后的值。    
将整数类数据类型转换为位数更少的有符号整数时，以及将无符号整数转换为位数相同的有符号整数时，如果不能正确表示转换后的值，则此时的操作由编译器而定。     

（三）浮点型和整数数据类型    
将浮点型的值转换为整数类数据类型时，会截断小数部分。整数部分的值不能用整数类数据类型表示时的操作未定义。    
将整数类数据类型转换为浮点型时，如果数据类型转换后的结果在数值范围内不能正确表示，那么会根据编译器定义的方法取大于或小于原值的最接近的近似值作为转换结果。    

（四）浮点型    
float型提升为double型或long double型时，以及double型提升为long double型时，值不会发生变化。    
double型转换为float型时，以及long double型转换为float型时，会根据编译器定义的方法取大于或小于原值的最接近的近似值作为转换结果。    

（五）普通算数类型转换    
**a**:若有一个操作数为long double型，则将另一个操作数转换为long double型。    
**b**:若有一个操作数为double型，则将另一个操作数转换为double型    
**c**:若有一个操作数为float型，则将另一个操作数转换为float类型。
**d**：若均不符合以上情况，则根据以下规则对两个操作数进行整型提升。    
 1⃣️若有一个操作数为unsigned long型，则将另一个操作数转换为unsigned long。    
2⃣️在一个操作数为long型，另一个操作数为unsigned型的情况下，如果long型能表示unsigned型d的所有值，则将两个操作数都转换为unsigned long型。    
3⃣️若有一个操作数为long型，则将另一个操作数转换为long型。    
4⃣️若有一个操作数为unsigned型，则将另一个操作数转换为unsigned型。    
5⃣️ 否则将两个操作数都转换为int型。
****
****
**2.浮点数精度误差实例**    
```
#include <stdio.h>

int main(){
    float x;

    for(x=0;x<=1.0;x+=0.01)
        printf("x=%f\h",x);
    return 0;
}
```
由于计算机在储存浮点数的时候经常出现无法准确储存从而造成误差的情况，因此上述代码的运行结果不是1.0，而是0.9999.这是因为计算机不能保证其内部转换为二进制的浮点数的每一位都不发生数据丢失。因此将1000份的误差积累在x中。     
若对上述代码略作修改，则：
```
#include <stdio.h>

int main(){
    float x;
    for(x=0.0;x!=1.0;x+=0.01) 
        printf("x=%f\n",x);
    
    return 0;
}
输出结果为：    
x=0.000000
x=0.010000
..........
x=0.979999
x=0.989999
x=0.999999
x=1.009999
x=1.019999
x=1.029999
```
那么我们该如何得到1.0这个值呢？将程序改写为用整数控制循环，改写后的程序代码如下：
```
#include <stdio.h>

int main(){
    int i;
    float x;

    for(i=0;i<=100;i++){
        x=i/100.0;
        printf("x=%f\n",x);

       
    }
return 0;
}
运行结果为：
x=0.000000
x=0.010000
..........
x=0.980000
x=0.990000
x=1.000000
```

**2.作用域和储存期**    
先来看一段代码：
```
#include <stdio.h>

int x=75;  ··········1⃣️

void print_x(void){
    printf("x=%d\n",x)·····2⃣️
}
int main(void){
    int i;
    int x=999;

    print_x();··········3⃣️

    for(i=0;i<5;i++){
        int x=i*100;
        printf("x=%d\n",x）·4⃣️
    }

    printf("x"=%d\n",x); ···5⃣️

    return 0
}
输出结果
x=75
x=999
x=0
x=100
x=200
x=300
x=400
x=999
```
首先我们来看1⃣️处声明的x。该变量的初始值为75，因为它是在函数外面生命定义的，所以这个x拥有文件作用域。    
因此，函数print_x中的“x”就是上述的x，输出x=75；
然后我们来看main函数里的声明的x。由于它是在main函数的程序块也就是复合语句中声明的，所以这个名称在main函数结尾的大括号}之前都是通用的。    
**若过两个同名变量分别拥有文件作用域和块作用域，那么只有拥有块作用域的变量是“可见“的，而拥有文件作用域的变量会被隐藏起来。**    
所以2⃣️处现实：x=999    
在main函数的for语句中声明定义了第三个变量x。适用于以下的规则：    
**当同名变量都被赋予块作用域的时候，内层的变量是‘可见的’，而外层的变量会被‘隐藏’起来。**    
因此，for语句循环体这个程序块中的x实际上就是上述的第三个变量x。由于for语句循环执行了5次，因此x显示为：
>x=0    
x=100    
x=200    
x=300    
x=400

for语句的循环结束之后，该变量x的名称就会失效。因此，在调用最后一个printf函数的地方，x的值显示为：x=999

下面我来介绍储存期的概念：    
**储存期：**变量的生存期称为储存期。    
##自动储存期：    
在函数中不使用存储类说明符static而定义出的对象（变量），被赋予了自动存储期，它具有以下特性：
>程序执行到对象声明的时候就创造出了相应的对象。而执行到包含该生命的程序快的结尾，也就是大括号}的时候，该对象就会消失。

也就是说，该对象拥有短暂的寿命，另外，如果不显示的进行初始化，则该对象会被初始化为不确定的值。    
被赋予自动储存期的对象，在程序执行到int ax=0；的时候，就被创建出来并且进行初始化。    

##静态存储期    
在函数中使用static定义出来的对象，或者在函数外声明定义出来的对象都被赋予静态存储期，它具有以下的特性。
>在程序开始执行的时候,具体地说是在main函数执行之前的准备阶段被创造出来，在程序结束的时候消失    
也就是说，该对象拥有永久的寿命。另外，如果不显示地进行初始化，则该对象会自动初始化为0.    
被赋予了静态存储器的对象，会在main函数开始执行前被初始化。因此，虽说程序执行的时候会经过static int sx=0；的声明，但其实那个时候并没有进行初始化处理，也就是说该变量并未执行赋值处理。如下代码可以更好的说明这些问题。    
```
#include <stdio.h>

int fx=0;
void func(void){
    static int sx=0;  //静态存储期+文件作用域

    int ax=0；//自动存储期+块作用域

    printf("%3d%3d%3d\n",ax++,sx++,fx++);
}

int main(void){
    int i;

    puts("ax   sx   fx");
    puts("-------------")
    for(i=0;i<10;i++)
        func();
    puts("--------------")

    return 0;
}
运行结果为：
ax   sx   fx
------------
0    0      0
0   1   1
0   2   2
0   3   3
0   4   4
0   5   5
.........
0   9   9
```

##Second Part 算法实例。
1。给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
解答：
```
int* twoSum(int* nums, int numsSize, int target) {
    int i,j,temp;
    int* outcome = (int*)malloc(sizeof(int)*2);
    for(i=0;i<numsSize;i++){
        temp=target-nums[i];
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[j]==temp)
            {
                outcome[0]=i;
                outcome[1]=j;
                break;
            }
        }
            
        }
    return outcome;
    
    }
```

2.给定一个 32 位有符号整数，将整数中的数字进行反转。    
解答
```
#include <math.h>
int reverse(int x) {
    int i,j,p,q,rest,outcome;
    int trans[999];
    int left[999];
    i=j=p=outcome=0;
    
    if(x>=0){
    
        while(x>0){
            rest=x%10;
            i++;
            trans[j++]=i; 
            left[p++]=rest;
            x=x/10;
                
                
            
                }
        for(q=0;q<i;q++){
            outcome+=(left[q]*pow(10,trans[j-q-1]))/10;
            
        }
        if(outcome<0)
            return 0;
        else
            return outcome;
    }
        else
        {
            if(x<INT_MIN)
                return 0;
            else
                x=-x;
                while(x>0){
                rest=x%10;
                i++;
                trans[j++]=i; 
                left[p++]=rest;
                x=x/10;
            
        }
        for(q=0;q<i;q++){
            outcome+=(left[q]*pow(10,trans[j-q-1]))/10;
    
    }
            if(outcome<0)
                return 0;
            else
                return -outcome;
        }
  
    
}
```
3.判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
```
bool isPalindrome(int x) {
    int rest,i,j;
    i=j=0;
    int store[999];
    if(x<0)
        return false;
    else if(x>=0&&x<=9)
        return true;
    else 
    {   
        while(x>0){
            store[i++]=x%10;
            x/=10;
            rest=i;
        }
        for(j=0;j<rest;j++){
            if(store[j]!=store[rest-j-1])
            {
                return false;
            }
        }
        return true;
    }
    
}
```

4.罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
解答：
```
int romanToInt(char* s) {
    int i,sum;
    i=0;
    sum = 0;
    while(s[i]!='\0'){
        switch(s[i]){
            case 'I':{
                     if(s[i+1]=='V'){sum+=4;i++;}
                     else if(s[i+1]=='X'){sum+=9;i++;}
                     else{ 
                         sum+=1;
                     }i++;
                break;
                     
                     }
            case 'V':{sum+=5;i++;break;}
            case 'X':{
                     if(s[i+1]=='L'){sum+=40;i++;}
                     else if(s[i+1]=='C'){sum+=90;i++;}
                     else 
                     {sum+=10;
                     
                     }i++;break;
                     }
            case 'L':{sum+=50;i++;break;}
            case 'C':{
                     if(s[i+1]=='D'){sum+=400;i++;}
                     else if(s[i+1]=='M'){sum+=900;i++;}
                     else {
                         sum+=100;
                     
                     }i++;break;
            case 'D':{sum+=500;i++;break;}
            case 'M':{sum+=1000;i++;break;}
                 
                
                     }
                
        
    }
        
    }
    return sum;
}
```
5.给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。
```
int searchInsert(int* nums, int numsSize, int target) {
    int i,j;
    if(nums[numsSize-1]<target)
        return numsSize;
    else if(nums[0]>target)
        return 0;
    else{
        for(i=0;i<numsSize;i++){
            if(nums[i]==target)
                return i;
            else if(nums[i]<target){
                if(nums[i+1]>=target)
                    return i+1;
                
            }
            else{
                if(nums[i-1]<=target)
                    return i-1;
                
                
            }
        }
    }
        return 0;
    
}
```