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


char a[2][6] = {"hello", "hi"};
printf("%lu\n", sizeof(a)); //12
printf("%lu\n", sizeof(*a)); //6
printf("%lu\n", sizeof(**a)); //1
printf("%p\n", a+1); //同下
printf("%p\n", *(a+1)); //同上
printf("%s\n", a+1); //hi
printf("%s\n", *(a+1)); //hi
printf("%s\n", *a+1); //ello


void (*(f)())(int, float);
void (*(*x)())(int, float) = f;
void (*y)(int, float); same to void ((*y)(int, float));
void foo(int i, float f);
void (*(f)())(int, float) { return foo; }
void foo(int i, float f) { printf("%d %f\n", i, f); }
y = x();
y(1, 2); //1 2.000000


int (*(*y)())[2];
y is pointer to the function which returns pointer to integer array
你自己能写出来吗？


struct p
{
    int k;
    char c;
    float f;
};
struct p x = {.c = 97, .f = 3, .k = 1}; //结构体初始化，不需要记住定义时的成员的顺序

struct p x = {.c = 97, .k = 1, 3};
printf("%f \n", x.f); according to c99, output is 0.000000
struct p x = {.c = 97};
printf("%f \n", x.f); according to c99, output is 0.000000


不同类型的结构体之间不能赋值
不能对结构体typecast
struct temp { int a; };
struct temp1 { int b; };
struct temp t;
struct temp1 t1 = (struct temp)t; //编译失败

struct point { int x; };
struct point p = {1};
struct point p1 = {1};
if(p == p1) printf("equal\n");
else printf("not equal\n"); //编译失败，
//invalid operands to binary == (have ‘struct point’ and ‘struct point’)


[] () . -> 优先级最高，为1
*(pointer) &(address) 优先级为2
容易出错的优先级例子
*p.f
int *ap[]
int *fp()
val & mask != 0         //== != 高于位操作
c = getchar() != EOF    //== != 高于赋值
msb << 4 + lsb          //算术运算符高于>> <<移位运算符，后者高于& | ^位运算符
i = 1, 2

struct point* p1 = &st;
printf("%d\n", *p.x++); //编译出错


struct student { };
struct student s[2];
printf("%lu", sizeof(struct student)); //0
printf("%d", sizeof(s)); //0


struct point { int x; int y; };
struct point p[] = {1, 2, 3, 4};
//编译有警告，更合理的是 {{1, 2}, {3, 4}}, 但可以运行，sizeof(p1)==16


int i=0;
printf("%d %d %d\n", i++, i++, i++); // 2 1 0, 注意参数计算顺序


struct p
{
    int x;
    char y;
    struct p *ptr;
};
struct p p = {1, 2, &p};
printf("%d\n", p.ptr->x); //1



int (*(x()))[2]
{
    int (*ary)[3] = malloc(printf("%lu\n", sizeof*ary));
    return &ary;
} //编译有警告，但是合法的，输出为 12



union p
{
    int x;
    float y;
};
union p p;
p.x = 10;
printf("%f\n", p.y); //0.000000 on gcc 4.9.2


struct p
{
    unsigned int x : 2;
    unsigned int y : 2;
};
struct p p;
p.x = 3;
p.y = 4;
printf("%d\n", p.y); //0 large integer implicitly truncated to unsigned type


C99 standard guarantees uniqueness of ____ characters for internal names. 63
C99 standard guarantess uniqueness of ____ characters for external names. 31


int main()
{
    int main = 3;
    printf("%d", main);
    return 0;
} //3


signed char chr;
chr = 128;
printf("%d\n", chr); //-128


int fgetc(FILE* stream)
char c;
FILE *file;
file = fopen("test.txt", "w+");
fprintf(file, "%c", 'a');
fprintf(file, "%c", -1);
fprintf(file, "%c", 'b');
fclose(file);
file = fopen("test.txt", "r");
while ((c = fgetc(file)) !=  EOF)
    printf("%c", c);
//输出为 a， 如果把char c改为 int c，则输出为 a， 乱码， b
//十六进制查看test.txt的内容为 61 ff 62
//将第二个字节ff读到char里变为-1(==EOF)， 读到int里是255(!=EOF)



float f1 = 0.1;
if (f1 == (float)0.1) printf("equal\n");
else printf("not equal\n");
//对float进行==和!=比较是unsafe的
//但是将0.1转换为float再比较后的输出是equal, 或者double f1=0.1; 则输出也是equal



enum {ORANGE = 5, MANGO, BANANA = 4, PEACH};
printf("PEACH = %d\n", PEACH); //5



char *str = “Sanfoundry.com\0” “training classes”;
The character pointer str holds reference to string:
a) Sanfoundry.com
b) Sanfoundry.com\0training classes
c) Sanfoundry.comtraining classes
d) Invalid declaration
//b


enum birds {SPARROW, PEACOCK, PARROT};
enum animals {TIGER = 8, LION, RABBIT, ZEBRA};
enum birds m = TIGER;
int k;
k = m;
printf("%d\n", k); //有警告，输出为8


printf("sanfoundry\rclass\n"); //classundry
Explanation:r is carriage return and moves the cursor back. sanfo is replaced by class


const int i = 10;
int *ptr = &i;
*ptr = 20;
printf("%d\n", i); //编译警告，输出20


int x = 5.3 % 2; //编译失败


int a = 3;
int b = ++a + a++ + --a;
printf("Value of b is %d", b); //行为未定义，在gcc 4.9.2 输出为 13, + 不是一个 sequence point


c/c++中的 sequence point 解释
https://en.wikipedia.org/wiki/Sequence_point
int a = 10;
if (a == a--)
    printf("TRUE 1\t");
a = 10;
if (a == --a)
    printf("TRUE 2\t");
//gcc 4.9.2 输出为 2, 先计算右边的表达式
//clang 输出为 1， 先计算了左边的
像这样的不是sequence point的例子很多，比如：
+, -, ==, !=,  i=i++, =, &, | 函数参数计算顺序等等
f(i++) + g(j++) + h(k++); f，g，h那个函数先运行是未定义的
但是:逗号运算符, && || 是sequence point, 先计算左边的表达式，再计算右边的表达式



unsigned int i = 23;
signed char c = -23;
if (i > c) printf("Yes\n");
else if (i < c) printf("No\n"); //No


int d, a = 1, b = 2;
d =  a++ + ++b; //可以编译
d =  a++ +++b; //语法错误


int x = 4;
int *p = &x;
int *k = p++;
int r = p - k;
printf("%d", r); //1


unsigned int a = 10;
a = ~a;
printf("%d\n", a); //-11


在c中左移也就是所说的逻辑移位，右端补0，而右移是算数移位，左端补齐的是最高位的符号位。
故负数左移，有可能变成正数，但负数右移，肯定还是负数。
int x = -2;
x = x >> 1;
printf("%d\n", x); //-1
int x = -9;
x = x << 28;
printf("%d\n", x); //1879048192
int x = -9;
x = x << 27;
printf("%d\n", x); //-1207959552

(~0 == 1) //false
(!0 == 1) //true 优先级问题


int y = 1;
if (y & (y = 2)) printf("true %d\n", y);
else printf("false %d\n", y);
unsequenced point问题, & 不是一个sequence point, 左边和右边的表达式都有可能首先
被计算, gcc ture 2, clang fales 2


int k = 8;
<<<<<<< Updated upstream
int m = 7;
k < m ? k++ : m = k; //编译错误，注意？和=的优先级顺序


*p++ //++和*的优先级是一样的，右结合，所以先求p++, 再运算*

& ^ | 的优先级分别是7， 8， 9, 也就是说它们的优先级是不一样的


[] () . ->                      1, l->r
---------------------------------------

-, ++, --, *, &, !, ~, sizeof   2, r->l
---------------------------------------

*, /, %, +, -                   3, l->r
---------------------------------------

+, -                            4, l->r
---------------------------------------

<<, >>                          5, l->r
<,  <=, >, >=                   6, l->r
== !=                           7, l->r
---------------------------------------

&                               8, l->r
^                               9, l->r
|                               10, l->r
---------------------------------------

&&                              11, l->r
||                              12, l->r
---------------------------------------

?:                              13, r->l
=, +=, ...                      14, r->l
,                               15, l->l
---------------------------------------


int p = 10, q = 20, r;
if (r = p = 5 || q > 20)
    printf("%d", r);
else
    printf("No Output\n"); //1, 注意优先级高低

int x = 0 == 1 && k+
printf("%d%d\n", x, k); //0 8


unsigned int x = -5;
printf("%d", x); //-5


int a = 1, b = 2;
a += b -= a;
printf("%d %d", a, b); //2 1


double f = 3;
printf("%lu\n", sizeof((x==2) ? f: 0)); //==sizeof(double)==sizeof(f)
//sizeof在什么情况下求表达式的值?


<<<<<<< Updated upstream
Array sizes are optional during array declaration by using external keyword.


register static int a;  //，multiple storage classes in declaration specifier
register auto int a;  //，multiple storage classes in declaration specifier
register 变量不能取地址
register 不能修饰全局变量

void foo(auto int i) //error: storage class specified for parameter ‘i’


#define foo(m, n) m ## n
printf("%d\n", foo(2, 3)); //23
printf("%s\n", foo(a, b)); //编译失败

#define foo(m, n) "m ## n"
printf("%s\n", foo(a, b)); //m ## n

#define foo(m, n) #m #n
printf("%s\n", foo(a, b)); //ab

#define max 37;
printf("%d", max);//编译失败

#define A 1 + 2
#define B 3 + 4
int var = A * B; //var==11


## macro operator
<token> ## <token>
The ## operator takes two separate tokens and pastes them together to form a 
single token. The resulting token could be a variable name, class name or any 
other identifier. A trivial example would be
#define type i##nt
type a; // same as int a; since i##nt pastes together to "int"
Real world uses of the token pasting operator often involve class, variable, 
or function names. For example, you might decide to create a macro that 
declares two variables, one with a name based on parameter to the macro 
and another with a different name, that stores the original value of the 
variable (perhaps for debugging).
#define DECLARE_AND_SET(type, varname, value) type varname = value; type orig_##varname = varname;
Now you can write code like
DECLARE_AND_SET( int, area, 2 * 6 );
and orig_area always has the original value of area no matter how the variable is changed. 


#<token>
Prefixing a macro token with # will quote that macro token. This allows you to 
turn bare words in your source code into text tokens. This can be particularly 
useful for writing a macro to convert an enum into a string:
enum ColorType
{
    CT_RED,
    CT_GREEN,
    CT_BLUE
};

note the use of CT to stand for the enum value
// and #CT to create a string, such as "CT_RED"
#define CONV_CASE(CT) case CT: return #CT
std::string getString (ColorType t)
{
    switch ( t )
    {
        CONV_CASE( CT_RED );
        CONV_CASE( CT_GREEN );
        CONV_CASE( CT_BLUE );
        default: return "unknown";
    }
}

#define SYSTEM 20
int main()
{
    int a = 20;
#if SYSTEM == a
    printf("HELLO ");
#endif
#if SYSTEM == 20
    printf("WORLD\n");
#endif
}//WORLD


#define MIN 0
#if MIN
#define MAX 10
#endif
printf("%d %d\n", MAX, MIN);//编译失败，MAX未定义


The special operator defined is used in ‘#if’ and ‘#elif’ expressions to test 
whether a certain name is defined as a macro. defined name and defined (name) 
are both expressions whose value is 1 if name is defined as a macro at the 
current point in the program, and 0 otherwise. Thus, #if defined MACRO is 
precisely equivalent to #ifdef MACRO.

defined is useful when you wish to test more than one macro for existence at once. For example,

#if defined (__vax__) || defined (__ns16000__)
would succeed if either of the names __vax__ or __ns16000__ is defined as a macro.

Conditionals written like this:

#if defined BUFSIZE && BUFSIZE >= 1024
can generally be simplified to just #if BUFSIZE >= 1024, since if BUFSIZE is
not defined, it will be interpreted as having the value zero.

If the defined operator appears as a result of a macro expansion, the C
standard says the behavior is undefined. GNU cpp treats it as a genuine defined
operator and evaluates it normally. It will warn wherever your code uses this 
feature if you use the command-line option -pedantic, since other compilers may
handle it differently.


int main(int argc, char **argv)
{
        printf("%d\n", argc);
}
./a.out > myfile argc==1, cat myfile: 1


int i = 10, j = 2;
printf("%d\n", printf("%d %d ", i, j));//10 2 5



printf
1.格式控制符使用说明

printf的格式控制的完整格式:
%[flags][width][.perc][F|N|h|l]type
"%[- 0][m*][.n*][lh]type" type就是下文说的格式字符串
下面对组成格式说明的各项加以说明:

%:
    %:  表示格式说明的起始符号,不可缺少。

flags:
    -:  有-表示左对齐输出(右侧补空格),如省略表示右对齐输出(左侧补空格)。
    +:  在数字前增加符号+或-
    0:  有0表示指定空位填0,如省略表示指定空位不填。
     :  输出值为正时冠以空格，为负时冠以负号 
    #:  

width:
    m:  m指域宽,即对应的输出项在输出设备上所占的字符数
    *:  "*" or "*m$" (for some decimal integer m) to specify that the field 
        width is given in the next argument, or in the m-th argument, 
        respectively, which must be of type int.

prec:
    .n: n指精度。用于说明输出的实型 数的小数位数。对数值型的来说,未指定n时,隐含的精度为n=6位。
    .*: "*"  or "*m$" (for some decimal integer m) to specify that the precision 
        is given in the next argument, or in the m-th argument, respectively, 
        which must be of type int.
     .: If the precision is given as just '.', the precision is taken to be zero.
        A negative  precision  is taken as if the precision were omitted.

l/h:
    l:  l对整型指long型,对实型指double型
    h:  h用于将整型的格式字符修正为short型

格式字符(格式字符用以指定输出项的数据类型和输出格式):
    d格式:用来输出十进制整数,有几种用法: %d %hd %ld
    i格式:用来输出十进制整数
    o格式:以无符号八进制形式输出整数
    x格式:以无符号十六进制形式输出整数, 小写
    X格式:以无符号十六进制形式输出整数, 大写
    f格式:用来输出实数(包括单精度,双精度),以小数形式输出
    e,E  :用科学记数法表示浮点数
    g,G  :用%f和%e表示中，总的位数最短的来表示浮点数
    u格式:以无符号十进制形式输出整数
    c格式:输出一个字符
    p格式:输出一个指针
    S格式:wchar_t字符（宽字符）类型字符串
    s格式:用来输出一个串。有几中用法:
        %s:例如:printf("%s","CHINA")输出"CHINA"字符串(不包括双引号)。
        %ms:输出的字符串占m列,如字符串本身长度大于m,则突破获m的限制,将字符串全部输出。若串 长小于m,则左补空格。
        %-ms:如果串长小于m,则在m列范围内,字符串向左靠,右补空格。
        %m.ns:输出占m列,但只取字符串中左端n个字符。这n个字符输出在m列的右侧,左补空格,注 意:如果n未指定,默认为0。
        %-m.ns:其中m、n含义同上,n个字符输出在m列范围的左侧,右补空格。如果n>m,则自动取n值,即保证n个字符正常输出,注意:如果n未指定,默认为0。

        如果是sprintf(desc, "%m.ns", sour);
        如果desc空间够的话,会在%m.ns 串 的结尾自动补null 字符,不同于strncpy。
        例如 :sprintf(desc, "%.3s", "123456"); desc如果空间>=4字节的话,第4个字节将是null字 符。


2.实型输出问题

%f:不指定宽度,整数部分全部输出并输出6位小数。
    // 默认输出6位小数
    printf("%f", 3.1415926535f);
    输出结果: 3.141593
指定保留多少位小数
    // 通过%.nf方式,指定保留多少位小数
    printf("%.2f", 3.1415926535f);
    输出结果: 3.14
3.实型精度问题

对于单精度数,使用%f格式符输出时,仅前7位是有效数字,小数6位.
对于双精度数,使用%lf格式符输出时,前15位是有效数字,小数6位
进制            float   double
十进制有效位数  7位     15位
二进制有效位数  24位    53位

一个练习引发的血案
要求输出3.1415926535f所有小数
    // 尝试通过指定保留位数
    printf("%.10f", 3.1415926535f);
    输出结果: 3.1415927410
    // float有效数字是7位, 多余位数则会显示垃圾数据(不准确)

    // 什么是有效位?
    printf("%.10f", 314159.26535f);
    输出结果: 314159.2500000000
    // 尝试指定宽度
    printf("%12f", 3.1415926535f);
    输出结果: $$$$3.141593 注意$代表空格
    // 尝试指定宽度和保留位数
    printf("%12.10f", 3.1415926535f);
    输出结果: 3.1415927410
    // 要想完整输出必须使用double, 因为double类型精度小数点后6位，有效数字是15位
    double doubleValue = 3.1415926535; // 注意后面没有f
    printf("%.10lf", doubleValue);
    输出结果:3.1415926535



scanf函数格式控制符

格式            意义
d               输入一个十进制整数
o               输入一个八进制整数
x               输入一个十六进制整数
i               输入一个有符号或无符号的十进制、八进制、十六进制整数
u               输入一个无符号十进制整数
f,e或E,g或G     输入一个小数形式或指数形式的浮点数
c               输入一个字符
s               输入一个字符串
获取整形数据
    // 1.定义变量用于接收输入数据
    int num = 0;
    // 2.利用scanf函数接收用户输入数据
    scanf("%d", &num);
    // 3.打印验证结果
    printf("num = %d", num);
获取实数型数据
全选复制放进笔记    // 1.定义变量用于接收输入数据
    float num = 0;
    // 2.利用scanf函数接收用户输入数据
    scanf("%f", &num);
    // 3.打印验证结果
    printf("num = %d", num);
注：不加\n,需要加&取地址
非法的输入
除"空格","回车","tab"之外, 如果输入的数据和scanf接收的数据不匹配将会自动结束接收



const char *s = "myworld";
const char *i = "myworld";
int i = 9;
printf("%*s", i, s); //两个空格myworld

const char *s = "myworld";
int i = 3;
printf("%10.*s", i, s);//7个空格myw


va_list start;
va_start(start, n);//n是前一个参数
int a = va_arg(start, int); 传给va_arg的类型必须是int类型而不能是char, so you 
                            should pass ‘int’ not ‘char’ to ‘va_arg’
                            传给va_arg的类型必须是double类型而不能是flost, so you 
                            should pass ‘double’ not ‘flost’ to ‘va_arg’

va_end(start)
va_copy(start, dst);


fprintf(stderr, "%d ", 65);//65 45, 缓冲的原因


unsigned int i = -1;
printf("%f\n", fabs(i));//garbage value


#define OFFSETOF(TYPE, ELEMENT) ((size_t)(uintptr_t)&(((TYPE *)0)->ELEMENT))

#define container_of(ptr, type, member) ({                              \
                const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
                (type *)( (char *)__mptr - offsetof(type,member) );})

这里有两个gnu gcc扩展

注意：typeof那一行对于计算结果没有影响，但是可以用来进行类型检查，如果用户传进
      来的ptr不是期望的类型，则编译器会给出警告/错误



#define SWAP(a, b)  do { a ^= b; b ^= a; a ^= b; } while ( 0 )
加{}的原因，加do while的原因
if(x < 0) SWAP(x, y);
else SWAP(x, z);
如果不加{},上面的代码会扩展成什么，如果不加do whille,第一个SWAP后面的各分号会
导致能编译失败, 当然如果一定要在次出加超过一个分号，那就没有办法了


#define PRINT_TOKEN(token) printf(#token " is %d", token)//for debug 方便

x & 1 判断奇偶

判断是否未未2的n次方
x &  (x -1)

计算x中1的个数

XOR
Given a set of numbers where all elements occur even number of times except 
one number, find the odd occuring number” This problem can be efficiently 
solved by just doing XOR of all numbers.

You are given a list of n-1 integers and these integers are in the range of 1 
to n. There are no duplicates in list. One of the integers is missing in the 
list. Write an efficient code to find the missing integer.
1) XOR all the array elements, let the result of XOR be X1.
2) XOR all numbers from 1 to n, let XOR be X2.
3) XOR of X1 and X2 gives the missing number.


XOR Linked List – A Memory Efficient Doubly Linked List
every node stores the XOR of addresses of previous and next nodes.
node->ptr = prev ^ next;


Find the two non-repeating elements in an array of repeating elements
Let x and y be the non-repeating elements we are looking for and arr[] be the 
input array. First calculate the XOR of all the array elements.
xor = arr[0]^arr[1]^arr[2].....arr[n-1]
All the bits that are set in xor will be set in one non-repeating element 
(x or y) and not in other. So if we take any set bit of xor and divide the 
elements of the array in two sets – one set of elements with same bit set and 
other set with same bit not set. By doing so, we will get x in one set and y 
in another set. Now if we do XOR of all the elements in first set, we will get 
first non-repeating element, and by doing same in other set we will get the 
second non-repeating element.



Add two numbers without using arithmetic operator
int add(int x, int y)
{
    // Iterate till there is no carry  
    while (y != 0)
    {
        // carry now contains common set bits of x and y
        int carry = x & y;  

        // Sum of bits of x and y where at least one of the bits is not set
        x = x ^ y;

        // Carry is shifted by one so that adding it to x gives the required sum
        y = carry << 1;
    }
    return x;
}
 
int add(int x, int y)
{
    if( y==0 )
        return x;
    else
        return add(x ^ y, (x & y)<<1);
}

Swap bits in a given number
Given a number x and two positions (from right side) in binary representation
of x, write a function that swaps n bits at given two positions and returns the
result. It is also given that the two sets of bits do not overlap.

1) Move all bits of first set to rightmost side
   set1 =  (x >> p1) & ((1U << n) - 1)
Here the expression (1U << n) - 1 gives a number that
contains last n bits set and other bits as 0. We do &
with this expression so that bits other than the last
n bits become 0.
2) Move all bits of second set to rightmost side
   set2 =  (x >> p2) & ((1U << n) - 1)
3) XOR the two sets of bits
   xor = (set1 ^ set2)
4) Put the xor bits back to their original positions.
   xor = (xor << p1) | (xor << p2)
5) Finally, XOR the xor with original number so
   that the two sets are swapped.
   result = x ^ xor

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* Move all bits of first set to rightmost side */
    unsigned int set1 =  (x >> p1) & ((1U << n) - 1);
 
    /* Moce all bits of second set to rightmost side */
    unsigned int set2 =  (x >> p2) & ((1U << n) - 1);
 
    /* XOR the two sets */
    unsigned int xor = (set1 ^ set2);
 
    /* Put the xor bits back to their original positions */
    xor = (xor << p1) | (xor << p2);
 
    /* XOR the 'xor' with the original number so that the
       two sets are swapped */
    unsigned int result = x ^ xor;
 
    return result;
}


Count number of bits to be flipped to convert A to B
xor = A ^ B, 求 xor中set bit的个数


Find the element that appears once
Given an array where every element occurs three times, except one element 
which occurs only once. Find the element that occurs once. Expected time 
complexity is O(n) and O(1) extra space.

Run a loop for all elements in array. At the end of every iteration, maintain following two values.

ones: The bits that have appeared 1st time or 4th time or 7th time .. etc.

twos: The bits that have appeared 2nd time or 5th time or 8th time .. etc.

Finally, we return the value of ‘ones’

How to maintain the values of ‘ones’ and ‘twos’?
‘ones’ and ‘twos’ are initialized as 0. For every new element in array, find 
out the common set bits in the new element and previous value of ‘ones’. These 
common set bits are actually the bits that should be added to ‘twos’. So do 
bitwise OR of the common set bits with ‘twos’. ‘twos’ also gets some extra 
bits that appear third time. These extra bits are removed later.
Update ‘ones’ by doing XOR of new element with previous value of ‘ones’. There 
may be some bits which appear 3rd time. These extra bits are also removed later.

Both ‘ones’ and ‘twos’ contain those extra bits which appear 3rd time. Remove 
these extra bits by finding out common set bits in ‘ones’ and ‘twos’.

#include <stdio.h>
 
int getSingle(int arr[], int n)
{
    int ones = 0, twos = 0 ;
 
    int common_bit_mask;
 
    // Let us take the example of {3, 3, 2, 3} to understand this
    for( int i=0; i< n; i++ )
    {
        /* The expression "one & arr[i]" gives the bits that are
           there in both 'ones' and new element from arr[].  We
           add these bits to 'twos' using bitwise OR
 
           Value of 'twos' will be set as 0, 3, 3 and 1 after 1st,
           2nd, 3rd and 4th iterations respectively */
        twos  = twos | (ones & arr[i]);
 
 
        /* XOR the new bits with previous 'ones' to get all bits
           appearing odd number of times
 
           Value of 'ones' will be set as 3, 0, 2 and 3 after 1st,
           2nd, 3rd and 4th iterations respectively */
        ones  = ones ^ arr[i];
 
 
        /* The common bits are those bits which appear third time
           So these bits should not be there in both 'ones' and 'twos'.
           common_bit_mask contains all these bits as 0, so that the bits can 
           be removed from 'ones' and 'twos'   
 
           Value of 'common_bit_mask' will be set as 00, 00, 01 and 10
           after 1st, 2nd, 3rd and 4th iterations respectively */
        common_bit_mask = ~(ones & twos);
 
 
        /* Remove common bits (the bits that appear third time) from 'ones'
             
           Value of 'ones' will be set as 3, 0, 0 and 2 after 1st,
           2nd, 3rd and 4th iterations respectively */
        ones &= common_bit_mask;
 
 
        /* Remove common bits (the bits that appear third time) from 'twos'
 
           Value of 'twos' will be set as 0, 3, 1 and 0 after 1st,
           2nd, 3rd and 4th itearations respectively */
        twos &= common_bit_mask;
 
        // uncomment this code to see intermediate values
        //printf (" %d %d \n", ones, twos);
    }
 
    return ones;
}
 
Detect if two integers have opposite signs
(x ^ y) < 0



int main()
{
    int k = m();
    printf("%d", k);
    return 0;
}
void m()
{
    printf("hello");
}
//gcc有警告，可以编译过去，输出为 hello 5
//clang 编译失败, 和gcc识别的出的错误时一样的，但更严格一些


enum m{JAN, FEB, MAR};
enum m foo();
int foo()
{
        return JAN;
}//编译失败，冲突的type for foo



#include <stdio.h>
int main()
{
    extern ary1[];
    printf("scope rules\n");

}//未链接 ary1的定义文件时可以编译




#include <stdio.h>
int main()
{
    extern ary1[];
    printf("%d\n", ary1[0]);

}//链接了有ary1定义的文件，编译失败


#include <stdio.h>
int main(void)
{
    static int i = 5;
    if (--i){
        printf("%d ", i);
        main(10);
    }
}//编译失败
#include <stdio.h>
int main()
{
    static int i = 5;
    if (--i){
        printf("%d ", i);
        main(10);
    }
}//4 3 2 1
In C, if a function signature doesn’t specify any argument, it means that the 
function can be called with any number of parameters or without any parameters. 
But in c++, There is no dereference, both are the same.


The macro arguments are not evaluated before macro expansion.

The tokens passed to macros can be contcatehanted using operator ## called 
Token-Pasting operator. 
#define merge(a, b) a##b
printf("%d ", merge(12, 34));// Output: 1234

A token passed to macro can be converted to a sting literal by using # before it. 
#define get(a) #a
printf("%s", get(GeeksQuiz));//Output: GeeksQuiz

file (__FILE__), Date of compilation (__DATE__), Time of compilation (__TIME__)
and Line Number in C code (__LINE__)



