/*
 * @Description: 结构体测试
 * @Author: yc
 * @Date: 2019-05-29 16:31:58
 * @LastEditTime: 2019-05-29 18:37:15
 * @LastEditors: Please set LastEditors
 */


#include "stdio.h"
#include "stdlib.h"
#include "math.h"



//枚举
enum coordinate_type { PECTANGULAR = 1, POLAR};

typedef struct rational
{
    int x, y;
}Rational;


Rational make_rational(int x, int y)
{
    Rational z;
    z.x = x;
    z.y = y;
    return z;
}

//最大公约数
int euclid(int a,int b)
{
    if (a%b == 0)
    {
        return b;
    }else
    {
        return euclid(b,a%b);
    }
    
}

//x 分子   y分母
Rational do_euclid(int x, int y)
{
    int divisor = euclid(x,y);
    if (abs(divisor) != y || (abs(divisor)==abs(x) && abs(divisor) == abs(y)))
    {
        //如果约数不等于分母
        x = x / divisor;
        y = y / divisor;
    }
    return make_rational(x,y);
}

Rational add_rational(Rational a, Rational b)
{
    Rational z;
    //参考小学乘法..
    z.x = a.x * b.y + b.x * a.y;
    z.y = a.y * b.y;
    return do_euclid(z.x,z.y);
}

Rational sub_rational(Rational a, Rational b)
{
    Rational z;
    //参考小学乘法..
    z.x = a.x * b.y - b.x * a.y;
    z.y = a.y * b.y;
    return do_euclid(z.x,z.y);
}

Rational mul_rational(Rational a, Rational b)
{
    Rational z;
    //参考小学乘法..
    z.x = a.x * b.x;
    z.y = a.y * b.y;
    return do_euclid(z.x,z.y);
}

Rational div_rational(Rational a, Rational b)
{
    Rational z;
    //参考小学乘法..
    z.x = a.x * b.y;
    z.y = a.y * b.x;
    return do_euclid(z.x,z.y);
}

void print_rational(Rational z)
{
    printf("%d/%d\n",z.x,z.y);
}

int main(void)
{
    Rational a = make_rational(1, 8); /* a=1/8 */
    Rational b = make_rational(-1, 8); /* b=-1/8 */
    print_rational(add_rational(a, b));
    print_rational(sub_rational(a, b));
    print_rational(mul_rational(a, b));
    print_rational(div_rational(a, b));
    system("pause");
    return 0;
}