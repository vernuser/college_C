#include <stdio.h>
 
typedef struct BiTNode
{
	struct BiTNode *lchild;
	struct BiTNode *rchild;
	char key;
}BiTNode;
 
 
//��������������� 
char List[100];
int m=0,p=0;
//m����ȡ������������ ��p�����ж� ���ʱ�Ƿ�Ϊ��һ�� ������һ���ⶼҪ�ڿ�ͷ\n�� 
 
//������ʼ�� 
BiTNode *InitBiTree()
{
	BiTNode* t =(BiTNode *)malloc(sizeof(BiTNode));
	t->lchild = NULL;
	t->rchild = NULL;
	t->key='@';
	return t;
}
 
//����������������л�ö����� 
void GetBiTree(BiTNode* bt)
{
	if(List[m]!='\n')
	{
		bt->key=List[m++];
		if(bt->key!='@')
		{
			BiTNode *n=InitBiTree();
			GetBiTree(n);
			if(n->key!='@')bt->lchild = n;
		}
		if(bt->key!='@')
		{
			BiTNode *u=InitBiTree();
			GetBiTree(u);
			if(u->key!='@')bt->rchild = u;
		}
	}
}
//����һ���ݹ麯�� 
 
//����������� 
void  PrintTree(BiTNode* x)
{	
 	if(p==0)p++;
 	else printf("\n");
	printf("%c  ",x->key);
	if(x->lchild)printf("0  ");
	else printf("1  ");
	if(x->rchild)printf("0");
	else printf("1");		
}
 
//������������ 
void  OutTree(BiTNode* x)
{	
	BiTNode* n = x->lchild ;
	BiTNode* u = x->rchild ;
	if(n)OutTree(n);
	PrintTree(x);
	if(u)OutTree(u);
}
//����һ���ݹ麯�� 
 
//д�������� 
int main()
{ 	
    gets(List);
	BiTNode *bt=InitBiTree();
	GetBiTree(bt);
	OutTree(bt);
} 