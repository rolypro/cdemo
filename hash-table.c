
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include "hash-table.h"


static HashTable *hashTable;

unsigned char BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
 
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
 
    //return (hash & 0x7FFFFFFF);    
	return (hash & 0xFF);  //保留8位，最大255
}

NODE make_node(char *key, VALUE value)
{
    NODE p = (NODE)malloc(sizeof *p);
    p->key = key;
    p->value = value;
    p->next = NULL;
    p->stat = Valid;
}

HashTable * init_hash_table(HashTable *ht,HashFunc hash_func)
{
    ht = malloc(sizeof *ht);
    ht->hash_func = hash_func;
    for(int i = 0; i<HASH_MAX_SIZE; i++)
    {
        ht->table[i] = malloc(sizeof(NODE));
        ht->table[i]->key = NULL;
        ht->table[i]->value = 0;
        ht->table[i]->stat = Empty;
        ht->table[i]->next = NULL;
    }
    return ht;
}

void inset(char * key, VALUE value)
{
    unsigned char index = hashTable->hash_func(key);
    NODE node = make_node(key,value);
    if (hashTable->table[index]->stat != Valid)
    {   
        //没有数据
        hashTable->table[index] = node;
    }else
    {
        //直接覆盖
        NODE temp = hashTable->table[index];
        while(temp)
        {
            if(strcmp(temp->key,key)==0){
                temp->value = value;
                temp->stat = Valid;
                return;
            }
            temp = temp->next;
        }
        temp->next = node;
    }    
}

int get_node(char *key)
{
    unsigned char index = hashTable->hash_func(key);
    NODE node = hashTable->table[index];
    while(node)
    {
        if(strcmp(node->key,key)==0)
        {
            if(node->stat==Valid)
                return node->value;
        }
        node = node->next;
    }
    return INVALID_VALUE;
}

void print_node(NODE n)
{
    printf(" [key:%s value:%d stat:%d] ",n->key,n->value,n->stat);
}

void delete_node(char *key)
{
    //暂时置位无效
    unsigned char index = hashTable->hash_func(key);
    NODE node = hashTable->table[index];
    while(node)
    {
        if(strcmp(node->key,key)==0)
        {
            node->stat = Invalid;
        }
        node = node->next;
    }
}

//遍历
void Traversal(HashTable *ht,void (*visit)(NODE))
{
    for(int i = 0; i<HASH_MAX_SIZE;i++)
    {
        printf("table %d:  ",i);
        NODE n = ht->table[i];
        while(n)
        {            
            visit(n);
            n = n->next;
        }
        printf("\n");
    }
}


void test()
{
    hashTable = init_hash_table(hashTable,BKDRHash);

    char *strList[20]={
        "fdsa","rewf","fds","fdsva","eee","www","qqq","bd","fdskl","vc",
        "vvv","bbb","fdaaasa","ccc","klkk","vnm","f","e","w","a"
    };
    VALUE values[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    for(int i = 0; i<20; i++)
    {
        inset(strList[i],values[i]);
    }
    
    printf("get key %s value %d\n","ccc",get_node("ccc"));
    delete_node("ccc");
    printf("get key %s value %d\n","ccc",get_node("ccc"));
    inset("ccc",888);
    inset("ccc",999);
    printf("get key %s value %d\n","ccc",get_node("ccc"));

}

void main()
{
    test();
    system("pause");
}