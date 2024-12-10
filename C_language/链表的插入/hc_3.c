#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
struct Node
{
	DataType data;
	struct Node* next;
};
typedef struct Node *PNode;
typedef struct Node *Linklist;

Linklist SetNullList_Link()
{
	Linklist head=(Linklist)malloc(sizeof(struct Node));
	if(head!=NULL)
	head->next=NULL;
	else
	printf("分配空间失败\n");
	return head;
}

void CreateList(struct Node *head)
{
	PNode p=NULL;
	int data;
	printf("请输入整形类型数据建立链表,以-1结束\n");
	scanf("%d",&data);
	while(data!=-1)
	{
		p=(struct Node*)malloc(sizeof(struct Node));
		p->data=data;
		p->next=head->next;
		head->next=p;
		scanf("%d",&data);
	}
}

void print(Linklist head)
{
	PNode p=head->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

PNode Locate(Linklist llist,int x)
{
	int y;
	PNode p;
	if(llist==NULL)
	return NULL;
	p=llist->next;
	while(p->data!=x&&p!=NULL)
	{
		p=p->next;
	}
	return p;
}

void InsertPost_Link_value(Linklist head,int finddata,int insertdata)
{
	PNode p,q,pre;
	pre=head;
	while(pre->next->data!=finddata)
	{
		pre=pre->next;
	}
	p=pre->next;
	q=(PNode)malloc(sizeof(struct Node));
	q->data=insertdata;
	q->next=p;
	pre->next=q;
}

int main()
{
	int x,y;
	PNode alist;
	alist=SetNullList_Link();
	CreateList(alist);
	print(alist);
	printf("\n请输入要查找的数据:");
	scanf("%d",&x);
	printf("请输入要插入的数据:");
	scanf("%d",&y);
	InsertPost_Link_value(alist,x,y);
	print(alist);
	return 0;
}
