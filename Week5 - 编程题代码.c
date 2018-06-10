
/** 第5周——周而复始的循环之道 */

/* 猜数游戏 */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
#include <time.h>
int main()
{
    int magic,counter,guess;
    char reply;
    do{
        srand(time(NULL));
        counter = 0;
        magic = rand()%100+1;
        //printf("magic = %d\n",magic);
        do{
            printf("Please input a magic number: ");
            int ret;
            ret = scanf("%d",&guess);
            while(ret!=1){
                while (getchar()!='\n'); //读取缓冲区中的值，读到回车符后往下
                printf("Please input a magic number: ");
                ret = scanf("%d",&guess);
            }
            counter++;
            if(guess > magic){
                printf("Wrong!Too big.\n");
            }else if(guess < magic){
                printf("Wrong!Too small.\n");
            }else{
                printf("Right!\n");
            }
        }while(guess != magic && counter < 10);
        printf("counter = %d\n",counter);
        printf("Do you want to continue?(Y or N,y or n? )");
        scanf(" %c",&reply);
    }while(reply == 'Y' || reply == 'y');
}

/* 输出九九乘法表 */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int m,n;
    for(m = 1;m < 10;m++){
        for(n = 1;n <= m;n++){
            printf("%d*%d=%-5d",m,n,m*n);
        }
        printf("\n");
    }
}

/* 韩信点兵 */

#include <stdio.h> //标准输入输出文件
int main()
{
    int x = 1;
    int find = 0;
    while( !find ){
        if(x%5 == 1 && x%6 ==5 && x%7 == 4 && x%11 == 10){
            printf("x = %d\n",x);
            find = 1;
        }else{x++;}
    }
    return 0;
}

/* 1马克思手稿中的趣味数学题（4分）

编程求解马克思手稿中的趣味数学题：有30个人，其中有男人、女人和小孩，在一家饭馆里吃饭共花了50先令，每个男人各花3先令，每个女人各花2先令，每个小孩各花1先令，请编程计算男人、女人和小孩各有几人？

输出提示信息: "Man   Women   Children\n" （注意：每个单词之间有3个空格）
输出格式："%3d%8d%8d\n" （注意：输出数据按照男人的数量递增的顺序给出） */

#include <stdio.h> //标准输入输出文件
int main()
{
    int man,women,children;
    printf("Man   Women   Children\n");
    for(man = 1;man < 30;man++){
        for(women = 1;women < 30;women++){
            children = 30-women-man;
            if(man*3+women*2+children == 50){
                printf("%3d%8d%8d\n",man,women,children);
            }
        }
    }
}

/* 2猜神童年龄（4分）

美国数学家维纳（N.Wiener）智力早熟，11岁就上了大学。他曾在1935~1936年应邀来中国清华大学讲学。一次，他参加某个重要会议，年轻的脸孔引人注目。于是有人询问他的年龄，他回答说：“我年龄的立方是一个4位数。我年龄的4次方是一个6位数。这10个数字正好包含了从0到9这10个数字，每个都恰好出现1次。”请你编程算出他当时到底有多年轻。

【解题思路】：因为已知年龄的立方是一个4位数字，所以可以推断年龄的范围在10到22之间，因此确定穷举范围为10到22。如果年龄还满足“年龄的4次方是一个6位数”这个条件，则先计算年龄的立方值的每一位数字，从低位到高位分别保存到变量b1,b2,b3,b4中，再计算年龄的4次方值的每一位数字，从低位到高位分别保存到变量a1,a2,a3,a4,a5,a6中。如果上述10个数字互不相同，则必定是包含了从0到9这10个数字并且每个都恰好出现1次，因此只要判断上述10个数字互不相同，即可确定这个年龄值为所求。

输出格式："age=%d\n" */

#include <stdio.h> //标准输入输出文件
int main()
{
    int age;
    int age_3,age_4;
    int b1,b2,b3,b4;
    int a1,a2,a3,a4,a5,a6;
    for(age=11;age<22;age++){
        age_3 = age*age*age;
        b1 = age_3%10;
        b2 = age_3%100/10;
        b3 = age_3%1000/100;
        b4 = age_3/1000;
        age_4 = age_3*age;
        a1 = age_4%10;
        a2 = age_4%100/10;
        a3 = age_4%1000/100;
        a4 = age_4%10000/1000;
        a5 = age_4%100000/10000;
        a6 = age_4/100000;
        if(a1+a2+a3+a4+a5+a6+b1+b2+b3+b4 == 45){
            if(a1 != a2 && a1 != a3 && a1 != a4 && a1 != a5 && a1 != a6 && a1 != b1 && a1 != b2 && a1 != b3 && a1 != b4 ){
                printf("age=%d\n",age);
                /*printf("%d",a1);
                printf("%d",a2);
                printf("%d",a3);
                printf("%d",a4);
                printf("%d",a5);
                printf("%d",a6);
                printf("%d",b1);
                printf("%d",b2);
                printf("%d",b3);
                printf("%d",b4);*/
           }
        }
    }
}

/* 3闰年相关的问题v3.0——计算有多少闰年（4分）

从键盘输入你的出生年和今年的年份，编程判断并输出从你的出生年到今年之间中有多少个闰年。

程序的运行结果示例1： 
Input your birth year:2000↙
Input this year:2020↙
2000
2004
2008
2012
2016
2020
count=6

输入提示信息："Input your birth year:"
输入提示信息："Input this year:"
输入格式："%d"
输出格式：
闰年年份： "%d\n"
闰年总数："count=%d\n" */

#include <stdio.h> //标准输入输出文件
int main()
{
    int this_year,birth_year,count,i;
    count = 0;
    printf("Input your birth year:");
    scanf("%d",&birth_year);
    printf("Input this year:");
    scanf("%d",&this_year);
    for(i=birth_year;i<=this_year;i++){
        if((i%4==0 && i%100!=0)||(i%400==0)){
            printf("%d\n",i);
            count++;
        }
    }
    printf("count=%d\n",count);
}

/* 4闰年相关的问题v4.0——计算心跳数（4分）

假设人的心率为每分钟跳75下，编程从键盘输入你的出生年和今年的年份，然后以年为单位计算并输出从你出生开始到目前为止的生命中已有的心跳总数（要求考虑闰年）。

程序运行结果示例1：
Input your birth year:1986↙
Input this year:2016↙
The heart beats in your life: 1183356000

输入提示信息："Input your birth year:"
输入提示信息："Input this year:"
输入格式:"%d"
输出格式："The heart beats in your life: %lu" */

#include <stdio.h> //标准输入输出文件
int main()
{
    int this_year,birth_year,count,i;
    unsigned int heart_beat;
    //int days;
    count = 0;
    printf("Input your birth year:");
    scanf("%d",&birth_year);
    printf("Input this year:");
    scanf("%d",&this_year);
    for(i=birth_year;i<=this_year;i++){
        if((i%4==0 && i%100!=0)||(i%400==0)){
            //printf("%d\n",i);
            count++;
        }
    }
    //days = (this_year-birth_year+1)*365+count;
    heart_beat = ((this_year-birth_year+1)*365+count)*24*60*75;
    //printf("days = %d\n",days);
    printf("The heart beats in your life:%lu\n",heart_beat);
}

/* 1判断一个整型数据有几位v2.0（4分）

从键盘输入一个整型数据(int型)，编写程序判断该整数共有几位，并输出包含各个数字的个数。例如，从键盘输入整数16644,该整数共有5位，其中有1个1,2个6,2个4。

程序运行结果示例1：
Please enter the number:
12226↙
12226: 5 bits
1: 1
2: 3
6: 1
程序运行结果示例2：
Please enter the number:
-12243↙
-12243: 5 bits
1: 1
2: 2
3: 1
4: 1

输入格式: "%d"
输出格式：
输入提示信息："Please enter the number:\n"
判断该整数共有几位："%d: %d bits\n"
包含数字0的个数："0: %d\n"
包含数字1的个数："1: %d\n"
包含数字2的个数："2: %d\n"
包含数字3的个数："3: %d\n"
包含数字4的个数："4: %d\n"
包含数字5的个数："5: %d\n"
包含数字6的个数："6: %d\n"
包含数字7的个数："7: %d\n"
包含数字8的个数："8: %d\n"
包含数字9的个数："9: %d\n" */

//尝试过使用pow(10,count)函数，函数返回值为double类型，需要强制类型转换为int，且有时候存在精度问题，返回的数是99、9999，故没有使用。

#include <stdio.h> //标准输入输出文件
int main()
{
    int x,x_init,count,x_bit;
    int a0=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0;
    count = 0;
    printf("Please enter the number:\n");
    scanf("%d",&x);
    x_init = x;
    do{
        x = x/10;
        count++;
    }while(x != 0);
    printf("%d: %d bits\n",x,count);
    for(count;count>0;count--){
        //printf("count = %d  ",count);
        int ten = 1,count_ten;
        count_ten = count-1;
        for(count_ten;count_ten>0;count_ten--){
            ten = 10*ten;
        }
        x_bit = x_init / ten % 10;
        //printf("?? = %d\n",ten);
        printf("x_Bit = %d\n",x_bit);
        switch(x_bit)
        {
            case 0:a0++;break;
            case 1:a1++;break;
            case 2:a2++;break;
            case 3:a3++;break;
            case 4:a4++;break;
            case 5:a5++;break;
            case 6:a6++;break;
            case 7:a7++;break;
            case 8:a8++;break;
            case 9:a9++;break;
            default:a0++;
        }
    }
    printf("0: %d\n",a0);
    printf("1: %d\n",a1);
    printf("2: %d\n",a2);
    printf("3: %d\n",a3);
    printf("4: %d\n",a4);
    printf("5: %d\n",a5);
    printf("6: %d\n",a6);
    printf("7: %d\n",a7);
    printf("8: %d\n",a8);
    printf("9: %d\n",a9);
}

/* 2奖金计算（6分）

企业发放的奖金根据利润提成。利润低于或等于10万元时，奖金可提10%；利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；20万到40万之间时，高于20万元的部分，可提成5%；40万到60万之间时，高于40万元的部分，可提成3%；60万到100万之间时，高于60万元的部分，可提成1.5%，高于100万元时，超过100万元的部分按1%提成，从键盘输入当月利润i，求应发放奖金总数？

程序运行结果示例1：
789↙
bonus=78
程序运行结果示例2：
789516↙
bonus=36342

输入格式: "%ld"
输出格式："bonus=%ld\n" */

#include <stdio.h> //标准输入输出文件
int main()
{
    long int i,bonus;
    scanf("%ld",&i);
    if(i <= 100000){
        bonus = i*0.1;
    }else if(i <= 200000){
        bonus = 100000*0.1 + (i-100000)*0.075;
    }else if(i <= 400000){
        bonus = 100000*0.1 + 100000*0.075 + (i-200000)*0.05;
    }else if(i <= 600000){
        bonus = 100000*0.1 + 100000*0.075 + 200000*0.05 + (i-400000)*0.03;
    }else if(i <= 1000000){
        bonus = 100000*0.1 + 100000*0.075 + 200000*0.05 + 200000*0.03 + (i-600000)*0.015;
    }else{bonus = 100000*0.1 + 100000*0.075 + 200000*0.05 + 200000*0.03 + 400000*0.015 + (i-1000000)*0.001;}
    printf("bonus=%ld\n",bonus);
}

/* 3程序修改—1（4分）
修改下面这个程序使其快速计算1+2+3……+n的值，n从键盘输入。并按照下面给出的运行示例检查程序。*/

#include  <stdio.h>
  int main()
  { 
    int i, j, sum = 0, n=100; 
    for (i=1,j=n; i<=j; i++,j--) 
    {
        sum = sum + i + j;
    }
    printf("sum = %d", sum);
    return 0;
  }

/* 程序运行结果示例1：
5↙
sum = 15
程序运行结果示例2：
6↙
sum = 21
输入格式: "%d"
输出格式： "sum = %d"  （注意：等号两侧各有一个空格） */

#include  <stdio.h>
  int main()
  {
    int n;
    scanf("%d",&n);
    int i, j, sum = 0;
    for (i=1,j=n; i<=j; i++,j--)
    {
        sum = sum + i + j;
        if(i==j){
            sum = sum -i;
        }
    }
    printf("sum = %d", sum);
    return 0;
  }

/* 4程序修改—2（4分）
修改下面这个用do-while语句实现的程序，改用while语句实现，并对比其优缺点。*/

#include  <stdio.h>
  int main()
  { 
      int sum = 0, m;
      do{
          printf("Input m:\n");
          scanf("%d", &m);
          sum = sum + m;
          printf("sum = %d\n", sum);
      }while (m != 0);
      return 0;
  }

/* 程序运行结果示例：
Input m:
1↙
sum = 1
Input m:
2↙
sum = 3
Input m:
3↙
sum = 6
Input m:
4↙
sum = 10
Input m:
0↙

输入格式:"%d"
输出格式：
输入提示： "Input m:\n"
输出累加和： "sum = %d\n"（注意：等号两侧各有一个空格） */

//区别；直到型循环和当型循环

#include  <stdio.h>
int main()
{
    int sum = 0, m = 1;
    while(m != 0){
        printf("Input m:\n");
        scanf("%d", &m);
        sum = sum + m;
        printf("sum = %d\n", sum);
    }
    return 0;
}

/* 5程序改错-1（4分）

我国古代的《张丘建算经》中有这样一道著名的百鸡问题：“鸡翁一，值钱五；鸡母一，值钱三；鸡雏三，值钱一。百钱买百鸡，问鸡翁、母、雏各几何？”其意为：公鸡每只5元，母鸡每只3元，小鸡3只1元。用100元买100只鸡，问公鸡、母鸡和小鸡各能买多少只？目前程序运行结果有误，请问为什么会比正确答案多出三个解？不仅要找出错误和修正错误，还要求利用以前学过的知识分析错误的原因。 */

#include <stdio.h>
int main()
{
  int x, y, z;
  for (x=0; x<=20; x++)
  {
	  for (y=0; y<=33; y++)
	  {
		  z = 100 - x - y;
		  if (5*x + 3*y + z/3 == 100)
		  {
			  printf("x=%d, y=%d, z=%d\n", x, y, z);
		  }
	  }
  }
  return 0;
}

/* 程序目前的运行结果：
x=0, y=25, z=75
x=3, y=20, z=77
x=4, y=18, z=78
x=7, y=13, z=80
x=8, y=11, z=81
x=11, y=6, z=83
x=12, y=4, z=84

程序正确的运行结果：
x=0, y=25, z=75
x=4, y=18, z=78
x=8, y=11, z=81
x=12, y=4, z=84

输入格式: 无
输出格式：
"x=%d, y=%d, z=%d\n */

//错误原因：z/3时，舍弃了余数。
#include <stdio.h>
int main()
{
    int x, y, z;
    for (x=0; x<=20; x++)
    {
      for (y=0; y<=33; y++)
      {
          z = 100 - x - y;
          if (z%3 == 0 && 5*x + 3*y + z/3 == 100)
          {
              printf("x=%d, y=%d, z=%d\n", x, y, z);
          }
      }
    }
    return 0;
}

/* 6程序改错-2（5分）

从键盘任意输入一个正整数，编程判断它是否是素数，若是素数，输出“Yes!”，否则输出“No！”。已知负数、0和1都不是素数。请找出下面程序的错误并改正之，同时按照给出的运行示例检查修改后的程序。 */

#include <stdio.h>
#include <math.h>
int main()
{
    int n, i;
    printf("Input n:\n");
    scanf("%d", &n);
    for (i=2; i<=sqrt(n); i++)
    {
        if (n % i = 0)
    {
        printf("No!\n");
    }
    }
    printf("Yes!\n");
    return 0;
}

/* 程序的运行结果示例1：
Input n:
-3↙
No!
程序的运行结果示例2：
Input n:
0↙
No!
程序的运行结果示例3：
Input n:
1↙
No!
程序的运行结果示例4：
Input n:
6↙
No!
程序的运行结果示例5：
Input n:
7↙
Yes!

输入格式: "%d"
输出格式：
输入提示信息： "Input n:\n"
是素数： "Yes!\n"
不是素数： "No!\n" */

#include <stdio.h>
#include <math.h>
int main()
{
    int n, i;
    printf("Input n:\n");
    scanf("%d", &n);
    if( n==0 || n ==1 || n<0){
        printf("No!\n");
    }else{
        for (i=2; i<=sqrt(n); i++)
        {
            if (n % i == 0)
            {
                printf("No!\n");
                break;
            }else{
                printf("Yes!\n");
                break;
            }
        }
    }
    return 0;
}

/* 7程序改错-3（4分）

从键盘任意输入两个符号各异的整数，直到输入的两个整数满足要求为止，然后打印这两个数。请通过测试找出下面这个程序存在的问题（不止一个问题哦），并改正。同时用下面给出的运行结果示例检查修改后的程序。*/

#include <stdio.h>
  int main()
  {
    int x1, x2;
    do{
      printf("Input x1, x2:");
      scanf("%d,%d", &x1, &x2);
    }while (x1 * x2 > 0);
    printf("x1=%d,x2=%d\n", x1, x2);
    return 0;
  }

/* 程序正确的运行结果示例：
Input x1, x2:
a,s↙
Input x1, x2:
a,1↙
Input x1, x2:
2,s↙
Input x1, x2:
1,2↙
Input x1, x2:
-1,-2↙
Input x1, x2:
0,3↙
Input x1, x2:
1.2,3.4↙
Input x1, x2:
1.2,5↙
Input x1, x2:
-1,3↙
x1=-1,x2=3

输入格式: "%d,%d"
输出格式：
输入提示信息："Input x1, x2:\n"
输出： "x1=%d,x2=%d\n" */

#include <stdio.h>
#include <math.h>
int main()
{
    int x1, x2;
    do{
        printf("Input x1, x2:");
        int ret;
        ret = scanf("%d,%d",&x1,&x2);
        while(ret!=2){
            while(getchar()!='\n');
            printf("Input x1, x2:");
            ret = scanf("%d,%d",&x1,&x2);
        }
    }while (x1 * x2 >= 0);
    printf("x1=%d,x2=%d\n",x1,x2);
    return 0;
}

/* 8 9 猴子吃桃程序的扩展
（1）为了加强交互性，由用户输入不同的天数n进行递推，即假设第n天的桃子数为1，问第1天的桃子数是多少，其中n由用户从键盘输入。此时，猴子吃桃的程序该如何修改？

（2）如果要增加对用户输入数据的合法性验证（即不允许输入的天数是0和负数），那么猴子吃桃的程序又该如何修改呢？ */

#include <stdio.h> //标准输入输出文件
#include <stdlib.h> //标准库文件
int main()
{
    int i,n,sum = 1;
    do{
        printf("please input n: ");
        scanf("%d",&n);
        }while(n<=0);
    for(i = 1;i < n;i++){
        sum = (sum + 1)*2;
    }
    printf("the number of peaches: %d",sum);
}

/* 10 6位密码输入检测（4分）

从键盘输入6位仅由数字0~9组成的密码。用户每输入一个密码并按回车键后，程序给出判断：如果是数字，则原样输出该数字，并提示用户目前已经输入了几位密码，同时继续输入下一位密码；否则，程序提示"error"，并让用户继续输入下一位密码。直到用户输入的密码全部是数字为止。

程序的运行结果示例：
Input your password:
1↙
1, you have enter 1-bits number
6↙
6, you have enter 2-bits number
a↙
error
d↙
error
4↙
4, you have enter 3-bits number
6↙
6, you have enter 4-bits number
8↙
8, you have enter 5-bits number
2↙
2, you have enter 6-bits number

输入提示信息："Input your password:\n"
输入格式: "%c"
输出格式：
如果输入的是数字，输出格式为："%c, you have enter %d-bits number\n"
如果输入的不是数字，输出提示信息："error\n" */

#include <stdio.h>
#include <math.h>
int main()
{
    char a;
    int counter;
    printf("Input your password:\n");
    for(counter=0;counter<6; ){
        int ret = scanf("%c",&a);
        while( ret!= 1){
            while(getchar()!='\n');
            ret = scanf("%c",&a);
        }
        if(a>='0' && a<='9'){
            counter++;
            printf("%c, you have enter %d-bits number\n",a,counter);
            while(getchar()!='\n');
        }else{
            printf("error\n");
            while(getchar()!='\n');
        }
    }
}

/* 11判断一个整型数据有几位v1.0（4分）

从键盘输入一个整型数据(int型)，编写程序判断该整数共有几位。例如，从键盘输入整数16644,该整数共有5位。

程序运行结果示例1：
Please enter the number:
21125↙
21125: 5 bits
程序运行结果示例2：
Please enter the number:
-12234↙
-12234: 5 bits

输入提示信息："Please enter the number:\n"
输入格式: "%d"
输出格式："%d: %d bits\n" */

#include <stdio.h>
int main()
{
    int a,a_init,counter;
    printf("Please enter the number:\n");
    scanf("%d",&a);
    a_init = a;
    counter = 0;
    do{
        a = a/10;
        counter++;
    }while(a!=0);
    printf("%d: %d bits\n",a_init,counter);
}

/* 12检测输入数据中奇数和偶数的个数（4分）

从键盘输入一系列正整数，输入-1表示输入结束（-1本身不是输入的数据）。编写程序判断输入数据中奇数和偶数的个数。如果用户输入的第一个数据就是-1，则程序输出"over!"。否则。用户每输入一个数据，输出该数据是奇数还是偶数，直到用户输入-1为止，分别统计用户输入数据中奇数和偶数的个数。

程序运行结果示例1：
Please enter the number:
1↙
1:odd
5↙
5:odd
8↙
8:even
9↙
9:odd
12↙
12:even
17↙
17:odd
-1↙
The total number of odd is 4
The total number of even is 2
程序运行结果示例2：
Please enter the number:
-1↙
over!
The total number of odd is 0
The total number of even is 0

输入提示信息："Please enter the number:\n"
输入格式: "%d"
输出格式：
用户输入的第一个数据就是-1，输出格式："over!\n"
奇数的输出格式："%d:odd\n"
偶数的输出格式："%d:even\n"
输入数据中奇数的个数统计："The total number of odd is %d\n"
输入数据中偶数的个数统计："The total number of even is %d\n" */

#include <stdio.h>
int main()
{
    int num,counter_even = 0,counter_odd = 0;
    printf("Please enter the number:\n");
    scanf("%d",&num);
    while(num != -1 && num >=0){
        if(num%2 == 0){
                printf("%d:even\n",num);
                counter_even++;
        }else{
            printf("%d:odd\n",num);
            counter_odd++;
        }
        while(getchar()!='\n');
        scanf("%d",&num);
    }
    printf("over!\n");
    printf("The total number of odd is %d\n",counter_odd);
    printf("The total number of even is %d\n",counter_even);
}

/* 13计算球的反弹高度（4分）

一个球从100米高度自由落下，每次落地后反跳回原高度的一半，再落下并反弹......，求它在第5次和第10次落地时，分别共经过了多少米？第5次和第10次反弹分别是多高？要求计算结果保留到小数点后3位。用户从键盘输入想要计算的第n次（n<=15）。程序中所有浮点数的数据类型均为float。

程序运行结果示例1：
Input:
5↙
5 times:
287.500
3.125
程序运行结果示例2：
Input:
10↙
10 times:
299.609
0.098

输入提示信息："Input:\n"
输入格式: "%d"
输出格式：
反弹次数："%d times:\n"
第n次反弹共经过多少米："%.3f\n"
第n次的反弹高度："%.3f\n" */

#include <stdio.h>
int main()
{
    int n,counter;
    float height = 100,meters = -100;
    printf("Input:\n");
    scanf("%d",&n);
    printf("%d times:\n",n);
    if(n > 15){while(getchar()!='\n');scanf("%d",&n);}
    for(n;n>0;n--){
        meters = height*2 + meters;
        height /= 2;
    }
    printf("%.3f\n",meters);
    printf("%.3f\n",height);
}
