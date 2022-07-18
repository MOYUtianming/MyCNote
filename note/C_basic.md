# 计算机与编程语言

1. 计算机做的所有事情都叫计算,
2. 计算的步骤就是算法;

## 解释型和编译型语言

1. 解释型: 借助一个能理解待运行程序的程序执行的语言;
2. 编译型: 借助一个程序将待运行程序翻译成机器语言, 然后, 运行翻译结果。
3. 语言本身没有解释型或编译型之分, 只要有特定的工具就可以。

## 现代语言

1. 指1980sC语言成熟之后的语言;
2. 语法相似;
3. 根据库选择语言;

## C语言历史

1. `1969年夏`出现;
2. `Fortran`->`BCPL`->`B`->`C`;
3. 继承了“支持指针间接形式”这一特质;
4. `1973.3`, 第三版Unix系统上出现了C语言的编译器;
5. `1973.11`, 第四版Unix操作系统完全用C语言编写;
6. `K&R the C` 经典的C语言版本;
7. `1990`年ISO接受了1989年的ANSI-C作为标准 `ISOC89 = ANSI-C`
8. `1995`年第一次更新=>C95;
9. `1999`年第二次更新=>C99;
10. 当代所有的C编译器`都已经支持C99`;

## C语言特性

1. C语言主要做底层驱动（包括操作系统）也即C语言是一种`工业语言`;
2. C是一种编译型语言;
   * 需要编辑器 + 编译器 的组合才能够完成开发;
   * 可以使用IDE（集成开发环境）, 它一般包括编辑器、编译器和调试器;
3. 各个平台上的推荐开发工具;
    1. 主流
        * Windows: `DevC++ (4.9 for Win7,5.0> for Win8>)` || `MS Visual Studio` || Visual Studio Code
        * Mac OS: Xcode
        * Linux: Eclipse-CDT
    2. 轻量级开发工具 = 支持语法高亮/自动对齐等功能的编辑器 + 调用外部编译器（如MinGW = Minimal GNU for Windows）
       1. 编辑器
            1. `Geany`
            2. `Subline`
            3. `vim`
            4. `emacs`
            5. `VSCode`
       2. 编译器
            1. `MSVC`
            2. `GCC`/`MinGW`(MinGW just for windows)
            3. `Clang`
4. sizeof()运算符在编译时就已经计算完毕, 并不会随着括号中变量的改变而变;
5. 常见数据类型保留字
    1. `char`     = `8bit`(1字节) s`-128~127` /u`0~255`
    2. `short`    = `16bit`(2字节)
    3. `int`      = `8bit/16bit/32bit/64bit`(一个字)
    4. `long`     = `8bit/16bit/32bit/64bit`(一个字)
       * 上述两者与机器和编译器有关;
    5. `long long` = 两个字
    6. `long double/double long` = 四个字
    7. `float` = 32bit 有效位 7
    8. `double` = 64bit 有效位 15
    9. `bool` = 布尔类型, dependence:`#include <stdbool.h>`;(`true/false`)

6. 常见常量修饰符
    1. `后缀U/u`: 字面量(整型常量) 加上 `U/u` 后缀就可以被视为`unsigned` 值;
    2. `后缀F/f`: 字面量(浮点常量) 加上 `F/f` 后缀就可以被视为`float`    值;
7. 常见打印占位符
    1. `%o`: `八进制`格式化;
    2. `%x/X`: `十六进制`格式化(用`x`值会`小写`, 用`X` 值会`大写`);
    3. `%i`: 让`十六进制`或者`八进制`数字并以`十进制`格式`输入`;
    4. `%u`: 输出unsigned 值。
    5. `%e/%E`: 输出`科学计数法形式的浮点数`;
    6. `%x1.x2TYPE`: 限制输出位的数量, `x1`限制整数位, `x2`限制小数位, `TYPE`指定类型, 在`x1`和`x2`前加`0`会让不足位数补0;
    7. `%x1.x2h(h)TYPE`: `h`tag用来输出`short`, `hh`tag用来输出`char整型`;
8. 常见数值处理技巧
    1. `int/double`: 对于32位/64位机器, 默认使用 `int/double` 更符合硬件特性;
    2. `fabs<目标精度`: 用于比较两个浮点数的大小;
    3. `inf / nan/NaN`: `inf`=超出表示范围的数, `nan/NaN`=不存在的数;
9. `补码的意义`是补码的`-1`和`1`相加会得到一个溢出的`0`;
10. `转义字符` = 使用 `\` 前缀的字母;
    1. `\n` = 换行;
    2. `\r` = 回车(回到行首);
    3. `\b` = 回退一格(在cmd中被屏蔽为方框);
    4. `\"` = 双引号;
    5. `\'` = 单引号;
    6. `\\` = 反斜杠本身;
    7. `\t` = 到下一个表格位(水平制表, 输出一个tab) 可以用于漂亮的输出多个同类型参数(连读可能会出现错误的类型);;
    8. `\v` = 垂直制表(跳转到当前列的下一行对应处)(在cmd中被屏蔽为方框);
    9. `\0` = NULL,作为字符串的结束符;
    10. `\f` = 翻页(清空之前显示的内容, 显示后面的内容)(在cmd中被屏蔽);

11. `强制类型转换`

    1. 优先级高于所有的运算符;
    2. 例如 `t = (int)a/b` 是将`a`转为`int`再与`b`运算之后赋给`t`;

12. 条件运算符是`自右向左结合`的

    例如 u = x>y?a:b 运算后u的值根据x和y的大小关系不同会变成a或者b;

13. `,`运算符一般作为多个语句的连接符, 它的运算优先级`最低`;

## 函数

1. 一般main函数写法

    ```C
        int main(int argc, char * argv[])
        {

        }
    ```

2. 函数的声明必须`放在正式调用的位置之前`;
3. 函数声明在编译时`不关心参数名`;
4. C语言`不支持函数的嵌套定义`(在函数中无法定义函数, 但是可以声明函数)
5. `static` 前缀可以让函数变成内部函数(默认是可以被其它文件调用的外部函数);
6. `const` 前缀可以固化值;
7. C语言的函数间传递的是`值`, 而`不是变量`;(传入数组/指针时, 传入的是一个同值指针(相同的地址值), 所以可以用指针间接改变原变量);
8. 因为7, 本地变量指针不应当被作为函数返回值, 最好的方法是用传入的指针参数返回值或者返回它自己;

## 数组

1. `x[0]` 可以存在, 一般作为`结构体的末尾单位`, 被视作`动态数组`, 需要使用`malloc`和`free`进行管理;
2. `x[n] = {0}` 可用于快速初始化数组;
3. `x[n] = {[2]=1,[5]=6}` 可用于快速给`特定位置初始化`;
4. `(sizeof(x) / sizeof(x[0]))` 可以用于得到`整个数组的元素个数`;
5. 可以使用 `FuncName(int a[], int elemNum)` 来`传入一个数组`;
6. 二维数组初始化一般形式 `{{1,2,3},{5,3,1}}`;
   * 除了用于字符串指针数组外，不推荐使用二维数组,因为它相当于一个成员匿名的双元素结构体数组;

## 变量前缀

1. `volatile`: 用该前缀修饰的值每次被使用时不是是用上次的值, 而是重新计算得到最新值;
2. `extern`: 代表被修饰的变量是外部可见的;
    1. `int x = 1;` 这是定义; (只用定义一次, 需要定义为全局变量)
    2. `int extern x;` 这是声明; (其他文件中需要使用的时候要在使用前这样声明)
3. `const`: 代表被修饰的对象是不变的;
    1. 总是可以将一个变量变为const类型;
    2. const 修饰的变量在初始化之后值不能再被修改;特别的, const 修饰的指针在初始化之后不能再指向别的变量;

        ```C
            int* const q; //指针是const; (修饰的是指针)
            int const* p;//所指是const;
        ```

4. `auto`: 代表变量自己的空间是自动回收的。
5. `restrict`: 对象已经被指针所引用, 不能通过除该指针以外的任何方式修改其内容;
6. `static`:
   1. 在一个变量前面加static之后, 这个变量的`生存周期`不再和它的作用域有关;
   2. 例如, `静态局部变量`具有`全局生存期, 局部作用域`;

## 字符串

> C语言的字符串是以零结尾的一串字符; (零 可以是`数字0` 或者`转义字符'\0'`, 但`不`可以是字符`'0'`);

1. 一共有三种创建字符串的方式;
   1. char *s = "Hello World!" // 总是const类型;(不可修改),存放在代码段;用于表达只读字符串和接收动态空间;
   2. char s2[10] = "Hello World!" // 两种数组类型是可修改的字符串.存放在本地变量区域,自动带有auto前缀;
   3. char s1[] = "Hello World!" // 用法2的简略写法;
2. 字符串可以表达为char*,char* 不一定是字符串(要看结尾是否有`0 / '\0'`);
3. 使用 `%s` 可以读入/输出字符串, 但读入字符串时`以空格 回车或tab`为`结束标志`;
4. 使用 `%ns` 可以用 `n` 指定读入字符串的长度;
5. 使用 char s[] = ""; 的确可以建立一个字符串, 但是它`无法存储`任何字符;
6. 使用 char*s[] ; 可以`建立一个存储多个字符串的矩阵`; //main函数的参数2就是这么建立的;(参数1是这些字符串的数量,参数2是命令输入位置)
7. 输入Ctrl + C 会让程序强制退出;(由shell执行)
8. 输入Ctrl + D (linux) / Ctrl + Z 会在stdin里面输入一个EOF;(由程序读入)

## size_t

1. `size_t` 是用来存储一个size的数据类型, 也就是说这个机器上的所有类型的大小都可以存储进一个size_t数据中;
2. 一般在`32位机`中是一个`unsigned int` , 在`64位机`中是一个`long unsigned int`;

## 常用的字符串函数原型 (should include string.h)

1. `size_t strlen(const char*s);`
   * return the length of input string;(without '/0',diff with sizeof())
2. `int strcmp(const char *s1,const char *s2);`
   * compare s1 and s2,return 0 == equal;return 1 == 1>2;return -1 == 1<2;
   * 实际上是两个字符串逐个元素相减(使用指针);,不相等或者相等却为'0',返回两者ASCII值差值;
   * `int strcmp_s(const char *s1,const char *s2,size_t n);`
     * safe版本, 主要是指定了比较的数量;
3. `char *strcpy(char *restrict dst,const char *restrict src);`
   * copy src to dst;(src and dst can't be overlapped);
   * `errno_t strcpy_s(char *strDestination , size_t numberOfElements , const char *strSource);`
     * safe版本, 主要是指定了最多拷贝的数量;
4. `char *strcat(char *restrict s1,const char *restrict s2);`
   * copy s2 to the end of s1;
   * `errno_t strcat_s(char *strDestination, size_t numberOfElements, const char *strSource);`
     * safe版本, 主要是指定了最多拷贝的数量;
5. `char *strchr(const char *s , int c);`
   * search c in s from left to right;
   * `char *strrchr(const char *s , int c);`
     * search c in s from right to left;
   * return NULL means can't find;
   * `p = strchr(s,c);p2 = strchr(p+1,c);` can find the second c;
6. `char *strstr(const char *s1,const char *s2);`
   * //search a string in a string;
7. `char *strcasestr(const char *s1,const char *s2);`
   * search a string in a string ignoring case difference;

## 枚举

> enum TYPENAME{n1, n2, n3, ...}; n1, n2, n3, ... 都是可引用的常量;

1. 一般在大括号最后的元素用来作为左侧元素数量的计数位;
2. 声明枚举量的时候可以使用 enum TYPENAME{n1 = 1,n2,n3 = 5,...};这样的赋值方式;
3. 比macro 好用, 因为有类型, 可以作为参数类型;
4. 一般用于定义符号量;

## 结构体

### 三种使用方式

1. //先声明后定义;

    ```C
        struct NAME{
            int a;
            char b;
            double c;
            ...
        };
        struct NAME p1, p2;
    ```

2. 定义两个匿名结构体变量p1, p2;

    ```C
        struct{

            int a;
            char b;
            double c;
            ...

        }p1, p2;
    ```

3. 声明结构体的同时定义p1, p2两个变量;

    ```C
        struct NAME{

            int a;
            char b;
            double c;
            ...

        }p1, p2;
    ```

### 赋值方式

1. `struct NAME p1 = {a1,b1,c1,...};`, 顺序赋值;
2. `struct NAME p1 = {.a = a1,.c = c1,...};`, 指定赋值;
3. `p1 = (struct NAME){a2,b2,c2,...};`, 整体赋值

### 访问成员/元素

1. `struct NAME p1;int x = p1.a;`, 通过变量名直接访问;
2. `struct NAME p1,*pp1 = &p1; int x = pp1->a;`, 通过指向变量的指针间接访问;

### 可以建立结构体数组

`struct NAME p1[5];`

## typedef

```C
    typedef orgType tag;
```

1. 用于将`orgType`类型 用`tag`替换;
2. 常用 `typedef struct NAME name` 来`简化使用结构体`;
3. 下述结构可以再定义时将一个结构体用指定NAME代替表示;

```C
        typedef struct{
            ...
        } NAME;
```

## union

1. 所有成员共享一个存储空间;
2. 同一时刻只有一个成员是有效的;
3. union的大小是其最大的成员大小;
4. 初始化是对第一个成员做初始化;
5. 可以用于求得一个整数内部的各个字节;(注意小端存储会让printf输出倒置,一般的x86/64机器都是小端存储)

    ```C
        typedef union {
            int i;
            unsigned char ch[sizeof(int)];
        } CHI;

        CHI chi;
        chi.i = 1234;
        for(int i = 0;i<sizeof(int);i++)
        {
            printf("%02hhX",chi.ch[i]);
            //Note:Little-endian storage will make it's output upside down.
        }
    ```

## 全局变量

1. 定义在函数外面的变量就是全局变量;
2. 没有做初始化的全局变量会自动为0,全局指针变量会得到NULL值;
3. 一般全局变量不应当与其他的全局变量相关联;(否则会涉及到一个初始化顺序问题,特别是多文件编译)
4. 全局变量会被同名局部变量在后者作用范围内覆盖(这一条对局部变量自身也适用);
5. 尽量避免使用全局变量;(主要是对于多线程、多文件联合运行不安全)

## 一些常见的预定义参数(包括周围的__)

1. `__LINE__` = 当前行;
2. `__FUNC__` = 是当前函数的名字;
3. `__FILE__` = 当前文件名;
4. `__DATE__` = 文件编译日期;
5. `__TIME__` = 文件编译时间;
6. `__STDC__` = 当值为 1 时, 表示当前文件严格按照ANSIC标准编译;

## C语言的编译链

1. `*.c/*.h`: C语言文本文件;
2. 在gcc 命令的最后加入 `--save-temps` 命令可以将编译过程的中间文件保存下来。
   * (CMakeLists.txt 中可以使用`add_compile_options(--save-temps)`)
   * 共会按照顺序多出下列三类新文件
     1. =>`*.i`: 做完预处理的C文件;
        * 预处理(主要为处理 `#` 开头的所有指令(`除了 #pragma` ), `删除注释`, `添加行号和文件名`)(调用文本编辑器)
     2. =>`*.s`: 汇编语言文件;
        * => C语言转汇编语言(主要包括词法、语法、语义分析和优化工作)(调用编译器)
     3. =>`*.o`: 机器语言文件(汇编之后的目标代码文件); (每个模块的源代码文件)
        * => 汇编语言转二进制码(调用汇编器)
3. `.out/.exe`: 可执行文件;
   * => 链接(将外部引用与内部对应位置相连接, 主要是地址处理和空间分配, 其中重定向 = 重新计算各个变量的地址)(调用链接器)

## 预处理指令 = `#`开头的指令

### 常见预处理语句

1. #include< name >/"name"
2. #define value tag
3. #ifndef tag = if not define
4. #ifdef tag = if define
5. #if tag = if
6. #elif tag = else if
7. #else = else
8. #endif = endif

### 在预处理中用到的额外符号(注意, 所有操作在预处理阶段就会完成)

1. `#` = `stringification sign`
    * 如果在define语句中的被替代部分使用 `#` 作为输入变量前缀, 那么输入变量本身将会被视为一个字符串;
    * e.g: #define rep(y) ##y; //使用例子: rep(who's your daddy?), 然后返回值就会是字符串`who's your daddy?`
2. `##` = `pasting operator`
    * 如果在define语句中的被替代部分使用 `##` 作为输入变量间连接符, 那么两个输入量本身会被拼接为一个字符串;
    * e.g: `#define comb(x, y) x##y;` //使用例子: comb(com, bine), 返回值会是变量名 `combine`;
3. `()` 变量保护
    * 由于宏定义的`直接替换`的特性, 其变量如果不用 () 框起来 < 即使是单字母变量也需要逐个框起 > , 在运算时就会出现因为实际优先级产生的运算错误;
    * e.g: `##define sqr(x) x * x` // 若使用时写为u = 16/sqr(4), 则实际计算过程为u = (16 / 4) * 4, 因为运算优先级相同时从左到右顺序计算;

### 宏 & 宏函数

1. #define NAME (variable1,variable2,...) (command-line...)
   * 所有的参数都需要被圆括号包裹, 包括command-line内的部分;
2. 宏 的最后没有 *;* ;
3. 宏没有类型检查;
4. 推荐将后半部分实体用do{}while(0)包裹;

## 头文件与联合编译

1. 在主文件和库文件中都需要包含头文件;
2. 对于MinGW ,标准库头文件在../MinGW/include文件夹中;
3. 标准头文件结构

    ```C
        #ifndef _NAME_H_
        #define _NAME_H_
        ...
        #endif
    ```

4. 或者, 在较新的编译器上, 也支持直接在文件开头直接声明这种(但是这并不是跨平台的):

    ```C
        #pragma once
    ```

   * 这样写前向历史兼容性不好, 但是这样的使用方式可以规避不同文件对应的的保护宏的冲突问题, 这是前者无法规避的;

## 声明和定义

1. 声明不会产生代码
2. 声明包括
   * 函数原型
   * 变量声明
   * 结构声明
   * 宏声明
   * 枚举声明
   * 类型声明
   * inline函数
3. 定义会产生代码
4. 定义包括
    * 函数定义
    * 变量定义

## 格式化输入输出

### printf

```C
    //标准的格式结构定义如下
    %[flags][width][.prec][hlL]<type>
```

1. `flags` = `-`(左对齐) / `+`(强制输出数字符号,不与-一同使用) / `(space)`(正数留空) / `0`(0填充),在使用他们时,需要使用 `[]` 进行框选,以示区别。
2. `width`和`prec`
   1. `width` = 整体数字最小宽度(包括小数部分和小数点)
   2. `prec` = 小数部分最大宽度
   3. 关于`width` 和 `prec` : 用 `*` 会让对应位置的填充参数作为`width`或者`prec`的值;
       * e.g.: `printf("%*.*d",5,1,100);` 表示输出总长 = 5,小数部分为1,值为100的结果;
3. `hlL` = 三种类型修饰符
    * `hh` = 单字节
    * `h` = short
    * `l` = long
    * `ll` = long long
    * `L` = long double
4. `type` = 数据类型
    * `c`   = char
    * `i/d` = int
    * `u`   = unsigned int
    * `o/O` = 八进制
    * `x/X` = 十六进制
    * `a`   = 十六进制float
    * `f`   = float(wid = 6)
    * `g`   = float
    * `e/E` = 指数格式的float
    * `s`   = string
    * `p`   = point
    * `n`   = save num of chars which has been used in the corresponding variable behind "..."(用gcc未实现)
5. printf函数返回值为它读入的所有数据数目;

#### scanf

```C
    %[integerPartWidth.decimalPartWidth]<type>
```

1. flag = printf_hlL
2. type = printf_type OR [...]
3. 关于 `%i` ,可以将输入的十六进制字符识别出并转换为十进制;
4. 关于 [...], 正则表达式;
5. scanf函数返回值为它输出的所有符号数目;

#### 重定向输出内容

1. `运行程序时`(不是编译)在command最后加入 `> < filename >` 就可以将文件的输出内容放入这个指定的文件中;
2. `运行程序时`(不是编译)在command最后加入  `< < filename >` 就可以将文件的内容作为输入;

#### sprintf

* `sprintf(*point, "format string", variables);`
* 其中point用来存储制造好的字符串;

#### fopen

* `fopen("filename", "moudle");`
* moudle = r(ead)/w(rite)/a(dd)/r+/w+/b(binary);

#### fprintf

`fprintf(*data, elem_length, elem_number, *file);`

#### fscanf

`fscanf(*save, elem_length, elem_number, *file);`

## windows 的注册表

1. 注册表是一个非常大的文件
2. 所有程序的配置信息都在注册表中
3. 需要专门的程序来读取注册表
4. Unix只需要用文本进行配置;

## 逻辑运算符

1. `&`    = 算数与;(用于指定位取0)
2. `|`    = 算数或;(用于指定位取1)
3. `~`    = 算数非(按位全体取反);
4. `&&`   = 逻辑与;(全1则1, 否则0)
5. `||`   = 逻辑或;(全0则0, 否则1)
6. `!`    = 逻辑非(0->1, 非0->0);
7. `^`    = 按位异或; (不等为1), 对一个变量用同一个值异或两次等于空操作 , 用一次等于将掩码中为1的对应位取反(用于指定位取反);
8. `<<`   = 左移; ( x << n) , 将x左移n位, 低位补0; (与符号无关)
9. `>`    = 右移; ( x >> n) , 将x右移n位, 高位补二进制最高位(符号不变, 但值可能受符号影响);
   * 对于一个负数而言 , 相当于除以$2^n$再加上-1.
10. 左移右移运算常用于制作单片机控制寄存器控制掩码; (掩码目标位为1, 那么或上 *掩码* 置1, 与上 *~ 掩码* 置0);

## 三目运算符

* `(statement) ? < return when statement == true > : < return when statement == false >`
