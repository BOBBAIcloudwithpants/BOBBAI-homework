# Python 编程实验报告

众所周知，Python是一种广泛的使用的高级语言，属于通用型编程语言。作为一种解释型语言，Python的设计哲学强调代码的可读性和简洁的语法。相比C++和Java，Python让开发者能够用更少的代码表达想法。不管是小型还是大型程序，该语言都是土壤程序的结构清晰明了。    
这次试验我们着重利用python 的两个库：numpy以及sympy来对现有的数学问题进行解决。     

## Sympy：

1.用python进行泰勒展开：
在x=x<sub>0</sub>处，令x<sub>0</sub>=0;对以下函数进行展开：    
y=sin(x)
>![](https://upload.cc/i1/2018/11/17/GNUBsE.png)

y=cos(x)    
>![](https://upload.cc/i1/2018/11/17/RK6tCE.png)

y=tan(x)
>![](https://upload.cc/i1/2018/11/17/BOsJkK.png)    

![](https://upload.cc/i1/2018/11/17/btAiI3.png)    

语法的实现：    
```python
>>>from sympy import
>>>func.series(变量名，展开位置，无穷小的阶数)    
```

2.解二元一次方程    
在求函数的不定积分时，我们经常遇到要对分母的多项式进行拆分来方便求解过程的操作，待定系数法是最主要的工具，则难以避免的要进行多元一次方程的求解。   
e.g.求方程组:    
2*x-3*y=7    
3*x-9*y=29的解：
>![](https://upload.cc/i1/2018/11/17/mjt8TQ.png)

语法：
```python
>>>equation f1
>>>equation f2
   ·
   ·
   ·
>>>equation fn
>>>print(solve([f1,f2···fn]))   
```

3.求导    
·验证y=cosx在x=a处的导数为-sina
>![](https://upload.cc/i1/2018/11/17/OTDAs5.png)    

语法：
```python
>>>diff(函数名，变量名，（变量的值）)
```

## Numpy    
1.创建一个矩阵
>![](https://upload.cc/i1/2018/11/17/WPSqLa.png)

可以采用arange来快速排列元素，然后以reshape函数来定义该矩阵的行数与列数。要注意的是若arange的范围大小与行数乘列数不匹配则会出现Error。    
    
>![](https://upload.cc/i1/2018/11/17/0juIls.png)
也可以直接在列表中逐行以中括号的形式陈列出每个元素的值，注意每一行元素的个数要相等，否则会出现错误。
    
2.矩阵的乘法
>![](https://upload.cc/i1/2018/11/17/WPSqLa.png)

语法格式如下
```python
>>>from numpy import *
>>>dot(matrix1,matrix2)
# 要注意如果矩阵1的列数不等于矩阵2的行数则无法相乘，会报错。
```

3.求可逆矩阵
>![](https://upload.cc/i1/2018/11/17/BgyqPl.png)

语法格式如下：
```python
>>>from numpy.linalg import inv
#导入inv函数    
>>>inv(matrix1)    
```
