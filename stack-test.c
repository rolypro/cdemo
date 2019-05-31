#include "stdio.h"
#include "stdlib.h"

#define LEN 512

//栈
char stack[LEN];
//栈顶
int top = 0;

//出栈
char pop()
{
    return stack[--top];
}

//入栈
void push(char value)
{
    stack[top++] = value;
}

int is_empty()
{
    return top == 0;
}

int main()
{
    push('a');
    push('b');
    push('c');
    push('d');
    while(!is_empty())
        printf("%c ",pop());
    printf("\n");
    system("pause");
    return 0;
}