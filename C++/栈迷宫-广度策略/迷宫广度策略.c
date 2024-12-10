#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
struct Node
{
    DataType data;
    struct Node *link;
};
typedef struct Node*PNode;
struct Queue
{
    PNode f;
    PNode r;
};
typedef struct Queue *LinkQueue;
struct MAZE_STRUCT
{
    int size;
    int **data;
};
typedef struct MAZE_STRUCT Maze;
LinkQueue SetNullQueue_Link()//创建空队列
{
    LinkQueue lqueue;
    lqueue=(LinkQueue)malloc(sizeof(struct Queue));
    if(lqueue!=NULL)
    {
        lqueue->f=NULL;
        lqueue->r=NULL;
    }
    else
        printf("Aloc failure!\n");
    return lqueue;
}
int IsNullQueue_Link(LinkQueue lqueue)//判断队列是否为空
{
   return  (lqueue->f==NULL);
}
void EnQueue_Link(LinkQueue lqueue,DataType x)//入队操作
{
    PNode p;
    p=(PNode)malloc(sizeof(struct Node));//申请节点空间
    if(p==NULL)
        printf("Alloc Failure!\n");
    else
    {    p->data=x;//数据域赋值
         p->link=NULL;//指针域赋值
        if(lqueue->f==NULL)//空队列的特殊处理
        {
            lqueue->f=p;
            lqueue->r=p;
        }
        else
        {
            lqueue->r->link=p;//插入队尾
            lqueue->r=p;//修改队尾指针
        }
    }
 
}
void DeQueue_Link(LinkQueue lqueue)
{
    PNode p;
    if(lqueue->f==NULL)
        printf("It is empty queue!\n");
    else
    {
        p=lqueue->f;
        lqueue->f=lqueue->f->link;
        free(p);
    }
}
DataType FrontQueue_Link(LinkQueue lqueue)
{
 
    if(lqueue->f==NULL)
    {
         printf("It is empty queue");
         return 0;
    }
    else
    {
 
        return lqueue->f->data;
    }
 
}
Maze* InitMaze(int size)//初始化一个迷宫
{
    int i;
    Maze*maze=(Maze*)malloc(sizeof(Maze));
    maze->size=size;//maze->size表示迷宫的大小
    maze->data=(int **)malloc(sizeof(int*)*maze->size);//申请空间
    for(i=0;i<maze->size;i++)
    {
        maze->data[i]=(int*)malloc(sizeof(int)*maze->size);
    }
    return maze;
}
void ReadMaze(Maze* maze)
{   int i,j;
    for(i=0;i<maze->size;i++)
    {
 
        for(j=0;j<maze->size;j++)
        scanf("%d",&maze->data[i][j]);
    }
}//将迷宫的结构显示出来,读取迷宫结构
void WriteMaze(Maze* maze)
{
    int i,j;
    printf("迷宫的结构如下：\n");
    for(i=0;i<maze->size;i++)
    {
        for(j=0;j<maze->size;j++)
        {
            printf("%5d",maze->data[i][j]);
        }
        printf("\n");
    }
}
 
 
 
 
int MazeBFS(int entryX,int entryY,int exitX,int exitY,Maze *maze)
{
    LinkQueue linkQueueX=NULL;
    LinkQueue linkQueueY=NULL;
    int direction[8][2]={{0,1},{1,1},{1.0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
    int preposX,preposY;
    int posX,posY;//临时变量，存放坐标点（x,y）
 
    int i,j,mov;
    int **preposMarkX;//记录迷宫行走的前驱X值
    int **preposMarkY;//记录迷宫行走过程中的前驱Y值
    int **Mark;//标记二维数组，标记那些点走过，不再重复走
    //给存放前驱的数组X分配空间
    preposMarkX=(int **)malloc(sizeof(int*)*maze->size);
    for(i=0;i<maze->size;i++)
    {
        preposMarkX[i]=(int *)malloc(sizeof(int)*maze->size);
    }
    //给存放前驱的数组Y分配空间
    preposMarkY=(int **)malloc(sizeof(int*)*maze->size);
    for(i=0;i<maze->size;i++)
    {
        preposMarkY[i]=(int *)malloc(sizeof(int)*maze->size);
    }//给做标记的二维数组分配空间，并附初值
    Mark=(int **)malloc(sizeof(int*)*maze->size);
    for(i=0;i<maze->size;i++)
    {
        Mark[i]=(int *)malloc(sizeof(int)*maze->size);
    }
    for(i=0;i<maze->size;i++)//给所有元素设置初值
    {
        for(j=0;j<maze->size;j++)
        {
            preposMarkX[i][j]=-1;
            preposMarkX[i][j]=-1;
            Mark[i][j]=0;
        }
 
    }
    linkQueueX=SetNullQueue_Link();//创建空队列
    linkQueueY=SetNullQueue_Link();//创建空队列
    EnQueue_Link(linkQueueX,entryX);//迷宫入口点入队
    EnQueue_Link(linkQueueY,entryY);//迷宫入口点入队
    Mark[entryX][entryY]=1;//迷宫设置标志位
    while(!IsNullQueue_Link(linkQueueX))
   {
        preposX=FrontQueue_Link(linkQueueX);//取队头
        DeQueue_Link(linkQueueX);//出队
        preposY=FrontQueue_Link(linkQueueY);//取队头
        DeQueue_Link(linkQueueY);//出队
        //将于当前点相邻且满足一定条件的点放入队列
        for(mov=0;mov<8;mov++)
        {
            posX=preposX+direction[mov][0];
            posY=preposY+direction[mov][1];
            if(posX==exitX&&posY==exitY)//到达出口点
            {
                preposMarkX[posX][posY]=preposX;
                preposMarkY[posX][posY]=preposY;
                while(!(posX==entryX&&posY==entryY))
                {
                    preposX=preposMarkX[posX][posY];
                    preposY=preposMarkY[posX][posY];
                    if(posX==exitX&&posY==exitY)
                        printf("%d %d;",exitX,exitY);
                    posX=preposX;
                    posY=preposY;
                    printf("%d %d;",posX,posY);
                }
                return 1;
            }
            //如果能走，且没有被扩展过
            if(maze->data[posX][posY]==0&&Mark[posX][posY]==0)
            {
                EnQueue_Link(linkQueueX,posX);//入队扩展
                EnQueue_Link(linkQueueY,posY);
                Mark[posX][posY]=1;//做标记
                preposMarkX[posX][posY]=preposX;//记录前驱
                preposMarkY[posX][posY]=preposY;
            }
 
        }
   }
   return 0;
}
int main()
{
    Maze* maze;
    int mazeSize;
    int entryX,entryY,exitX,exitY;
    int find=0;
    scanf("%d",&mazeSize);
    maze=InitMaze(mazeSize);
    ReadMaze(maze);
    scanf("%d%d%d%d",&entryX,&entryY,&exitX,&exitY);
    find=MazeBFS(entryX,entryY,exitX,exitY,maze);
    if(find==0)
        printf("找不到路径！");
    return 0;
}

