
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
struct Node {
    DataType      data;
    struct Node*  next;
};
typedef struct Node  *PNode;
typedef struct Node  *LinkList;

LinkList SetNullList_Link()
{
    LinkList head = (LinkList)malloc(sizeof(struct Node));
    if (head != NULL) head->next = NULL;
    else printf("alloc failure");
    return head;
}

int IsNull_Link(LinkList llist)
{
    return(llist->next == NULL);
}

void CreateList(struct Node* head)
{
    PNode p = NULL; 
    PNode q = head; int data;
    scanf("%d", &data);
    while (data != -1) 
    {   
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = data;
        p->next = NULL;
        q->next = p;
        q = p;
        scanf("%d", &data);
    }
}

void DelNode_Link(struct Node*head, int deldata)
{
    PNode p=head ->next;
    PNode beforeP = head;
    while (p!=NULL)
    {
        if (p ->data ==deldata)
        {
            beforeP ->next=p->next;
            free (p);
            break; 
        }
     else
     {
         beforeP=p;
         p=p->next;
     }
        if (p==NULL)
        {
            printf("not exist %d\n",deldata);
        }
    }    
}    

void print(LinkList head)
{
    PNode  p = head->next;
    while (p) {
        printf("%d ", p->data); 
        p = p->next;
    }
}
void DestoryList_Link(LinkList head)
{
    PNode  pre = head; 
    PNode p = pre->next;
    while (p) 
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

int main()
{
    LinkList head = NULL;
    PNode p = NULL;
    int deldata;
    head = SetNullList_Link();
    CreateList(head);
    scanf("%d", &deldata);
    DelNode_Link(head, deldata);
    print(head);
    DestoryList_Link(head);
    return 0;
}

