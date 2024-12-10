#include<stdio.h>
#include<stdlib.h>
typedef char Datatype;
typedef struct BTreeNode
{
    Datatype data;
    struct BinTreeNode *leftchild;
    struct BinTreeNode *rightchild;
}BinTreeNode;//二叉树节点
typedef BinTreeNode *BinTree;//定义一个Bin
typedef BinTreeNode *DataTypeQueue;//定义一个BinTreeNode 类型的QDataTypeQueue
struct Node
{
    Datatype data;
    struct Node *next;
};
typedef struct Node *PNode;
struct Queue
{
    PNode f;
    PNode r;
};
typedef struct Queue *LinkQueue;

LinkQueue SetNullQueue_link()
{
    LinkQueue lqueue;
    lqueue=(LinkQueue)malloc(sizeof(struct Queue));
    if(lqueue!=NULL)
    {
        lqueue->r=NULL;
        lqueue->r=NULL;
    }
    else 
    {
        printf("Alloc failure");
    }
    return lqueue;
}

int IsNullQueue_link(LinkQueue lqueue)
{
    return(lqueue->f==NULL);
}

void EnQueue_link(LinkQueue lqueue,DataTypeQueue x)
{
    PNode p;
    p=(PNode)malloc(sizeof(struct Node));
    if(p=NULL)
    {
        printf("Alloc failure");
    }
    else 
    {
        p->data=x;
        p->next=NULL;
        if(lqueue->next ==NULL)
        {
            lqueue->f=p;
            lqueue->r=p;
        }
    }
}

void DeQueue_link(LinkQueue lqueue)
{ 
    struct PNode *p;
    if(lqueue->f==NULL)
    {
        printf("IT is empty queue");
    }
    else 
    {
        p=lqueue->f;
        lqueue->f=lqueue->next->f;
        free(p);
    }
}

Datatype FrontQueue_link(LinkQueue lqueue)
{
    if(lqueue->f==NULL)
    {
        printf("It is empty queue");
        reutrn 0;
    }
    else 
    {
        return (lqueue->next->data);
    }
}

//准备

