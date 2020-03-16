#include "stdio.h"
#include "binary-tree.h"
#include "stdlib.h"

//static局部变量
static link make_node(unsigned char item)
{
    link p = malloc(sizeof *p);
    p->item = item;
    p->left = NULL;
    p->right = NULL;
    return p;
}

static void free_node(link p)
{
    free(p);
}

static void print_node(link p)
{
    printf("%d ",p->item);
}

link init(unsigned char VLR[], unsigned char LVR[], int n)
{

}


link insert(link tree, unsigned char item)
{
    //构造一个子节点
    link p = make_node(item);

    //没有节点，根节点
    if (tree == NULL)
    {
        tree = p;
        return tree;
    }else
    {
        link temp = tree;
        while (temp != NULL)
        {
            if (item<temp->item)
            {
                //进左边
                if(temp->left == NULL)
                {
                    temp->left = p;
                    return tree;
                } 
                temp = temp->left;
            }else
            {
                //进右边
                if(temp->right == NULL)
                {
                    temp->right = p;
                    return tree;
                }    
                temp = temp->right;
            }            
        }
    }
    return tree;
}

//先根遍历
void pre_order(link t, void (*visit)(link))
{
    if(t == NULL)
        return;
    visit(t);
    pre_order(t->left,visit);
    pre_order(t->right,visit);
}

//中根遍历
void in_order(link t, void (*visit)(link))
{
    if (t==NULL)
        return;
    in_order(t->left,visit);
    visit(t);
    in_order(t->right,visit);
}

//后根遍历
void post_order(link t, void (*visit)(link))
{
    if (t==NULL)
        return;
    post_order(t->right,visit);
    post_order(t->left,visit);
    visit(t);
}
int count(link t);
int depth(link t);
void destroy(link t);



void test()
{
    unsigned char items[] = {5,6,2,8,7,1,9,4,3};
    link tree = NULL;
    for (int i = 0; i<9; i++)
    {
        tree = insert(tree,items[i]);
    }

    pre_order(tree,print_node);
    printf("\n");
    in_order(tree,print_node);
    printf("\n");
    post_order(tree,print_node);
}


int main()
{
    test();
    system("pause");
}