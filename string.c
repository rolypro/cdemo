#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//https://blog.csdn.net/flyapy/article/details/38475817
//https://www.jianshu.com/p/367fe0e2976c

//单引号代表一个字符  双引号代表字符串有区别
size_t my_strlen(const char *s) {
    const char *sc = s;    
    for(sc = s; *sc != '\0'; ++sc);
    return sc-s;
}

char *my_strcpy(char *dst, const char *src) {
    char *dst_1 = dst;
    for(; (*dst_1 = *src) != '\0'; ++dst_1, ++src);
    dst_1 = '\0';
    return dst;
}

char *my_strncpy(char *dst, const char *src, size_t n) {
    char * dst_1 = dst;
    for(; ((*dst_1 = *src) != '\0') && (n > 1); ++dst_1, ++src, --n);
    dst_1 = '\0';
    return dst;
}


int main() {

    char *str = "hello world";
    printf("%u, %u\n",my_strlen(str), strlen(str));
    // printf("%u %u\n", strlen(str), 1);

    // char *dst = (char *)malloc(sizeof(char) * 20);
    // char dst[20]
    // my_strcpy(dst, str);
    // printf("%s, %s\n",str, dst);
    // free(dst);

    char dst[20];
    // char *dst = (char *)malloc(sizeof(char) * 20);       //开辟内存的方式会乱码
    my_strncpy(dst, str, 3);
    printf("%s, %s\n",str, dst);


    system("pause");
    return 0;
}