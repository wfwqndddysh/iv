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


int foo(int x, int n)
{
    int val=1;
    if(n>0)
    {
        if(n%2==1) val=val*x;
        val = val*foo(x*x, n/2);
    }
    return val;
}
该函数的功能是 x^n


void foo(int b[][3])
{
    b[1][1]=9;
}
int a[][3]= { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
foo(a);
printf("%d\n", a[2][1]); //9


int a, b, c, d;
a=3;
b=5;
c=a,b;
d=(a,b);
printf("%d, %d\n"); //3, 5 (逗号的优先级最低)


int a[][3]={ {1, 2, 3}, {4, 5, 6} };
int (*ptr)[3] = a;
printf("%d %d\n", (*ptr)[1], (*ptr)[2]); //2, 3
++ptr;
printf("%d %d\n", (*ptr)[1], (*ptr)[2]); //5, 6



void f(int a[][3])
{
    sizeof(a)==8;
    type of a is int (*)[3];
}
void f(int a[3])
{
    sizeof(a)==8;
    type of a is int*;
}


c中的可变长参数问题


int i = 3;
int l = i / -2;
int k = i % -2;
printf("%d %d\n", l, k); //-1, 1

浮点数相等不想测试不能用 == 和 != , unsafe

How to free a block of memory previously allocated without using free?
If the pointer holding that memory address is passed to realloc with size 
argument as zero (like realloc(ptr, 0)) the the memory will be released.

int x = 5.3 % 2; 编译失败

void change()
{
// Add a statement here such that printf in main prints 5
}
int main()
{
    int i;
    i=5;
    change();
    i=10;
    printf("%d",i); /* this should print 5*/
}
#define printf(x, y) printf("5");


int x = 5 % (-3);
int y = (-5) % (3);
int z = (-5) % (-3); 
printf("%d ,%d ,%d", x, y, z); //2 -2 -2
C99 requires that when a/b is representable:
(a/b) * b + a%b == a

Example A. 5/(-3) is -1
=> (-1) * (-3) + 5%(-3) = 5
=> 5%(-3) should be 2

Example B. (-5)/3 is -1
=> (-1) * 3 + (-5)%3 = -5
=> (-5)%3 should be -2
...

int remainder(int a, int b)
{
    return a - (a / b) * b;
}
For modulo operation, we can have the following function:
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}
My conclusion is (a % b) in C is a remainder operator and NOT modulo operator.


When does the compiler not implicitly generate the address of the first
element of an array?
Whenever an array name appears in an expression such as
- array as an operand of the sizeof operator
- array as an operand of & operator
- array as a string literal initializer for a character array
Then the compiler does not implicitly generate the address of the
address of the first element of an array


不能对void*dereference, 编译错误


int i = 10;
void *p = &i;
printf("%f\n", *(float*)p); //输出和浮点数的表示有关，但期望输出为10.0是不对的


int *ptr, p; //ptr是指针，p是int


float x = 0.1;
printf("%d, ", x); //垃圾值
printf("%d, ", (int)x); //0
printf("%f\n", x); //0.000001

double x = 123828749.66;
int y = x;
printf("%d\n", y); //123828749
printf("%lf\n", y); //垃圾值

float x;
int y;
printf("enter two numbers \n", x);
scanf("%f %f", &x, &y);
printf("%f, %d", x, y); //7.000000 垃圾值

Narrowing conversions and widening conversions



typedef int(*ptr)(int); //定以一个类型别名
int (*ptr)(int); //定一个变量,可以赋值，取地址

int (*foo(int))(int); //声明
foo是一个函数，这个函数接收一个int参数，返回一个指针，这个指针指向一个参数为int
返回值为int的函数
int ((*foo(int i)))(int) //定义
{
    return myfoo;
}

int (*(*pf())())()
{
    return nullptr; 
}

a()    a是一个函数
*a     a是一个指针
由于函数声明的特殊性，当指针解引用操作符*与一个表示函数的标识符结合时，
表示这个函数的返回值是一个指针。例如 *a() 表示a是一个返回值为指针的函数。

            pf()            pf是一个无参数函数
          * pf()            pf是一个无参数函数，它的返回值是一个指针
      * ( * pf() ) ()       pf是一个无参数函数，它的返回值是一个无参数函数的指针
    * * ( * pf() ) ()       pf是一个无参数函数，它的返回值是一个无参数函数的指针，这个函数的返回值又是一个指针
  * ( * ( * pf() ) () ) ()  pf是一个无参数函数，它的返回值是一个无参数函数的指针，这个函数的返回值又是一个无参数函数的指针
int ( * ( * pf() ) () ) ()  pf是一个无参数函数，它的返回值是一个无参数函数的指针，这个函数的返回值又是一个无参数且返回值为int的函数的指针。


funcptr = f; //implicit conversion to pointer
funcptr = &f; //explicit manufacture of a pointer
(*funcptr)(2, 3); //explicit dereference of the pointer
(********funcptr)(2, 3); //和上面是一样的，也就是说编译器会忽略掉funcptr前面的*
funcptr(2, 3); // implicit dereference of the pointer


void f(int, int){}
void (*foo)() = f;
foo(10, 10); //OK

void f(int, int){}
void (*foo)(void) = f;
foo(10, 10); //compile error, too many args
在C中如果真的是空参数，应该坚持写为void, 而不是什么也不写, 否则编译器会当作它
需要可变个数的参数

void f(int i) { printf("%d\n", i); }
void (*foo)(float) = f;
foo(10); //未定义的行为


void f(int (*i)(int)) { i(11); }
int foo(int i) { printf("%d\n", i); return i; }
f(foo(10)); //可以编译，有警告，结果：10 segmentation fault
整数到指针的隐式转换

C in a nut shell 类型转换一节

void foo(float *p) { printf("%f\n", *p); }
int i = 10, *p = &i;
foo(&i); //0.000000


void foo(int **p) { int j = 11; *p = &j; }
int i = 10;
int *const p = &i;
foo(&p); //编译能过，p确实被改过了, 但在foo里直接修改p是编译不过的


char *s= "hello";
char *p = s;
printf("%c, %c", 1[p], s[1]); //e, e


int a = 10;
int **c = &&a; //编译失败


int f(int a[][]) {}; //编译失败：array type has incomplete element type
int f(int a[5[]) {}; //编译失败：array type has incomplete element type

int *a1[8];
int *(a3[8]);
都是 Array of pointers



void foo(int *ary[])
{
    int i = 10, j = 2, k;
    ary[0] = &i;
    ary[1] = &j;
    *ary[0] = 2;
    for (k = 0;k < 2; k++)
        printf("%d\n", *ary[k]);
}
int ary[2][3];
foo(ary); //编译警告，重要的是警告在foo(ary)行上，输出为：2 2

void foo(int (*ary)[3])
{
    int i = 10, j = 2, k;
    ary[0] = &i;
    ary[1] = &j;
    for (k = 0;k < 2; k++)
        printf("%d\n", *ary[k]);
}
int ary[2][3];
foo(ary); //编译失败, 和上一例比较


int j=20;
int a[2];
int b[2][2];
int c[2][2][2];
a = &j;         //编译失败, 数组类型不能赋值
b[0] = &j;      //编译失败, 数组类型不能赋值
c[0][0] = &j;   //编译失败, 数组类型不能赋值


char *a = {"p", "r", "o", "g", "r", "a", "m"};
printf("%s", a); //编译警告：excess elements in scalar initializer, 输出为p


long = 0, j = 2, k=4, o=6, p=8;
long *a[] = {&p, &o};
printf("%d", (*a)[0]); //8, *a的类型是int*, 对一维数组来说，*a的类型==a[0]的类型
printf("%d", (*a)[4]); //0, *a的类型是int*, 栈的地址是下降的
printf("%d", *a[0]);   //8


int a[][] = {{1, 2, 3}, {2, 3, 4, 5}};//编译不过
