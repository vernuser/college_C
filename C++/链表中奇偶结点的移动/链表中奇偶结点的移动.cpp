#include<stdio.h>
#include<stdlib.h>

typedef int DataType; 
struct Node {
    DataType      data; 
    struct Node*  next;  
};
typedef struct Node  *PNode;    
typedef struct Node  *LinkList;   

LinkList CreateList_Tail_loop()
{
    LinkList head = (LinkList)malloc(sizeof(struct Node));
    PNode cur = NULL;
    PNode tail = head;
    DataType data;
    scanf("%d", &data);
    while (data != -1)
    {   
        cur = (struct Node*)malloc(sizeof(struct Node));
        cur->data = data;
        tail->next = cur;
        tail = cur;
        scanf("%d", &data);
    }
    tail->next = head;
    return tail;
}
PNode  Move_Odd_Even(LinkList tail)
{
	PNode last = NULL, p = NULL, pre = NULL, temp = NULL;
	int flag = 1;
	last = tail;
	temp = tail->next;
	pre = tail->next;
	p = (tail->next)->next;
	tail->next = NULL;
	while (flag)
	{
		if (p == tail)
		{
			break;
		}
		if ((p->data) % 2 == 0)
		{
			pre->next = p->next;
			p->next = NULL;
			last->next = p;
			last = p;
			p = pre->next;
		}
		else
		{
			pre = p;	//¼ÇÂ¼pµÄÇ°Çý
			p = p->next;
		}
	}
	if (tail->data % 2 == 0)
	{
		pre->next = p->next;
		p->next = NULL;
		last->next = p;
		last = p;
	}
	last->next = temp;
	tail = last;
	return tail;
}

void print(LinkList tail)    
{
    PNode  head = tail->next;
    PNode p = head->next;
    while (p != head)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void DestoryList_Link(LinkList tail)
{
    PNode pre = tail->next;
    PNode p = pre->next;
    while (p != tail)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
    free(tail);
}

int main()
{
    LinkList tail = NULL;
    LinkList p = NULL;
    tail = CreateList_Tail_loop();
    p = Move_Odd_Even(tail);
    print(p);
    DestoryList_Link(tail);
    return 0;
}

