#include "stdio.h"
#include "stdlib.h"

#ifndef PARA_CALLBACK_H
#define PARA_CALLBACK_H

typedef void (*callback_t)(void *);  //定义一种函数指针  callback_t
extern void repeat_three_times(callback_t, void *); //需要用extern声明函数

#endif

//void 参数可以是任意类型，但是需要强转
void repeat_three_times(callback_t f, void *para)
{
    f(para);
    f(para);
    f(para);
}

void say_hello(void *str)
{
    printf("hello %s \n",(const char *) str);
}

void count_num(void *num)
{   
    int i;
    for ( i = 1; i < (int)num; i++);

    printf("num %d\n",i);
}

int main()
{
    char * str = "qll";
    repeat_three_times(say_hello,str);
    repeat_three_times(count_num,(void *)10);

    system("pause");
    return 0;

}