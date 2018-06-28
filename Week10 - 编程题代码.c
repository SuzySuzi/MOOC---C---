
/* 第10周——字符串：C语言世界中的大力水手 */

/* 课堂例题 */ 

/* 见证奇迹的时刻——Mission Impossible */
/* 源程序（不要添加任何空格和换行）
main(){char*a="main(){char*a=%c%s%c;printf(a,34,a,34);}";printf(a,34,a,34);}
这个程序的运行结果与源代码完全一样，你能解释这个运行结果吗？ */

我是通过逐步增加printf函数中的参数的方式，看看每个参数对程序运行结果的影响：

STEP 1 
运行：main(){char*a="main(){char*a=%c%s%c;printf(a,34,a,34);}";printf(a);}
打印结果：main(){char*a=@?a?printf(a,34,a,34);}

分析：a是一个字符类型的指针 - char * a，指向的字符串是 "main(){char*a=%c%s%c;printf(a,34,a,34);}"，
暂且将这个字符串代入到printf函数中，相当于%c%s%c等格式符都没有参数的打印语句

运行：printf("main(){char*a=%c%s%c;printf(a,34,a,34);}");
打印结果：main(){char*a= €;printf(a,34,a,34);}

STEP 2
运行：main(){char*a="main(){char*a=%c%s%c;printf(a,34,a,34);}";printf(a,34);}
打印结果：main(){char*a="?a?printf(a,34,a,34);}

分析：?前的@变成了"，说明，%c对应是34，说明ANSCII值34对应的字符是"；其他没有变化；

STEP 3
运行：main(){char*a="main(){char*a=%c%s%c;printf(a,34,a,34);}";printf(a,34,a);}
打印结果：main(){char*a="main(){char*a=%c%s%c;printf(a,34,a,34);}?printf(a,34,a,34);}

分析：留意代码中%s后至?前的位置，被这一串字符替代：main(){char*a=%c%s%c;printf(a,34,a,34);}
这个说明a指针确实指向这一串字符

STEP 4
运行：main(){char*a="main(){char*a=%c%s%c;printf(a,34,a,34);}";printf(a,34,a,34);}
打印结果：main(){char*a="main(){char*a=%c%s%c;printf(a,34,a,34);}";printf(a,34,a,34);}

分析：对比STEP 3，发现STEP 3运行结果?处换成了"，还多出了一个;
说明，%c对应打印了"

总结：
1、第一个a作为printf的第一个参数，用a指向的字符串描述需要打印的语句
2、后面的34、a、34都作为打印语句中格式符对应的参数
3、%c格式符对应两个34，打印两个""
4、%s格式符对应a，再打印了一遍a指向的字符串

***还不明白的点有：
Q1：为什么printf语句第一个参数输入的是指针类型的变量，printf函数会读取指针指向的字符串带入？
A1：printf函数原型如下，说明函数本来第一个参数就是常字符指针，ok
extern int printf(const char *format,...);
Q2：在格式符%c%s%c没有对应输入参数的时候，按照什么规则，打印出了：@ ?a? 这些字符？


/* 计算字符串的长度
这两个版本的函数有什么区别吗？都能实现计算字符串长度吗？*/

//版本1：
unsigned int  MyStrlen(const char *pStr)
{
  const char *start = pStr;
  while (*pStr) 
  {
      pStr++;
  }
  return pStr - start;           
}

//版本2：
unsigned int  MyStrlen(const char *pStr)
{
  const char *start = pStr;
  while (*pStr++) 
  {
      ;
  }
  return pStr - start;           
}

//版本1，当指针不为结束字符，执行pStr++，即，当 *pStr == '\0'，pStr不再自增，此时pStr指向字符串末尾的空字符；返回的值等于实际字符串长度。
//版本2，不同在于，当 *pStr == '\0'，pStr多自增1，此时pStr指向字符串末尾空字符的下一个存储空间；返回的值等于实际字符串的长度+1。
 
 /* 字符串连接
请分析下面的程序错在哪里？找到错误的原因后，请修改这个错误。 */

#include <stdio.h>
#include <string.h>
int main(void)
{
        char *first, *second, *result; //pointer variables are not assigned a value!wrong here.
        printf("Input the first string:");
        gets(first);
        printf("Input the second string:");
        gets(second);
        result = MyStrcat(first, second);
        printf("The result is : %s\n", result);
        return 0;
}
char* MyStrcat(char *dest, char *source) //string source connect to the end of string dest
{
        int i = 0;
        while (*(dest+i)!='\0')   i++; //i:length of dest string
        for (; *(source+i)!='\0'; i++) //i:length of source string?but i start from length(dest)! something wrong here.
        {
            *(dest+i) = *(source+i);   
        }
		//there is no sign to mark the end of the string
        return dest; //the pointer dest not longer point to the begin of the string dest!wrong here. 
}

//修改后
#include <stdio.h>
#include <string.h>
#define N 50
char* MyStrcat(char *dest, char *source);
int main(void)
{
        char *first, *second, *result;
        char a[N];
        char b[N];
        first = a;
        second = b;
        printf("Input the first string:");
        gets(first);  //get a string
        printf("Input the second string:");
        gets(second);
        result = MyStrcat(first, second);
        printf("The result is : %s\n", result);
        return 0;
}
char* MyStrcat(char *dest, char *source) //string source connect to the end of string dest
{
        int i = 0;
		int j = 0;
		char *start = dest;
        while (*(dest+i)!='\0')   i++;
        for (; *(source+j)!='\0'; j++)
        {
            *(dest+i+j) = *(source+j);
        }
        *(dest+i+j) = '\0';
        return start;
}

/* 缓冲区溢出实例 - 1 */
#include <stdio.h>
#include <string.h>
int main(void)
{
    char password[8]="secret", input[8];
    while(1){
        printf("Enter your password:");
        //gets(input);  //not a safe function.No limit of input string
        scanf("%7s",input); //safe.Add length limit
        //fgets(input,sizeof(input),stdin); 
        //for(i=0;input[i]!='\n';i++){;}
        //input[i]='\0';
        if(strcmp(input,password)==0){
            printf("Welcome!\n");
            break;
        }else{
            printf("Sorry!\n");
        }
    }
    return 0;
}

/* 防止缓冲区溢出：
1、使用更安全（限制字符串长度、检查数组越界）的字符串处理函数：fgets()、strncpy()、strncat()
2、向内存写入数据前确认内存是否可以写入，同时检查写入的数据是否超过这块内存的大小 */

/* 缓冲区溢出实例 - 2 错误实例 */

#include <stdio.h>
int main(void)
{
    char a,b,c,d; 
    scanf("%c%c%d,%d",&a,&b,&c,&d);
    printf("%c,%c,%c,%c",a,b,c,d);
    return 0;
}

//编译器为c d只分配了一个字节
//以整型格式读入时，又分配了4个字节，发生了缓冲区溢出溢出
//启示：不要忽略warning

/* 打印杨辉三角形
请分析下面的程序错在哪里？找到错误的原因后，请修正这个错误。 */

#include<stdio.h>
#define  ARR_SIZE  5
void  YH(int a[][ARR_SIZE], int  n);
void  PrintYH(int a[][ARR_SIZE], int  n);
int main(void)
{
        int  a[ARR_SIZE][ARR_SIZE];
        YH(a, ARR_SIZE);
        PrintYH(a, ARR_SIZE);
        return 0;
}

void YH(int a[][ARR_SIZE], int n)
{
        int  i, j ;
        for (i=1; i<=n; i++)  //i range [1,5]. Index out of bounds
        {  
             a[i][1] = 1;
             a[i][i] = 1;
        }
         for (i=3; i<=n; i++)
        {
            for (j=2; j<=i-1; j++)
            {
                 a[i][j] = a[i-1][j-1] + a[i-1][j];
            }       
        }
}

void PrintYH(int a[][ARR_SIZE], int n)
{
        int i , j ;
        for (i=1; i<n; i++)
        {
            for (j=1; j<=i; j++)
            {
                printf("%4d", a[i][j]);
            }
             printf("\n");
        }
}

//错在数组越界：for (i=1; i<=n; i++)  //i range [1,5]. Index out of bounds
//修改后的程序
#include<stdio.h>
#define  ARR_SIZE  5
void  YH(int a[][ARR_SIZE], int  n);
void  PrintYH(int a[][ARR_SIZE], int  n);

int main(void)
{
	int  a[ARR_SIZE][ARR_SIZE] = {0};  //a[5][5]
	YH(a, ARR_SIZE);
	PrintYH(a, ARR_SIZE);
	return 0;
}

void YH(int a[][ARR_SIZE], int n)
{
	int  i, j ;
	for (i=0; i<n; i++) 
	{
		 a[i][0] = 1;
		 a[i][i] = 1;
	}
	 for (i=2; i<n; i++)
	{
		for (j=1; j<=i-1; j++)
		{
			 a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
}

void PrintYH(int a[][ARR_SIZE], int n)
{
	int i , j ;
	for (i=0; i<n; i++)
	{
		printf("第%d行",i);
		for (j=0; j<=i; j++)
		{
			printf("%4d", a[i][j]);
		}
		 printf("\n");
	}
}


/* 鸡蛋里挑骨头——口令检查程序的继续修改
缓冲区溢出与缓冲区溢出攻击视频（ppt第8页）中的这个程序在输入secret123时还是有错误，请分析为什么会出错，同时思考如何修改这个程序，使其在输入secret123时不会出错。 */

#include <stdio.h>
#include <string.h>
int main()
{
	char password[8] = "secret\n", input[8];
	while (1)
	{
		printf("Enter your password:");
		fgets(input, sizeof(input), stdin);
		if (strcmp(input, password) ==0)
		{
		printf("Welcome!\n");
		break;
		}
		else
		{
		printf("Sorry!\n");
		}
	}
	return 0;
}

/* 运行发现，程序的问题只在于，打印了两遍sorry
通过debug发现：
输入secret123，fgets函数先读走了secret1，和原字符串对比不一致，输出sorry；
还余下23\n等字符在缓冲区中，函数再次读走，和原字符串对比不一致，再次输出sorry；
解决方法，在fgets前先把缓冲区已有的字符读走，在fgets语句前添加：fflush(stdin); */


/* 课后编程题 */

/* 1数字字符串转换为整型数（4分）

从键盘输入一串字符（假设字符数少于8个），以回车表示输入结束，编程将其中的数字部分转换为整型数并以整型的形式输出。   
函数原型为 int Myatoi(char str[]);
其中，形参数组str[]对应用户输入的字符串，函数返回值为转换后的整型数。

解题思路的关键是：1）判断字符串中的字符是否是数字字符；2）如何将数字字符转换为其对应的数字值；3）如何将每一个转换后的数字值加起来形成一个整型数。

程序运行结果示例1：
Input a string:7hg09y↙
709
程序运行结果示例2：
Input a string:9w2k7m0↙
9270
程序运行结果示例3：
Input a string:happy↙
0

输入提示信息："Input a string:"
输入格式: "%7s"
输出格式："%d\n" */

#include <stdio.h>
#define N 8
int Myatoi(char str[]);
int main()
{
    char str[N];
    int num;
    printf("Input a string:");
    scanf("%7s",str);
    //printf("%s\n",str);
    num = Myatoi(str);
    printf("%d\n",num);
    //printf(" 0 = %d\n",'0');
    //printf(" 9 = %d\n",'9');
	return 0;
}

int Myatoi(char str[]){
    int num = 0;
    int length = 0;
    char *start = str;
    while(*str){length++;str++;}
    //printf("%d\n",length);
    for(int i=0;i<length;i++){
        if(*start>=48 && *start<=57){
            num = num*10 + (*start-48);
        }
        start++;
    }
    return num;
}


/* 2查找子串（4分）

用字符数组作函数参数，编程实现在从键盘输入的字符串（假设长度小于80）中查找与指定的子串，并输出该子串在字符串中首次出现的位置，如果该字符不存在，则输出"Not found!"。

函数原型：int SearchString(char s[], char d[])

函数功能：在字符数组s中查找子串d，返回d在s中首次出现的位置，若找不到，则返回-1。

程序运行结果示例1：
Input a string:How are you!↙
Input another string:are↙
Searching results:5

程序运行结果示例2：
Input a string:hello↙
Input another string:are↙
Not found!

程序运行结果示例3：
Input a string:You are a student.↙
Input another string:you↙
Not found!

输入第一个字符串的提示信息："Input a string:"
输入第二个字符串的提示信息："Input another string:"
输入格式： gets()
输出格式："Searching results:%d\n"
没找到子串的输出提示信息： "Not found!\n" */

#include <stdio.h>
#define N 80
int SearchString(char s[], char d[]);
int main()
{
    char s[N];
    char d[N];
    int result;
    printf("Input a string:");
    gets(s);
    printf("Input another string:");
    gets(d);
    result = SearchString(s,d);
    if(result == -1){
            printf("Not found!\n");
    }else{
        printf("Searching results:%d\n",result);
    }
	return 0;
}

int SearchString(char s[], char d[]){
    char *source = s;
    char *dest = d;
    int pos = -1;
    int s_length = 0;
    int d_length = 0;
    while(*source){s_length++;source++;}
    while(*dest){d_length++;dest++;}
    if(d_length>s_length){return -1;}
    for(int i=0;i<=s_length-d_length;i++){
        for(int j=0;j<d_length;j++){
            if(*(s+i+j) != *(d+j)){break;}
            if(j==d_length-1 && *(s+i+j) == *(d+j)){
                pos = i+1;
            }
        }
        if(pos!=-1){break;}
    }
    return pos;
}


/* 3统计重复字符（4分）

输入一串字符（字符数小于80），以回车表示输入结束，编程计算并输出这串字符中连续重复次数最多的字符和重复次数。如果重复次数最多的字符有两个，则输出最后出现的那一个。

已知函数原型：
//函数功能：统计字符串中连续重复次数最多的字符及其重复的次数
//函数参数：str指向待统计的字符串，指针形参tag返回重复字符最后出现的下标位置 
//函数返回值：返回字符重复的次数
int CountRepeatStr(char str[], int *tag);

求解思路：设置一个计数器，遍历字符串中的所有字符，若str[i] == str[i+1]，则计数器加1，同时判断计数器的值是否大于记录的最大重复次数max，若大于，则用计数器的值更新max，并记录该字符最后出现的位置i+1.若str[i] != str[i+1]，则计数器重新初始化为1。遍历结束时，函数返回max的值。

程序运行结果示例1：
Input a string:
2344455555↙
5:5

程序运行结果示例2：
Input a string:
sgf222257↙
2:4

输入提示信息："Input a string:\n"
输入格式:  用gets()输入字符串
输出格式："%c:%d\n" */

#include <stdio.h>
#define N 80
int CountRepeatStr(char str[], int *tag);
int main()
{
    char str[N];
    int pos;
    int *tag;
    tag = &pos;
    int max = 0;
    printf("Input a string:\n");
    gets(str);
    max = CountRepeatStr(str,tag);
    printf("%c:%d\n",str[pos],max);
	return 0;
}

int CountRepeatStr(char str[], int *tag){
    int max = 1;
    int count = 1;
    for( int i=0;str[i]!='\0';i++){
        if(str[i] == str[i+1]){
            count++;
            if(count>max){
                    max = count;
                    *tag = i;
            }
        }else{count = 1;}
    }
    return max;
}


/* 4凯撒密码（4分）

凯撒密码是罗马扩张时期朱利斯•凯撒（Julius Caesar）创造的，用于加密通过信使传递的作战命令，其原理很简单，就是通过将字母表中的字母移动一定位置而实现加密。
例如，每个字母按字母表顺序向后移3位，如a加密后变成d，b加密后变成e，……x加密后变成a，y加密后变成b，z加密后变成c。
请编写一个程序，将用户从键盘输入的文本字符串（只包含a～z的字符且长度小于100）进行加密后输出。

函数原型：void Caesar(char c[]);
函数功能：计算凯撒密码

程序的运行结果示例1：
Input a string:baidu↙
edlgx
程序的运行结果示例2：
Input a string:xyz↙
abc

输入提示信息："Input a string:"
输入格式: 用 gets()函数
输出格式：用 puts()函数 */

#include <stdio.h>
#define N 100
void Caesar(char c[]);
int main()
{
    char c[N];
    printf("Input a string:");
    gets(c);
    Caesar(c);
    //printf("a = %d\n",'a'); //a:97
    //printf("z = %d\n",'z'); //z:122
    puts(c);
	return 0;
}

void Caesar(char c[]){
    for(int i=0;c[i]!='\0';i++){
        if(c[i]<97||c[i]>122){printf("Input error!\n");break;}
        c[i]=c[i]+3;
        if(c[i]>122){c[i]-=26;}
    }
}



/* 1有趣的“回文”检测（4分）

英文中有很多的回文词，回文词的拼法十分有趣，无论是从前往后拼读，还是从后往前拼读，他们的拼法和词义都不变。
例如：dad（爸爸），mum（妈妈），noon（中午），eve（前夕），eye（眼睛），pop（流行），deed（行为），level（水平）等。
简单地说，“回文”就是指顺读和倒读都一样的字符串。现在请你编程输入一个单词，判断它是否是回文。

提示：
（1）设置两个指针pStart和pEnd，让pStart指向字符串首部，让pEnd指向字符串尾部。
（2）利用循环从字符串两边对指针所指字符进行比较，当对应的两字符相等且两指针未超越对方时，使指针pStart向前移动一个字符位置（加1），使指针pEnd向后移动一个字符位置（减1），一旦发现两字符不等或两指针已互相超越（不可能是回文），则立即停止循环。
（3）根据退出循环时两指针的位置，判断字符串是否为回文。

程序的两次运行结果如下：
第1次
Input string:ABCCBA↙
Yes!
第2次
Input string:student↙
No!

输入提示信息："Input string:"
输入格式: 用gets()函数
输出格式：
输出信息，不是回文："No!\n"
输出信息，是回文："Yes!\n" */

#include <stdio.h>
#define N 100
int PalindromeDetection(char *str);
int main()
{
    char str[N];
    int result;
    printf("Input string:");
    gets(str);
    result = PalindromeDetection(str);
    if(result){printf("Yes!\n");}else{printf("No!\n");}
	return 0;
}

int PalindromeDetection(char *str){
    int result = 1;
    char *pStart = str;
    int i;
    for(i=0;str[i]!=0;i++){;}
    char *pEnd = &str[i-1];
    for(int j=0;j<i;j++){
        if(pStart > pEnd){break;}
        if(*pStart != *pEnd){result = 0;break;}
        pStart++;
        pEnd--;
    }
    return result;
}


/* 2学生成绩管理系统V1.0（4分）

某班有最多不超过30人（具体人数由键盘输入）参加某门课程的考试，用一维数组作函数参数编程实现如下学生成绩管理：
（1）录入每个学生的学号和考试成绩；
（2）计算课程的总分和平均分；
（3）按成绩由高到低排出名次表；
（4）按学号由小到大排出成绩表；
（5）按学号查询学生排名及其考试成绩；
（6）按优秀（90~100）、良好（80~89）、中等（70~79）、及格（60~69）、不及格（0~59）5个类别，统计每个类别的人数以及所占的百分比；
（7）输出每个学生的学号、考试成绩。

程序运行结果示例：
Input student number(n<30):
6↙

Management for Students' scores
1.Input record
2.Caculate total and average score of course
3.Sort in descending order by score
4.Sort in ascending order by number
5.Search by number
6.Statistic analysis
7.List record
0.Exit
Please Input your choice:
1↙
Input student's ID, name and score:
11003001 87↙
11003005 98↙
11003003 75↙
11003002 48↙
11003004 65↙
11003006 100↙

Management for Students' scores
1.Input record
2.Caculate total and average score of course
3.Sort in descending order by score
4.Sort in ascending order by number
5.Search by number
6.Statistic analysis
7.List record
0.Exit
Please Input your choice:
2↙
sum=473,aver=78.83

Management for Students' scores
1.Input record
2.Caculate total and average score of course
3.Sort in descending order by score
4.Sort in ascending order by number
5.Search by number
6.Statistic analysis
7.List record
0.Exit
Please Input your choice:
3↙
Sort in descending order by score:
11003006	100
11003005	98
11003001	87
11003003	75
11003004	65
11003002	48

Management for Students' scores
1.Input record
2.Caculate total and average score of course
3.Sort in descending order by score
4.Sort in ascending order by number
5.Search by number
6.Statistic analysis
7.List record
0.Exit
Please Input your choice:
4↙
Sort in ascending order by number:
11003001	87
11003002	48
11003003	75
11003004	65
11003005	98
11003006	100

Management for Students' scores
1.Input record
2.Caculate total and average score of course
3.Sort in descending order by score
4.Sort in ascending order by number
5.Search by number
6.Statistic analysis
7.List record
0.Exit
Please Input your choice:
5↙
Input the number you want to search:
11003004
11003004	65

Management for Students' scores
1.Input record
2.Caculate total and average score of course
3.Sort in descending order by score
4.Sort in ascending order by number
5.Search by number
6.Statistic analysis
7.List record
0.Exit
Please Input your choice:
6↙
<60	1	16.67%
60-69	1	16.67%
70-79	1	16.67%
80-89	1	16.67%
90-99	1	16.67%
100	1	16.67%

Management for Students' scores
1.Input record
2.Caculate total and average score of course
3.Sort in descending order by score
4.Sort in ascending order by number
5.Search by number
6.Statistic analysis
7.List record
0.Exit
Please Input your choice:
7↙
11003001	87
11003002	48
11003003	75
11003004	65
11003005	98
11003006	100
Management for Students' scores
1.Input record
2.Caculate total and average score of course
3.Sort in descending order by score
4.Sort in ascending order by number
5.Search by number
6.Statistic analysis
7.List record
0.Exit
Please Input your choice:
8↙
Input error!
Management for Students' scores
1.Input record
2.Caculate total and average score of course
3.Sort in descending order by score
4.Sort in ascending order by number
5.Search by number
6.Statistic analysis
7.List record
0.Exit
Please Input your choice:
0↙
End of program!

输入格式:
（ 1 ）录入学生的人数：
                 **输入数据格式："%d"
                 **提示信息："Input student number(n<30):\n"
（ 2 ）录入每个学生的学号和考试成绩： 
               **输入数据格式："%ld%f"
               **提示信息："Input student's ID, name and score:\n"
输出格式：
菜单项的输出显示：
Management for Students' scores
1.Input record
2.Caculate total and average score of course
3.Sort in descending order by score
4.Sort in ascending order by number
5.Search by number
6.Statistic analysis
7.List record
0.Exit
Please Input your choice:
计算课程的总分和平均分：
              **输出总分与平均分格式："sum=%.0f,aver=%.2f\n"
按成绩由高到低排出名次表：
              **输出格式："%ld\t%.0f\n"
              **提示信息："Sort in descending order by score:\n"
按学号由小到大排出成绩表：
              **输出格式："%ld\t%.0f\n"
              **提示信息："Sort in ascending order by number:\n"
按学号查询学生排名及其考试成绩：
               **如果未查到此学号的学生，提示信息："Not found!\n"
               **如果查询到该学生，输出格式："%ld\t%.0f\n"
按优秀（90~100）、良好（80~89）、中等（70~79）、及格（60~69）、不及格（0~59）5个类别，统计每个类别的人数以及所占的百分比：
                **成绩<60输出格式："<60\t%d\t%.2f%%\n"
                **成绩=100输出格式："%d\t%d\t%.2f%%\n"
                **其他输出百分比格式："%d-%d\t%d\t%.2f%%\n"  */

//题目某些地方描述不一致；除个别格式外，基本按照题意完成

#include <stdio.h>
#define N 30
int InputRecord(int *student,float *score);
void Caculate(const int *student,const float *score);
void DescendByScore(const int *student,const float *score);
void AscendByNumber(const int *student,const float *score);
void SearchByNumber(const int *student,const float *score);
void StatisticAnalysis(const int *student,const float *score);
void ListRecord(const int *student,const float *score);
int stu_num = 0;
int main()
{
    int choice = 0;
    float score[N];
    int student[N];
    int valid_num = 0;
    char *option;
    option = "Management for Students' scores\n"
    "1.Input record\n"
    "2.Caculate total and average score of course\n"
    "3.Sort in descending order by score\n"
    "4.Sort in ascending order by number\n"
    "5.Search by number\n"
    "6.Statistic analysis\n"
    "7.List record\n"
    "0.Exit\n"
    "Please Input your choice:\n";
    printf("Input student number(n<30):\n");
    scanf("%d",&stu_num);
    do{
       printf("%s",option);
       fflush(stdin);
       scanf("%d",&choice);
       switch(choice)
       {
       case 0:break;
       case 1:valid_num = InputRecord(student,score);break;
       case 2:if(!valid_num){printf("No Record!\n");}else{Caculate(student,score);}break;
       case 3:if(!valid_num){printf("No Record!\n");}else{DescendByScore(student,score);}break;
       case 4:if(!valid_num){printf("No Record!\n");}else{AscendByNumber(student,score);}break;
       case 5:if(!valid_num){printf("No Record!\n");}else{SearchByNumber(student,score);}break;
       case 6:if(!valid_num){printf("No Record!\n");}else{StatisticAnalysis(student,score);}break;
       case 7:if(!valid_num){printf("No Record!\n");}else{ListRecord(student,score);}break;
       default:printf("No such option!\n");
       }
    }while(choice!=0);
	return 0;
}

int InputRecord(int *student,float *score){
    int valid_input = 0;
    printf("Input student's ID and score:\n");
    for(int i=0;i<stu_num;i++){
       valid_input += (scanf("%ld%f",&student[i],&score[i]))/2;
       if(score[i]<0||score[i]>100){
            printf("Invalid Input!(score>=0 && score<=100)Input this record again:\n");
            scanf("%ld%f",&student[i],&score[i]);
       }
    }
    //printf("valid_input = %d\n",valid_input);
    printf("\n");
    return valid_input;
}

void Caculate(const int *student,const float *score){
    float total = 0;
    float average = 0;
    for(int i=0;i<stu_num;i++){
        total = total+score[i];
    }
    average = total/stu_num;
    printf("sum=%.0f,aver=%.2f\n",total,average);
    printf("\n");
}

void DescendByScore(const int *student,const float *score){
    int stu[N];
    float sco[N];
    for(int i=0;i<stu_num;i++){
        stu[i] = student[i];
        sco[i] = score[i];
    }
    for(int i=0;i<stu_num-1;i++){
        int temp;
        for(int j=i+1;j<stu_num;j++){
            if(sco[j]>sco[i]){
                temp = sco[i];
                sco[i] = sco[j];
                sco[j] = temp;
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    printf("Sort in descending order by score:\n");
    for(int i=0;i<stu_num;i++){
        printf("%ld\t%.0f\n",stu[i],sco[i]);
    }
    printf("\n");
}

void AscendByNumber(const int *student,const float *score){
    int stu[N];
    float sco[N];
    for(int i=0;i<stu_num;i++){
        stu[i] = student[i];
        sco[i] = score[i];
    }
    for(int i=0;i<stu_num-1;i++){
        int temp;
        for(int j=i+1;j<stu_num;j++){
            if(stu[j]<stu[i]){
                temp = sco[i];
                sco[i] = sco[j];
                sco[j] = temp;
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    printf("Sort in ascending order by number:\n");
    for(int i=0;i<stu_num;i++){
        printf("%ld\t%.0f\n",stu[i],sco[i]);
    }
    printf("\n");
}

void SearchByNumber(const int *student,const float *score){
    int search_num;
    int flag = 0;
    printf("Input the number you want to search:\n");
    scanf("%d",&search_num);
    for(int i=0;i<stu_num;i++){
        if(student[i]==search_num){flag=1;printf("%ld\t%.0f\n",student[i],score[i]);break;}
    }
    if(!flag){printf("Not found!\n");}
    printf("\n");
}

void StatisticAnalysis(const int *student,const float *score){
    int great = 0;
    int good = 0;
    int medium = 0;
    int pass = 0;
    int fail = 0;
    for(int i=0;i<stu_num;i++){
        if(score[i]>=90){great++;}
        else if(score[i]>=80){good++;}
        else if(score[i]>=70){medium++;}
        else if(score[i]>=60){pass++;}
        else{fail++;}
    }
    printf("%d-%d\t%d\t%.2f%%\n",90,100,great,(float)great/stu_num*100);
    printf("%d-%d\t%d\t%.2f%%\n",80,90,good,(float)good/stu_num*100);
    printf("%d-%d\t%d\t%.2f%%\n",70,80,medium,(float)medium/stu_num*100);
    printf("%d-%d\t%d\t%.2f%%\n",60,70,pass,(float)pass/stu_num*100);
    printf("<60\t%d\t%.2f%%\n",fail,(float)fail/stu_num*100);
    printf("\n");
}

void ListRecord(const int *student,const float *score){
    for(int i=0;i<stu_num;i++){
        printf("%d %.0f\n",student[i],score[i]);
    }
    printf("\n");
}

				
/* 3程序改错——1（4分）

下面程序的功能是，从键盘输入两个字符串，分别存放在字符数组d和s中，
过调用子函数MyStrcat( )将这两个字符串连接起来，并将连接后的字符串存放在字符数组r中，同时输出连接后的字符串。
已知每个字符数组的最大长度为80。下面给出的程序存在错误，找到错误的原因后，请修改正确。并按照给出的程序运行结果示例检查你的程序。

已知函数原型：char* MyStrcat(char *dest, char *source);//函数返回连接后的字符串的首地址 */

#include <stdio.h>
#include <string.h>
int main(void)
{
        char *first, *second, *result;
        printf("Input the first string:\n");
        gets(first);
        printf("Input the second string:\n");
        gets(second);
        result = MyStrcat(first, second);
        printf("The result is : %s\n", result);
        return 0;
}
char* MyStrcat(char *dest, char *source)
{
        int i = 0;
        while (*(dest+i)!='\0')   i++;
        for (; *(source+i)!='\0'; i++)
        {
            *(dest+i) = *(source+i);   
        }
        return dest;
}

/* 程序运行结果示例1：
Input the first string:
fri↙
Input the second string:
end↙
The result is : friend
程序运行结果示例2：
Input the first string:
home↙
Input the second string:
work↙
The result is : homework

输入提示信息："Input the first string:\n"
输入提示信息："Input the second string:\n"
输入格式: 使用gets()函数
输出格式："The result is : %s\n" */

//修正后

#include <stdio.h>
#include <string.h>
#define N 80
char* MyStrcat(char *dest, char *source);
int main(void)
{
    char *first, *second, *result;
    char a[N];
    char b[N];
    first = a;
    second = b;
    result = a;
    printf("Input the first string:\n");
    gets(first);
    printf("Input the second string:\n");
    fflush(stdin);
    gets(second);
    result = MyStrcat(first, second);
    printf("The result is : %s\n", result);
    return 0;
}
char* MyStrcat(char *dest, char *source)
{
    int i = 0;
    int j = 0;
    while (*(dest+i)!='\0')   i++;
    for (j; *(source+j)!='\0'; j++)
    {
        *(dest+i+j) = *(source+j);
    }
    *(dest+i+j)='\0';
    return dest;
}


/* 4程序改错——2（4分）

下面程序的功能是输出如示例所示形式的数据,目前程序中存在错误，找到错误的原因后，请修改正确,并按照给出的程序运行结果示例检查你的程序。
程序中用到的函数原型如下：
void YH(int a[][ARR_SIZE], int n);
void PrintYH(int a[][ARR_SIZE], int  n);
程序运行结果示例：
   1
   1   1
   1   2   1
   1   3   3   1 */

#include<stdio.h>
#define  ARR_SIZE  5
void  YH(int a[][ARR_SIZE], int  n);
void  PrintYH(int a[][ARR_SIZE], int  n);
int main(void)
{
        int  a[ARR_SIZE][ARR_SIZE];
        YH(a, ARR_SIZE);
        PrintYH(a, ARR_SIZE);
        return 0;
}
void YH(int a[][ARR_SIZE], int n)
{
        int  i, j ;
        for (i=1; i<=n; i++)
        {  
             a[i][1] = 1;
             a[i][i] = 1;
        }
        for (i=3; i<=n; i++)
        {
            for (j=2; j<=i-1; j++)
            {
                 a[i][j] = a[i-1][j-1] + a[i-1][j];
            }       
        }
}
void PrintYH(int a[][ARR_SIZE], int n)
{
        int i , j ;
        for (i=1; i<n; i++)
        {
            for (j=1; j<=i; j++)
            {
                printf("%4d", a[i][j]);
            }
             printf("\n");
        }
}

/* 输入格式: 无
输出格式： "%4d" */

//在前面课堂习题中已更正


/* 5出售金鱼（4分）

买买提将养的一缸金鱼分五次出售：第一次卖出全部的一半加二分之一条；第二次卖出余下的三分之一加三分之一条；第三次卖出余下的四分之一加四分之一条；第四次卖出余下的五分之一加五分之一条；最后卖出剩下的11条。问原来鱼缸中共有几条鱼？

输入格式:  无
输出格式："There are %d fishes at first.\n" */

#include<stdio.h>
float fish(float n);
void main()
{
    float n;
    n=fish(1);
    printf("%.0f",n);
}

float fish(float n)
{
    if(n==5) return (11);
    else return ((n+1)/n)*(fish(n+1)+1/(n+1));
}


/* 6找最值（4分）

从键盘任意输入10个整数，用指针变量作函数参数编程计算最大值和最小值，并返回它们所在数组中的位置。

函数原型如下所示：
int FindMax(int num[], int n, int *pMaxPos);
//函数返回最大值，pMaxPos返回最大值所在的下标
int FindMin(int num[], int n, int *pMinPos);
//函数返回最小值，pMinPos返回最小值所在的下标

程序运行结果示例：
Input 10 numbers:
-1 2 3 45 92 8 9 12 7 8↙
Max=92,Position=4,Min=-1,Position=0

输入提示信息："Input 10 numbers:\n"
输入格式: "%d"
输出格式："Max=%d,Position=%d,Min=%d,Position=%d\n" */

#define N 10
#include<stdio.h>
int FindMax(int num[], int n, int *pMaxPos);
int FindMin(int num[], int n, int *pMinPos);
void main()
{
    int a[N];
    int pMaxPos = 0;
    int pMinPos = 0;
    int *p1 = &pMaxPos;
    int *p2 = &pMinPos;
    printf("Input 10 numbers:\n");
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    int Max = FindMax(a,N,p1);
    int Min = FindMin(a,N,p2);
    printf("Max=%d,Position=%d,Min=%d,Position=%d",Max,pMaxPos,Min,pMinPos);
}

int FindMax(int num[], int n, int *pMaxPos){
    for(int i=0;i<N;i++){
        if(num[*pMaxPos]<num[i]){*pMaxPos = i;}
    }
    return num[*pMaxPos];
}

int FindMin(int num[], int n, int *pMinPos){
    for(int i=0;i<N;i++){
        if(num[*pMinPos]>num[i]){*pMinPos = i;}
    }
    return num[*pMinPos];
}


/* 7杨辉三角形（4分）

编程打印具有如下形式的杨辉三角形，其中输出数据的行数n从键盘输入，并且n<=10。

程序运行结果示例1：
Input n (n<=10):
5↙
   1
   1   1
   1   2   1
   1   3   3   1
   1   4   6   4   1

程序运行结果示例2：
Input n (n<=10):
7↙
   1
   1   1
   1   2   1
   1   3   3   1
   1   4   6   4   1
   1   5  10  10   5   1
   1   6  15  20  15   6   1

输入提示信息："Input n (n<=10):\n"
输入格式:  "%d"
输出格式：
输出数据格式："%4d"
数据换行： "\n" */

#include<stdio.h>
#define  ARR_SIZE  10
void  YH(int a[][ARR_SIZE], int  n);
void  PrintYH(int a[][ARR_SIZE], int  n);

int main(void)
{
    int n;
	int  a[ARR_SIZE][ARR_SIZE] = {0};
	printf("Input n (n<=10):\n");
	scanf("%d",&n);
	while(n<0||n>10){
        printf("Input error!(n<=10),input again:\n");
        scanf("%d",&n);
	}
	YH(a, n);
	PrintYH(a, n);
	return 0;
}

void YH(int a[][ARR_SIZE], int n)
{
	int  i, j ;
	for (i=0; i<n; i++)
	{
		 a[i][0] = 1;
		 a[i][i] = 1;
	}
	 for (i=2; i<n; i++)
	{
		for (j=1; j<=i-1; j++)
		{
			 a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
}

void PrintYH(int a[][ARR_SIZE], int n)
{
	int i , j ;
	for (i=0; i<n; i++)
	{
		//printf("第%d行",i+1);
		for (j=0; j<=i; j++)
		{
			printf("%4d", a[i][j]);
		}
		 printf("\n");
	}
}

/* 8颠倒句子中的单词顺序（4分）

从键盘输入一个句子（假设字符数小于100个），句子中的单词之间用空格分隔，句子必须以一个标点符号作为结尾，句子开头和末尾标点符号前均没有空格，以回车表示输入结束，请编程颠倒句中的单词顺序并输出。

函数原型：int Inverse(char str1[], char str2[][N])

程序运行结果示例1：
Input a sentence:you can cage a swallow can't you?↙
you can't swallow a cage can you?
程序运行结果示例2：
Input a string:you are my sunshine!↙
sunshine my are you!
程序运行结果示例3：
Input a sentence:I love you!↙
you love I!

输入提示信息："Input a sentence:"
输入格式:  用gets()函数
输出格式：
每个单词的输出格式："%s "   (注意： %s后面有一个空格)
最后一个单词和标点符号的输出格式："%s%c\n" */

#define N 100
#include<stdio.h>
int Inverse(char str1[], char str2[][N]);
void main()
{
    char str1[N];
    char str2[N][N];
    printf("Input a sentence:");
    gets(str1);
    Inverse(str1,str2);
}
int Inverse(char str1[], char str2[][N]){
    int length = 0;
    int i = 1;
    int j = 0;
    while(str1[length+1]!='\0'){
        if(str1[length]!=' '){
            str2[i][j] = str1[length];
            j++;
        }else{i++;j=0;}
        length++;
    }
    str2[0][0] = str1[length];
    for(i;i>=0;i--){
        printf("%s",str2[i]);
        if(i!=1 && i!=0) printf(" ");
    }
    return 0;
}
