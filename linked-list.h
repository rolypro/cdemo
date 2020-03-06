#ifndef LINKEDLIST_H

#define LINKEDLIST_H

//link指针
typedef struct node *link;
struct node
{
    unsigned char item;
    link next;
};

link make_node(unsigned char item);
void free_node(link p);
link search(unsigned char key);
void insert(link p);
void del(link p);
void traverse(void (*visit) (link));
void destroy(void);
void push(link p);
link pop(void);
void reverse(void);

#endif