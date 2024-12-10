#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[20]; 
    char sex; 
} DataType;

struct Node {
    DataType      data;
    struct Node*  next;
};
typedef struct Node  *PNode;
struct Queue
{
    PNode        f;
    PNode        r;
};
typedef struct Queue *LinkQueue;
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
    }
    else
        return (lqueue->f->data);
}


void DancePartner(DataType dancer[], int num)
{
	LinkQueue Mdancers = SetNullQueue_Link();
	LinkQueue Fdancers = SetNullQueue_Link();
    int i;
    for (i = 0; i < num; ++i) 
    {
        if (dancer[i].sex == 'M')
            EnQueue_link(Mdancers,dancer[i]);
        else{
            EnQueue_link(Fdancers,dancer[i]);
        }
        if (dancer[i].sex == 'M')
        {
            if (IsNullQueue_link(Fdancers) != 1)
            {
                printf("%s %s\n",FrontQueue_link(Fdancers).name,FrontQueue_link(Mdancers).name);
                DeQueue_link(Mdancers);
                DeQueue_link(Fdancers);
            }

        } 
        else
        {
            if(IsNullQueue_link(Mdancers) != 1)
            {
                printf("%s %s\n",FrontQueue_link(Fdancers).name,FrontQueue_link(Mdancers).name);
                DeQueue_link(Mdancers);
                DeQueue_link(Fdancers);
            }
        }
    }
    printf("\n");
    if (IsNullQueue_link(Mdancers) != 1)
        printf("%s",FrontQueue_link(Mdancers).name);
    if (IsNullQueue_link(Fdancers) != 1)
        printf("%s",FrontQueue_link(Fdancers).name);
}


int main()
{
    DataType dancer[9];
    int i;
    for (i = 0; i < 9; i++)
    scanf("%s %c", dancer[i].name, &dancer[i].sex);
    DancePartner(dancer, 9);
    return 0;
}