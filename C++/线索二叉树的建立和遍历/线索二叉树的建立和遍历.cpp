#include <stdio.h>
 
typedef struct BiTNode
{
	struct BiTNode *lchild;
	struct BiTNode *rchild;
	char key;
}BiTNode;
 
 
//数组存入先序序列 
char List[100];
int m=0,p=0;
//m用于取出数组中序列 ，p用于判定 输出时是否为第一行 （除第一行外都要在开头\n） 
 
//建立初始化 
BiTNode *InitBiTree()
{
	BiTNode* t =(BiTNode *)malloc(sizeof(BiTNode));
	t->lchild = NULL;
	t->rchild = NULL;
	t->key='@';
	return t;
}
 
//从数组的先序序列中获得二叉树 
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
//这是一个递归函数 
 
//输出这个树结点 
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
 
//中序输出这个树 
void  OutTree(BiTNode* x)
{	
	BiTNode* n = x->lchild ;
	BiTNode* u = x->rchild ;
	if(n)OutTree(n);
	PrintTree(x);
	if(u)OutTree(u);
}
//这是一个递归函数 
 
//写出主函数 
int main()
{ 	
    gets(List);
	BiTNode *bt=InitBiTree();
	GetBiTree(bt);
	OutTree(bt);
} 