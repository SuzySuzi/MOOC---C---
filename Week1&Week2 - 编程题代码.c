
/** 第1周——初识C语言从认识变量和常量开始 */

/* 3计算半圆弧长及半圆的面积。（3分）
题目内容：

编程并输出半径r=5.3的半圆弧长（提示：半圆弧长不应该加直径的长度。）及该半圆弧与直经围成的半圆的面积，pi的取值为3.14159。
要求半径r和pi必须利用宏常量表示。

输入格式:无
输出格式：
半圆的面积输出格式： "Area=%.5f\n"
半圆弧长输出格式： "circumference=%.5f\n"

输出样例：
Area=44.12363
circumference=16.65043 */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#define PI 3.14159
#define R 5.3
int main()
{
    float Area,circumference;
    Area = PI * R *R / 2;
    circumference = PI * R;
    printf("Area=%.5f\n",Area);
    printf("circumference=%.5f\n",circumference);
}


/* 4计算长方体体积（3分）
编程并输出长1.2、宽4.3、高6.4的长方体的体积。要求长方体的长、宽、高必须利用const常量表示。程序中用到的数据类型均为为 double类型。

输入格式:无

输出格式："volume=%.3f\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    const double length = 1.2,width = 4.3,height = 6.4;
    double volume;
    volume = length*width*height;
    printf("volume=%.3f\n",volume);
}

/** 第2周——数字间的那些事儿，做点计算哈 */

/* 1输出逆序数（3分）
题目内容：
从键盘任意输入一个3位整数，编程计算并输出它的逆序数（忽略整数前的正负号）。
例如，输入-123，则忽略负号，由123分离出其百位1、十位2、个位3，然后计算3*100+2*10+1 = 321，并输出321。

提示：
1. 从键盘输入数据可以使用函数scanf()。例如，scanf("%d", &x); 表示从键盘输入整数并存入整形变量x中。
2. 利用取绝对值函数 fabs()忽略输入数据的负号。fabs(x)表示计算变量x的绝对值。
3.使用数学函数，需要在程序开头加上编译预处理指令 #include <math.h>

以下为程序的一个运行示例
Input x:
-123↙
y=321

输入格式: "%d"
输出格式：
提示信息："Input x:\n"
输出格式："y=%d\n"
 */
 
#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    int x,y;
    printf("Input x:\n");
    scanf("%d",&x);
    if(x>=100 && x<=999){
        y=x/100+x%10*100+(x-100*(x/100))/10*10;
        printf("y=%d\n",y);
    }else{
        printf("please input a three bit integer and try again.");
    }
}
 
 /* 2计算总分和平均分（3分）
 题目内容：
小明本学期共有5门课程，分别是英语、语文、数学、历史和音乐。5科的期中考试成绩分别是86分、74分、92分、77分、82分，期末考试成绩分别是81分、87分、90分、62分、88分。已知期中和期末考试成绩分别占总成绩的30%和70%。定义相应的变量存放各科成绩，并计算出小明5门课程的总分和平均分。
要求平均分输出两种形式：带2位小数的浮点数形式和不带小数的整数形式。要求总分输出带2位小数的浮点数形式。程序中浮点数的数据类型均为float类型。
提示：
输出不带小数的平均分的整数形式可以使用强制类型转换。

以下为输出示例：
total=408.90
average=81.78
average=81

输入格式:无
输出格式：
输出总分的格式： "total=%.2f\n"
输出平均分的格式： "average=%.2f\n"
                   "average=%d\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    float english,chinese,math,history,music;
    float total,average;
    english = 86*0.3 + 81*0.7;
    chinese = 74*0.3 + 87*0.7;
    math = 92*0.3 + 90*0.7;
    history = 77*0.3 + 62*0.7;
    music = 82*0.3 + 88*0.7;
    total = english+chinese+math+history+music;
    average = total/5;
    printf("total=%.2f\n",total);
    printf("average=%.2f\n",average);
    printf("average=%d\n",(int)average);
}

/* 3存款利率计算器V1.0（3分）
题目内容：
设银行定期存款的年利率rate为2.25%，已知存款期为n年，存款本金为capital元，试编程计算并输出n年后的本利之和deposit。程序中所有浮点数的数据类型均为double类型。

提示：
1. 从键盘输入数据可以使用函数scanf()。本例中为scanf("%lf,%d,%lf", &rate, &n, &capital);
2. 本程序最终计算的是复利。
3. 计算幂的数学函数为pow(a,n), 代表a的n次幂。
4. 使用数学函数，需要在程序开头加上编译预处理指令 #include <math.h>

以下为程序的一个运行示例：
Please enter rate, year, capital:
0.0225,10,1000↙
deposit=1249.203 

输入格式: "%lf,%d,%lf"
输出格式：
输入信息提示： "Please enter rate, year, capital:\n"
输出格式："deposit=%.3f\n"		 */		

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    int n;
    double rate,capital,deposit;
    printf("Please enter rate,year,capital:\n");
    scanf("%lf,%d,%lf", &rate, &n, &capital);
    deposit=capital*pow((1+rate),n);
    //printf("%lf,%d,%lf", rate, n, capital);
    printf("deposit=%.3f\n",deposit);
}

/* 4数位拆分v1.0（3分）
题目内容：
现有一个4位数的正整数n=4321（即n是一个已知的数，固定为4321），编写程序将其拆分为两个2位数的正整数43和21，计算并输出拆分后的两个数的加、减、乘、除和求余的结果。
例如n=4321,设拆分后的两个整数为a,b，则a=43,b=21。除法运算结果要求精确到小数点后2位,数据类型为float。

以下为程序的运行结果示例：
a=43,b=21
a+b=64
a-b=22
a*b=903
a/b=2.05
a%b=1

输入格式: 无
输出格式：
数位拆分的输出格式："a=%d,b=%d\n"
加法运算的输出格式："a+b=%d\n"
减法运算的输出格式："a-b=%d\n"
乘法运算的输出格式："a*b=%d\n"
除法运算的输出格式："a/b=%.2f\n"
求余运算的输出格式："a%%b=%d\n"    */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int n=4321;
    int a,b;
    a=n/1000*10+(n-n/1000*1000)/100;
    b=(n-a*100);
    printf("a=%d,b=%d\n",a,b);
    printf("a+b=%d\n",a+b);
    printf("a-b=%d\n",a-b);
    printf("a*b=%d\n",a*b);
    printf("a/b=%.2f\n",(float)a/(float)b);
    printf("a%%b=%d\n",a%b);
}

/* 5求正/负余数（3分）
题目内容：
在C语言中，如果被除数为负值，则对一个正数求余的时候，求出的余数也是一个负数。
在某些场合下，我们需要求出它的正余数，例如：在C语言中有(-11)%5=-1，但是有时我们希望得到的余数不是-1，而是4。请编写程序计算(-11)%5的负余数和正余数。

以下为程序运行结果示例：
negative: -1
positive: 4

输入格式:无
输出格式：
负余数的输出格式："negative: %d\n"
正余数的输出格式："positive: %d\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int dividend = -11, divisor = 5;
    int negative,positive;
    negative = dividend % divisor;
    positive = dividend%divisor+divisor;
    printf("negative: %d\n",negative);
    printf("positive: %d\n",positive);
}

/* 6身高预测（3分）
题目内容：
已知小明（男孩）爸爸的身高是175厘米，妈妈的身高是162厘米。小红（女孩）爸爸的身高是169厘米，妈妈的身高是153厘米，按照下面公式，预测并输出小明和小红的遗传身高（不考虑后天因素）。
         男性成人时身高=(faHeight + moHeight)×0.54cm
         女性成人时身高=(faHeight×0.923 + moHeight)/2cm

以下为程序的运行结果示例：
Height of xiao ming:181
Height of xiao hong:154

输入格式: 无
输出格式：
小明身高的输出格式："Height of xiao ming:%d\n"
小红身高的输出格式："Height of xiao hong:%d\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int height_male,height_female;
    int faHeight,moHeight;
    printf("please input your father's height: ");
    scanf("%d",&faHeight);
    printf("please input your mother's height: ");
    scanf("%d",&moHeight);
    height_male = (faHeight + moHeight)*0.54;
    height_female = (faHeight*0.923 + moHeight)/2;
    printf("Height of xiao ming:%d\n",height_male);
    printf("Height of xiao hong:%d\n",height_female);
}

/* 7求一元二次方程的根（3分）
题目内容：
计算并输出一元二次方程2x^2+3x+1=0的两个实根，要求精确到小数点后4位。程序中所有浮点数的数据类型均为float.

提示：
1. 计算平方根的数学函数为sqrt（）。
2. 使用数学函数，需要在程序开头加上编译预处理指令 #include <math.h>

以下为程序运行结果示例
x1=-0.5000
x2=-1.0000

输入格式: 无
输出格式：
      "x1=%.4f\n" */
	 
#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    int a,b,c;
    float x1,x2;
    printf("please input a,b,c: ");
    scanf("%d%*c%d%*c%d",&a,&b,&c);
    printf("and confirm the equation is: %dx^2 + %dx + %d\n",a,b,c);
    x1 = (sqrt(b*b-4*a*c)-b)/(2*a);
    x2 = (0-sqrt(b*b-4*a*c)-b)/(2*a);
    printf("x1=%.4f\n",x1);
    printf("x2=%.4f\n",x2);
}

