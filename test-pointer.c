#include "stdio.h"
#include "stdlib.h"

char *strcpy(char *dst, const char *src)
{   
    char * ret = dst;
    while((*dst++=*src++) != '\0');
    return ret;
}

int main()
{   
    int arr[4][2] = {
        {1,2},
        {3,4},
        {5,6},
        {7,8}
    };

    int (*p)[2] = &arr[0];
    //p是一个二重指针了，指向arr[0]，所以要访问arr[1][1],那么先把 p+1 再把 *(p+1)+1
    //下面两个一样
    printf("%d\n",*(*(p)+1));
    printf("%d\n",p[0][1]);
    printf("%d\n",*(*(p+1)+1));
    
    char dst[15];
    const char *src = "hello world\0";
    char *str = strcpy(dst,src);
    printf("%s\n",str);
    
    system("pause");
    return 0;
}