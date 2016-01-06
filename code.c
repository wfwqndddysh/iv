//
// Simple and fast atof (ascii to float) function.
//
// - Executes about 5x faster than standard MSCRT library atof().
// - An attractive alternative if the number of calls is in the millions.
// - Assumes input is a proper integer, fraction, or scientific format.
// - Matches library atof() to 15 digits (except at extreme exponents).
// - Follows atof() precedent of essentially no error checking.
//
// 09-May-2009 Tom Van Baak (tvb) www.LeapSecond.com
//

#define white_space(c) ((c) == ' ' || (c) == '\t')
#define valid_digit(c) ((c) >= '0' && (c) <= '9')

double atof (const char *p)
{
    int frac;
    double sign, value, scale;

    // Skip leading white space, if any.

    while (white_space(*p) ) {
        p += 1;
    }

    // Get sign, if any.

    sign = 1.0;
    if (*p == '-') {
        sign = -1.0;
        p += 1;

    } else if (*p == '+') {
        p += 1;
    }

    // Get digits before decimal point or exponent, if any.

    for (value = 0.0; valid_digit(*p); p += 1) {
        value = value * 10.0 + (*p - '0');
    }

    // Get digits after decimal point, if any.

    if (*p == '.') {
        double pow10 = 10.0;
        p += 1;
        while (valid_digit(*p)) {
            value += (*p - '0') / pow10;
            pow10 *= 10.0;
            p += 1;
        }
    }

    // Handle exponent, if any.

    frac = 0;
    scale = 1.0;
    if ((*p == 'e') || (*p == 'E')) {
        unsigned int expon;

        // Get sign of exponent, if any.

        p += 1;
        if (*p == '-') {
            frac = 1;
            p += 1;

        } else if (*p == '+') {
            p += 1;
        }

        // Get digits of exponent, if any.

        for (expon = 0; valid_digit(*p); p += 1) {
            expon = expon * 10 + (*p - '0');
        }
        if (expon > 308) expon = 308;

        // Calculate scaling factor.

        while (expon >= 50) { scale *= 1E50; expon -= 50; }
        while (expon >=  8) { scale *= 1E8;  expon -=  8; }
        while (expon >   0) { scale *= 10.0; expon -=  1; }
    }

    // Return signed and scaled floating point result.

    return sign * (frac ? (value / scale) : (value * scale));
}

double Clib_atof(char s[])
{
    double val, power, rtn;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ; /*empty*/

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') ++i;

    for (val = 0.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        ++i;
    }

    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    rtn = (sign * val / (power));

    // Next work on exponent
    if (s[i] == 'e' || s[i]=='E') {
        int j, esign; 
        int eval = 0;

        esign = (s[j] == '-') ? -1 : 1;
        if (s[j] == '+' || s[j] == '-') ++j;

        for (; isdigit(s[j]); ++j) {
            eval = 10 * eval + (s[j] - '0');
        }

        int l;
        for (l = 0; l < eval; l++) {
            (esign >= 0) ? (rtn *= 10) : (rtn /= 10);
        }
    }

    // Finally return the solution
    return rtn;
}

//一句话测试是否为2的n次方
(x-1)&x==0

不用额外变量交换两个int变量的值
int a;  int b;
a=a^b;
b=a^b;
a=a^b;

unsigned char* p1;
unsigned long* p2;
p1 = (unsigned char*)0x801000;
p2 = (unsigned long*)0x801000;
p1+5 = ?  0x801005
p2+5 = ?  0x801014

char  a1[] = "abc";
char* p1 = "abc";
char* p2 = "abc";
const char* p3 = "abc";
const char* p4 = "abc";

p1==p2==p3==p4 0x400b40;
指向相同常量区域


用预处理指令#define 声明一个常数，用以表明1年中有多少秒（忽略闰年问题）
#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL
#define MIN(A,B) ((A) <= (B) ? (A) : (B))

用变量a给出下面的定义 
a) 一个整型数（An integer） 
b) 一个指向整型数的指针（A pointer to an integer） 
c) 一个指向指针的的指针，它指向的指针是指向一个整型数（A pointer to a pointer to an integer） 
d) 一个有10个整型数的数组（An array of 10 integers） 
e) 一个有10个指针的数组，该指针是指向一个整型数的（An array of 10 pointers to integers） 
f) 一个指向有10个整型数数组的指针（A pointer to an array of 10 integers） 
g) 一个指向函数的指针，该函数有一个整型参数并返回一个整型数（A pointer to a function that takes an integer as an argument and returns an integer） 
h) 一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数（ An array of ten pointers to functions that take an integer argument and return an integer ）

答案是： 
a) int a; // An integer 
b) int *a; // A pointer to an integer 
c) int **a; // A pointer to a pointer to an integer 
d) int a[10]; // An array of 10 integers 
e) int *a[10]; // An array of 10 pointers to integers 
f) int (*a)[10]; // A pointer to an array of 10 integers 
g) int (*a)(int); // A pointer to a function a that takes an integer argument and returns an integer 
h) int (*a[10])(int); // An array of 10 pointers to functions that take an integer argument and return an integer 

11. 中断是嵌入式系统中重要的组成部分，这导致了很多编译开发商提供一种扩展—让标准C支持中断。具代表事实是，产生了一个新的关键字 __interrupt。下面的代码就使用了__interrupt关键字去定义了一个中断服务子程序(ISR)，请评论一下这段代码的。

__interrupt double compute_area (double radius) 
{ 
    double area = PI * radius * radius; 
    printf(" Area = %f", area); 
    return area; 
}

这个函数有太多的错误了，以至让人不知从何说起了： 
1). ISR 不能返回一个值。如果你不懂这个，那么你不会被雇用的。 
2). ISR 不能传递参数。如果你没有看到这一点，你被雇用的机会等同第一项。 
3). 在许多的处理器/编译器中，浮点一般都是不可重入的。有些处理器/编译器需要让额处的寄存器入栈，有些处理器/编译器就是不允许在ISR中做浮点运算。此外，ISR应该是短而有效率的，在ISR中做浮点运算是不明智的。 
4). 与第三点一脉相承，printf()经常有重入和性能上的问题。如果你丢掉了第三和第四点，我不会太为难你的。不用说，如果你能得到后两点，那么你的被雇用前景越来越光明了。


int a[] = {1, 2, 3, 4, 5};
int *ptr = (int *)(&a + 1);
printf("%d, %d\n",  *(a+1), *(ptr-1));
2, 5
&a是数组指针，其类型是 int(*)[5];

int a[][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} };
printf("%lu\n", sizeof(a[0]));
printf("%d\n", *((int*)(&a[0]+1)-1));
printf("%d\n", *((int*)(&a+1)-1));
16, 4, 8


float 与 0 的比较
#define EPSINON 0.00001
if(x>-EPSINON && x<-EPSINON)

