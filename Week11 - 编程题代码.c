
/* 第11周——指针的孪生兄弟 */

/* 课堂例题 */ 

/* 指针数组应用之命令行参数 */

#include  <stdio.h>
int main(int argc,char *argv[])
{
    int i;
    printf("The number of command line arguments is:%d\n",argc);
    printf("The program name is:%s\n",argv[0]);
    if(argc > 1){
        printf("The other arguments are following:\n");
        for(i=i;i<argc;i++){
            printf("%s\n",argv[i]);
        }
    }
    return 0;
}
//如何输入命令行参数？
//1、命令行窗口 - 如demo.exe文件 - demo programming is fun 
//2、IDE环境中执行 - set programming arguments

/* 计算每个学生的课程总分和平均分
从键盘任意输入m个学生n门课程的成绩，然后计算每个学生各门课的总分sum和平均分aver。
下面程序存在一个极为隐蔽的错误，请分析错误的原因，并修改程序。如果这个程序你能分析明白错在哪里的话，那么用指针向用函数传递二维数组，你是真真地学明白了。 */

//修改后的程序：
#include  <stdio.h>
#define STUD   30            //最多可能的学生人数
#define COURSE 5             //最多可能的考试科目数
void  Total(int *score, int sum[], float aver[], int m, int n);
void  Print(int *score, int sum[], float aver[], int m, int n);
int main(void)
{
     int     i, j, m, n, score[STUD][COURSE], sum[STUD];
     float   aver[STUD];
     printf("Enter the total number of students and courses:");
     scanf("%d%d",&m,&n);
     printf("Enter score\n");
     for (i=0; i<m; i++)
     {
        for (j=0; j<n; j++)
        {
            scanf("%d", &score[i][j]);
        }
    }
    Total(*score, sum, aver, m, n);
    Print(*score, sum, aver, m, n);
    return 0;
}
void  Total(int *score, int sum[], float aver[], int m, int n)
{
    int  i, j;
    for (i=0; i<m; i++)
    {
        sum[i] = 0;
        for (j=0; j<n; j++)
        {
            sum[i] = sum[i] + *(score + i * COURSE  + j);  //访问下一行，列指针的访问跨度应该是数组的实际申请列数，所以原来的i*n需要改为i*course
        }
        aver[i] = (float) sum[i] / n;
    }
}
void  Print(int *score, int sum[], float aver[], int m, int n)
{
    int  i, j;
    printf("Result:\n");
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%4d\t", *(score + i * COURSE + j));  ////原来的i*n改为i*course
        }
        printf("%5d\t%6.1f\n", sum[i], aver[i]);
 }
}

/* 确定奥运参赛国的入场次序
下面主函数调用函数SortString()按奥运会参赛国国名在字典中的顺序对其入场次序进行排序，请问程序错在哪里？ */

//错在字符指针没有初始化，修改后的程序：

#include  <stdio.h>
#include  <string.h>
#define   M  150 /* 最多的字符串个数 */
void SortString(char *ptr[], int n);
int main()
{
    int    i, n;
    char   *pStr[M];
    char str[M][M];   //定义一个二维字符数组
    printf("How many countries?");
    scanf("%d",&n);
    getchar();        /* 读走输入缓冲区中的回车符 */
    printf("Input their names:\n");
    for (i=0; i<n; i++)
    {
        pStr[i] = str[i];  //初始化字符指针
        gets(pStr[i]);  /* 输入n个字符串 */
    }
    SortString(pStr, n); /* 字符串按字典顺序排序 */
    printf("Sorted results:\n");
    for (i=0; i<n; i++)
    {
        puts(pStr[i]);  /* 输出排序后的n个字符串 */
    }
    return 0;
}
void SortString(char *ptr[], int n)
{
    int   i, j;
    char  *temp = NULL;
    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
             if (strcmp(ptr[j], ptr[i]) < 0)
             {
                  temp = ptr[i];
                  ptr[i] = ptr[j];
                  ptr[j] = temp;
             }
        }
    }
}

/* 课后编程题 */

/* 1山地训练（4分）

为了能在下一次跑步比赛中有好的发挥，小白在一条山路上开始了她的跑步训练。
她希望能在每次训练中跑得尽可能远，不过她也知道农场中的一条规定：女孩子独自进山的时间不得超过M秒（1 <= M <= 10,000,000）。
假设整条山路划分成T个长度相同的路段（1 <= T <= 100,000），并且小白用si表示第i个路段的路况，用u、f、d这3个字母分别表示第i个路段是上坡、平地、下坡。
小白跑完一段上坡路的耗时是U秒（1 <= U <= 100），跑完一段平地的耗时是F秒（1 <= F <= 100），跑完一段下坡路的耗时是D秒（1 <= D <= 100）。
注意，沿山路原路返回时，原本是上坡的路段变成了下坡路段，原本是下坡的路段变成了上坡路段。
小白想知道，在能按时返回农场的前提下，她最多能在这条山路上跑多少个路段。请你编程帮助她计算。

函数原型：long Fun(long M, long T, long U, long F, long D, char str[]);

函数功能：计算在限时M秒内T个路段的情况下，最多往返可跑的路段数。
         参数：M,T,U,F,D分别代表限时、路段数，以及上坡、平地、下坡的耗时
               数组str保存整条山路的路段状况
			   返回值：最多可跑的路段数

程序运行结果示例1：
Input M,T,U,F,D:13 5 3 2 1↙
Input conditions of road:ufudf↙
num=3
程序运行结果示例2：
Input M,T,U,F,D:4000 8 18 10 5↙
Input conditions of road:fuffdfud↙
num=7

进山时间等信息的输入提示: "Input M,T,U,F,D:"
路况输入提示信息: "Input conditions of road:"
进山时间等数据的输入格式: "%ld%ld%ld%ld%ld"
路况等数据的输入格式: "%s"
输出格式： "num=%ld\n" */

//分析清楚题目：根据测试用例1的输出结果，题目要求的最多能跑几个路段，指，每次都完成等路程往返跑的情况下，最多离开起点几个路段。
//暂且这么理解，完成程序后输入测试用例2验证。验证通过。

#include  <stdio.h>
#define N 100
long Fun(long M, long T, long U, long F, long D, char str[]);
int main()
{
    long M,T;
    long U,F,D;
    char str[N];
    long num;
    printf("Input M,T,U,F,D:");
    scanf("%ld%ld%ld%ld%ld",&M,&T,&U,&F,&D);
    printf("Input conditions of road:");
    fflush(stdin);
    scanf("%s",str);
    num = Fun(M,T,U,F,D,str);
    printf("num=%ld\n",num);
    return 0;
}

long Fun(long M, long T, long U, long F, long D, char str[]){
    long num = 0;
    int length = 0;
    int need_time = 1;
    while(str[length]){length++;}
    //printf("length=%d\n",length);
    i=0;
    while(num<length && M/need_time>0){
        if(str[num]=='u'||str[num]=='d'){need_time=need_time+U+D;}
        if(str[num]=='f'){need_time=need_time+2*F;}
        num++;
    }
    return --num;
}


/* 2奇偶数分离（4分）

输入n个整数（n从键盘输入，假设n的值不超过100），按奇偶数分成两组并输出。输出两行，第一行为所有奇数，第二行为所有偶数，保持数据的相对顺序与输入顺序相同。

函数原型如下所示：
void Seperate(int a[], int n); //数组a[]存放用户输入的n个整数

解题思路：用两个循环分别输出奇数和偶数，在输出第一个数时用"%d"格式字符，在输出其余数时用",%d"格式字符，用标志变量记录和判断是否是第一个奇数或偶数。

程序运行结果示例1：
Input n:7↙
Input numbers:5 9 47 82 0 6 7↙
5,9,47,7
82,0,6

程序运行结果示例2：
Input n:8↙
Input numbers:-2 3 5 0 23 62 79 83↙
3,5,23,79,83
-2,0,62

输入提示信息："Input n:"
              "Input numbers:"
输入格式: "%d"
每行第一个数据的输出格式："%d"
每行第二个及以后数据的输出格式：",%d" */

#include  <stdio.h>
#define N 100
void Seperate(int a[], int n);
int main()
{
    int n;
    int a[N];
    printf("Input n:");
    scanf("%d",&n);
    printf("Input numbers:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Seperate(a,n);
    return 0;
}

void Seperate(int a[], int n){
    int flag = 0;
    for(int i=0;i<n;i++){
        if(a[i]%2!=0){
            flag++;
            if(flag==1){printf("%d",a[i]);}else{printf(",%d",a[i]);}
        }
    }
    flag = 0;
    printf("\n");
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            flag++;
            if(flag==1){printf("%d",a[i]);}else{printf(",%d",a[i]);}
        }
    }
}


/* 3子串判断（4分）

从键盘输入两个长度小于80的字符串A和B，且A的长度大于B的长度，编程判断B是不是A的子串，如果是，则输出”Yes”，否则输出”No”。
这里所谓的该串的子串是指字符串中任意多个连续的字符组成的子序列。

函数原型：int IsSubString(char a[], char b[]);
函数功能：判断b是否是a的子串，是则返回1，否则返回0

程序运行结果示例1：
Input the first string: Abcdefghijk123↙
Input the second string: 123↙
Yes
程序运行结果示例2：
Input the first string: abefsfl↙
Input the second string: befs↙
Yes
程序运行结果示例3：
Input the first string: aAbde↙
Input the second string: abc↙
No

输入第一个字符串的提示信息： "Input the first string:"
输入第二个字符串的提示信息： "Input the second string:"
输入格式: 用 gets()函数
输出格式：
是子串，输出： "Yes\n"
不是子串，输出： "No\n" */

//不做了，和week10-2查找子串相似

/* 4星期查找（4分）

任意输入英文的星期几，通过查找如图所示的星期表，输出其对应的数字，若查到表尾，仍未找到，则输出错误提示信息。
0  Sunday
1  Monday
2  Tuesday
3  Wednesday
4  Thursday
5  Friday
6  Saturday

提示：用一个二维字符数组weekDay来存放如图所示的星期表的内容（字符串）。
输入待查找的字符串，然后在星期表中顺序查找与输入字符串相匹配的字符串。
找到的字符串在星期表数组中的第一维下标（行号）即为题目所求。

程序运行结果示例1：
Please enter a string:
Friday↙
Friday is 5

程序运行结果示例2：
Please enter a string:
Fruday↙
Not found!

输入提示信息："Please enter a string:\n"
输入格式:  字符串输入采用gets()函数
输出格式：
找到了，输出："%s is %d\n"
没找到，输出："Not found!\n" */

#include <string.h>
#include  <stdio.h>
#define N 10
int main()
{
    char weekDay[][N]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    //puts(weekDay[0]);
    char a[N];
    char *str;
    str = a;
    int flag = 0;
    printf("Please enter a string:\n");
    gets(str);
    for(int i=0;weekDay[i][0];i++){
        if(strcmp(weekDay[i],str)==0){
            printf("%s is %d\n",str,i);
            flag = 1;
        }
    }
    if(!flag){printf("Not found!\n");}
    return 0;
}


/* 1找出按字典顺序排在最前面的国名（4分）

输入5个国名，编程找出并输出按字典顺序排在最前面的国名。
提示：所谓字典顺序就是将字符串按由小到大的顺序排列，因此找出按字典顺序排在最前面的国名指的就是最小的字符串。

程序的运行结果示例：
Input five countries' names:
America↙
China↙
Japan↙
England↙
Sweden↙
The minimum is:America

输入提示信息："Input five countries' names:\n"
输入格式: 国名输入用gets()函数
输出格式："The minimum is:%s\n" */

//不做了，课堂练习题有相似的程序

/* 2学生成绩管理系统V2.0（4分）

某班有最多不超过30人（具体人数由键盘输入）参加某门课程的考试，参考前面章节的“学生成绩管理系统V1.0”，用一维数组和函数指针作函数参数编程实现如下菜单驱动的学生成绩管理系统：
（1）录入每个学生的学号和考试成绩；
（2）计算课程的总分和平均分；
（3）按成绩由高到低排出名次表；
（4）按成绩由低到高排出名次表；
（5）按学号由小到大排出成绩表；
（6）按学号查询学生排名及其考试成绩；
（7）按优秀（90~100）、良好（80~89）、中等（70~79）、及格（60~69）、不及格（0~59）5个类别，统计每个类别的人数以及所占的百分比；
（8）输出每个学生的学号、考试成绩。

//不做了，和week10 v1.0相比变动不大

/* 3月份表示（4分）

用指针数组保存表示每个月份的英文单词以及“Illegal month”的首地址，然后编程实现：从键盘任意输入一个数字表示月份值n，程序输出该月份的英文表示，若n不在1～12之间，则输出“Illegal month”。

程序的运行结果示例1：
Input month number:
3↙
month 3 is March
程序的运行结果示例2：
Input month number:
12↙
month 12 is December
程序的运行结果示例3：
Input month number:
14↙
Illegal month

月份输入提示信息："Input month number:\n"
输入格式:  "%d"
输出格式：
月份正确时输出格式："month %d is %s\n"
月份错误时输出格式："%s\n" */


/* 4程序改错——1（4分）
/* 5程序改错——2（4分）

//上面两题同课堂练习

/* 6找数组最值（4分）

按如下函数原型编程从键盘输入一个m行n列的二维数组，然后计算数组中元素的最大值及其所在的行列下标值。其中，m和n的值由用户键盘输入。已知m和n的值都不超过10。

void InputArray(int *p, int m, int n);
int  FindMax(int *p, int m, int n, int *pRow, int *pCol);
//函数返回最大值，pRow和pCol分别返回最大值所在的行列下标
例如，程序的1次运行结果如下：
Input n:
3,4↙
Input 3*4 array:
1 2 3 4
5 6 7 8
9 0 -1 -2
max=9,row=2,col=0

数组行列数输入提示信息: "Input m,n:\n"
数组输入提示信息: "Input %d*%d array:\n"
输入格式:
输入数组行列数："%d,%d"
输入数组元素："%d"
输出格式： "max=%d,row=%d,col=%d\n" */

#include  <stdio.h>
#define N 10
void InputArray(int *p, int m, int n);
int  FindMax(int *p, int m, int n, int *pRow, int *pCol);
int main()
{
    int p[N][N];
    int m,n;
    int max;
    int row = 0;
    int col = 0;
    int *pRow;
    int *pCol;
    pRow = &row;
    pCol = &col;
    printf("Input m,n:\n");
    scanf("%d%d",&m,&n);
    InputArray(p,m,n);
    max = FindMax(p,m,n,pRow,pCol);
    printf("max=%d,row=%d,col=%d\n",max,*pRow,*pCol);
    return 0;
}

void InputArray(int *p, int m, int n){
    printf("Input %d*%d array:\n",m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",(p+i*N+j));
        }
    }
}
int  FindMax(int *p, int m, int n, int *pRow, int *pCol){
    int max = *p;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(*(p+i*N+j)>max){
                max = *(p+i*N+j);
                *pRow = i;
                *pCol = j;
            }
        }
    }
    return max;
}


/* 7冒泡排序（4分）

采用冒泡法进行升序排序法的基本原理是：
对数组中的n个数执行n-1遍检查操作，在每一遍执行时，对数组中剩余的尚未排好序的元素进行如下操作：对相邻的两个元素进行比较，若排在后面的数小于排在前面的数，则交换其位置，这样每一遍操作中都将参与比较的数中的最大的数沉到数组的底部，经过n-1遍操作后就将全部n个数按从小到大的顺序排好序了。

程序的某次运行结果如下：
Input n:10↙
Input 10 numbers:-↙
Sorting results:   0   1   2   3   4   5   6   7  8  9

输入数据个数提示："Input n:"
输入数据提示："Input %d numbers:"
输入格式: "%d"
输出提示："Sorting results:"
输出格式："%4d" */

#include  <stdio.h>
#define N 100
void BubbleSort(int *p,int n);
int main()
{
    int a[N];
    int n;
    printf("Input n:");
    scanf("%d",&n);
    printf("Input %d numbers:",n);
    fflush(stdin);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    printf("Sorting results:");
    BubbleSort(a,n);
    return 0;
}

void BubbleSort(int *p,int n){
    int temp;
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            if(*(p+j)<*(p+j+1)){
                temp = *(p+j+1);
                *(p+j+1) = *(p+j);
                *(p+j) = temp;
            }
        }
        printf("%4d",*(p+i-1));
    }
}


/* 8删除字符串中与某字符相同的字符（4分）

在字符串中删除与某字符相同的字符，要求用字符数组作函数参数。

程序运行结果示例：
Input a string:
hello, my friend!↙
Input a character:
!↙
Results:hello, my friend

输入字符串的提示信息： "Input a string:\n"
输入单个字符的提示信息： "Input a character:\n"
输入格式:
字符串输入用 gets()函数
单个字符输入用 getchar()函数
输出格式："Results:%s\n" */

#include  <stdio.h>
#define N 100
void DeleteCharacter(char *str,char c);
int main()
{
    char str[N];
    char c;
    printf("Input a string:\n");
    gets(str);
    fflush(stdin);
    printf("Input a character:\n");
    c = getchar();
    DeleteCharacter(str,c);
    printf("Results:%s\n",str);
    return 0;
}

void DeleteCharacter(char *str,char c){
    int i = 0;
    int pos = -1;
    while(*(str+i) != '\0'){
        if(*(str+i)==c){
            pos++;
        }
        if(pos!=-1){
            *(str+pos+i) = *(str+pos+i+1);
        }
        i++;
    }
    printf("length = %d\n",i);
}


/* 9求最大数和最小数的最大公约数（4分）

从键盘输入10个正整数，求出最大数，最小数，以及他们的最大公约数。要求用数组实现。

程序运行结果示例1：
Input 10 numbers:
15 23 56 87 94 105 78 19 22 43↙
maxNum=105
minNum=15
15

程序运行结果示例2：
Input 10 numbers:
33 1 2 9 8 7 5 4 0 10↙
maxNum=33
minNum=0

输入提示信息："Input 10 numbers:\n"
输入格式: "%d"
输出格式：
最大数输出格式："maxNum=%d\n"
最小数输出格式："minNum=%d\n"
最大公约数输出格式："%d" */

#include  <stdio.h>
#define N 10
int Max(int num[]);
int Min(int num[]);
int GreatestCommonDivisor(int a,int b);
int main()
{
    int num[N];
    int max;
    int min;
    int gcd;
    printf("Input %d numbers:\n",10);
    for(int i=0;i<N;i++){
        scanf("%d",num+i);
    }
    max = Max(num);
    min = Min(num);
    gcd = GreatestCommonDivisor(max,min);
    printf("maxNum=%d\n",max);
    printf("minNum=%d\n",min);
    printf("%d",gcd);
    return 0;
}
int Max(int num[]){
    int max = num[0];
    for(int i=0;i<N;i++){
        if(num[i]>max){max = num[i];}
    }
    return max;
}
int Min(int num[]){
    int min = num[0];
    for(int i=0;i<N;i++){
        if(num[i]<min){min = num[i];}
    }
    return min;
}
//辗转相除法求最大公约数
int GreatestCommonDivisor(int a,int b){
    int divident;
    int divisor;
    int reminder;
    if(a>b){
        divident = a;divisor = b;
    }else{
        divident = b;divisor = a;
    }
    reminder = divident%divisor;
    while(reminder != 0){
        divident = divisor;
        divisor = reminder;
        reminder = divident%divisor;
    }
    return divisor;
}


/* 10数列合并（4分）

已知两个不同长度的降序排列的数列（假设序列的长度都不超过5），请编程将其合并为一个数列，使合并后的数列仍保持降序排列。

【提示】假设两个降序排列的数列分别保存在数组a和数组b中，用一个循环，从前往后依次比较保存在数组a和数组b中的两个剩余序列里的第一个数，将其中的较大者存到数组c中，当一个较短的序列存完后，再将较长的序列剩余的部分依次保存到数组c的末尾。假设两个序列的长度分别是m和n，在比较剩余序列的循环中，用i和j分别记录两个序列待比较的数组元素位置，循环结束后，若i小于m，则说明数组a中的数有剩余，将数组a中剩余的数存到数组c的末尾即可；若j小于n，则说明数组b中的数有剩余，将数组b中剩余的数存到数组c的末尾即可。在第一个循环中，用k记录往数组c中存了多少个数，在第二个循环中，就从k这个位置开始继续存储较长序列中剩余的数。

函数原型：void Merge(int a[], int b[], int c[], int m, int n);
函数功能：将两个长度分别为m和n、降序排列的子序列a和b合并后放到数组c中

程序运行结果示例1：
Input m,n:3,2↙
Input array a:5 3 1↙
Input array b:4 2↙
   5   4   3   2   1

程序运行结果示例2：
Input m,n:3,3↙
Input array a:31 27 -5
Input array b:98 30 -7
  98  31  30  27  -5  -7

输入两个数列长度的提示信息："Input m,n:"
输入数列a的提示信息："Input array a:"
输入数列b的提示信息："Input array b:"
输入格式: 
数列长度的输入格式："%d,%d"
数列中每个数据的输入格式："%d"
输出格式："%4d" */

//假设输入两序列降序，程序不再检测是否降序

#include  <stdio.h>
#define N 10
void Merge(int a[], int b[], int c[], int m, int n);
int main()
{
    int m,n;
    int a[N];
    int b[N];
    int c[2*N]={0};
    printf("Input m,n:");
    scanf("%d %d",&m,&n);
    fflush(stdin);
    printf("Input array a:");
    for(int i=0;i<m;i++){
        scanf("%d",a+i);
    }
    fflush(stdin);
    printf("Input array b:");
    for(int j=0;j<n;j++){
        scanf("%d",b+j);
    }
    Merge(a,b,c,m,n);
    for(int i=0;i<m+n;i++){
        printf("%4d",c[i]);
    }
    return 0;
}

void Merge(int a[], int b[], int c[], int m, int n){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<m && j<n){
        if(a[i]>=b[j]){
            c[k] = a[i];
            i++;
        }else{
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while(i<m){
        c[k] = a[i];
        k++;
        i++;
    }
    while(j<n){
        c[k] = b[j];
        k++;
        j++;
    }
}
