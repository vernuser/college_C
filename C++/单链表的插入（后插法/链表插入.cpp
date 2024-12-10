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

int IsNull_Link(LinkList llist)
{
    return(llist->next == NULL);
}

void CreateList(struct Node *head)
{
    PNode p = NULL;  int data;
    scanf("%d", &data);
    while (data != -1) { 
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = data;  
        p->next = head->next;  
        head->next = p;
        scanf("%d", &data);
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
    PNode  pre = head; PNode p = pre->next;
    while (p) {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}
int InsertPost_link(LinkList llist, DataType x, DataType y)
{
    PNode q;
    PNode p=llist;
    q=(PNode)malloc(sizeof(struct Node));
    while(p != NULL && p->data != x)
    {
        p=p->next;
    }
    if(p==NULL)
    {
    	printf("not exist data %d\n",x);
    	return 0;
	}
    q->data=y;
    q->next=p->next;
    p->next=q;
}
int main()
{
    LinkList head = NULL;
    PNode p = NULL;
    int searchdata,deldata, insertdata;
    head = SetNullList_Link();

    CreateList(head);
    
    scanf("%d %d", &searchdata,&insertdata);
    InsertPost_link(head, searchdata, insertdata);
    print(head);

    DestoryList_Link(head);
    return 0;
}



