#include "stdio.h"
#include "stdlib.h"
#include "linked-list.h"

static link head = NULL;

//node 的构造方法
link make_node(unsigned char item)
{
    //malloc需要强转
    link p = (link)malloc(sizeof *p);
    p->item = item;
    p->next = NULL;
    return p;
}

//释放node空间
void free_node(link p)
{
    free(p);
}

//查找
link search(unsigned char key)
{   
    link p = head;
    while(p != NULL)
    {           
        if (p->item == key)
            return p;
        p = p->next;
    }
    return NULL;
}


//插入
void insert(link p)
{
    p->next = head;
    head = p;
}

void del(link p)
{
    link pre;
    if (p == head){
        head = p->next;
        return;
    }

    for(pre = head;pre;pre = pre->next)
    {
        if (p == pre->next)
        {
            pre->next = p->next;
            return;
        }
    }
}

//遍历，使用指针函数处理
void traverse(void (*visit) (link))
{
    link p;
    for(p = head; p; p = p->next)
        visit(p);
}

//释放linkedlist
void destroy(void)
{
    link p = head;
    //释放head,p已经指向head的地址了
    head = NULL;
    while(p)
    {
        link temp = p;
        p = p->next;
        free_node(temp);
    }
}

void push(link p)
{
    insert(p);
}

link pop(void)
{
    if(head == NULL)
    {
        return NULL;
    }        
    else
    {
        link p = head;
        head = head->next;
        return p;
    }
    
}

//反转链表
void reverse(void)
{
    link p = head;
    link q = NULL;  //保存上一个节点 
    while(p != NULL)
    {
        if (p==head)
        {
            q = p;
            p = p->next;
            q->next = NULL; //把原来的头节点next为NULL            
            continue;
        }

        link nextNode = p->next;
        p->next = q;
        q = p;
        p = nextNode;       
    }
    head = q;
}

void print_node(link p)
{   
    if (p==NULL)
    {
        printf("NULL ");
        return;
    }        
    //char 用 %c   unsigned  char  signed char 用 %d
    printf("%d ",p->item);
}

void test()
{
    link p = make_node(1);
    insert(p);
    p = make_node(2);
    insert(p);
    p = make_node(3);
    insert(p);
    p = make_node(4);
    insert(p);

    //a b c d
    traverse(print_node);
    printf("\n");

    reverse();
    traverse(print_node);
    printf("\n");

    del(p);
    //b c d 
    traverse(print_node);
    printf("\n");

    p = make_node(5);
    push(p);
    //e b c d
    traverse(print_node);
    printf("\n");

    p = search(1);
    print_node(p);
    printf("\n");

    p = pop();
    print_node(p);
    printf("\n");

    destroy();
    print_node(head);
    printf("\n");
}

int main()
{
    test();
    system("pause");
}

