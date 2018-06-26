
/* 第9周——指针：C语言世界中所向披靡的“金箍棒” */

/* 课堂例题 */ 

/* 最大值和最小值互换位置
下面程序的功能是从键盘任意输入n个数，然后找出其中的最大数与最小数，并将其位置对换。
这个程序有无错误？如果有，那么错在哪里？请通过程序调试找到错误的原因并修正错误。 */

//原程序
#include  <stdio.h>
#define ARR_SIZE 10
void  MaxMinExchang(int a[], int n);
int main()
{
   int a[ARR_SIZE], i, n;
   printf("Input n(n<=10):");
   scanf("%d", &n) ;
   printf("Input %d Numbers:\n", n);
   for (i=0; i<n; i++)
   {
      scanf("%d", &a[i]);
   }
   MaxMinExchang(a, n);
   printf("After MaxMinExchange:\n");
   for (i=0; i<n; i++)
   {
      printf("%d ", a[i]);
   }
   printf("\n");
  return 0;
}
void  MaxMinExchang(int a[], int n)
{
   int  maxValue = a[0], minValue = a[0], maxPos, minPos;
   int  i, temp;
   for (i=0; i<n; i++)
   {
      if (a[i] > maxValue)
      {
          maxValue = a[i];
          maxPos = i;
      }
      if (a[i] < minValue)
      {
          minValue = a[i];
           minPos = i;
      }
   } 
   temp = a[maxPos];  
   a[maxPos] = a[minPos];
   a[minPos] = temp;
}


//出错原因，minPos和maxPOs没有初始化；修改后：

//方法一：
void  MaxMinExchang(int a[], int n)
{
   int  maxValue = a[0], minValue = a[0], maxPos = 0, minPos = 0;
   int  i, temp;
   for (i=0; i<n; i++)
   {
      if (a[i] > maxValue)
      {
          maxValue = a[i];
          maxPos = i;
      }
      if (a[i] < minValue)
      {
          minValue = a[i];
           minPos = i;
      }
   }
   temp = a[maxPos];
   a[maxPos] = a[minPos];
   a[minPos] = temp;
}

//方法二：
void  MaxMinExchang(int a[], int n)
{
   int  maxValue = a[0], minValue = a[0], *maxPos = &a[0], *minPos = &a[0];
   int  i, temp;
   for (i=0; i<n; i++)
   {
      if (a[i] > maxValue)
      {
          maxValue = a[i];
          maxPos = &a[i];
      }
      if (a[i] < minValue)
      {
          minValue = a[i];
           minPos = &a[i];
      }
   }
   temp = *maxPos;
   *maxPos = *minPos;
   *minPos = temp;
}


/* 使用函数指针编写一个通用的排序函数 - 选择法 */

void SelectionSort(int a[], int n, int (*compare)(int int) ){
	int i,j,k;
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1; j<n;j++){
			if((*compare)(a[j],a[k]) {k=j;}
		}
		if(k!=i)
		{
			Swap(&a[k],&a[i]);
		}
	}
}

int Ascending(int a,int b){
	return a<b;  //为真，则升序
}

int Descending(int a,int b){
	return a>b;  //为真，则降序
}

/* 计算任意函数的定积分 - 梯形法 */

#include  <stdio.h>
#define N 100 //accuracy
float Intergral(float (*f)(float),float a, float b);
float F1(float x);
float F2(float x);
int main()
{
    float s = Intergral(F2,1,10);
    printf("%f",s);
    return 0;
}

float Intergral(float (*f)(float), float a, float b){
    float s,h;
    int n = N;
    int i;
    s = ((*f)(a) + (*f)(b))/2;
    h = (b-a)/N;
    for(i=i;i<n;i++){
        s = s + (*f)(a + i*h);
    }
    return s*h;
}

float F1(float x){
    return (1 + x*x);
}

float F2(float x){
    return x*x*x;
}


/* 筛法求N以内的素数 */
#include <math.h>
#include  <stdio.h>
#define N 1000
void SiftPrime(int a[], int n);
int main()
{
    int a[N]={0};
    int n;
    printf("Input n: ");
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        a[i] = i;
        //printf("a[%d]=%d\n",i,a[i]);
    }
    SiftPrime(a,n);
    for(int i=2;i<=n;i++){
        if(a[i]!=0){
            printf("%4d",i,a[i]);
        }
    }
    return 0;
}

void SiftPrime(int a[], int n){
    for(int i=2;i<sqrt(n);i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]!=0 && a[i]!=0 && a[j]%a[i]==0){
                a[j] = 0;
            }
        }
    }
}


/* 鲁智深吃馒头
据说，鲁智深一天中午匆匆来到开封府大相国寺，想蹭顿饭吃，当时大相国寺有99个和尚，只做了99个馒头。智清长老不愿得罪鲁智深，便把他安排在一个特定位置，之后对所有人说： 从我开始报数（围成一圈），第5个人可以吃到馒头（并退下） ,按此方法，所有和尚都吃到了馒头，唯独鲁智深没有吃上。请问他在那个位置？ 能否借鉴筛法求出剩下的最后一个人的位置？ */

#include  <stdio.h>
#define N 100
int main()
{
    int a[N]={1};
    int n = 100;
    int m = 100;
    int count = 0;
    for(int i=0;i<n;i++){
        a[i] = i+1;
    }
   do{
        for(int i=0;i<n;i++){
            if(a[i]!=0){
                count++;
            }
            if(count == 5)
            {
                a[i]=0;
                m--;
                count = 0;
            }
            //printf("%4d\n",a[i]);
        }
     //printf("m=%4d\n",m);
    }while(m>1);
    //int j = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            printf("a[%d],NO.%d",i,i+1);
           //j++;
        }
    }
    //printf("zero num:%4d\n",j);
    return 0;
}

/* 文曲星猜数游戏 */

#include  <stdio.h>
int IsRightPosition(int a[],int b[]);
int IsRightDigit(int a[], int b[]);
void MakeDigit(int a[]);
void MakeDigit_b(int a[]);
int InputGuess(int b[]);
int main()
{
    int a[4]={0};
    int b[4]={0};
    int count = 1;
    int level;
    int rightPosition;
    int rightDigit;
    MakeDigit(a);
    printf("Digit[a] = {%d,%d,%d,%d}",a[0],a[1],a[2],a[3]);
    printf("How many times do you want to guess?");
    scanf("%d",&level);
    do{
        printf("No. %d of %d time\n",count,level);
        printf("Input your guess:\n");
        if(InputGuess(b) == 0) continue;  //skip the following statement,start a new cycle
        count++;
        rightPosition = IsRightPosition(a, b);
        rightDigit = IsRightDigit(a, b)- rightPosition;
        printf("%dA%dB\n",rightPosition,rightDigit);

    }while(rightPosition != 4 && count <= level);
    if(rightPosition == 4)
        printf("Congratulations,you guess the right number at No.%d\n",count);
    else{
        printf("Sorry,you haven't guess the right number,see you next time!\n");
    }
    printf("Correct answer is : %d%d%d%d\n",a[0],a[1],a[2],a[3]);
    return 0;
}

void MakeDigit(int a[]){   //method a: Randomly generate four different ordered numbers
    srand(time(NULL));
    a[0] = rand()%10;
    do
    {
        a[1] = rand()%10;
    }while(a[0] == a[1]);
    do
    {
        a[2] = rand()%10;
    }while(a[0]==a[2] || a[1]==a[2]);
    do
    {
        a[3] = rand()%10;
    }while(a[0]==a[3] || a[1]==a[3] || a[2]==a[3]);
}

void MakeDigit_b(int a[]){   //method b
    int i,j,temp;
    srand(time(NULL));
    for(i=0;i<10;i++){
        a[i]=i;
    }
    for(i=0;i<10;i++){
        j = rand()%10;
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
}

int InputGuess(int b[]){   //users input the numbers he guessed
    int i, ret;
    for(i=0;i<4;i++){
        ret = scanf("%d",&b[i]);
        if(ret != 1){
            printf("Input data Type error!\n");
            fflush(stdin);  //Clear the input buffer
            return 0;       //Invalid input data
        }
    }
    if(b[0]== b[1]||b[1]==b[2]||b[0]==b[3]||b[1]==b[2]||b[1]==b[3]||b[2]==b[3]){
        printf("The numbers must be different from each other,input again\n");
        return 0;
    }else{
        return 1;
    }
}

int IsRightPosition(int magic[],int guess[]){
    int rightPosition = 0;
    int j;
    for(j=0;j<4;j++){
        if(guess[j]==magic[j]){
            rightPosition++;
        }
    }
    return rightPosition;
}

int IsRightDigit(int magic[], int guess[]){
    int rightDigit = 0;
    int j,k;
    for(j=0;j<4;j++){
        for(k=0;k<4;k++){
            if(guess[j]==magic[k]){
                rightDigit++;
            }
        }
    }
    return rightDigit;
}

/********* 大数的存储问题 *********/

/* 大数的存储问题 - 阶乘 */

//原程序：double的表数精度 - 16位，出现精度缺失
#include  <stdio.h>
double Fact(unsigned int n);
int main()
{
    int i;
    for(i=1;i<40;i++){
        printf("%d!=%.0f\n",i,Fact(i));
    }
    return 0;
}

double Fact(unsigned int n){
    unsigned int i;
    double result = 1;
    for(i=1;i<n;i++){
        result = result*i;
    }
    return result;
}

/*数组a[3]
① 进位设置为10：
用数组来存储大数的每一位：a[2] = 3，a[1] = 2，a[0] = 5，表示这个数为325.
② 进位设置为1000：
a[2] = 223，a[1] = 100，a[0] = 4，表示这个数为223,100,4.
采用%来计算当前位的值，用/来计算进位值。*/

#include <stdio.h>
#define N 10
void main()
{
    int a[3000]={1};
    int n;
    printf(" please input n (1~1000):");
    do
    {
        scanf("%d",&n);
    }
    while (n>1000||n<0);

    int wei=0;   //N0.wei
    int i;
    for (i=2;i<=n;i++)
    {
        int jinwei=0;
        int j;
        for (j=0;j<=wei;j++)
        {
            int w=a[j]*i+jinwei;
            a[j]=w%N;
            jinwei=w/N;
        }
        while(jinwei)  //when
        {
        wei++;
        a[wei]=jinwei%N;
        jinwei/=N;
        }
    }
    
    int sum=0;
    int k;
    for (k=wei;k>=0;k--)
    {
        printf("%d",a[k]);
        if(a[k]==0) sum=sum+1;
    }

    int m , count = 0;
    for( m = 0;m<wei;m++)
    {
        if(a[m] == 0)
        {
            count ++;
        }else break;
    }

    printf("\n");
    printf("%d%s%d\n",n,"!中共位数为：",wei);
    printf("%d%s%d\n",n,"!中共有0的个数为：",sum);
    printf("%d%s%d\n",n,"!尾部中共有0的个数为：",count);
}


/* 课后编程题 */

/* 1重复数字检查（4分）

从键盘输入一个数，检查这个数中是否有重复出现的数字。如果这个数中有重复出现的数字，则显示“Repeated digit!”；否则显示“No repeated digit!”。

已知函数原型：
int CountRepeatNum(int count[], int n);

若有重复数字，则该函数返回重复出现的数字；否则返回-1.

程序运行结果示例1：
Input n:
28212↙
Repeated digit!
程序运行结果示例2：
Input n:
12345↙
No repeated digit!

输入提示："Input n:\n"
输入格式: "%ld"
输出格式：
有重复数字，输出信息: "Repeated digit!\n"
没有重复数字，输出信息: "No repeated digit!\n" */

#include <string.h>
#include <stdio.h>
#define N 100
int CountRepeatNum(int count[], int n);
void main()
{
    int count[N];
    memset(count,-1,sizeof(count));
    int n;
    printf("Input n:\n");
    scanf("%d",&n);
    if(n<0) {n = -n;}
    printf("n=%d\n",n);
    int result;
    result = CountRepeatNum(count,n);
    if(result != -1){
        printf("Repeated digit!\nRepeat number: %d",result);
    }else{printf("No repeated digit!\n");}
}

int CountRepeatNum(int count[], int n){
    int i = 0;
    while(n!=0){
        count[i] = n%10;
        n = n/10;
        i++;
    }
    printf("digit_number=%d\n",i);
    int flag = 0;
    for(int j=0;j<i-1;j++){
        for(int k=j+1;k<i-1;k++){
            if(count[j] == count[k]) {
                //printf("count[j] = %d ,count[k] = %d\n",count[j],count[k]);
                return count[j];
            }
        }
    }
    return -1;
}


/* 2教授的课（4分）

教授正在为一个有N个学生的班级讲授离散数学课。他对某些学生缺乏纪律性很不满意，于是决定：如果课程开始后上课的人数小于K，就取消这门课程。
从键盘输入每个学生的到达时间，请编程确定该课程是否被取消。如果该门课程被取消，则输出“Yes”，否则输出“No”。
假设教授在时刻0开始上课。如果一个学生的到达时间是非正整数，则表示该学生在上课前进入教室。如果一个学生的到达时间是正整数，则表示该学生在上课后进入教室。如果一个学生在时刻0进入教室，也被认为是在上课前进入教室。假设到达时间的绝对值不超过100，学生数N不超过1000。要求在输入学生的到达时间之前，先输入N和K。

已知函数原型：
//函数功能：根据数组a中记录的学生到达时间确定课程是否被取消，取消则返回1，否则返回0
int IsCancel(int a[], int n, int k);

程序运行结果示例1：
Input n,k:
4,3↙
-1 -3 4 2↙
YES
程序运行结果示例2：
Input n,k:
5,3↙
-1 -2 -3 0 4↙
NO

输入提示："Input n,k:\n"
输入格式: 
"%d,%d"
"%d"
输入包括两行数据：
    第1行是n,k的值。
    第2行是学生的到达时间。
输出格式： 
课程被取消，输出"YES"
课程不取消，输出"NO" */

#include <stdio.h>
#define N 1000
int IsCancel(int a[], int n, int k);
void main()
{
    int a[N];
    int n;
    int k;
    printf("Input n,k:\n");
    scanf("%d %d",&n,&k);
    int flag = IsCancel(a,n,k);
    if(flag){printf("IS CANCEL!");}else{printf("NOT CANCEL!");}
}

int IsCancel(int a[], int n, int k){
    int count = 0;
    int flag = 1;
    for(int i=0;i<n;i++){
        //fflush(stdin);
        scanf("%d",&a[i]);
        if(a[i]<0){count++;}
        if(count>=k){ flag=0;break;}
    }
    return flag;
}


/* 3寻找鞍点（4分）

请编程找出一个M*N矩阵中的鞍点，即该位置上的元素是该行上的最大值，是该列上的最小值。如果矩阵中没有鞍点，则输出“No saddle point！”

已知函数原型：
void FindSaddlePoint(int a[][N], int m, int n);
在该函数中输出有无鞍点的信息。

程序运行结果示例1：
Input m,n:
3 3
Input matrix:
1 2 3
4 5 6
7 8 9
a[0][2] is 3

程序运行结果示例2：
Input m,n:
3 4
Input matrix:
3 4 7 5
0 1 8 2
9 3 2 6
No saddle point!

输入提示： "Input m,n:\n"
        “Input matrix:\n" 
输入格式: 
输入矩阵大小： "%d,%d"
输入矩阵元素： "%d"
输出格式：
找到鞍点的输出格式："a[%d][%d] is %d\n"
没找到鞍点的输出格式："No saddle point!\n" */

#include <stdio.h>
#define N 100
void FindSaddlePoint(int a[][N], int m, int n);
void main()
{
    int a[N][N];
    int m;
    int n;
    printf("Input m,n:\n");
    scanf("%d %d",&m,&n);
    printf("Input matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    FindSaddlePoint(a,m,n);
}

void FindSaddlePoint(int a[][N], int m, int n){
    int count = 0;
    for(int i=0;i<m;i++){
        int row_max = 0;
        int flag = 1; //is a saddle point
        for(int j=0;j<n;j++){ //find the maximum value in a row
            //printf("a[i][row_max]=%d\n",a[i][row_max]);
            //printf("a[i][j]=%d\n",a[i][j]);
            if(a[i][j] > a[i][row_max]){row_max = j;}
        }
        for(int k=0;k<m;k++){ //check if this is the minimum in this column
            if(a[k][row_max] < a[i][row_max]){flag = 0;break;}
        }
        if(flag){ count++;printf("a[%d][%d] is %d\n",i,row_max,a[i][row_max]);}
    }
    if(!count){
        printf("No saddle point!");
    }
}


/* 4计算三位阶乘和数（4分）

试求出所有三位阶乘和数：m=a!+b!+c!(其中a为百位数字，b为十位数字，c为个位数字。约定0!=1，并输出所有的m)

输入格式: 无
输出格式："%ld\n" */

#include <stdio.h>
int CountFactorial(int n,long int m);
void main()
{
    //int n=5;printf("%d",CountFactorial(n,1));
    for(int long m = 100;m<1000;m++){
        int hundreds = m/100;
        int tens = m/10%10;
        int units = m%10;
        if(m == CountFactorial(hundreds,1)+CountFactorial(tens,1)+CountFactorial(units,1)){
            printf("%ld\n",m);
        }
    }
}

/* 尾递归求阶乘 */
int CountFactorial(int n,long int m){
    int i = 0;
    if(n==0 || n==1) {
            return m;
    }else{
        CountFactorial(n-1,m*n);
    }
}


/* 1二分法求根（4分）

用二分法求下面的一元三次方程在区间[-10, 10]上误差不大于的根。
x^3-x-1=0;
用二分法求方程的根的基本原理是：若函数有实根，则函数曲线应当在根x*这一点上与x轴有一个交点，并且由于函数是单调的，在根附近的左右区间内，函数值的符号应当相反。
利用这一特点，可以通过不断将求根区间二分的方法，每次将求根区间缩小为原来的一半，在新的折半后的区间内继续搜索方程的根，对根所在区间继续二分，直到求出方程的根为止。

该方法的关键在于要解决如下两个问题：
1）如何对区间进行二分，并在二分后的左右两个区间中确定下一次求根搜索的区间？
假设区间端点为x1和x2，则通过计算区间的中点x0，即可将区间[x1, x2]二分为[x1, x0]和[x0, x2]。这时，为了确定下一次求根搜索的区间，必须判断方程的根在哪一个区间内，由上图可知方程的根所在区间的两个端点处的函数值的符号一定是相反的。也就是说，如果f(x0)与f(x1)是异号的，则根一定在左区间[x1, x0]内，否则根一定在右区间[x0, x2]内。

2）如何终止这个搜索过程？即如何确定找到了方程的根？
对根所在区间继续二分，直到|f(x0)<=10^-6,即|f(x0)|≈0时，则认为x0是逼近函数f(x)的根。
程序中所有变量的数据类型均为float。

输入格式: "%f,%f"
输出格式： "x=%6.2f\n"

输入样例：
0,4
输出样例：
x=__1.32 */

#include <math.h>
#include <stdio.h>
float F(float x);
float Dichotomy(float x1,float x2,float (*f)(float x));
void main()
{
    float x1,x2;
    float answer;
    printf("Input the start point and end point of the interval:");
    scanf("%f %f",&x1,&x2);
    answer = Dichotomy(x1,x2,F);
    printf("x=%6.2f\n",answer);
}

float F(float x){
    float y = x*x*x - x - 1;
    return y;
}

float Dichotomy(float x1,float x2,float (*f)(float x)){
        int count = 0;
        float answer = 0;
        float x0;
        float y0,y1,y2;
        do{
        count++;
        y1 = (*f)(x1);
        y2 = (*f)(x2);
        if(y1 == 0){answer = x1;break;}
        if(y2 == 0){answer = x2;break;}
        if( y1*y2 < 0){
                x0 = (x1+x2)/2;
                y0 = (*f)(x0);
        }else{ printf("Interval input error!");break;}
        if(y0 == 0){answer = x0;break;}
        if(y0*y1<0){
            x2 = x0;
        }else{
            x1 = x0;
        }
        answer = x0;
    }while(fabs(y1-y2) > 1e-006 || count > 100);
    return answer;
}

/* 2矩阵转置（4分）

某二维数组存放的数据构成一个n*n的方阵，其中n<=5。写程序，从键盘输入n的值（n<=5），该n*n矩阵中各元素的值按下面的公式计算：
a[i][j] = i * n + j + 1
其中，a[i][j]表示第i行第j列的元素。要求分别输出该矩阵和它的转置矩阵。
注意：定义数字大小N时，请用
#define N 10

输入格式: "%d"
输出提示："The original matrix is:\n"
输出提示："The changed matrix is:\n"
输出格式： 矩阵的列与列之间为%3d,行与行之间为\n

输入样例1：
5↙
输出样例1：
The_original_matrix_is:
__1__2__3__4__5
__6__7__8__9_10
_11_12_13_14_15
_16_17_18_19_20
_21_22_23_24_25
The_changed_matrix_is:
__1__6_11_16_21
__2__7_12_17_22
__3__8_13_18_23
__4__9_14_18_24
__5_10_15_20_25

输入样例2：
4↙
输出样例2：
The original matrix is:
__1__2__3__4
__5__6__7__8
__9_10_11_12
_13_14_15_16
The changed matrix is:
__1__5__9_13
__2__6_10_14
__3__7_11_15
__4__8_12_16 */

#define N 10
#include <stdio.h>
void main()
{
    int n;
    int a[N][N];
    scanf("%d",&n);
    while(n>5){
        printf("Input error!n<=5,try again:");
        fflush(stdin);
        scanf("%d",&n);
    }
    printf("The original matrix is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] = i*n + j + 1;
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("The changed matrix is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",a[j][i]);
        }
        printf("\n");
    }
}


/* 3程序改错（4分）

下面程序的功能是从键盘任意输入n个数，然后找出其中的最大数与最小数，并将其位置对换。
目前程序中存在错误，请修改正确。并按照给出的程序运行结果示例检查修改后的程序。

程序运行结果示例1：
Input n(n<=10):
5↙
Input 5 Numbers:
12 4 6 7 0↙
After MaxMinExchange:
0 4 6 7 12

程序运行结果示例2：
Input n(n<=10):
6↙
Input 6 Numbers:
7 -3 2 0 56 18↙
After MaxMinExchange:
7 56 2 0 -3 18 */

#include  <stdio.h>
#define ARR_SIZE 10
int main()
{
	int a[ARR_SIZE], i, n;
	printf("Input n(n<=10):\n");
	scanf("%d", &n);
	printf("Input %d Numbers:\n", n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	MaxMinExchang(a, n);
	printf("After MaxMinExchange:\n");
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
void  MaxMinExchang(int *a, int n)
{
	int  maxValue = a[0], minValue = a[0], maxPos, minPos;
	int  i, temp;
	for (i=0; i<n; i++)
	{
		if (a[i] > maxValue)
		{
			maxValue = a[i];
			maxPos = i;
		}
		if (a[i] < minValue)
		{
			minValue = a[i];
			minPos = i;
		}
	} 
	temp = a[maxPos];
	a[maxPos] = a[minPos];
	a[minPos] = temp;
}
  
/* 输入提示信息："Input n(n<=10):\n"
                 "Input %d Numbers:\n"

输入格式: "%d"
输出格式："%d " (注意：%d后面有一个空格)
输出提示信息："After MaxMinExchange:\n" */

//这一题在前面课堂练习里面做过了

/* 4蛇形矩阵（4分）

从键盘任意输入一个自然数n（n表示矩阵的大小，假设不超过100），请编程输出一个n*n的蛇形矩阵。
如果输入的n不是自然数或者输入了不合法的数字，则输出"Input error!"。

函数原型： void ZigzagMatrix(int a[][N], int n);
函数功能：计算n*n的蛇形矩阵

提示：用两个双重循环分别计算n*n矩阵的左上三角和右下三角，设置一个计数器从1开始记录当前要写入矩阵的元素值，每次写完一个计数器加1，在计算左上角和右下角矩阵元素时，分奇数和偶数两种情况考虑待写入的元素在矩阵中的行列下标位置。

程序运行结果示例1：
Input n:
5↙
   1   2   6   7  15
   3   5   8  14  16
   4   9  13  17  22
  10  12  18  21  23
  11  19  20  24  25

程序运行结果示例2：
Input n:
4↙
   1   2   6   7
   3   5   8  13
   4   9  12  14
  10  11  15  16

程序运行结果示例3：
Input n:
-5↙
Input error!

程序运行结果示例4：
Input n:
105↙
Input error!

程序运行结果示例5：
Input n:
w↙
Input error!

输入提示信息："Input n:\n"
输入错误提示信息："Input error!\n"
输入格式： "%d"
输出格式："%4d"
数据换行： "\n" */

#define N 10
#include <stdio.h>
void ZigzagMatrix(int a[][N], int n);
void main()
{
    int n;
    int a[N][N] = {0};
    printf("Input n:");
    scanf("%d",&n);
    while(n>10){
        printf("Input error!n<=10,try again:");
        scanf("%d",&n);
    }
    ZigzagMatrix(a,n);
}

void ZigzagMatrix(int a[][N], int n){
    int count = 0;
    for(int k=0;k<n;k++){
        int i,j;
        for(int i=0;i<=k;i++){
            j = k - i;
            count++;
            if(k%2 != 0){ a[i][j] = count;}else{a[j][i] = count;}
        }

    }

    int q = 1;
    for(int k=n;k<=2*(n-1);k++){
        int i,j;
        for(i = q;i<=(n-1);i++){
            j = k - i;
            count++;
            if(k%2 != 0){ a[i][j] = count;}else{a[j][i] = count;}
        }
        q++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}


/* 5亲密数_1（4分）

2500年前数学大师毕达哥拉斯就发现，220与284两数之间存在着奇妙的联系：
220的真因数之和为：1+2+4+5+10+11+20+22+44+55+110=284
284的真因数之和为：1+2+4+71+142=220
毕达哥拉斯把这样的数对称为相亲数。相亲数，也称为亲密数，如果整数A的全部因子（包括1，不包括A本身）之和等于B，且整数B的全部因子（包括1，不包括B本身）之和等于A，则将整数A和B称为亲密数。

从键盘任意输入两个整数m和n，编程判断m和n是否是亲密数。若是亲密数，则输出“Yes!”，否则输出“No!”

程序运行示例1
Input m, n:
220,284↙
Yes!

程序运行示例2Input m, n:
224,280↙
No!

输入提示信息："Input m, n:\n"
输入格式: "%d,%d"
输出格式：
输出提示信息："Yes!\n"
              "No!\n" */

#include <stdio.h>
int CloseNumber(int m, int n);
void main()
{
    int m;
    int n;
    printf("Input m,n:");
    scanf("%d %d",&m,&n);
    int judge = CloseNumber(m,n);
    if(judge){printf("Yes!");}else{printf("No!");}
}

int CloseNumber(int m, int n){
    int sum_m = 0;
    int sum_n = 0;
    for(int i = 1;i<=m/2;i++){
        if(m%i==0){sum_m = sum_m + i;}
    }
    for(int j = 1;j<=n/2;j++){
        if(n%j==0){sum_n = sum_n + j;}
    }
    if(sum_m == n && sum_n == m){return 1;}else{return 0;}
}

			  
/* 6亲密数_2（4分）

2500年前数学大师毕达哥拉斯就发现，220与284两数之间存在着奇妙的联系：
220的真因数之和为：1+2+4+5+10+11+20+22+44+55+110=284
284的真因数之和为：1+2+4+71+142=220

毕达哥拉斯把这样的数对称为相亲数。
相亲数，也称为亲密数，如果整数A的全部因子（包括1，不包括A本身）之和等于B，且整数B的全部因子（包括1，不包括B本身）之和等于A，则将整数A和B称为亲密数。

从键盘任意输入一个整数n，编程计算并输出n以内的全部亲密数。

程序运行示例1
Input n:
3000↙
(220,284)
(1184,1210)
(2620,2924)

程序运行示例2
Input n:
1000↙
(220,284)

输入提示信息："Input n:\n"
输入格式: "%d"
输出格式： "(%d,%d)\n" */

#include <stdio.h>
int CloseNumber(int n);
void main()
{
    int n;
    printf("Input n:\n");
    scanf("%d",&n);
    int judge = CloseNumber(n);
    if(!judge){printf("No Close Number!");}
}

int CloseNumber(int n){
    int judge = 0;
    for(int i=1;i<n;i++){
        int sum_i = 0;
        int sum_k = 0;
        for(int j=1;j<=i/2;j++){
            if(i%j==0){sum_i = sum_i+j;}
        }
        for(int k=1;k<=sum_i/2;k++){
            if(sum_i%k==0){sum_k = sum_k+k;}
        }
        if(sum_k == i && sum_k < sum_i){printf("(%d,%d)\n",i,sum_i);judge = 1;}
    }
    return judge;
}


/* 7完全数（4分）

完全数（Perfect Number），又称完美数或完数，它是指这样的一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和，恰好等于它本身，即m的所有小于m的不同因子（包括1）加起来恰好等于m本身。
注意：1没有真因子，所以1不是完全数。计算机已经证实在10300以下，没有奇数的完全数。例如，因为6 = 1 + 2 + 3，所以6是一个完全数。

从键盘任意输入一个整数m，编程判断m是否是完全数。若m是完全数，则输出“Yes!”，并同时打印出每一个完美数的全部因子，以验证这个数确实是一个完美数。若m不是完全数，则输出“No!”

程序运行示例1
Input m:
28↙
Yes!
1,2,4,7,14

程序运行示例2
Input m:
6↙
Yes!
1,2,3

程序运行示例3
Input m:
1↙
No!

输入信息提示："Input m:\n"
输入格式: "%d"
输出格式：
输出格式： "%d"
输出信息提示："Yes!\n"
              "No!\n" */

#include <stdio.h>
int PerfectNumber(int m);
void main()
{
    int m;
    printf("Input m:\n");
    scanf("%d",&m);
    int judge = PerfectNumber(m);
    if(!judge){printf("No!\n");}else{printf("Yes!\n");}
}

int PerfectNumber(int m){
    int sum_i = 0;
    for(int i=1;i<=m/2;i++){
        if(m%2==0 && m%i==0){
            sum_i = sum_i + i;
            printf("%d ",i);
        }
    }
    printf("\n");
    if(sum_i == m){return 1;}else{return 0;}
}


/* 8回文素数（4分）

所谓回文素数是指对一个素数n，从左到右和从右到左读是相同的，这样的数就称为回文素数，例如11，101，313等。
编程计算并输出不超过n（100<=n<1000）的回文素数，并统计这些回文素数的个数，其中n的值从键盘输入。

程序运行示例1
Input n:
100↙
  11
count=1

程序运行示例2
Input n:
1000↙
  11 101 131 151 181 191 313 353 373 383 727 757 787 797 919 929
count=16

输入提示信息："Input n:\n"
输入格式:"%d"
输出格式：

回文素数的输出格式："%4d"
统计回文素数个数的输出格式： "\ncount=%d\n" */

#include <stdio.h>
#include <math.h>
#define N 10
int PalindromePrime(int n);
void main()
{
    int n;
    printf("Input n:\n");
    scanf("%d",&n);
    int count = PalindromePrime(n);
    if(count == 0){printf("No Palindrome Prime!\n");}
    else{printf("\ncount = %d",count);}
}

int PalindromePrime(int n){
    int count = 0;
    int a[N];
    for(int i=11;i<=n;i++){
        int flag = 1;
        int m = i;
        int digit = 0;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){flag = 0;}
        }
        if(!flag) continue;  //current number is not a prime,check the next number.
        do{                  //array a store each digit of the prime
            a[digit] = m%10;
            digit++;
            m/=10;
        }while(m != 0);
        //printf("digit = %d\n",digit);
        for(int k=0;k<digit/2;k++){
            if(a[k]!=a[digit-1-k]){flag = 0;break;}
        }
        if(flag == 1){count++;printf("%4d",i);}
    }
    return count;
}


/* 9梅森尼数（4分）

形如2^i-1的素数，称为梅森尼数。编程计算并输出指数i在[2,n]中的所有梅森尼数，并统计这些梅森尼数的个数，其中n的值由键盘输入，并且n的值不能大于50。
其中，2^i表示2的i次方，请不要使用pow(2,i)编程计算，应采用循环累乘求积的方式计算2^i。

提示：当i超过30以后，2^i-1的值会很大，不能用long型变量来存储，必须使用double类型来存储。对于double类型变量x（不是整型）不能执行求余运算，即不能用x%i == 0来判断x是否能被i整除，可以使用x/i == (int)(x/i)来判断x是否能被i整除。

程序运行示例
Input n:
50↙
2^2-1=3
2^3-1=7
2^5-1=31
2^7-1=127
2^13-1=8191
2^17-1=131071
2^19-1=524287
2^31-1=2147483647
2^49-1=562949953421311
count=9

输入提示信息："Input n:\n"
输入格式: "%d"
输出格式：
梅森尼数的输出格式： "2^%d-1=%.0lf\n"
统计梅森尼数个数的输出格式：  "count=%d\n" */

#include <stdio.h>
#include <math.h>
int MersennePrime(int n);
double PowerFunc(int base,int exponent);
void main()
{
    int n;
    printf("Input n:\n");
    scanf("%d",&n);
    int count = MersennePrime(n);
    if(count == 0){printf("No Mersenne Prime!\n");}
    else{printf("\ncount = %d",count);}
}

int MersennePrime(int n){
    int count = 0;
    for(int i=2;i<=n;i++){
        int flag = 1;
        double num = PowerFunc(2,i) - 1;
        for(long int j=2;j<=sqrt(num);j++){
            if(num/j == (int)(num/j)){flag = 0;break;}
        }
        if(!flag) {continue;}else{count++;printf("2^%d-1=%.0lf\n",i,num);}
    }
    return count;
}

double PowerFunc(int base,int exponent){
    double num = 1;
    for(int i=0;i<exponent;i++){
        num = num*base;
    }
    return num;
}


/* 10工资统计（4分）

某公司有职员（最多50人），试编写程序打印最高工资、最低工资和平均工资。
公司人数在主函数给出，职工工资输入请调用Input函数，计算最高工资、最低工资和平均工资调用Compute函数，打印最高工资、最低工资和平均工资在主函数。
请在给定的框架下写出完整程序。
*/

#include<stdio.h>
void Input(float wage[], int n);
float Compute(float wage[], int n, float *pmaxwage, float *pminwage);
int main()
{
    float wage[50],maxwage,minwage,avewage;
    int n;
    printf("Please input n:\n");
    scanf("%d",&n);
    Input(  ...  );     
    avewage=Compute(  ...  );
    printf("maxwage=%.2f, minwage=%.2f, avewage=%.2f\n",maxwage,minwage,avewage);
    return 0;
}

void Input(float wage[], int n)
{
     ...
}

float Compute(float wage[], int n, float *pmaxwage, float *pminwage)
{
	...
}

/* 序运行结果示例：
Please input n:
10
1200.34
2378.48
8600.56
5372.42
6317.25
7265.88
2156.39
1876.31
1792.14
4326.22
maxwage=8600.56, minwage=1200.34, avewage=4128.60

输入人数提示信息："Please input n:\n"
人数输入格式："%d"
工资输入格式："%f"
输出格式："maxwage=%.2f, minwage=%.2f, avewage=%.2f\n" */

#include <stdio.h>
void Input(float wage[], int n);
float Compute(float wage[], int n, float *pmaxwage, float *pminwage);
int main()
{
    float wage[50],maxwage,minwage,avewage;
    int n;
    printf("Please input n:\n");
    scanf("%d",&n);
    Input(wage,n);
    avewage=Compute(wage,n,&maxwage,&minwage);
    printf("maxwage=%.2f, minwage=%.2f, avewage=%.2f\n",maxwage,minwage,avewage);
    return 0;
}

void Input(float wage[], int n)
{
    for(int i=0;i<n;i++){
        scanf("%f",&wage[i]);
        fflush(stdin);
    }
}

float Compute(float wage[], int n, float *pmaxwage, float *pminwage)
{
    float sum = 0;
    *pmaxwage = wage[0];
    *pminwage = wage[0];
    for(int i=0;i<n;i++){
        if(*pmaxwage < wage[i]){*pmaxwage = wage[i];}
        if(*pminwage > wage[i]){*pminwage = wage[i];}
        sum = sum + wage[i];
        printf("i=[%d],max=%.2f\n",i,*pmaxwage);
    }
    return sum/n;
}

