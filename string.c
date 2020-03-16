#include "stdio.h"
#include "stdlib.h"
#include "string.h"


//https://blog.csdn.net/flyapy/article/details/38475817
//https://www.jianshu.com/p/367fe0e2976c

void swap(char *a, char *b) {
    unsigned char tmp = *a;
    *a = *b;
    *b = tmp;
}

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
    // 方法1
    // for(; ((*dst_1 = *src) != '\0') && (n > 1); ++dst_1, ++src, --n);
    // 方法2
    while (n) {
        if (src != 0) {
            *dst_1 = *src++;
        }
        dst_1++;
        n--;
    }
    dst_1 = '\0';
    return dst;
}

char* my_strcat(char * str1,char * str2) {
    char *tmp = str1;
    while(*tmp != 0) tmp++;
    while((*tmp++ = *str2++) != 0);
    *tmp = '\0';
    return str1;
}

char *my_strncat(char *dest, const char *src, size_t n) {
    char *tmp = dest;
    while (*tmp != 0) tmp++;
    while ((*tmp++ = *src++) != 0 && n > 0) --n;
    *tmp = '\0';
    return dest;
}

//str1<str2,返回负数; str1=str2,返回 0; str1>str2,返回正数.  
int my_strcmp(char * str1, char * str2) {
    unsigned char c1, c2;
    while(1) {
        c1 = *str1;
        c2 = *str2;

        //如果不一致
        if (c1 != c2) {
            return c1 < c2 ? -1 : 1;
        }

        //如果是对比完了
        if(!c1) 
            break;

        str1++;
        str2++;
    }
    return 0;
}

//按字典顺序比较两个串s1和s2的前n个字节  
//函数返回:   <0,=0,>0分别表示s1<,=,>s2 
int my_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *su1, *su2;
    int res = 0;
    for(su1 = s1, su2 = s2; n > 0; ++su1, ++su2, n--) {
        if ((res = *su1 - *su2) != 0)
            break;
    }
    return res;
}

//找出str2字符串在str1字符串中第一次出现的位置(不包括str2的串结束符) 
char* my_strstr(char* str1,char* str2) {
    int l1 = my_strlen(str1);
    int l2 = my_strlen(str2);
    

    while(str1 != 0) {
        int l1 = my_strlen(str1);
        if(l1 < l2) return NULL;    //长度不够长了直接返回

        if (my_memcmp(str1, str2, l2) == 0) return str1;
        ++str1;
    }
}

//字符串反转
char *my_strrev(char *s) {
    char *head = s;
    char *tmp = s;
    s = s + my_strlen(s) - 1;
    while(1) {        
        swap(tmp, s);
        if(tmp == s || tmp+1 == s) break;
        ++tmp;
        --s;
    }
    return head;
}

int main() {

    char *str = "hello world";
    printf("%u, %u\n",my_strlen(str), strlen(str));

    char dst[20];
    my_strcpy(dst, str);
    printf("%s, %s\n",str, dst);
    

    char dst1[20];
    // char *dst = (char *)malloc(sizeof(char) * 20);       //开辟内存的方式会乱码
    my_strncpy(dst1, str, 5);
    printf("%s, %s\n",str, dst1);
    // free(dst);

    char dst2[50] = "hi,I'm Bruse Li. ";
    my_strcat(dst2, str);
    printf("%s\n",dst2);

    char dst3[50] = "hi,I'm Bruse Li. ";
    my_strncat(dst3, str, 5);
    printf("%s\n",dst3);

    char *cmp_str1 = "hello";
    char *cmp_str2 = "hello";
    printf("my_strcmp: %d\n",my_strcmp(cmp_str1, cmp_str2));

    char *mem_str1 = "abcdef";
    char *mem_str2 = "abcdef";
    printf("my_memcmp: %d\n",my_memcmp(mem_str1, mem_str2, 6));

    char *str2 = "a hello fds";
    char *str3 = "hello";
    printf("strstr: %s", my_strstr(str2, str3));

    char str4[] = "hello";       //如果声明称指针，该字符串是无法进行修改的，要写成数组
    printf("my_strrev: %s\n",my_strrev(str4));

    system("pause");
    return 0;
}