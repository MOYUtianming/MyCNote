# 技巧与常用算法实现

## 浮点运算、除法的商结果应当使用double变量存储

## "double x = 1.0*(...)"可以让圆括号里的变量成为浮点数

## 1.0/x  可以用于求解x的倒数

## sign = 1 ; sign = -sign; x = sign*u; 可以用于处理振荡级数的计算

## 取值区间二分法（可用于求简单方程）

## 无论哪个while，后面的都是进入条件

## 使用x + 'a'-'A' 可以将x对应的大写字母转为小写字母

## 使用x + 'A'-'a' 可以将x对应的小写字母转为大写字母

## 跳出多重循环的两种方法

1. flag + if_break组合(break用于跳出循环/终结switch_case结构 , continue用于终止当次子过程并重新判断循环条件)
2. goto + 标志（结构为顶格的flag:） 组合（goto语句一般只在这个场合可以使用）

## 求最大值

    int x=0, y=0;
    scanf("%d%d",&x,&y);
    int max = (x-y>0)?x:y;

## 辗转相除法（用于求两个数的最大公约数）

    int u=0, v=0;
    scanf("%d%d",&u,&v);
    int max = (u-v>0)? u:v;
    int min = (u-v<=0)? u:v;
    //初始为两个数中较大的数除以另一个取余
    //之后若余数不为零则用前式中除数除以前式中余数取余
    //用余数为零作为循环中止条件
    //将最后一个有效除数作为最大公约数
    //需要注意的是,由于循环中的赋值语句的效果,最后跳出循环时,除数有效值被存在原先的被除数容器中,余数有效值被存在原先的除数容器中,所以实际使用时,应将被除数作为输出变量,除数作为判定条件用变量.
    printf("max  min  temp\n");
    while(min!=0){
        int temp = max%min;
        printf("%d  %d  %d\n",max,min,temp);
        max = min;
        min = temp;
    }
    printf("%d",max);

## 求最大公约数拓展_约分最简分式

顺序输入 分子(被除数)/分母(除数) ，求它的最简分式

    int dividend = 0,divisor = 1;
    scanf("%d/%d\n",&dividend,&divisor);
    int remainder = 0;
    int max = (dividend - divisor > 0)?dividend : divisor;
    int min = (dividend - divisor <=0)?dividend : divisor;
    while(min != 0){
        remainder = max % min;
        printf("%d,%d,%d\n",max,min,remainder);
        max = min;
        min = remainder;
    }
    printf("the max common divisor is %d\n",max);
    printf("the simplest fraction is %d/%d\n",dividend/max,divisor/max);

## x%10 可以用于得出x的最低位

## 倒/逆序输出一个数(取模法)

    int x=0;
    scanf("%d",&x);
    int out = 0;
    do{
        int d = x%10;//d是x最低位
        printf("%d",d);
        if(x>9)
        {
            printf(" ");
        }
        out = out*10 + d;
        x/=10;
    }while(x>0);
    printf("\nout = %d\n",out);

## 正序输出一个数(掩模法)

    int x=0;
    scanf("%d",&x);
    int mask = 1;
    int t = x;//中间变量
    while(t>9){
        t /= 10;
        mask *=10;
    }//用于得到mask;
    printf("x=%d, mask=%d\n",x,mask);
    do{
        int d= x/mask;
        printf("%d",d);
        //下面的程序可选
        if(mask>9){
            printf(" ");
        }
        x %= mask;
        mask /= 10;
    }while(mask > 0);//注意停止条件;
    printf("\n");

## 循环输出时可以使用特定的if判断解决最后输出空格 || 回车这类问题

    int n = 0;
    int cnt = 0;
    scanf("%d",&n);
    int i = 0;
    int temp = n;
    for (i=0;i < n;i++)
    {
        //这里是主要输出部分
        printf("%d",temp--);
        //这里是辅助符号输出部分
        cnt++;
        if(cnt==6)
        {
            printf("\n");
            cnt = 0;
        }
        else
        {
            printf(" ");
        }
    }

## 求指定位数水仙花数
/*
三位的水仙花数共有4个：153，370，371，407；
四位的四叶玫瑰数共有3个：1634，8208，9474；
五位的五角星数共有3个：54748，92727，93084；
六位的六合数只有1个：548834；
七位的北斗七星数共有4个：1741725，4210818，9800817，9926315；
八位的八仙数共有3个：24678050，24678051，88593477
*/

定义：一个N位数（N>=3），它的每个位上的数字的N次幂之和等于它本身。

    int N = 0;
    scanf("%d",&N);
    int i = 0;
    int base = 1,max = 1;
    for(i = 1;i < N;i++)
    {
        base *= 10;
        max *= 10;
    }
    max *= 10;

    while(base < max)
    {
        int sum = 0;
        int temp = base;
        do{
            //拿到余数
            int temp2 = temp%10;
            temp /= 10;
            //循环自乘N次
            int temp3 = 1;
            for(i=0;i<N;i++)
            {
                temp3 *= temp2;
            }
            sum += temp3;
        }while(temp != 0);
        if(sum == base)
        {
            printf("right = %d\n",base);
        }
        base++;
    }

## 求区间内素数+素数个数

    int H=0,E=0;
    scanf("%d %d",&H,&E);
    int cnt;//统计位;
    if(H == 1)
        H = 2;
    if(E<H)
    {
        printf("error,the end number should larger than head number!");
        getchar();
        return 1;
    }
    int i = 0;
    for(i=H;i<E;i++)
    {
        int IsPrime = 1;
        int k = 0;
        for(k = 2;k < i-1;k++)//对i 判断;
        {
            if(i % k == 0)
            {
                IsPrime = 0;
                break;
            }
        }
        if(IsPrime)
        {
            cnt++;
            printf("%d\tis\t%d\n",cnt,i);
        }
    }
    printf("the count of them is :%d\n",cnt);

## 求区间内素数(构造数组法)

    int x;
    printf("Please input the upper limit.\n");
    scanf("%d",&x);

    const int num = 2000;
    int prime[num];
    int temp = 0,temp2 = 0,temp3 = 0;
    for(temp = 0;temp < x;temp++)
    {
        prime[temp]=1;
    }
    for(temp = 2;temp < x;temp++)
    {
        if(prime[temp])
        {
            for(temp2 = 2;temp2*temp < x;temp2++)//find all multiples of temp;
            {
                prime[temp2 * temp] = 0;//make these multiples' flag become 0;
            }
        }
    }
    temp2 = 0;
    // print the result;
    for(temp = 0;temp<x;temp++)
    {
        if(prime[temp])
        {
            printf("%d",temp);
            temp2++;
            if(temp2 % 5 == 0)
            {
                printf("\n");
            }
            else
            {
                printf("\t");
            }
        }
    }

## 输出一个数的二进制

    int x = 0;
    scanf("%i",&x);
    unsigned int mask = 1u<<31;//制作0x8000000000000000;
    for(;mask;mask>>=1)
    {
        printf("%d",(mask & x)?1:0);
    }
    printf("\n");

## *(int*)&NAME 语句可以用来将结构体作为一个int进行处理, 这样相当于制作了一个位段, 可以用线性复杂度访问成员

    但是由于大小端、编译器等问题,基于位段的程序不具有可移植性;

## 判断闰年
//闰年是指满足如下条件的年数:
//1:Num!==100 * n && Num==4 * m;
//2:Num==400 * j;
//注:上述条件中n,m,j都是正整数.

    int N=0;
    scanf("%d",&N);
    while(N<=0)
    {
        printf("illegal input");
        scanf("%d",&N);
    }

    if(N%100!=0&&N%4==0||N%400==0)
    {
        printf("the number is right\n");
    }
    else
    {
        printf("it's not the point year num\n");
    }

## 解任意阶方程

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "math.h"

    typedef struct {
        float coef[8];  // 各项系数
        int hi; // 最高次
    } polyn_t;

    // 初始化多项式
    void polyn_init(polyn_t* p, char* const tokens[], int count)
    {
        int n = 0;
        while(count > 0) {
            count--;
            p->coef[n] = strtod(tokens[count], NULL);
            n++;
        }
        p->hi = n - 1;
    }

    // 多项式求值
    float polyn_calc(polyn_t* p, float x)
    {
        float f = 0;
        for(int i = p->hi; i >= 0; i--) {
            f *= x;
            f += p->coef[i];
        }
        return f;
    }

    // 显示多项式
    void polyn_view(polyn_t* p)
    {
        for(int i = p->hi; i >= 0; i--) {
            if(i >= 2)
                printf("%.3f * x^%d + ", p->coef[i], i);
            else if(i == 1)
                printf("%.3f * x + ", p->coef[i]);
            else
                printf("%.3f", p->coef[i]);
        }
        printf("\n");
    }

    // 多项式除法
    void polyn_div(polyn_t* p1, polyn_t* p2)
    {
        if(p1->hi < p2->hi)
            return;

        polyn_t tmp, quot;

        quot.hi = p1->hi - p2->hi;
        while(p1->hi >= p2->hi) {
            memset(&tmp, '\0', sizeof(tmp));
            tmp.hi = p2->hi;
            float n = p1->coef[p1->hi] / p2->coef[p2->hi];
            int k = p1->hi - p2->hi;
            for(int i = p2->hi; i >= 0; i--) {
                tmp.coef[i + k] = p2->coef[i] * n;
            }
            for(int i = p1->hi; i >= 0; i--) {
                p1->coef[i] -= tmp.coef[i];
            }
            quot.coef[k] = n;
            p1->hi--;
        }
        memset(p1, '\0', sizeof(*p1));
        memcpy(p1, &quot, sizeof(*p1));
    }

    // 在(x1, x2)区间内寻找一根
    float polyn_searchroot(polyn_t* p, float x1, float x2)
    {
        while(x2 - x1 > 1e-20) {
            float mid = (x2 + x1) / 2;
            float y1 = polyn_calc(p, x1);
            float y2 = polyn_calc(p, x2);
            float ymid = polyn_calc(p, mid);
            if(ymid == 0) {
                return mid;
            }
            if(y1 * ymid < 0)
                x2 = mid;
            else if(ymid * y2 < 0)
                x1 = mid;
            else
                return FP_SNAN;
        }
        return FP_SNAN;
    }

    // 解方程
    void polyn_solve(polyn_t* p)
    {
        int count = 1;
        while(p->hi >= 1) {
            if(polyn_calc(p, 0) == 0) {
                polyn_div(p, &(polyn_t) { {0, 1}, 1});
                printf("x%d = 0\n", count);
                count++;
            }
            else {
                float y0 = polyn_calc(p, 0);
                float x = x, y;
                int state = 0;
                for(float xi = 1e-10; xi < 1e10; xi *= 1.01) {
                    y = polyn_calc(p, -xi);
                    if(y * y0 < 0) {
                        x = polyn_searchroot(p, -xi, 0);
                        state = 1;
                        break;
                    }
                    y = polyn_calc(p, xi);
                    if(y * y0 < 0) {
                        x = polyn_searchroot(p, 0, xi);
                        state = 1;
                        break;
                    }
                }
                if(state == 0) {
    //                printf("Can't find more roots.\n");
                    exit(1);
                }
                polyn_div(p, &(polyn_t) { {-x, 1}, 1});
                printf("x%d = %f\n", count, x);
                count++;
            }
        }
    }

    int main(void)
    {
        static char buf[256], seps[] = ", ";
        char* token;
        char* tokens[8];
        int count = 0;
        fgets(buf, 256, stdin);

        token = strtok(buf, seps);
        while(token != NULL) {
            tokens[count] = token;
            token = strtok(NULL, seps); // Get next token:
            count++;
            if(count >= 8)
                break;
        }
        if(count <= 0) {
            exit(1);
        }
        polyn_t p;
        polyn_init(&p, tokens, count);

        polyn_view(&p);
        polyn_solve(&p);
    }
