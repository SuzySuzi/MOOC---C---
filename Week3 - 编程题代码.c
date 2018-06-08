/** 第3周——从键盘中来，到键盘中去，开始输入和输出啦 */

/* 1学分绩计算（3分）
题目内容：
已知某大学期末考试学分绩的计算公式为：学分绩 =（工科数学 * 5 + 英语 * 1.5 + 线性代数 * 3.5） / 10
请编程从键盘按顺序输入某学生的工科数学、英语和线性代数成绩，计算并输出其学分绩。

以下为程序的运行结果示例：
Input math1, English and math2:80,70,100↙
Final score = 85.50

输入提示信息："Input math1, English and math2:"
输入格式: "%d,%d,%d"
输出格式："Final score = %.2f\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件 
int main()
{
    int math1,english,math2;
    float final_score;
    printf("Input math1,English and math2:");
    scanf("%d,%d,%d",&math1,&english,&math2);
    final_score = (math1*5+english*1.5+math2*3.5)/10;
    printf("Final score = %.2f\n",final_score);
}


/* 2一尺之捶，日取其半（3分）
题目内容：
我国古代著作《庄子》中记载道：“一尺之捶，日取其半，万世不竭”。
其含义是：对于一尺的东西，今天取其一半，明天取其一半的一半，后天再取其一半的一半的一半总有一半留下，所以永远也取不尽。
请编写一个程序，使其可以计算出一条长为m的绳子，在n天之后剩下的长度。

运行结果示例1：
Input length and days:12,5↙
length=0.37500
运行结果示例2：
Input length and days:57.6,7↙
length=0.45000

输入提示信息："Input length and days:"
输入格式: "%f,%d"
输出格式："length=%.5f\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    float length;
    int days;
    printf("Input length and days:");
    scanf("%f %d",&length,&days);
    length = length / pow(2,days);
    printf("length=%.5f\n",length);
}

/* 3网购打折商品V1.0（4分）
题目内容：
某网上购物网站对用户实行优惠，买家购物货款p越多，则折扣越多。今天正值该网站优惠折扣日，买家可以获得8%的折扣。
请编程从键盘输入买家购物货款p，计算并输出买家折扣后实际应付出的价钱。

注：程序中的数据类型为float。
程序的运行结果示例1：
Input payment p:300↙
price = 276.0
程序的运行结果示例2：
Input payment p:1299.8↙
price = 1195.8

输入提示信息："Input payment p:"
输入格式: "%f"
输出格式："price = %.1f\n" (注：等号左右均有空格) */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    float p,payment,discount;
    discount = 0.08;
    printf("Input payment p: ");
    scanf("%f",&p);
    payment = p*(1-discount);
    printf("price = %.1f\n",payment);
}

/* 4计算时间差V1.0（4分）
题目内容：
编程从键盘任意输入两个时间（例如4时55分和1时25分），计算并输出这两个时间之间的间隔。要求不输出时间差的负号。

程序的运行结果示例1： 
Input time one(hour, minute):4,55↙
Input time two(hour, minute):1,25↙
3 hour 30 second

程序的运行结果示例2： 
Input time one(hour, minute):1,56↙
Input time two(hour, minute):3,25↙
1 hour 29 second

输入提示信息："Input time one(hour, minute):"
               "Input time two(hour, minute):"
输入格式："%d,%d"
输出格式："%d hour %d minute\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    int hour1,minute1;
    int hour2,minute2;
    int differ_hour,differ_minute;
    printf("Input time one(hour,minute):");
    scanf("%d%d",&hour1,&minute1);
    printf("Input time two(hour,minute):");
    scanf("%d%d",&hour2,&minute2);
    differ_hour = fabs(((hour1*60 + minute1) - (hour2*60 + minute2))/ 60);
    differ_minute = fabs(((hour1*60 + minute1) - (hour2*60 + minute2))% 60);
    printf("%d hour %d minute",differ_hour,differ_minute);
}

/* 1日期显示（3分）
题目内容：
编写一个程序, 接收用户录入的日期信息并且将其显示出来. 其中, 输入日期的形式为月/日/年(mm/dd/yy), 输出日期的形式为年月日(yy.mm.dd)。

以下为程序的运行结果示例：
Enter a date (mm/dd/yy):
12/03/2015↙
You entered the date: 2015.12.03

输入格式: "%d/%d/%d"
输出格式：
输入提示信息："Enter a date (mm/dd/yy):\n"
输出格式："You entered the date: %04d.%02d.%02d\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int mm,dd,yy;
    printf("Enter a date (mm/dd/yy):\n");
    scanf("%d/%d/%d",&mm,&dd,&yy);
    printf("You entered the date: %04d.%02d.%02d\n",yy,mm,dd);
}

/* 2产品信息格式化（3分）
题目内容：
编写一个程序, 对用户录入的产品信息进行格式化。

以下为程序的运行结果示例：
Enter item number:
385↙
Enter unit price:
12.5↙
Enter purchase date (mm/dd/yy):
12/03/2015↙
Item      Unit     Purchase
385      $ 12.50    12032015

输入格式:
产品编号输入格式："%d"
产品价格输入格式："%f"
购买日期输入格式："%d/%d/%d"

输出格式：
产品编号输入提示信息："Enter item number:\n"
产品价格输入提示信息："Enter unit price:\n"
购买日期输入提示信息："Enter purchase date (mm/dd/yy):\n"
格式化输出的表头信息："Item      Unit     Purchase\n"
输出格式："%-9d$ %-9.2f%02d%02d%02d\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int item_num;
    float unit_price;
    int mm,dd,yy;
    printf("Enter item number:\n");
    scanf("%d",&item_num);
    printf("Enter unit price:\n");
    scanf("%f",&unit_price);
    printf("Enter purchase date (mm/dd/yy):\n");
    scanf("%d/%d/%d",&mm,&dd,&yy);
    printf("Item     Unit     Purchase\n");
    printf("%-9d$ %-9.2f%02d%02d%02d\n",item_num,unit_price,mm,dd,yy);
}

/* 3计算两个数的平方和（3分）
题目内容：
从键盘读入两个实数，编程计算并输出它们的平方和，要求使用数学函数pow(x,y)计算平方值，输出结果保留2位小数。 程序中所有浮点数的数据类型均为float。
提示：使用数学函数需要在程序中加入编译预处理命令 #include <math.h>

以下为程序的运行结果示例：
Please input x and y:
1.2,3.4↙
Result=13.00

输入格式: "%f,%f"
输出格式：
输入提示信息："Please input x and y:\n"
输出格式："Result=%.2f\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    float x,y,result;
    printf("Please inout x and y:\n");
    scanf("%f,%f",&x,&y);
    result = pow(x,2) + pow(y,2);
    printf("Result=%.2f\n",result);
}

/* 4逆序数的拆分计算（3分）
题目内容：
从键盘输入一个4位数的整数，编程计算并输出它的逆序数（忽略整数前的正负号）。
例如，输入-1234，忽略负号，由1234分离出其千位1、百位2、十位3、个位4，然后计算4*1000+3*100+2*10+1 = 4321，并输出4321。
再将得到的逆序数4321拆分为两个2位数的正整数43和21，计算并输出拆分后的两个数的平方和的结果。

以下是程序的运行结果示例：
Input x:
-1234↙
y=4321
a=43,b=21
result=2290

输入提示信息："Input x:\n"
输入格式： "%d"
输出格式：
逆序数输出格式："y=%d\n"
逆序数拆分后的输出格式："a=%d,b=%d\n"
平方和的输出格式："result=%d\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int x,y,a,b;
    printf("Input x: \n");
    scanf("%d",&x);
    y = x/1000 + x%1000/100*10 + (x%100)/10*100 + x%10*1000 ;
    a = y/100;
    b = y%100;
    printf("y=%d\na=%d,b=%d\n",y,a,b);
}


/* 5拆分英文名（3分）
题目内容：
从键盘输入某同学的英文名（小写输入，假设学生的英文名只包含3个字母。如: tom），编写程序在屏幕上输出该同学的英文名，且首字母大写（如: Tom）。
同时输出组成该英文名的所有英文字符在26个英文字母中的序号。

以下为程序的运行结果示例：
Input your English name:
tom↙
Tom
t:20
o:15
m:13

输入提示信息："Input your English name:\n"
输入格式： "%c%c%c"
输出格式：
首字母大写的英文姓名的输出格式："%c%c%c\n"
姓名中每个字母在26个英文字母中的序号的输出格式："%c:%d\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    char a,b,c;
    printf("Input your English name:\n");
    scanf("%c%c%c",&a,&b,&c);
    printf("%c%c%c\n",a-32,b,c);
    printf("%c:%d\n%c:%d\n%c:%d\n",a,a-'a'+1,b,b-'a'+1,c,c-'a'+1);
}

/* 6计算体指数（3分）
题目内容：
从键盘输入某人的身高（以厘米为单位，如174cm）和体重（以公斤为单位，如70公斤），将身高（以米为单位，如1.74m）和体重（以斤为单位，如140斤）输出在屏幕上，
并按照以下公式计算并输出体指数，要求结果保留到小数点后2位。程序中所有浮点数的数据类型均为float。
假设体重为w公斤，身高为h米，则体指数的计算公式为：
t=w/(h^2)
以下是程序的运行结果示例：

Input weight, height:
70,174↙
weight=140
height=1.74
t=23.12

输入提示信息："Input weight, height:\n"    (注意：在height和逗号之间有一个空格)
输入格式: "%d,%d"
输出格式：
体重输出格式："weight=%d\n"
身高输出格式："height=%.2f\n"
体指数输出格式："t=%.2f\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    int height,weight;
    float t;
    printf("Input weight,height:\n");
    scanf("%d,%d",&weight,&height);
    t = weight/pow(((float)height/100),2);
    printf("weight=%d\nheight=%.2f\nt=%.2f\n",weight*2,(float)height/100,t);
}
