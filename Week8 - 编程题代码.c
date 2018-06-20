
/* 第8周—— 一堆数据来了，你准备好了吗 */

/* 课堂例题 */
/* 计算最大值 - 先假设第一个数为最大值，一旦发现更大的，修改当前最大值 */

int FindMaxValue(int x[],int n){
	int maxValue,i;
	maxValue = x[0];
	for(i=1;i<n;i++){
		if(x[i]>maxValue){
			maxValue = x[i];
		}
	}
	return maxValue;
}

/* 二分查找 */
int Binsearch(long num[],long x,int n){
	int low = 0;high = n - 1,mid;
	while(low <= high){
		mid = (high + low) / 2;
		if(x > num[mid]){
			low = mid + 1;
		}else if(x > num[mid]{
			high = mid - 1;
		}else{
			return mid;
		}
	}
	return -1;
}
//防御式编程--存在的问题：如果数组很大，low和high之和大于有符号整数的极限值————发生数值溢出，使mid成为一个负数
//解决：修改计算中间值的方法，用减法代替加法：mid = low (high - low)/2

/* 冒泡法排序 */
void BubbleSort(int score[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=1;j<n-i;j++){
			if(score[j]<score[j-1]){
				temp = score[j];
				score[j] = score[j-1];
				score[j-1] = temp;
			}
		}
	}
}

/* 交换法排序 */
void ChangeSort(int score[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++{
			if(score[j]<score[i]){ //一旦发现更小的数就交换
				temp = score[j];
				score[j] = score[i];
				score[i] = temp;
			}
		}
	}
}

/* 选择法排序 */
void SelectionSort(int score[],int n){
	int i,j,k,temp;
	for(i=0;i<n-1;i++){
		k = i;
		for(j=i+1:j<n;j++){
			if(score[j]<score[k]){
				k=j;	//记录最小数下标位置
			}
		}
		if(k!=i){		//如果最小数不在下标位置
			temp = score[k];
			score[k] = score[i]'
			score[i] = temp;
		}
	}
}

//选择法和交换法的区别：选择法，找到最小的元素后再交换；交换法：只要有哪个数更小，就交换————交换次数更多

/* 课后编程题 */

/* 1摘苹果（4分）

陶陶家的院子里有一棵苹果树，每到秋天树上就会结出10个苹果。苹果成熟的时候，陶陶就会跑去摘苹果。陶陶有个30厘米高的板凳，当他不能直接用手摘到苹果的时候，就会踩到板凳上再试试。现在已知10个苹果到地面的高度（已知在100cm到200cm之间，包括100cm和200cm），以及陶陶把手伸直时能达到的最大高度（已知在100cm到120cm之间，包括100cm和120cm），请你编写程序帮助陶陶计算一下他能摘到的苹果数目。假设他碰到苹果，苹果就会掉下来。

函数原型：int GetApple(int a[], int height, int n)；
函数功能：计算淘淘能摘到的苹果数目
函数参数：数组a保存苹果到地面的高度；height代表陶陶把手伸直时能达到的最大高度；n为苹果数
函数返回值：淘淘能摘到的苹果数目

程序运行示例1：
100 200 150 140 129 134 167 198 200 111↙
110↙
5
程序运行示例2：
120 110 200 134 122 162 183 144 128 100↙
105↙
6

输入格式: "%d"
注意（第一行输入的数据是10个苹果分别到地面的高度；第二行输入的数据是陶陶把手伸直时能达到的最大高度）
输出格式："%d" */

#include <stdio.h>
#define N 10
int GetApple(int a[], int height, int n);
int main()
{
    int a[N] = {};
    int height;
    int n = N;
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    while(getchar() != '\n'){}
    scanf("%d",&height);
    if( height<100 || height > 120){
        printf("Input error,please enter again:");
        while(getchar() != '\n'){}
        scanf("%d",&height);
    }
    printf("%d",GetApple(a,height,n));
}

int GetApple(int a[], int height, int n){
    int count = 0;
    for(int i=0;i<n;i++){
        if(a[i]<=height+30){count++;}
    }
    return count;
}


/* 2好数对（4分）

已知一个集合A，对A中任意两个不同的元素求和，若求得的和仍在A内，则称其为好数对。例如，集合A={1 2 3 4}，1+2=3，1+3=4，则1,2和1,3 是两个好数对。编写程序求给定集合中好数对的个数。
注：集合中最多有1000个元素，元素最大不超过10000

程序运行示例1：
4↙
1 2 3 4↙
2
程序运行示例2：
7↙
2456 3251 654 890 100 754 1234↙
1

输入格式:"%d"
第一行：输入集合A的元素个数
第二行：输入A的各个元素，用空格隔开
输出格式："%d" */

#include <stdio.h>
#define N 1000

int main()
{
    int num;
    int a[N];
    int count = 0;
    scanf("%d",&num);
    if(num>1000){
        printf("Input error, please enter again: ");
        while(getchar() != '\n') {}
        scanf("%d",&num);
    }
    for(int i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    printf("finish input.\n");
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            for(int k=0;k<num;k++){
                if(a[i]+a[j] == a[k]){count++;}
            }
        }
    }
    printf("%d",count);
}


/* 组合三位数（4分）

将0到9这十个数字分成三个3位数，要求第一个3位数，正好是第二个3位数的1/2，是第三个3位数的1/3。问应当怎样分，编写程序实现。

输入格式: 无
输出格式："%d,%d,%d\n" （注意：输出的顺序为第一个3位数，第二个3位数，第三个3位数） */

#include <stdio.h>
#define N 9
int OK(int m,int a[]);
int main()
{
    int a[N];
    int m;      //the first number
    int count = 0;
    for(m=123;m<333;m++){
        if(OK(m,a)){
            count++;
            printf("NO.%d:%d%d%d,%d%d%d,%d%d%d\n",count,a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
        }
    }
}

int OK(int m,int a[]){
    int k = 1;
    for(int i=0;i<9;i+=3){     //m\m*2\m*3,numbers stored in the array
        a[i] = (m*k)/100;       //hundreds
        a[i+1] = (m*k)/10%10;   //tens
        a[i+2] = (m*k)%10;      //units
        //printf("m=%d:%d,%d,%d\n",m,a[i],a[i+1],a[i+2]);
        k++;
    }
    for(int i=0;i<8;i++){
        for(int j=(i+1);j<9;j++){
            if(a[i] == a[j]) return 0;
        }
    }
    return 1;
}



/* 4求100以内的最大素数（4分）

编程计算n(n<=500)以内的10个最大素数及其和，分别输出这最大的10个素数及其和。n的值要求从键盘输入。要求10个素数按从大到小的顺序输出。

程序运行示例1：
Input n(n<=500):10↙
     7     5     3     2
sum=17
程序运行示例2：
Input n(n<=500):100↙
    97    89    83    79    73    71    67    61    59    53
sum=732

输入提示信息："Input n(n<=500):"
输入格式: "%d"
10个最大素数的输出格式："%6d"
10个最大素数和的输出格式："\nsum=%d\n" */

#include <math.h>
#include <stdio.h>
#define N 10
void FindPrime(int n,int a[]);
int main()
{
    int a[N];
    int n;
    printf("Input n(n<=500):");
    scanf("%d",&n);
    if(n>500){
        printf("Input error!please enter again:");
        while(getchar()!= '\n'){}
        scanf("%d",&n);
    }
    FindPrime(n,a);
}

void FindPrime(int n,int a[]){
    int k = 0;
    int sum = 0;
    for(int i=n;i>1;i--){  //judge whether i is a prime or not
        int flag = 1;
        for(int j=2;j<=sqrt(i);j++){
            if(i==2){ }else if(i%j == 0) {flag = 0;break;}
        }
        if(flag == 1){    //if i is,k++,when k=10,break and print result
            a[k] = i;
            sum = sum + a[k];
            k++;
            if(k == 10) break;
            printf("%6d",i);
        }
    }
    printf("\nsum = %d\n",sum);
}


/* 1三天打渔两天晒网（4分）

中国有句俗语叫“三天打鱼两天晒网”，某人从1990年1月1日起开始“三天打鱼两天晒网”，即工作三天，然后再休息两天。问这个人在以后的某一天中是在工作还是在休息。从键盘任意输入一天，编程判断他是在工作还是在休息，如果是在工作，则输出：He is working，如果是在休息，则输出：He is having a rest，如果输入的年份小于1990或者输入的月份和日期不合法，则输出：Invalid input。

输入格式: "%4d-%2d-%2d"
输出格式：
"Invalid input" 或
"He is having a rest" 或
"He is working"

输入样例1：
2014-12-22
输出样例1：
He is working
输入样例2：
2014-12-24
输出样例2：
He is having a rest
输入样例3：
2014-12-32
输出样例3：
Invalid input */

#include <stdio.h>
int CountDays(int y,int m,int d);
int y_init = 1990;
int m_init = 1;
int d_init = 1;

int main()
{
    int y,m,d;
    printf("Input n(n<=500):");
    int valid_input_num = scanf("%4d-%2d-%2d",&y,&m,&d);
    if(y < 1990 || m <0 || m>12 || d <0 || d>31 || valid_input_num != 3){
        printf("Invalid input, please try again:");
        while(getchar()!='\n'){}
        valid_input_num = scanf("%4d-%2d-%2d",&y,&m,&d);
    }
    printf("cpuntdays = %d\n",CountDays(y,m,d));
    switch(CountDays(y,m,d)%5){
    case 1:
    case 2:
    case 3:printf("He is working");break;
    case 4:
    case 0:printf("He is having a rest");break;
    default:printf("error");
    }
}

int CountDays(int y,int m,int d){
    int days = 0;
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int leap_month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    for(int i=y_init;i<y;i++){
        if(i%400==0 || (i%4==0 && i%100!=0)){
            days = days+366;
        }else{
            days = days+365;
        }
    }
    for(int j=0;j<m-m_init;j++){
        if(y%400==0 || (y%4==0 && y%100!=0)){
            days = days+leap_month[m_init-1+j];
        }else{
            days = days+month[m_init-1+j];
        }

    }
    days = days + d + 1 - d_init;
    return days;
}


/* 2统计用户输入（4分）

从键盘读取用户输入直到遇到#字符，编写程序统计读取的空格数目、读取的换行符数目以及读取的所有其他字符数目。(要求用getchar()输入字符)

程序运行结果示例1：
Please input a string end by #:
abc def↙
jklm op↙
zkm #↙
space: 3,newline: 2,others: 15
程序运行结果示例2：
Please input a string end by #:
hello friend!#↙
space: 1,newline: 0,others: 12

输入提示信息："Please input a string end by #:\n"
输入格式: getchar()
输出格式： "space: %d,newline: %d,others: %d\n" */

#include <stdio.h>
#define N 1000
int main()
{
    int space = 0;
    int newline = 0;
    int others = 0;
    int i = -1;
    int a[N];
    printf("Please input a string end by #:\n");
    do{
        i++;
        a[i] = getchar();
        if(a[i]==' '){
            space++;
        }else if(a[i]=='\n'){
            newline++;
        }else if(a[i]!='#'){others++;}
    }while(a[i]!='#');
    printf("space: %d,newline: %d,others: %d\n",space,newline,others);
}


/* 统计正整数中指定数字的个数（4分）

从键盘输入一个正整数number，求其中含有指定数字digit的个数。例如：从键盘输入正整数number=1222,若digit=2，则1223中含有 3个2，要求用函数实现。函数原型为：int CountDigit(int number,int digit)；

程序运行结果示例1：
Input m,n:
1222,2↙
3
程序运行结果示例2：
Input m,n:
1234,6↙
0

输入提示信息："Input m,n:\n"
输入格式: "%d,%d"
输出格式： "%d\n" */

#include <stdio.h>
#define N 100
int a[N];
int PowerFunc(int base,int exponent);
int CountDigit(int number,int digit);
int main()
{
    int number,digit;
    printf("Input m,n:\n");
    scanf("%d %d",&number,&digit);
    while(digit<0||number<0){
        printf("Input error,try again:");
        while(getchar()!='\n'){}
        scanf("%d %d",&number,&digit);
    }
    printf("%d\n",CountDigit(number,digit));
}

int CountDigit(int number,int digit){
    int count = 0;
    int significand = 1;
    int copy;
    copy = number;
    while(copy/10!=0){
        significand++;
        copy = copy/10;
    }
    //printf("significand: %d\n",significand);
    for(int i=0;i<significand;i++){
        a[i] = number%PowerFunc(10,significand-i)/PowerFunc(10,significand-i-1);
        if(a[i]==digit){count++;}
    }
    return count;
}

int PowerFunc(int base,int exponent){
    int result = 1;
    for(int i=0;i<exponent;i++){
        result = base*result;
    }
    return result;
}


/* 4玫瑰花数（4分）

如果一个n位正整数等于它的n个数字的n次方和，则称该数为n位自方幂数。四位自方幂数称为玫瑰花数。编程计算并输出所有的玫瑰花数。

输入格式:无
输出格式："%d\n" */

#include <stdio.h>
#define N 100
int PowerFunc(int base,int exponent);
int main()
{
    int a[N];
    int i = 0;
    for(int num = 1000;num<10000;num++){
        int thousands = num%10000/1000;
        int hundreds = num%1000/100;
        int tens = num%100/10;
        int units = num%10;
        int biquadrate_sum = PowerFunc(thousands,4)+PowerFunc(hundreds,4)+PowerFunc(tens,4)+PowerFunc(units,4);
        //printf("thousands = %d,biquadrate = %d\n",thousands,PowerFunc(thousands,4));
        //printf("num = %d,biquadrate_sum = %d\n",num,biquadrate_sum);
        if(biquadrate_sum == num){
            a[i] = num;
            i++;
        }
    }
    for(int j=0;j<i;j++){
        printf("%d\n",a[j]);
    }
}

int PowerFunc(int base,int exponent){
    int result = 1;
    for(int i=0;i<exponent;i++){
        result = base*result;
    }
    return result;
}


/* 5四位反序数（4分）

反序数就是将整数的数字倒过来形成的整数。例如，1234的反序数是4321。设N是一个四位数，它的9倍恰好是其反序数，编程计算并输出N的值。

输入格式: 无
输出格式："%d\n" */

#include <stdio.h>
#define N 10
int main()
{
    int a[N];
    int i = 0;
    for(int num = 1000;num<1111;num++){
        int thousands = num%10000/1000;
        int hundreds = num%1000/100;
        int tens = num%100/10;
        int units = num%10;
        int inverted_num = thousands + hundreds*10 + tens*100 + units*1000;
        if(num*9 == inverted_num){
            a[i] = num;
            i++;
        }
    }
    for(int j=0;j<i;j++){
        printf("%d\n",a[j]);
    }
}


/* 6除不尽的自然数（4分）

一个自然数被8除余1，所得的商被8除也余1，再将第二次的商被8除后余7，最后得到一个商为a。又知这个自然数被17除余4，所得的商被17除余15，最后得到一个商是a的2倍。求满足以上条件的最小自然数。

输入格式: 无
输出格式："%d\n" */

#include <stdio.h>
int main()
{
    int num = 15;
    int flag = 0;
    do{
        int first_quotient = num/8;
        int second_quotient = first_quotient/8;
        int third_quotient = second_quotient/8;
        int first_quotient_2 = num/17;
        int second_quotient_2 = first_quotient_2/17;
        if(num%8==1 && first_quotient%8==1 && second_quotient%8==7
           && num%17==4 && first_quotient_2%17==15 && second_quotient_2 == third_quotient*2)
           {
               flag = 1;
           }else{num++;}
    }while(flag == 0);
    printf("%d\n",num);
}


/* 7矩阵转置v1.0（4分）

用二维数组作为函数参数，编程计算并输出n×n阶矩阵的转置矩阵。其中，n的值不超过10，n的值由用户从键盘输入。

程序运行结果示例1：
Input n:3↙
Input 3*3 matrix:
1 2 3↙
4 5 6↙
7 8 9↙
The transposed matrix is:
   1   4   7
   2   5   8
   3   6   9

程序运行结果示例2：
Input n:2↙
Input 2*2 matrix:
1 2↙
4 5↙
The transposed matrix is:
   1   4
   2   5

输入提示信息：
提示输入矩阵的阶数："Input n:"
提示输入矩阵数据："Input %d*%d matrix:\n"
输入格式: "%d"
输出提示信息："The transposed matrix is:\n"
输出格式："%4d" */

#include <stdio.h>
#define N 10
int main()
{
    int a[N][N];
    int n;
    printf("Input n:");
    scanf("%d",&n);
    while(n>10){
        printf("Input error,try agian(n<=10):");
        while(getchar()!='\n'){}
        scanf("%d",&n);
    }
    printf("Input %d*%d matrix:\n",n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
		while(getchar()!='\n') {}
    }
    printf("The transposed matrix is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%4d",a[j][i]);
        }
        printf("\n");
    }
}


/* 8兔子生崽问题（4分）

假设一对小兔的成熟期是一个月，即一个月可长成成兔，那么如果每对成兔每个月都可以生一对小兔，一对新生的小兔从第二个月起就开始生兔子，试问从一对兔子开始繁殖，n(n<=12)月以后可有多少对兔子（即当年第n月份总计有多少对兔子，含成兔和小兔）？请编程求解该问题，n的值要求从键盘输入。

参考答案：依题意，兔子的繁殖情况如图所示。图中实线表示成兔仍是成兔或者小兔长成成兔；虚线表示成兔生小兔。观察分析此图可发现如下规律：

（1）每月小兔对数 = 上个月成兔对数。
（2）每月成兔对数 = 上个月成兔对数 + 上个月小兔对数。
综合（1）和（2）有：每月成兔对数 = 前两个月成兔对数之和。

用fn（n=1，2，…）表示第n个月成兔对数，于是可将上述规律表示为如下递推公式：
f1 = 1		(n=1)
f2 = 1		(n=2)
fn = f(n-1) + f(n-2) (n>=3)

程序运行示例：
Input n(n<=12):
10↙
   1   2   3   5   8  13  21  34  55  89
Total=89

输入提示："Input n(n<=12):\n"
输入格式:"%d"
输出格式：
每个月兔子对数的输出格式：  "%4d"
第12个月的兔子总数的输出格式：  "\nTotal=%d\n" */

//注意：递推公式计算的是成兔对数，不是兔子总数
//兔子总数 = 这个月成兔对数 + 小兔对数（上个月成兔对数）

#include <stdio.h>
#define N 100
int a[N];
void Fibonaci(int n);
int main(){
    int n;
    printf("Input n(n<=12):\n");
    scanf("%d",&n);
    Fibonaci(n);
}

void Fibonaci(int n){
    for(int i=0;i<n;i++){
        if(i==0 || i==1){
            a[i] = 1;
        }else{
            a[i]=a[i-1]+a[i-2];
        }
    }
    for(int i=0;i<n;i++){
        printf("%4d",a[i]+a[i-1]);
    }
    printf("\nTotal=%d\n",a[n-1]+a[n-2]);
}

/* 9抓交通肇事犯（4分）

一辆卡车违犯交通规则，撞人后逃跑。现场有三人目击事件，但都没记住车号，只记下车号的一些特征。甲说：牌照的前两位数字是相同的；乙说：牌照的后两位数字是相同的，但与前两位不同；丙是位数学家，他说：四位的车号刚好是一个整数的平方。现在请根据以上线索帮助警方找出车号以便尽快破案。

[提示]：假设这个4位数的前两位数字都是i，后两位数字都是j，则这个可能的4位数
k = 1000*i + 100*i + 10*j + j
式中，i和j都在0～9变化。此外，还应使k=m*m，m是整数。由于k是一个4位数，所以m值不可能小于31。

输入格式: 无
输出格式："k=%d,m=%d\n" */

#include <stdio.h>
int main(){
    int k;
    int m;
    int flag = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(m=32;m<100;m++){
                k = 1000*i + 100*i + 10*j + j;
                if(k == m*m){
                    flag = 1;
                    printf("k=%d,m=%d\n",k,m);break;
                }
            }
            if(flag == 1){break;}
        }
        if(flag == 1){break;}
    }
}


/* 10检验并打印幻方矩阵（4分）

幻方矩阵是指该矩阵中每一行、每一列、每一对角线上的元素之和都是相等的。从键盘输入一个5×5的矩阵并将其存入一个二维整型数组中，检验其是否为幻方矩阵，并将其按指定格式显示到屏幕上。

输入格式: "%d"
输出格式：

如果是幻方矩阵，输出提示信息: "It is a magic square!\n"
矩阵元素的输出： "%4d"（换行使用"\n"）
如果不是幻方矩阵，输出提示信息: "It is not a magic square!\n"

输入样例1：
17 24 1 8 15
23 5 7 14 16
4 6 13 20 22
10 12 19 21 3
11 18 25 2 9

输出样例1：
It is a magic square!
**17**24***1***8**15
**23***5***7**14**16
***4***6**13**20**22
**10**12**19**21***3
**11**18**25***2***9
(输出样例中“*”代表空格)

输入样例2：
1 0 1 6 1
3 1 1 1 1
1 1 1 1 2
1 1 1 1 1
9 1 7 1 1

输出样例2：
It is not a magic square! */

#include <stdio.h>
#define N 5
int main(){
    int a[N][N];
    int flag = 1;
    int sum_row[5] = {0};
    int sum_column[5] = {0};
    int sum_diagonal[2] = {0};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&a[i][j]);
        }
        while(getchar()!='\n'){}
    }
    for(int i=0;i<N;i++){  //judge columns and rows
        for(int j=0;j<N;j++){
            sum_row[i] = a[i][j]+sum_row[i];
            sum_column[i] = a[j][i]+sum_column[i];
            if(i==j){
                sum_diagonal[0] = sum_diagonal[0]+a[i][j];
            }
            if(i+j==4){
                sum_diagonal[1] = sum_diagonal[1]+a[i][j];
            }
        }
        if(sum_row[i]!=sum_row[0] || sum_column[i]!=sum_row[0]){
            flag = 0;
        }
        //printf("sum_row = %d\n",sum_row[i]);
        //printf("sum_column = %d\n",sum_column[i]);
    }
    if(sum_diagonal[0]!= sum_row[0] || sum_diagonal[1]!=sum_row[0]){ //judge diagonal
       flag = 0;
       }
    //printf("sum_diagonal_1 = %d,sum_diagonal_2 = %d\n",sum_diagonal[0],sum_diagonal[0]);
    if(flag == 1){
        printf("It is a magic square!\n");
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                printf("%4d",a[i][j]);
            }
        printf("\n");
    }
    }else{printf("It is not a magic square!");}
}

