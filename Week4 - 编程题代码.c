
/** 第4周——无处不在的抉择 */

/* 1分数比较（4分）
题目内容：
利用人工方式比较分数大小的最常见的方法是：对分数进行通分后比较分子的大小。请编程模拟手工比较两个分数的大小。
先输入两个分数分子分母的值，例如"11/13,17/19"，比较分数大小后输出相应的提示信息。例如，第一个分数11/13小于第二个分数17/19，则输出"11/13<17/19"。

程序的运行结果示例1：
Input a/b, c/d:11/13,17/19↙
11/13<17/19
程序的运行结果示例2：
Input a/b, c/d:17/19,23/27↙
17/19>23/27
程序的运行结果示例3：
Input a/b, c/d:3/4,18/24↙
3/4=18/24

输入提示信息："Input a/b, c/d:"  (注意：逗号后面有一个空格)
输入格式: "%d/%d,%d/%d"
输出格式：
比较的结果是大于："%d/%d>%d/%d\n"
比较的结果是小于："%d/%d<%d/%d\n"
比较的结果是相等："%d/%d=%d/%d\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int a,b,c,d;
    printf("Input a/b, c/d:");
    scanf("%d/%d %d/%d",&a,&b,&c,&d);
    if(a*d > c*b){
        printf("%d/%d>%d/%d\n",a,b,c,d);
    }else if(a*d < c*b){
        printf("%d/%d<%d/%d\n",a,b,c,d);
    }else{
        printf("%d/%d=%d/%d\n",a,b,c,d);
    }
}


/* 2存款利率计算器v2.0（4分）
题目内容：
设capital是最初的存款总额（即本金），rate是整存整取的存款年利率，n是储蓄的年份，deposit是第n年年底账号里的存款总额。已知如下两种本利之和的计算方式：
按复利方式计息的本利之和计算公式为：
		deposit  =  capital  * (1 + rate)^n
按普通计息方式计算本利之和的公式为：
		deposit  =  capital  * (1 + rate * n)
编程从键盘输入存钱的本金、存款期限以及年利率，然后再输入按何种方式计息，最后再计算并输出到期时能从银行得到的本利之和，要求结果保留到小数点后4位。

提示：使用数学函数需要加入头文件 <math.h>

程序的运行结果示例1：
Input rate, year, capital:0.0225,2,10000↙
Compound interest (Y/N)?Y
deposit = 10455.0625
程序的运行结果示例2：
Input rate, year, capital:0.0225,2,10000↙
Compound interest (Y/N)?n
deposit = 10450.0000

输入提示信息："Input rate, year, capital:"
输入提示信息："Compound interest (Y/N)?" 
本金、存款期限以及年利率的输入格式: "%lf,%d,%lf"
是否选择复利计算的输入格式： " %c" (注意：%c的前面有一个空格。输入的字符大小写皆可，即Y或y，N或n皆可)
输出格式："deposit = %.4f\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    float rate,capital,deposit;
    int year;
    char flag;
    printf("Input rate, year, capital:");
    scanf("%f %d %f",&rate,&year,&capital);
    printf("Compound Interest (Y/N)?");
    scanf(" %c",&flag);
    if(flag == 'Y' || flag == 'y'){
        deposit = capital * pow((1+rate),year);
        printf("deposit = %.4f\n",deposit);
    }else if(flag == 'N' || flag == 'n'){
        deposit = capital * (1+rate*year);
        printf("deposit = %.4f\n",deposit);
    }else{
        printf("Input error");
    }
}

/* 3存款利率计算器v3.0（9分）
题目内容：
设capital是最初的存款总额（即本金），rate是整存整取的存款年利率，n 是储蓄的年份，deposit是第n年年底账号里的存款总额。已知如下两种本利之和的计算方式：
按复利方式计息的本利之和计算公式为：deposit  =  capital * (1 + rate)^ n
按普通计息方式计算本利之和的公式为：deposit  =  capital  * (1 + rate * n)
已知银行整存整取不同期限存款的年息利率分别为：
存期1年，利率为 0.0225
存期2年，利率为 0.0243
存期3年，利率为 0.0270
存期5年，利率为 0.0288
存期8年，利率为 0.0300
若输入其他年份，则输出"Error year!"

编程从键盘输入存钱的本金和存款期限，然后再输入按何种方式计息，最后再计算并输出到期时能从银行得到的本利之和，要求结果保留到小数点后4位。

程序的运行结果示例1：
Input capital, year:10000,2↙
Compound interest (Y/N)?Y↙
rate = 0.0243, deposit = 10491.9049
程序的运行结果示例2：
Input capital, year:10000,2↙
Compound interest (Y/N)?n↙
rate = 0.0243, deposit = 10486.0000
程序的运行结果示例3：
Input capital, year:1000,4↙
Compound interest (Y/N)?y↙
Error year!

输入提示信息："Input capital, year:"
输入提示信息："Compound interest (Y/N)?"
存期输入错误的提示信息： "Error year!\n"
本金及存款期限的输入格式: "%lf,%d"
是否选择复利计算的输入格式： " %c" (注意：%c的前面有一个空格。输入的字符大小写皆可，即Y或y，N或n皆可)
输出格式："rate = %.4f, deposit = %.4f\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    double rate,capital,deposit;
    int year;
    char flag;
    printf("Input capital, year:");
    scanf("%lf %d",&capital,&year);
    switch(year)
    {
        case 1:rate = 0.0225;break;
        case 2:rate = 0.0243;break;
        case 3:rate = 0.0270;break;
        case 5:rate = 0.0288;break;
        case 8:rate = 0.0300;break;
        default:rate = 0;printf("Error year!");
    }
    if(rate != 0){
        printf("Compound Interest (Y/N)?");
        scanf(" %c",&flag);
        if(flag == 'Y' || flag == 'y'){
        deposit = capital * pow((1+rate),year);
        printf("rate = %.4f, deposit = %.4f\n",rate,deposit);
        }else if(flag == 'N' || flag == 'n'){
        deposit = capital * (1+rate*year);
        printf("rate = %.4f, deposit = %.4f\n",rate,deposit);
        }else{
        printf("Input error");
        }
    }
}


/* 4博弈论之Best Response（6分）
题目内容：

在博弈论中，有一种决策称为Best Response，通俗的意思就是选择一种策略使得团体利益最大化。C语言学习成绩的评定方式分为两种，一种是自由刷题模式（compete），没有固定标准，刷题越多者排名越靠前，其期末分数越高；另一种是规定每个人必须做够多少道题（standard），达到要求就能取得相应分数。
假设一个班级中的学生分为A、B两类，A类同学学习热情很高，乐于做题，采用compete模式可以获得成就感并且在期末拿到高分，compete模式可以让他们有10分的收益；采用standard模式他们也可以在期末拿到高分，但不能满足他们的求知欲，standard模式可以让他们有8分的收益。B类同学仅仅希望期末拿高分，如果采用compete模式，他们竞争不过A类同学，期末成绩不理想，因此compete模式能给他们6分的收益；如果采用standard模式，他们可以完成规定任务并拿到高分，因此standard模式可以让他们有10分的收益。

编程输入A类和B类同学分别占班级总人数的百分比，分别计算并输出采用compete和standard两种刷题模式下的全班总收益，并输出这个班级在这场博弈中的Best Response是哪种模式。
注： 程序中使用的数据类型为float

程序运行结果示例1：
Input percent of A and B:0.2 0.8↙
compete = 6.8000
standard = 9.6000
The Best Response is standard!
程序运行结果示例2：
Input percent of A and B:0.8 0.2↙
compete = 9.2000
standard = 8.4000
The Best Response is compete!
程序运行结果示例3：
Input percent of A and B:0.5 0.5↙
compete = 8.0000
standard = 9.0000
The Best Response is standard!

输入提示信息："Input percent of A and B:"
输入格式: "%f%f"
输出格式："compete = %.4f\nstandard = %.4f\n"
输出提示信息："The Best Response is compete!"
输出提示信息："The Best Response is standard!" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    float A,B,compete,standard;
    printf("Input percent of A and B:");
    scanf("%f %f",&A,&B);
    if( A+B ==1 ){
        compete = A*10 + B*6;
        standard = A*8 + B*10;
        printf("compete = %.4f\n",compete);
        printf("standard = %.4f\n",standard);
        if(compete > standard){
            printf("The Best Response is compete!");
        }else if(compete < standard){
            printf("The Best Response is standard!");
        }else{printf("The same.");}
    }else{printf("Input error!");}
}

/* 1检测用户错误输入（4分）
题目内容：
根据scanf()的返回值判断scanf()是否成功读入了指定的数据项数，使程序在用户输入123a时，能输出如下运行结果：
123a↙
Input error!

输入格式: "%d %d"

输出格式：
如果成功读入指定的数据项数，输出格式为："a = %d, b = %d\n" （注意：等号的两边各有一个空格）
输入非法数据，输出格式为："Input error!" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int input1,input2,valid_input_num;
    valid_input_num = scanf("%d %d",&input1,&input2);
    if(valid_input_num == 2){
        printf("a = %d, b = %d\n",input1,input2);
    }else{printf("Input error!");}
}

/* 2闰年判断（6分）
题目内容：
从键盘任意输入一个公元年份（大于等于1），判断它是否是闰年。若是闰年输出“Yes”，否则输出“No”。要求对输入数据进行合法性判断。
已知符合下列条件之一者是闰年：
（1）能被4整除，但不能被100整除；
（2）能被400整除。

运行结果示例1：
2015↙
No
运行结果示例2：
2016↙
Yes
运行结果示例3：
-123↙
Input error!
运行结果示例4：
a↙
Input error!

输入格式: "%d"

输出格式：
是闰年，输出："Yes\n"
不是闰年，输出："No\n"
输入数据不合法，输出："Input error!\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int year;
    scanf("%d",&year);
    if(year<1){
        printf("Input error!\n");
    }else{
        if(( year%4 == 0 && year%100 != 0)|| year%400 == 0){
        printf("Yes\n");
        }else{printf("No\n");}
    }
}

/* 3程序改错v1.0（7分）
题目内容：
下面代码的功能是将百分制成绩转换为5分制成绩，具体功能是：如果用户输入的是非法字符或者不在合理区间内的数据（例如输入的是a,或者102，或-45等），则程序输出 Input error!，否则将其转换为5分制输出。目前程序存在错误，请将其修改正确。并按照下面给出的运行示例检查程序。
*/
//错误程序：
#include <stdio.h> 
#include <stdlib.h> 
int main()
{
    int score;
    char grade;
    printf("Please input  score:");
    scanf("%d", &score);
    if (score < 0 || score > 100)   
        printf("Input error!\n");
    else if (score >= 90) 
        grade = 'A’;
    else if (score >= 80)
        grade = 'B';   
    else if (score >= 70)
        grade = 'C';  
    else if (score >= 60)
        grade = 'D'; 
    else
        grade = 'E'; 
    printf("grade:%c\n", grade);
    return 0;
}

/*
程序运行结果示例1：
Please input score:
-1↙
Input error!
程序运行结果示例2：
Please input score:
95↙
grade: A
程序运行结果示例3：
Please input score:
82↙
grade: B
程序运行结果示例4：
Please input score:
72↙
grade: C
程序运行结果示例5：
Please input score:
66↙
grade: D
程序运行结果示例6：
Please input score:
32↙
grade: E
程序运行结果示例7：
Please input score:
127↙
Input error!
输入提示信息："Please input score:\n"
输入格式: "%d"
输出格式：
用户输入存在错误时，输出提示信息："Input error!\n"
输出格式："grade: %c\n" (注意：%c前面有一个空格) */

//正确程序
#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int score;
    char grade;
    printf("Please input  score:");
    scanf("%d", &score);
    if (score < 0 || score > 100)
        printf("Input error!\n");
    else if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'E';
    if((score >= 0 && score <= 100))
        printf("grade:%c, and the five point grade is %.2f\n", grade,(float)score/20);
}

/* 4字符类型判断（4分）
题目内容：
从键盘键入任意一个字符，判断该字符是英文字母（不区分大、小写）、数字字符还是其它字符。
若键入字母，则屏幕显示 It is an English character.；若键入数字则屏幕显示It is a digit character. ；若输入其它字符，则屏幕显示：It is other character. 

程序的运行示例1：
Input simple:
b↙
It is an English character.
程序的运行示例2：
Input simple:
6↙
It is a digit character.
程序的运行示例3：
Input simple:
*↙
It is other character
程序的运行示例4：
Input simple:
A↙
It is an English character.

输入信息提示："Input simple:\n"
输入格式:  "%c"

输出格式：
英文字符的输出格式："It is an English character.\n"
数字的输出格式："It is a digit character.\n"
其它字符的输出格式："It is other character.\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    char character;
    scanf("%c",&character);
    if((character >= 'A' && character <='Z') || (character >= 'a' && character <='z'))
       {
           printf("It is an English character.");
       }else if(character >= '0' && character <='9')
       {
           printf("It is a digit character.");
       }else{printf("It is other charcter.");}
}

/* 5快递费用计算（7分）
题目内容：
上海市的某快递公司根据投送目的地距离公司的远近，将全国划分成5个区域：
0区:同城	上海
1区:临近两省	江苏，浙江
2区:1500公里（含）以内	北京，天津，河北，辽宁，河南，安微，陕西，湖北，江西，湖南，福建，广东，山西。
3区:1500——2500公里	吉林，辽宁，甘肃，四川，重庆，青海，广西，云南，海南，内蒙古，黑龙江，贵州。
4区:2500公里以上	新疆，西藏。

快递费按邮件重量计算，由起重费用、续重费用两部分构成：
（1）起重（首重）1公斤按起重资费计算（不足1公斤，按1公斤计算），超过首重的重量，按公斤（不足1公斤，按1公斤计算）收取续重费；
（2）同城起重资费10元，续重3元/公斤；
（3）寄往1区（江浙两省）的邮件，起重资费10元，续重4元；
（4）寄往其他地区的邮件，起重资费统一为15元。而续重部分，不同区域价格不同：2区的续重5元/公斤，3区的续重6.5元/公斤，4区的续重10元/公斤。

编写程序，从键盘输入邮件的目的区域编码和重量，计算并输出运费，计算结果保留2位小数。程序中所有浮点数的数据类型均为float。
提示：续重部分不足一公斤，按1公斤计算。因此，如包裹重量2.3公斤：1公斤算起重，剩余的1.3公斤算续重，不足1公斤按1公斤计算，1.3公斤折合续重为2公斤。如果重量应大于0、区域编号不能超出0-4的范围。

程序运行结果示例1：
4,4.5↙
Price: 55.00
程序运行结果示例2：
5,3.2↙
Error in Area
Price:  0.00

输入格式:
用逗号分隔的两个数字，第一个表示区域、第二个是重量："%d,%f"
输出格式：
价格的输出格式："Price: %5.2f\n"
区域错误的提示信息："Error in Area\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    int area;
    float weight,min_price,excess_price;
    scanf("%d,%f",&area,&weight);
    if(area < 0 || area >4 ){
        printf("Error in Area\n");
    }else{
        switch(area)
        {
            case 0:min_price = 10;excess_price = 3;break;
            case 1:min_price = 10;excess_price = 4;break;
            case 2:min_price = 15;excess_price = 5;break;
            case 3:min_price = 15;excess_price = 6.5;break;
            case 4:min_price = 15;excess_price = 10;break;
            default:min_price = 0;excess_price = 0;
        }
    }
    if(weight<=1){
        printf("Price: %5.2f\n",min_price);
    }else{
        printf("Price: %5.2f\n",min_price+(ceil(weight)-1)*excess_price);
    }
}

/* 6数位拆分v2.0（4分）
题目内容：
从键盘上输入一个4位数的整数n，编写程序将其拆分为两个2位数的整数a和b，计算并输出拆分后的两个数的加、减、乘、除和求余运算的结果。例如n=-4321,设拆分后的两个整数为a,b，则a=-43,b=-21。除法运算结果要求精确到小数点后2位,数据类型为float。求余和除法运算需要考虑除数为0的情况，即如果拆分后b=0,则输出提示信息"The second operater is zero!"

程序的运行结果示例1：
Please input n:
1200↙
12,0
sum=12,sub=12,multi=0
The second operator is zero!
程序的运行结果示例2：
Please input n:
-2304↙
-23,-4
sum=-27,sub=-19,multi=92
dev=5.75,mod=-3

输入提示信息："Please input n:\n"
输入格式: "%d"
输出格式：
拆分后的两个整数的输出格式："%d,%d\n"
加法、减法、乘法的输出格式："sum=%d,sub=%d,multi=%d\n"
除法和求余的输出格式："dev=%.2f,mod=%d\n"
除数为0的提示信息："The second operator is zero!\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int n,a,b;
    printf("Please input n: \n");
    scanf("%d",&n);
    a = n/100;
    b = n%100;
    printf("%d,%d\n",a,b);
    printf("sum=%d,sub=%d,multi=%d\n",a+b,a-b,a*b);
    if(b == 0){
        printf("The second operator is zero!");
    }else{
        printf("dev=%.2f,mod=%d",(float)a/(float)b,a%b);
    }
}

/* 7出租车计价（4分）
题目内容：
已知某城市普通出租车收费标准为：起步里程为3公里，起步费为8元，10公里以内超过起步里程的部分，每公里加收2元，超过10公里以上的部分加收50%的回空补贴费，即每公里3元。出租车营运过程中，因堵车和乘客要求临时停车等客的，按每5分钟加收2元计算，不足5分钟的不计费。从键盘任意输入行驶里程（精确到0.1公里）和等待时间（精确到分钟），请编程计算并输出乘客应支付的车费，对结果进行四舍五入，精确到元。

程序运行结果示例1：
Input distance and time:2,2↙
fee = 8
程序运行结果示例2：
Input distance and time:5,5↙
fee = 14
程序运行结果示例3：
Input distance and time:12,15↙
fee = 34
程序运行结果示例4：
Input distance and time:20,0↙
fee = 52

输入提示信息："Input distance and time:"
输入格式:
用逗号分隔的两个数字，第一个表示距离、第二个表示时间："%f,%d"
输出格式："fee = %.0f\n"   （注意：等号的两边各有一个空格） */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    float distance,fee;
    int time;
    printf("Input distance and time:");
    scanf("%f,%d",&distance,&time);
    distance = ceil(distance);
    if(distance >0 && distance <= 3){
        fee = 8 + time/5*2 ;
        printf("fee = %.0f",fee);
    }else if(distance > 3 && distance <=10){
        fee = 8 + (distance-3)*2 + time/5*2;
    }else if(distance > 10){
        fee = 8 + 7*2 + (distance-10)*3 + time/5*2;
    }else{
        fee = 0;
        printf("Input error!");
    }
     printf("fee = %.0f",fee);
}

/* 8数据区间判断（6分）
题目内容：
从键盘输入一个int型的正整数n（已知：0<n<10000），编写程序判断n落在哪个区间。如果用户输入的数据不在指定的范围里，程序输出 "error!"。例如，输入265，则该数属于区间 100-999。

程序运行结果示例1：
Please enter the number:
2563↙
2563: 1000-9999
程序运行结果示例2：
Please enter the number:
156↙
156: 100-999
程序运行结果示例3：
Please enter the number:
36↙
36: 10-99
程序运行结果示例4：
Please enter the number:
3↙
3: 0-9
程序运行结果示例5：
Please enter the number:
10923↙
error!

输入提示信息："Please enter the number:\n"
输入错误提示信息："error!\n"
输入格式: "%d"
输出格式：
输出的区间判断：
"%d: 1000-9999\n"
"%d: 100-999\n"
"%d: 10-99\n"
"%d: 0-9\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int n;
    printf("Please enter the number:\n");
    scanf("%d",&n);
    if(n>0 && n<10000){
        if(n>=0&&n<=9) printf("%d: 0-9\n",n);
        if(n>=10&&n<=99) printf("%d: 10-99\n",n);
        if(n>=100&&n<=999) printf("%d: 100-999\n",n);
        if(n>1000&&n<=9999) printf("%d: 1000-9999\n",n);
    }else{printf("error!");}
}


/* 9计算一元二次方程的根v2.0（4分）
题目内容：
根据求根公式，计算并输出一元二次方程的两个实根，要求精确到小数点后4位。其中a，b，c的值由用户从键盘输入。如果用户输入的系数不满足求实根的要求，输出错误提示 "error!"。程序中所有的数据类型均为float。

程序运行结果示例1：
Please enter the coefficients a,b,c:
1,2,1↙
x1=-1.0000, x2=-1.0000
程序运行结果示例2：
Please enter the coefficients a,b,c:
2,6,1↙
x1=-0.1771, x2=-2.8229
程序运行结果示例3：
Please enter the coefficients a,b,c:
2,1,6↙
error!

输入提示信息："Please enter the coefficients a,b,c:\n"
输入格式: "%f,%f,%f"
输出格式： "x1=%7.4f, x2=%7.4f\n"
如果输入的系数不满足求实根的要求，输出错误提示信息："error!\n" */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <math.h>
int main()
{
    float a,b,c,x1,x2,triangle;
    printf("Please enter the coefficients a,b,c:\n");
    scanf("%f %f %f",&a,&b,&c);
    triangle = b*b - 4*a*c;
    x1 = (0-b+sqrt(triangle))/(2*a);
    x2 = (0-b-sqrt(triangle))/(2*a);
    if(triangle < 0){
        printf("error!\n");
    }else{printf("x1=%7.4f, x2=%7.4f\n",x1,x2);}
}