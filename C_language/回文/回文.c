#include<stdio.h>
#include<stdlib.h>

typedef char DataType;
struct Node {
    DataType      data;
    struct Node*  next;
};
typedef struct Node  *PNode;
typedef struct Node  *LinkStack;
struct Queue
{
    PNode        f;
    PNode        r;
};
typedef struct Queue *LinkQueue;

LinkStack SetNullStack_Link()  
{
    LinkStack top = (LinkStack)malloc(sizeof(struct Node));
    if (top != NULL) top->next = NULL;
    else printf("Alloc failure");
    return top;  
}

int IsNullStack_link(LinkStack top) 
{
    if (top->next == NULL)
        return 1;
    else
        return 0;
}

void Push_link(LinkStack top, DataType x) 
{
    PNode p;
    p = (PNode)malloc(sizeof(struct Node));
    if (p == NULL)
        printf("Alloc failure");
    else
    {
        p->data = x;
        p->next = top->next;
        top->next = p;
    }
}
void Pop_link(LinkStack top)
{
    PNode p;
    if (top->next == NULL)
        printf("it is empty stack!");
    else
    {
        p = top->next;
        top->next = p->next;
        free(p);
    }
}
DataType Top_link(LinkStack top)
{
    if (top->next == NULL)
    {
        printf("It is empty stack!");
        return 0;
    }
    else
        return top->next->data;
}

LinkQueue  SetNullQueue_Link() 
{
    LinkQueue lqueue;
    lqueue = (LinkQueue)malloc(sizeof(struct Queue));
    if (lqueue != NULL)
    {
        lqueue->f = NULL;
        lqueue->r = NULL;
    }
    else
        printf("Alloc failure! \n");
    return  lqueue;
}

int IsNullQueue_link(LinkQueue lqueue) 
{
    return (lqueue->f == NULL);
}

void EnQueue_link(LinkQueue lqueue, DataType x) 
{
    PNode  p;
    p = (PNode)malloc(sizeof(struct Node));
    if (p == NULL)
        printf("Alloc failure!");
    else {
        p->data = x;
        p->next = NULL;
        if (lqueue->f == NULL) 
        {
            lqueue->f = p;
            lqueue->r = p;
        }
        else
        {
            lqueue->r->next = p;
            lqueue->r = p;
        }
    }
}
void DeQueue_link(LinkQueue lqueue)
{
    struct Node  * p;
    if (lqueue->f == NULL)
        printf("It is empty queue!\n ");
    else
    {
        p = lqueue->f;
        lqueue->f = lqueue->f->next;
        free(p);
    }
}
DataType  FrontQueue_link(LinkQueue lqueue)
{
    if (lqueue->f == NULL)
    {
        printf("It is empty queue!\n");
        return 0;
    }
    else
        return (lqueue->f->data);
}

int main()
{
    DataType ch;
    int flag;
    LinkStack stack_pal = SetNullStack_Link();
    LinkQueue queue_pal = SetNullQueue_Link();
    ch = getchar();
    while (ch != '#')
    {
        Push_link(stack_pal, ch);
        EnQueue_link(queue_pal, ch);
        ch = getchar();
    }
    flag = 1;
    while (IsNullStack_link(stack_pal)&&IsNullStack_link(queue_pal)!=NULL)
    {
        if (Top_link(stack_pal)!=Top_link(queue_pal))
        {
            flag = 0;
            break;
        }
        else 
        {
        Pop_link(stack_pal);
        DeQueue_link(queue_pal);
        }
    }
    if (flag=1)
        printf("this is palindromic");
    else
        printf("this is NOT palindromic");
    return 0;
}