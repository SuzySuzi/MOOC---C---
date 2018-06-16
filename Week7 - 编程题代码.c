
/* 第7周——《盗梦空间》的逻辑：探寻递归的奥秘 */

/* 课堂例题 */

/*递归求解汉诺塔问题*/

#include <stdio.h>
void Move(int n,char a,char b);
void Hanoi(int n,char a,char b,char c);
int count = 0;

int main()
{
    int n;
    printf("Input the number of disks:");
    scanf("%d",&n);
    printf("Step of moving %d disks from A to B by means of C:\n",n);
    Hanoi(n,'A','B','C');
    printf("The number of movements of the plate:%d",count);
    return 0;
}

void Hanoi(int n,char a,char b,char c){
    if(n == 1){
        Move(n,a,b);
    }else{
        Hanoi(n-1,a,c,b);
        Move(n,a,b);
        Hanoi(n-1,c,b,a);
    }
}

void Move(int n,char a,char b){
    printf("Move %d:from %c to %c\n",n,a,b);
    count++;
}

/*能否不用递归的方法计算汉诺塔问题？*/

//循环实现；从F(0)往上算到需要的F(n)

#include <stdio.h>

int main()
{
    int n;
    int front = 1;
    int latter = 1;
    int intermediate_var = 1;
    printf("Input n(the nth number of sequence):");
    scanf("%d",&n);
    if(n > 2){
        for(int i=3;i<=n;i++){
            intermediate_var = latter;
            latter = front + latter;
            front = intermediate_var;
        }
    }
    printf("%d",latter);
}

/*计算斐波那契数列第n项*/

#include <stdio.h>
long Fib(int n);

int main()
{
    int n;
    scanf("%d",&n);
    printf("the %dth number is:%ld",n,Fib(n));
}

long Fib(int n){
    long f;
    if(n == 1 || n==2){
        f = 1;
    }else{
        f = Fib(n-1)+Fib(n-2);
    }
    return f;
}

/*编程计算斐波那契数列前n项平方和*/

#include <stdio.h>
long Fib(int n);

int main()
{
    int n;
    long int sum = 0;
    printf("Input how many number should be counted:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        long int a_n = Fib(i);
        printf("the %dth number is:%ld\n",i,a_n);
        sum = sum + a_n*a_n;
        printf("Sum of square of the first %d terms of sequence:%ld\n",i,sum);
    }
}

long Fib(int n){
    long f;
    if(n == 1 || n==2){
        f = 1;
    }else{
        f = Fib(n-1)+Fib(n-2);
    }
    return f;
}

/*从程序的运行结果中，你发现了Fibonacci数列具有的一个什么性质？你能不用编程的方法直接得到这个答案吗*/

//数列前n项的平方和=第n项*第(n+1)项


/*计算n的阶乘，尾递归*/

#include <stdio.h>
unsigned long Fact(unsigned int n,unsigned int a);

int main()
{
    int m;
    printf("Input m:");
    scanf("%d",&m);
    printf("%d! =%ld\n",m,Fact(m,1));
    return 0;
}

unsigned long Fact(unsigned int n,unsigned int a){
    if(n==0 || n==1)
        return a;
    else
        return Fact(n-1,n*a);
}

/* 课后编程题 */

/* 1 n层嵌套平方根的计算（4分）

编写程序利用递归法实现n层嵌套平方根的计算：

递归函数原型：double Y(double x, int n);

程序运行结果示例1：
Please input x and n:16,1↙
Result=4.00
程序运行结果示例2：
Please input x and n:16,2↙
Result=4.47
程序运行结果示例3：
Please input x and n:16,3↙
Result=4.52
程序运行结果示例4：
Please input x and n:16,0↙
Result=0.00

输入提示信息："Please input x and n:"
输入格式: "%lf,%d"
输出格式： "Result=%.2f\n" */

#include <math.h>
#include <stdio.h>
double Y(double x, int n);
int main()
{
    int n;
    double x;
    double result;
    printf("Please input x and n:");
    scanf("%lf %d",&x,&n);
    result = Y(x,n);
    printf("Result=%.2f\n",result);
}

double Y(double x, int n){
    double result;
    if(n == 1){
        result = sqrt(x);
    }else{
        result = sqrt(Y(x,n-1));
    }
    return result;
}


/* 2递归法求和（4分）

用递归方法计算如下求和计算
  sum = 1 + 2 + 3 + .... + n

递归函数原型：int Sum(int n);

程序运行结果示例1：
Please input n:5↙
sum=15
程序运行结果示例2：
Please input n:0↙
data error!
程序运行结果示例3：
Please input n:-3↙
data error!

输入提示信息："Please input n:"
输入错误提示信息："data error!\n"
输入格式:"%d"
输出格式："sum=%d\n" */

#include <stdio.h>
int Sum(int n);
int main()
{
    int sum = 0;
    int n = 0;
    printf("Please input n:");
    scanf("%d",&n);
    while(n <= 0){
        printf("data error!Please input again:");
        while(getchar()!='\n'){}
        scanf("%d",&n);
    }
    sum = Sum(n);
    printf("sum=%d\n",sum);
}

int Sum(int n){
    int sum = 0;
    if(n==1){
        sum = 1;
    }else{
        sum = n+Sum(n-1);
    }
    return sum;
}


/* 3猴子吃桃程序_扩展3（4分）

猴子第一天摘了若干个桃子，吃了一半，不过瘾，又多吃了1个。第二天早上将剩余的桃子又吃掉一半，并且又多吃了1个。此后每天都是吃掉前一天剩下的一半零一个。到第n天再想吃时，发现只剩下1个桃子，问第一天它摘了多少桃子？为了加强交互性，由用户输入天数n，即假设第n天的桃子数为1。

要求采用递归法求解。

递归函数原型：int Monkey(int n, int x);
函数功能：从第n天只剩下一个桃子反向逆推出第1天的桃子数

程序运行结果示例1：
Input days n:5↙
x=46
程序运行结果示例2：
Input days n:10↙
x=1534

输入提示信息："Input days n:"
输入格式: "%d"
输出格式："x=%d\n" */

#include <stdio.h>
int Monkey(int n, int x);
int main()
{
    int x;
    int n;
    printf("Input days n:");
    scanf("%d",&n);
    x=Monkey(n,1);
    printf("x=%d\n",x);
}

/* tail recurrence */
int Monkey(int n, int x){
    if(n == 1) {
        return x;
    }else{
        Monkey(n-1,(x+1)*2);
    }
}


/* 4网购打折商品V2.0（5分）

某网上购物网站对用户实行优惠，买家购物货款p越多，则折扣越多。

标准如下：
p<100元         没有折扣
100元≤p<200元       5%折扣
200元≤p<500元  8%折扣
500元≤p<1000元          10%折扣
1000元≤p               15%折扣

【提示】：从题意可以看出，折扣的变化是有规律的。当购物金额达到“100元”的2倍、5倍、10倍时，折扣值就会发生变化。假如一个变量c代表100的倍数，则当c<1时，无折扣；当1≤c<2时，折扣d=5%；当2≤c<5时，折扣d=8%；当5≤c<10时，折扣d=10%；当10≤c时，折扣d=15%。
注：程序中与价格相关的数据类型为float

程序运行结果示例1：
Input payment:90↙
price = 90.0
程序运行结果示例2：
Input payment:100↙
price = 95.0
程序运行结果示例3：
Input payment:300↙
price = 276.0
程序运行结果示例4：
Input payment:1000↙
price = 850.0
程序运行结果示例5：
Input payment:650.5↙
price = 585.5

输入提示："Input payment:"
输入格式: "%f" 
输出格式："price = %.1f\n"  */

#include <stdio.h>
float Discount(float payment);
int main()
{
    float payment;
    float price;
    printf("Input payment:");
    scanf("%f",&payment);
    price = (1-Discount(payment))*payment;
    printf("price = %.1f\n",price);
}

float Discount(float payment){
    float discount;
    payment = payment/100;
    if(payment >= 10){
        discount = 0.15;
    }else if(payment >= 5){
        discount = 0.1;
    }else if(payment >= 2){
        discount = 0.08;
    }else if(payment >= 1){
        discount = 0.05;
    }else{discount = 0;}
    return discount;
}


/* 1谐均值计算（4分）

两数值的谐均值可以这样计算：首先对两数值的倒数取平均值，最后再取倒数。编写一个带有两个double参数的函数，计算这两个参数的谐均值。

函数原型为：double Calculate(double x,double y);

程序运行结果示例1：
Input two doubles:
3 4↙
1/((1/x+1/y)/2) = 3.429
程序运行结果示例2：
Input two doubles:
6.5 3.8↙
1/((1/x+1/y)/2) = 4.796

输入提示信息："Input two doubles:\n"
输入格式: "%lf%lf"
输出格式："1/((1/x+1/y)/2) = %0.3f\n"   （注意：等号的两边各有一个空格） */

#include <stdio.h>
double Calculate(double x,double y);
int main()
{
    double x;
    double y;
    double mean_value;
    printf("Input two doubles:\n");
    scanf("%lf %lf",&x,&y);
    mean_value = Calculate(x,y);
    printf("1/((1/x+1/y)/2) = %0.3f\n",mean_value);
}

double Calculate(double x,double y){
    double mean_value;
    mean_value = 1/((1/x+1/y)/2);
    return mean_value;
}


/* 2输出指定行列数的字符（4分）

编写一个函数，函数原型：void Chline(char ch, int column, int row);

该函数的3个参数是一个字符和两个整数。字符参数是需要输出的字符。第一个整数说明了在每行中该字符输出的个数，而第二个整数指的是需要输出的行数。
编写一个调用该函数的程序。

程序运行结果示例1：
input a char:
k↙
input column and row:
2 3↙
kk
kk
kk
程序运行结果示例2：
input a char:
a↙
input column and row:
3 2↙
aaa
aaa

字符输入提示信息："input a char:\n"
行列数输入提示信息："input column and row:\n"
输入格式:
"%c"
"%d%d"
输出格式："%c" */

#include <stdio.h>
void Chline(char ch, int column, int row);
int main()
{
    char ch;
    int column;
    int row;
    printf("input a char:\n");
    scanf("%c",&ch);
    printf("input column and row:\n");
    scanf("%d %d",&column,&row);
    Chline(ch,column,row);
}

void Chline(char ch, int column, int row){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("%c",ch);
        }
        printf("\n");
    }
}


/* 3魔术师猜数（4分）

在一种室内互动游戏中，魔术师要每位观众心里想一个三位数abc（a、b、c分别是百位、十位和个位数字），然后魔术师让观众心中记下acb、bac、bca、cab、cba五个数以及这5个数的和值。只要观众说出这个和是多少，则魔术师一定能猜出观众心里想的原数abc是多少。例如，观众甲说他计算的和值是1999，则魔术师立即说出他想的数是443，而观众乙说他计算的和值是1998，则魔术师说：“你算错了！”。请编程模拟这个数字魔术游戏。

要求用函数实现，函数原型为：int Magic(int m);其中形参m代表观众计算的和值。

输入格式:"%d"
输出格式：
观众计算错误，魔术师给出的结论："The sum you calculated is wrong!\n"
观众计算正确，魔术师给出的结论："The number is %d\n"

输入样例1：
1998↙
输出样例1：
The_sum_you_calculated_is_wrong!
输入样例2：
1999↙
输出样例2：
The_number_is_443 */

#include <stdio.h>
int Magic(int m);
int main()
{
    int sum;
    scanf("%d",&sum);
    if(Magic(sum) != 1){
        printf("The_sum_you_calculated_is_wrong!");
    }
}

int Magic(int m){
    int a,b,c,n; //hundreds,tens,units
    for(a=0;a<10;a++){
        for(b=0;b<10;b++){
            for(c=0;c<10;c++){
                int acb = a*100+c*10+b;
                int bac = b*100+a*10+c;
                int bca = b*100+c*10+a;
                int cab = c*100+a*10+b;
                int cba = c*100+b*10+a;
                n = acb+bac+bca+cab+cba;
                if( n== m){printf("The_bumber_is_%d%d%d",a,b,c);return 1;}
            }
        }
    }
    return 0;
}


/* 4计算礼炮声响次数（4分）

在海军节开幕式上，有A、B、C三艘军舰要同时开始鸣放礼炮各21响。已知A舰每隔5秒放1次，B舰每隔6秒放1次，C舰每隔7秒放1次。假设各炮手对时间的掌握非常准确，请编程计算观众总共可以听到几次礼炮声。

输入格式:无
输出格式："n=%d" */

//题意有点难理解啊…A、B、C必须有21次同时放炮？或是A、B、C都要各放21响？21*3？还是说，任意两个或者三个同时放的时候，观众只能听到一声？——最后一种情况。

//方法一：数时间点，在有鸣放的时间点，count+1
#include <stdio.h>
int main()
{
    int a = 0, b = 0, c = 0, count = 0;
    while (a <= 5 * 20 || b <= 6 * 20 || c <= 7 * 20){
        if (a % 5 == 0 || b % 6 == 0 || c % 7 == 0) count++;
        if (a <= 5 * 20)a++;
        if (b <= 6 * 20)b++;
        if (c <= 7 * 20)c++;
    }
    printf("n=%d\n", count);
    return 0;
}

//方法二：容斥法，inclusion-exclusion principle；单个鸣放的-两个同时鸣放的+三个同时鸣放的*2

#include <stdio.h>
int main()
{
    int time = 0;
    int count = 0;
    int n = 21;
    int A = 5,B = 6,C = 7,max;
    if(A>=B){
        if(A>=C) max = A; else max = C;
    }else{
        if(B>=C) max = B;else max = C;
    }
    printf("max = %d\n",max);
    for(time=0;time<=max*n;time++){
        if(time<=A*n && time%A==0) count++;
        if(time<=B*n && time%B==0) count++;
        if(time<=C*n && time%C==0) count++;
        if(time%A==0 && time%B == 0) count--;
        if(time%B==0 && time%C == 0) count--;
        if(time%A==0 && time%C == 0) count--;
        if(time%A==0 && time%B == 0 && time%C == 0) count+=2;
    }
    printf("count= %d\n",count);
}


/* 5水手分椰子（4分）

n(1<n<=5)个水手在岛上发现一堆椰子，先由第1个水手把椰子分为等量的n堆，还剩下1个给了猴子，自己藏起1堆。然后，第2个水手把剩下的n-1堆混合后重新分为等量的n堆，还剩下1个给了猴子，自己藏起1堆。以后第3、4个水手依次按此方法处理。最后，第n个水手把剩下的椰子分为等量的n堆后，同样剩下1个给了猴子。请用迭代法编程计算并输出原来这堆椰子至少有多少个,n的值要求从键盘输入。若输入的n值超出要求的范围，程序输出"Error!"。

提示：分成的等量的堆数应该与水手的数量一致.

程序运行结果示例1：
Input n(1<n<=5):
5↙
y=3121
程序运行结果示例2：
Input n(1<n<=5):
7↙
Error!

输入提示信息： "Input n(1<n<=5):\n"
输入格式:  "%d"
输出格式："y=%d\n"
输入错误提示信息："Error!\n"   */

//y = y/(n-1)*n + 1;重点：当y/(n-1)不能整除，需要扩大最后一堆每堆剩下的数量，重新倒推；

#include <stdio.h>
int main()
{
    int n;
    int y;
    printf("please input n(1<n<=5):\n");
    scanf("%d",&n);
    //n = 5;
    while(n<=1 || n>5){
        while(getchar()!='\n'){}
        printf("Input error!please input n(1<n<=5):\n");
        scanf("%d",&n);
    }
    int a = 1; //at the last time,the number of each heap
    int flag = 0;
    while(!flag){
        flag = 1;
        for(int i=0;i<n;i++){
        if(i==0) {y = a*n + 1;}
        else{
            if(y%(n-1)!=0)
            {
                a++;
                flag = 0;
                break;
            }
            y = y /(n-1)*n + 1;
        }
    }
    }
    //printf("a=%d\n",a);
    printf("y=%d\n",y);
}


/* 6递归法计算游戏人员的年龄（4分）

有n个人围坐在一起，问第n个人多大年纪，他说比第n-1个人大2岁；问第n-1个人，他说比第n-2个人大2岁,.....,问第3个人，他说比第2个人大2岁；问第2个人，他说比第1个人大2岁。第1个人说自己10岁，问第n个人多大年纪。

递归函数原型：unsigned int ComputeAge(unsigned int n);

提示：计算年龄的递归公式为：
age(n)=
10         (n=1)
age(n-1)+2 (n>1)

输入格式: "%u"
输出格式： "The person's age is %u\n"

输入样例1：
5↙
输出样例1：
The_person's_age_is_18
输入样例2：
10↙
输出样例2：
The_person's_age_is_28 */

#include <stdio.h>
unsigned int ComputeAge(unsigned int n);
int main()
{
    unsigned int n;
    scanf("%u",&n);
    printf("The_person's_age_is_%u",ComputeAge(n));
}

unsigned int ComputeAge(unsigned int n){
    int age;
    if(n==1){ age = 10;}else{
            age = ComputeAge(n-1)+2;
    }
    return age;
}


/* 7递归法计算两个数的最大公约数（4分）

利用最大公约数的性质计算。对正整数a和b，当a>b时，若a中含有与b相同的公约数，则a中去掉b后剩余的部分a-b中也应含有与b相同的公约数，对a-b和b计算公约数就相当于对a和b计算公约数。反复使用最大公约数的上述性质，直到a和b相等为止，这时，a或b就是它们的最大公约数。这三条性质，也可以表示为： 

性质1  如果a>b，则a和b与a-b和b的最大公约数相同，即Gcd(a, b) = Gcd(a-b, b)
性质2  如果b>a，则a和b与a和b-a的最大公约数相同，即Gcd(a, b) = Gcd(a, b-a)
性质3  如果a=b，则a和b的最大公约数与a值和b值相同，即Gcd(a, b) = a = b

程序运行结果示例1：
Input a,b:16,24↙
8
程序运行结果示例2：
Input a,b:-2,-8↙
Input error!

输入提示信息："Input a,b:"
输入错误提示信息："Input error!\n"
输入格式:"%d,%d"
输出格式："%d\n" */

#include <stdio.h>
int Gcd(int a,int b);
int main()
{
    int a,b;
    printf("Input a,b:");
    scanf("%d %d",&a,&b);
    printf("%d",Gcd(a,b));
}

int Gcd(int a,int b){
    int gcd;
    if(a == b) gcd = a;
    else{
        if(a>b) {
            gcd = Gcd(a-b,b);
        }else{
            gcd = Gcd(a,b-a);
        }
    }
    return gcd;
}


/* 求两个数最大公约数和最小公倍数的函数 */

int leastCommonMultiple(int a,int b){
    int lcm;
    int gcd = greatestCommonDivisor(a,b);
    lcm = a*b/gcd;
    return lcm;
}

/* for循环求两个数的最大公约数 */
int greatestCommonDivisor(int a,int b){
    int gcd;
    if(a<=b) gcd = a;else gcd = b;
    for(gcd;gcd>0;gcd--){
        if(a%gcd==0 && b%gcd==0){
            return gcd;
        }
    }
}

/* 8寻找中位数v1.0（4分）

编写一个函数返回三个整数中的中间数。函数原型为： int mid(int a, int b, int c); 
函数功能是返回a，b，c三数中大小位于中间的那个数。

输入格式: "%d%d%d"
输出格式："The result is %d\n"

输入样例1：
12 6 18↙
输出样例1：
The_result_is_12
输入样例2：
-9 7 -2↙
输出样例2：
The_result_is_-2 */

#include <stdio.h>
int mid(int a, int b, int c);
int main()
{
    int a,b,c;
    printf("Input a,b,c:");
    scanf("%d %d %d",&a,&b,&c);
    printf("The_result_is_%d",mid(a,b,c));
}

int mid(int a, int b, int c){
    int mid;
    if(a>=b) {
        if(a>=c){
            if(b>=c){
                mid = b;
            }else{
                mid = c;
            }
        }else{
            mid = a;
        }
    }else{
        if(b>=c){
            if(a>=c) {
                mid = a;
            }else{
                mid = c;
            }
        }else{
            mid = b;
        }
    }
}


/* 9还原算术表达式（4分）

编写程序求以下算式中XYZ的值，其中两数XYZ与YZZ相加的和n（99<n<1000）的值要求从键盘输入。
    XYZ
+	YZZ
---------
三位数N

程序运行结果示例1：
Input n(n<1000):
532↙
X=3,Y=2,Z=1
程序运行结果示例2：
Input n(n<1000):
977↙
Invalid

输入提示："Input n(n<1000):\n"
输入格式: "%d" 
输出格式："X=%d,Y=%d,Z=%d\n"
计算不成功(无解)的输出提示："Invalid\n" */

#include <stdio.h>
int main()
{
    int x,y,z;
    int n;
    int flag = 0;
    printf("Input n:");
    scanf("%d",&n);
    while(n<=99||n>=1000){
        printf("Input error!\n");
        while(getchar()!='\n'){}
        printf("Input n:");
        scanf("%d",&n);
    }
    for(x=0;x<9;x++){
        for(y=0;y<9;y++){
            for(z=0;z<9;z++){
                if((x*100+y*10+z+y*100+z*10+z) == n){
                    printf("X=%d,Y=%d,Z=%d",x,y,z);
                    flag = 1;
                }
            }
        }
    }
    if(!flag) {printf("Invalid");}
}

