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
LinkQueue SetNullQueue_Link()//�����ն���
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
int IsNullQueue_Link(LinkQueue lqueue)//�ж϶����Ƿ�Ϊ��
{
   return  (lqueue->f==NULL);
}
void EnQueue_Link(LinkQueue lqueue,DataType x)//��Ӳ���
{
    PNode p;
    p=(PNode)malloc(sizeof(struct Node));//����ڵ�ռ�
    if(p==NULL)
        printf("Alloc Failure!\n");
    else
    {    p->data=x;//������ֵ
         p->link=NULL;//ָ����ֵ
        if(lqueue->f==NULL)//�ն��е����⴦��
        {
            lqueue->f=p;
            lqueue->r=p;
        }
        else
        {
            lqueue->r->link=p;//�����β
            lqueue->r=p;//�޸Ķ�βָ��
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
Maze* InitMaze(int size)//��ʼ��һ���Թ�
{
    int i;
    Maze*maze=(Maze*)malloc(sizeof(Maze));
    maze->size=size;//maze->size��ʾ�Թ��Ĵ�С
    maze->data=(int **)malloc(sizeof(int*)*maze->size);//����ռ�
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
}//���Թ��Ľṹ��ʾ����,��ȡ�Թ��ṹ
void WriteMaze(Maze* maze)
{
    int i,j;
    printf("�Թ��Ľṹ���£�\n");
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
    int posX,posY;//��ʱ�������������㣨x,y��
 
    int i,j,mov;
    int **preposMarkX;//��¼�Թ����ߵ�ǰ��Xֵ
    int **preposMarkY;//��¼�Թ����߹����е�ǰ��Yֵ
    int **Mark;//��Ƕ�ά���飬�����Щ���߹��������ظ���
    //�����ǰ��������X����ռ�
    preposMarkX=(int **)malloc(sizeof(int*)*maze->size);
    for(i=0;i<maze->size;i++)
    {
        preposMarkX[i]=(int *)malloc(sizeof(int)*maze->size);
    }
    //�����ǰ��������Y����ռ�
    preposMarkY=(int **)malloc(sizeof(int*)*maze->size);
    for(i=0;i<maze->size;i++)
    {
        preposMarkY[i]=(int *)malloc(sizeof(int)*maze->size);
    }//������ǵĶ�ά�������ռ䣬������ֵ
    Mark=(int **)malloc(sizeof(int*)*maze->size);
    for(i=0;i<maze->size;i++)
    {
        Mark[i]=(int *)malloc(sizeof(int)*maze->size);
    }
    for(i=0;i<maze->size;i++)//������Ԫ�����ó�ֵ
    {
        for(j=0;j<maze->size;j++)
        {
            preposMarkX[i][j]=-1;
            preposMarkX[i][j]=-1;
            Mark[i][j]=0;
        }
 
    }
    linkQueueX=SetNullQueue_Link();//�����ն���
    linkQueueY=SetNullQueue_Link();//�����ն���
    EnQueue_Link(linkQueueX,entryX);//�Թ���ڵ����
    EnQueue_Link(linkQueueY,entryY);//�Թ���ڵ����
    Mark[entryX][entryY]=1;//�Թ����ñ�־λ
    while(!IsNullQueue_Link(linkQueueX))
   {
        preposX=FrontQueue_Link(linkQueueX);//ȡ��ͷ
        DeQueue_Link(linkQueueX);//����
        preposY=FrontQueue_Link(linkQueueY);//ȡ��ͷ
        DeQueue_Link(linkQueueY);//����
        //���ڵ�ǰ������������һ�������ĵ�������
        for(mov=0;mov<8;mov++)
        {
            posX=preposX+direction[mov][0];
            posY=preposY+direction[mov][1];
            if(posX==exitX&&posY==exitY)//������ڵ�
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
            //������ߣ���û�б���չ��
            if(maze->data[posX][posY]==0&&Mark[posX][posY]==0)
            {
                EnQueue_Link(linkQueueX,posX);//�����չ
                EnQueue_Link(linkQueueY,posY);
                Mark[posX][posY]=1;//�����
                preposMarkX[posX][posY]=preposX;//��¼ǰ��
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
        printf("�Ҳ���·����");
    return 0;
}

