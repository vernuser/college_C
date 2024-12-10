#include<stdio.h>
#include<stdlib.h>
 
struct tagNode
{
	float coef;
	int exp;
	struct tagNode *next;
};
 
typedef struct tagNode Node;
typedef struct tagNode *PNode;
 
void insertList(PNode head,PNode pnode)
{
	PNode pPre = head;
	while(pPre->next != NULL)
	{
		if(pPre->next->exp>pnode->exp)
		{
			pnode->next = pPre->next;
			pPre->next = pnode;
			break;
		}
		else
		{
			pPre = pPre->next;
		}
	}
	if(pPre->next == NULL)
	{
		pPre->next = pnode;
	}
}
 
void CreateList(PNode head)
{
	int exp;
	float coef;
	PNode pTemp = NULL;
	head->next = NULL;
	scanf("%f,%d",&coef,&exp);
	while(coef != 0 || exp != 0)
	{
		pTemp = (PNode)malloc(sizeof(struct tagNode));
		pTemp->coef = coef;
		pTemp->exp = exp;
		pTemp->next = NULL;
		insertList(head,pTemp);
		scanf("%f,%d",&coef,&exp);
	}
}
 
void printLinkedList(PNode head)
{
	PNode temp = head->next;
	while(temp != NULL)
	{
		printf("%0.0f,",temp->coef);
		printf("%d ",temp->exp);
		temp = temp->next;
	}
	printf("\n");
}
 
void Add_Poly(PNode pa,PNode pb)
{
	PNode p = pa->next;
	PNode q = pb->next;
	PNode pre = pa;
	PNode u;
	float x;
	while(p != NULL && q != NULL)
	{
		if(p->exp < q->exp)
		{
			pre = p;
			p = p->next;
		}
		else if(p->exp == q->exp)
		{
			x = p->coef + q->coef;
			if(x != 0)
			{
				p->coef = x;
				pre = p; 
			 } 
			 else
			 {
				 pre->next = p->next;
				 free(p); 
			 }
			 p=pre->next;
			 
			 u = q;
			 q = q->next;
			 free(u); 
		}
		else
		{
			u = q->next;
			q->next = p;
			pre->next = q;
			pre = q;
			q = u; 
		}
	}
	if(q)
	{
		pre->next = q; 
	}
	free(pb);
}	
	
int main()
{
	PNode head1 = (PNode)malloc(sizeof(struct tagNode));
	PNode head2 = (PNode)malloc(sizeof(struct tagNode));
	CreateList(head1);
	CreateList(head2);
	Add_Poly(head1,head2);
	printLinkedList(head1);
	return 0;
	
}	
	
