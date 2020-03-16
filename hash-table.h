#include "stdio.h"
#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASH_MAX_SIZE 256   //hashtable最大长度
#define INVALID_VALUE 0   //无效值
typedef char *KEY;
typedef int VALUE;
typedef unsigned char (*HashFunc)(char *);

typedef enum Stat
{
    //以下会从0开始递增
    Empty = 0,     //空，当前没有值
    Valid,     //有效，当前的值有效
    Invalid    //非空但无效，表示当前结点被删除
}STAT;
typedef  int SIZE;

typedef struct node *NODE;
struct node
{
    KEY key;
    VALUE value;
    STAT stat;
    NODE next;

};

typedef struct HashTable
{
    NODE table[HASH_MAX_SIZE];
    size_t size;
    HashFunc hash_func;

}HashTable;

HashTable * init_hash_table(HashTable *ht,HashFunc hash_func);
void inset(char * key, VALUE value);
void Traversal(HashTable *ht,void (*visit)(NODE));

#endif