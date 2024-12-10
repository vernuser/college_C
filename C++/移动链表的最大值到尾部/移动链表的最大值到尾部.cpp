
#include<stdio.h>
#include<stdlib.h>

typedef int DataType; 
struct Node
{
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

void CreateList_Tail(struct Node* head)
{
    PNode p = NULL;
    PNode q = head;
    DataType data;
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
void MoveMaxToTail (LinkList head)
{
   PNode pre,p,pmax;
   p->next = head ->next;
   pre -> next=head;
   pmax ->next = head;
   while(p->next !=NULL)
   {
   	if(p->data > pmax->data)
   		pmax=p;
   		p->next;
   }
    if(p->data > pmax->data)
   	pmax=p;
   if(pmax->next!=NULL)
   {
   		while(pre->next!=pmax)
   		{
   			pre=pre->next;
		}
		   pre->next=pmax->next;
		   pmax->next=NULL;
		   p->next=pmax;
   }
}


void print(LinkList head)   
{
    PNode  p = head->next;
    while (p)
    {
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
    head = SetNullList_Link();
    CreateList_Tail(head);
    MoveMaxToTail(head);
    print(head);
    DestoryList_Link(head);
    return 0;
}

