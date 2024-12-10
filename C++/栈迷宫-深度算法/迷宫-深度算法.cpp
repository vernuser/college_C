#include<stdio.h>
#include<stdlib.h>

struct MAZE
{
    int size;
    int **data;
};
typedef struct MAZE Maze;

typedef int DataType;
struct Node
{
	DataType data;
	struct Node* next;
};
typedef struct Node *PNode;
typedef struct Node *top, *LinkStack;

LinkStack SetNullStack_Link()			//创建空栈 
{
	LinkStack top = (LinkStack)malloc(sizeof(struct Node));
	if(top!=NULL)
		top->next = NULL;
	else
		printf("Alloc failure");
	return top;
}

int IsNullStack_link(LinkStack top)
{
	if(top->next==NULL)
		return 1;
	else
		return 0;
}

void Push_link(LinkStack top, DataType x)//入栈 
{
	PNode p;
	p=(PNode)malloc(sizeof(struct Node));
	if(p==NULL)
		printf("Alloc failure");
	else
	{
		p->data=x;
		p->next=top->next;
		top->next=p;
	}
}

void Pop_link(LinkStack top)			//出栈 
{
	PNode p;
	if(IsNullStack_link(top))
		printf("it is empty stack!");
	else
	{
		p=top->next;
		top->next=p->next;
		free(p);
	}
}

DataType Top_link(LinkStack top)		//返回栈顶元素 
{
	if(IsNullStack_link(top))
		printf("it is empty stack!");
	else
		return top->next->data;
}

int MazeDFS(int entryX, int entryY, int exitX, int exitY ,Maze* maze)//找出口算法 
{
	int direction[8][2] ={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
	//8个方向
	LinkStack linkstackX = NULL;	//用两个栈，分别存放路径中的点 
	LinkStack linkstackY = NULL;
	int posX,posY;					//临时变量，存放坐标(x,y)
	int preposX,preposY;
	int **mark;						// 标记二维数组，标记那些点走过，不重复走
	int i,j;						//循环变量
	int mov;						//移动方向
	//给做标记的二维数组分配空间，并赋初值 
	mark = (int**)malloc(sizeof(int*)*maze->size);
	for(i=0;i<maze->size;i++)
		mark[i] = (int*)malloc(sizeof(int)*maze->size);
	for(i=0;i<maze->size;i++)
	{
		for(j=0;j<maze->size;j++)
			mark[i][j]=0;
	}
	linkstackX = SetNullStack_Link();//初始化栈 
	linkstackY = SetNullStack_Link();
	mark[entryX][entryY]=1;			//入口点设置标志位 
	Push_link(linkstackX, entryX);	//入口点入栈 
	Push_link(linkstackY, entryY);
	
	while(!IsNullStack_link(linkstackX))//如果栈不为空且还没有找到迷宫出口 
	{
		preposX = Top_link(linkstackX);
		preposY = Top_link(linkstackY);
		Pop_link(linkstackX);
		Pop_link(linkstackY);
		mov = 0;
		while(mov<8)
		{
			posX = preposX + direction[mov][0];
			posY = preposY + direction[mov][1];
			
			if(posX==exitX&&posY==exitY)		//找到出口 
			{
				Push_link(linkstackX,preposX);
				Push_link(linkstackY,preposY);
				printf("%d %d;",posX,posY);
				while(!IsNullStack_link(linkstackX))
				{
					posX = Top_link(linkstackX);
					posY = Top_link(linkstackY);
					Pop_link(linkstackX);
					Pop_link(linkstackY);
					printf("%d %d;",posX,posY);
				}
				return 1;
			}
			
			//还有路可以走
			if(maze->data[posX][posY]==0&&mark[posX][posY]==0)
			{
				mark[posX][posY]=1;
				Push_link(linkstackX,preposX);
				Push_link(linkstackY,preposY);
				preposX = posX;
				preposY = posY;
				mov = 0;		//重置方向 
			}
			else	mov++;
		}
	} 
	return 0; 
} 

void WriteMaze(Maze *maze)
{
	int i,j;
	maze->data = (int**)malloc(sizeof(int*)*maze->size);
	for(i=0;i<maze->size;i++)
		maze->data[i] = (int*)malloc(sizeof(int)*maze->size);
	for(i=0;i<maze->size;i++)
	{
		for(j=0;j<maze->size;j++)
			scanf("%d",&maze->data[i][j]);
	}
} 

int main()
{
	Maze *maze;
	int size;
	int entryX,entryY;
	int exitX,exitY;
	scanf("%d",&size);
	
	maze = (Maze*)malloc(sizeof(Maze));
	maze->size = size;
	WriteMaze(maze);
	scanf("%d %d %d %d",&entryX,&entryY,&exitX,&exitY);
	MazeDFS(entryX,entryY,exitX,exitY,maze);
	return 0;
}
