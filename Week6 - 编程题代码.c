
/* 第6周——函数：分工与合作的艺术 */

/* 1计算阶乘的和v2.0（4分）

假设有这样一个三位数m，其百位、十位和个位数字分别是a、b、c，如果m=a!+b!+c!，则这个三位数就称为三位阶乘和数（约定0!=1）。请编程计算并输出所有的三位阶乘和数。

函数原型： long Fact(int n)；
函数功能：计算n的阶乘

输入格式: 无
输出格式："%d\n" */

#include <stdio.h>
long Fact(int n);

int main()
{
    long m = 100;
    for(m=100;m<1000;m++){
        int a = m/100;      //hundreds
        int b = m/10%10;    //tens
        int c = m%10;       //units
        //printf("a=%d,a!=%d\n",a,Fact(a));
        //printf("b=%d,b!=%d\n",b,Fact(b));
        //printf("c=%d,!=%d\n",c,Fact(c));
        if(m == Fact(a)+Fact(b)+Fact(c)){
            printf("%d\n",m);
        }
    }
}

//Calculating the factorial of n
long Fact(int n){
    long int product = 1;
    if(n==0) {
        product = 1;
    }else{
        for(n;n>0;n--){
            product = product*n;
        }
    }
    return product;
}

/* 2计算最大的三位约数（4分）

从键盘任意输入一个数n（1000<=n<=1000000），编程计算并输出n的所有约数中最大的三位数（即最大的三位约数）。如果n小于1000或者大于1000000，则输出“Input error!”。

函数原型：int Func(int n)；
函数功能：计算n的所有约数中最大的三位数

程序运行结果示例1：
Input n:555555↙
777
程序运行结果示例2：
Input n:1000↙
500
程序运行结果示例3：
Input n:800↙
Input error!

输入提示信息："Input n:"
输入错误提示信息："Input error!\n"
输入格式： "%d"
输出格式： "%d\n" */

#include <stdio.h>
int Func(int n);

int main()
{
    int n;
    scanf("%d",&n);
    if(n<1000 || n>1000000){
        printf("Input error!\n");
    }else{
        printf("%d\n",Func(n));
    }
}

//Calculate the maximun  three-digit number of all the n's divisors
int Func(int n){
    int maximun = 999;
    for(maximun;maximun>99;maximun--){
        if(n%maximun == 0){
            break;
        }
    }
    return maximun;
}

/* 3孔融分梨（4分）

孔融没有兄弟姐妹，到了周末，就找堂兄孔明、堂姐孔茹、堂弟孔伟等7个堂兄妹来到家里玩。孔融妈妈买了8个梨给孩子们吃，结果小黄狗桐桐淘气叼走了一个，大花猫鑫鑫偷偷藏了一个。孔融抢过剩下的6个梨，妈妈止住他，说他要和大家平分吃。孔融不高兴，说8个人怎么分6个梨？妈妈说可以用分数解决这个问题。孔融学过分数，说把每个梨切8个相等的块，每个人拿6块就行了。妈妈说不用切那么多块，每个梨切4个相等的块，每个人拿3块正好。孔融糊涂了。孔明说，我来教你。于是孔明给孔融讲起了分数的化简。

分数化简要化简到最简形式，比如12/20可以化简成6/10和3/5，但3/5是最简形式；100/8可以化简成 50 /4和 25 /2,而25/2为最简形式。
为了降低难度，不要求将假分数（如7/2）化简成带分数（3 ）形式。请编程帮助孔融将任意一个分数化简成最简形式。
先从键盘输入两个整数m和n(1<=m,n<=10000) ，其中m表示分子，n表示分母。然后输出分数化简后的最简形式。

函数原型：int Gcd(int a, int b);
函数功能：计算a和b的最大公约数，输入数据超出有效范围时返回-1。

程序的运行结果示例1：
Input m,n:8,14↙
4/7
程序的运行结果示例2：
Input m,n:-13,31↙
Input error!
程序的运行结果示例3：
Input m,n:7,0↙
Input error!
程序的运行结果示例4：
Input m,n:210,35↙
6/1

输入提示信息： "Input m,n:"
输入错误提示信息： "Input error!\n"
输入格式："%d,%d" 
输出格式："%d/%d\n" */

#include <stdio.h>
int Gcd(int a, int b);

int main()
{
    int m,n,divisor;
    printf("Input m/n:");
    scanf("%d/%d",&m,&n);
    divisor = Gcd(m,n);
    if(divisor == -1){
        printf("Input error!");
    }else{
        printf("%d/%d",m/divisor,n/divisor);
    }
}

/*Calculates the greatest common divisor of A and B,
and returns -1 when the input data exceeds the valid range.*/
int Gcd(int a, int b){
    if(a < 1 || b > 10000)
    {
        return -1;
    }else
    {
        int max_divisor = a;
        if(b<a){
            max_divisor = b;
        }
        for(max_divisor;max_divisor>0;max_divisor--){
            if(b%max_divisor == 0 && a%max_divisor == 0){
                break;
            }
        }
        return max_divisor;
    }
}

/* 4素数求和（4分）

从键盘任意输入一个整数n，编程计算并输出1~n之间的所有素数之和。

函数原型：int IsPrime(int x);
函数功能：判断x是否是素数，若函数返回0，则表示不是素数，若返回1，则代表是素数

程序运行结果示例1：
Input n:8↙
sum=17
程序运行结果示例2：
Input n:10↙
sum=17
程序运行结果示例3：
Input n:-12↙
sum=0

输入提示信息："Input n:"
输入格式："%d"
输出格式："sum=%d\n"   */

#include <stdio.h>
#include <math.h>
int IsPrime(int x);

int main()
{
    int n;
    int sum = 0;
    printf("Input n:");
    scanf("%d",&n);
    for(n;n>1;n--){
        if(IsPrime(n) == 1){
            sum = sum + n;
        }
    }
    printf("sum=%d\n",sum);
}

/*If x is a prime number, the function returns 1, else return 0.*/
int IsPrime(int x){
    int i = sqrt(x);
    int flag = 1;
    if(x == 1) flag = 0;
    for(i;i>1;i--){
        if(x%i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}


 /* 1绘制金字塔（4分）

要求用户从键盘输入一个大写字母，使用嵌套循环产生像下面这样的金字塔图案：

    A
   ABA
  ABCBA
 ABCDCBA

程序运行结果示例1：
Please input a capital:
D↙
____A
___ABA
__ABCBA
_ABCDCBA

程序运行结果示例2：
Please input a capital:
F↙



（说明：上面运行结果示例中，每行字母前面的下划线"_"代表屏幕上实际输出的是空格，最后一行前面有一个空格，倒数第二行有两个空格，以此类推。）

输入提示信息："Please input a capital:\n"
输入格式： "%c"
输出格式："%c" */

#include <stdio.h>

int main()
{
    char input;
    int count,i,j;
    scanf("%c",&input);
    if( input>='A' && input<='Z' ){
        i = input - 'A' + 1; //number of the spaces in the first line
        count = i;           //order of the input character
        for(i;i>0;i--){
            for(j=0;j<i;j++){
                printf(" ");
            }
            for(j=0;j<count-i+1;j++){
                printf("%c",j+'A');
            }
            for(j=count-i;j>0;j--){
                printf("%c",j+'A'-1);
            }
            printf("\n");
        }
    }else{printf("Input error!");}
}

/* 2循环嵌套的应用（4分）

编写程序产生如下输出：
F
FE
FED
FEDC
FEDCB
FEDCBA

输入格式: 无
输出格式："%c" */

#include <stdio.h>

int main()
{
    char input;
    int count;
    int i,j;
    scanf("%c",&input);
    if( input>='A' && input<='Z' ){
        count = input - 'A' + 1;
        for(i=1;i<=count;i++){
            for(j=0;j<i;j++){
                printf("%c",input-j);
            }
            printf("\n");
        }
    }else{printf("Input error!");}

/* 3利用泰勒级数计算sinx的值（4分）

利用泰勒级数计算sinx的值，要求最后一项的绝对值小于10^-5,并统计出此时累加了多少项。请用“利用前项来计算后项”的方法计算累加项，不要使用pow函数编写程序。程序中所有实数的数据类型都是double类型。
sinx的泰勒级数第n项:a(n)：
令n=2m，a(n)=(-1)^(m-1)*x^(2m-1)/(2m-1)!

程序的运行结果示例1：
Input x:
3↙
sin(x)=0.141,count=9
程序的运行结果示例2：
Input x:
10↙
sin(x)=-0.544,count=18

输入提示信息："Input x:\n"
输入格式: "%lf"
输出格式："sin(x)=%.3f,count=%d\n" */

//观察，递推公式：后项分子=(-1)*前项分子*x*x；后项分母=后项分母!*((2m-1))*(2m-2))

#include <stdio.h>
double caculate_An(int count,double x);
int main()
{
    double x;
    double sin_x = 0;
    double a_n,abs_an;
    int count=0;
    printf("Input x:\n");
    scanf("%lf",&x);
    do{
        count++;
        a_n = caculate_An(count,x);
        sin_x = sin_x + a_n;
        printf("count=%d,an=%lf\n",count,a_n);
        if(a_n<0){
            abs_an = -a_n;
        }else{abs_an = a_n;}
    }while(abs_an >= 0.00001);
    printf("sin(x)=%lf,count=%d\n",sin_x,count);
}

double caculate_An(int count,double x){
    double a_n;
    if( count == 1 ){
        a_n = x;
    }else{
        a_n = (-1)*x*x*caculate_An(count-1,x)/((2*count-1)*(2*count-2));
    }
    return a_n;
}


/* 4计算100~200之间的所有素数之和（4分）

计算100~200之间的所有素数之和，判别一个数是否是素数请用给定的函数实现。

函数原型：int fun(int m);
说明：
  参  数：m 是要进行判断的数；
  返回值：若数 m 是素数，则返回值为1；否则返回值为0。

输入格式: 无
输出格式： "sum=%d\n" */

//略。同前面第四题

/* 5编程实现一个输入指定范围内的整数的函数（4分）

编程实现一个输入指定范围内的整数的函数getint，其完整的函数原型为：int getint(int min, int max);
它负责接收用户的输入进行验证，保证接收的一定是一个介于min和max之间（[min, max]区间内）的一个整数并最后返回该整数。
如果用户输入不合法，则会提示继续输入，直到输入合法时为止。要求编写完整的程序并测试你所写的getint函数。

程序的运行结果示例：
Please enter min,max:
3,100↙
Please enter an integer [3..100]:
-2↙
Please enter an integer [3..100]:
0↙
Please enter an integer [3..100]:
116↙
Please enter an integer [3..100]:
58↙
The integer you have entered is:58

输入提示信息："Please enter min,max:\n"
              "Please enter an integer [%d..%d]:\n"
输入格式:
输入数据区间的最小值和最大值："%d,%d"
输入指定范围内的整数： "%d"
输出格式："The integer you have entered is:%d\n" */

#include <stdio.h>
int getint(int min, int max);

int main()
{
    int min,max;
    printf("Please enter min,max:\n");
    scanf("%d %d",&min,&max);
    while(min > max){
        printf("Input error,max should bigger than min.Enter again:\n");
        while(getchar() != '\n'){};
        scanf("%d %d",&min,&max);
    }
    getint(min,max);
}

int getint(int min, int max){
    int valid_num;
    printf("Please enter an integer [%d..%d]:\n",min,max);
    while(getchar() != '\n'){};
    scanf("%d",&valid_num);
    if(valid_num>=min && valid_num<=max){
        printf("The integer you have entered is:%d",valid_num);
    }else{
        getint(min,max);
    }
    return valid_num;
}


/* 6程序改错v2.0（5分）

下面代码的功能是将百分制成绩转换为5分制成绩，具体功能是：如果用户输入的是非法字符或者不在合理区间内的数据（例如输入的是a,或者102，或-45等），则程序输出 Input error!，并允许用户重新输入,直到输入合法数据为止，并将其转换为5分制输出。目前程序存在错误，请将其修改正确。并按照下面给出的运行示例检查程序。 */

#include<stdio.h>
int main()
{
	int score;
	char grade;
	printf("Please input score:");
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

/* 程序运行结果示例1：
Please input score:
a↙
Input error!
Please input score:
-12↙
Input error!
Please input score:
230↙
Input error!
Please input score:
92↙
grade: A
程序运行结果示例2：
Please input score:
88↙
grade: B
程序运行结果示例3：
Please input score:
73↙
grade: C
程序运行结果示例4：
Please input score:
65↙
grade: D
程序运行结果示例5：
Please input score:
27↙
grade: E

输入提示信息："Please input score:\n"
输入格式: "%d"
输出格式：
输入错误时的提示信息："Input error!\n"
输出格式："grade: %c\n" (注意：%c前面有一个空格) */

#include <stdio.h>
int checkNum(int score);

int main()
{
    int score;
	char grade;
	printf("Please input score:");
	scanf("%d", &score);
	while(checkNum(score) == 0){
        printf("Input error!\n");
        printf("Please input score:");
        while(getchar()!='\n'){}
        scanf("%d", &score);
        checkNum(score);
	}
	if (score >= 90)
		 grade = 'A';
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

int checkNum(int score){
	if (score < 0 || score > 100){
        return 0;
    }else{
        return 1;
    }
}


/* 7编程计算a+aa+aaa+…+aa…a（n个a）的值（4分）

编程计算 a+aa+aaa+…+aa…a（n个a）的值，n和a的值由键盘输入。例如，当n=4,a=2,表示计算2+22+222+2222的值。

程序运行结果示例：
Input a,n:
2,4↙
sum=2468

输入提示信息："Input a,n:\n"
输入格式:   "%d,%d"（先输入a，后输入n）
输出格式：  "sum=%ld\n" */

#include <stdio.h>
int caculate_An(int n,int a);

int main()
{
    int a;
    int n = 0;
    int sum = 0;
    int i;
    while(n<=0){
        printf("Input a,n:\n");
        scanf("%d %d",&a,&n);
        while(getchar()!='\n'){}
    }
    for(i=1;i<=n;i++){
        sum = sum+caculate_An(i,a);
    }
    printf("sum=%d",sum);
}

int caculate_An(int n,int a){
    int a_n;
    if(n == 1){
        a_n = a;
    }else{
        a_n = caculate_An(n-1,a)*10+a;
    }
    return a_n;
}


/* 8搬砖问题（4分）

n块砖( 27<n<=77 )，36人搬，男搬4，女搬3，两个小孩抬一块砖，要求一次搬完，问男人、女人和小孩各需多少人？
请用穷举法编程求解,n的值要求从键盘输入。输出结果按照男人数量升序给出（见下面示例3）。

程序的运行结果示例1：
Input n(27<n<=77):
28↙
men=0,women=4,children=32
程序的运行结果示例2：
Input n(27<n<=77):
36↙
men=3,women=3,children=30
程序的运行结果示例3：
Input n(27<n<=77):
60↙
men=2,women=14,children=20
men=7,women=7,children=22
men=12,women=0,children=24

输入提示： "Input n(27<n<=77):\n"
输入格式: "%d"  
输出格式："men=%d,women=%d,children=%d\n" */

#include <stdio.h>

int main()
{
    int man,woman,child;
    int n = 0;
    int i,j;
    while(n<=27||n>77){
        printf("Input n:\n");
        scanf("%d",&n);
        while(getchar()!='\n'){}
    }
    man = n/4;
    for(i=0;i<=man;i++){
        woman = (n-i*4)/3;
        for(j=0;j<=woman;j++){
            child = (n - i*4 - j*3)*2;
            if(child+i+j == 36){
                printf("men=%d,women=%d,children=%d\n",i,j,child);
            }
        }
    }
}


/* 9编程输出某年某月有多少天（考虑到闰年）（5分）

从键盘输入一个年份和月份，输出该月有多少天（考虑闰年），用switch语句编程。

程序运行结果示例1：
Input year,month:
2015,3↙
31 days
程序运行结果示例2：
Input year,month:
2015,4↙
30 days
程序运行结果示例3：
Input year,month:
2016,2↙
29 days
程序运行结果示例4：
Input year,month:
2014,2↙
28 days
程序运行结果示例5：
Input year,month:
2015,13↙
Input error!

输入提示信息："Input year,month:\n"
输入格式:  "%d,%d"
输出格式：
输入错误时的提示信息："Input error!\n"
输出格式：
          "31 days\n"
          "30 days\n"
          "29 days\n"
          "28 days\n" */
		  
#include <stdio.h>

int main()
{
    int year = 0,month = 0;
    int days = 1;
    printf("Input year,month:\n");
    scanf("%d %d",&year,&month);
    while(year<=0 || month <=0 || month>12){
        printf("Input error!\n");
        printf("Input year,month:\n");
        scanf("%d %d");
        while(getchar()!='\n'){}
    }
    switch(month){
    case 1:days = 31;break;
    case 2:days = 28;break;
    case 3:days = 31;break;
    case 4:days = 30;break;
    case 5:days = 31;break;
    case 6:days = 30;break;
    case 7:days = 31;break;
    case 8:days = 31;break;
    case 9:days = 30;break;
    case 10:days = 31;break;
    case 11:days = 30;break;
    case 12:days = 31;break;
    default:days = 0;
    }
    if(((year%4==0 && year%100!=0)||year%400==0) && month==2){
        days+=1;
    }
    printf("%d days\n",days);
}
		  