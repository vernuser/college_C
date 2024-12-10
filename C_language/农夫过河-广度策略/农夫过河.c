#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
struct Queue
{
    int Max;
    int f;
    int r;
    DataType *top;
};
typedef struct Queue *SeqQueue;
 
SeqQueue SetNullQueue_seq(int m)
{
    SeqQueue squeue;
    squeue = (SeqQueue)malloc(sizeof(struct Queue));
    if (squeue == NULL)
    {
        printf("Alloc failure\n");
        return NULL;
    }
    squeue->top = (int *)malloc(sizeof(DataType) * m);
    if (squeue->top != NULL)
    {
        squeue->Max = m;
        squeue->f = 0;
        squeue->r = 0;
        return squeue;
    }
}
 
int IsNullQueue_seq(SeqQueue squeue)
{
    return (squeue->f == squeue->r);
}
void EnQueue_seq(SeqQueue squeue, DataType x)
{
    if ((squeue->r + 1) % squeue->Max == squeue->f)
        printf("It is FULL Queue!");
    else
    {
        squeue->top[squeue->r] = x;
        squeue->r = (squeue->r + 1) % squeue->Max;
    }
}
void DeQueue_seq(SeqQueue squeue)
{
    if (IsNullQueue_seq(squeue) == 1)
        printf("it is empty queue!");
    else
    {
        squeue->f = (squeue->f + 1) % (squeue->Max);
    }
}
DataType FrontQueue_seq(SeqQueue squeue)
{
    if (IsNullQueue_seq(squeue) == 1)
    {
        printf("It is empty queue");
        return 1;
    }
    else
    {
        return squeue->top[squeue->f];
    }
}
int FarmerOnRight(int status) //判断当前条件下农夫的位置是否在右侧
{
    return (0 != (status & 0x08));
}
int WorfOnRight(int status) //判断当前位置下狼的位置是否在右侧
{
    return (0 != (status & 0x04));
}
int CabbageOnRight(int status) //判断当前位置下白菜的位置是否在右侧
{
    return (0 != (status & 0x02));
}
int GoatOnRight(int status) //判断当前位置下羊是否在右侧
{
    return (0 != (status & 0x01));
}
int IsSafe(int status) //判断当前位置下羊是否安全
{
    if ((GoatOnRight(status) == CabbageOnRight(status)) && (GoatOnRight(status) != FarmerOnRight(status)))
        return 0; //羊吃白菜
    if ((GoatOnRight(status) == WorfOnRight(status)) && (GoatOnRight(status) != FarmerOnRight(status)))
        return 0; //狼吃羊
    return 1;     //其他状态时安全的
}
void FarmerRiver()
{
    int i, movers, nowstatus, newstatus;
    int status[16];                //用于记录已考虑的状态路径，这里的16是因为物品的数量固定为3个，所以最多有16种可能的状态
    SeqQueue moveTo;               //用于记录可以安全到达的中间状态
    moveTo = SetNullQueue_seq(20); //创建空队列，这里的20是因为要创建一个足够大的队列防止算法的实现中出现数组越界的问题
    EnQueue_seq(moveTo, 0x00);     //初始状态时所有物品在右侧
    for (i = 0; i < 16; i++)       //数组status初始化位-1
        status[i] = -1;
    status[0] = 0;
    while (!IsNullQueue_seq(moveTo) && (status[15] == -1))
    //moveTo不为空并且status[15]不为-1的时候跳出循环
    {
        nowstatus = FrontQueue_seq(moveTo); //取队头状态为当前状态
        DeQueue_seq(moveTo);
        for (movers = 1; movers <= 8; movers <<= 1) //遍历三个要移动的物品
                                                    //考虑各种物品移动
            if ((0 != (nowstatus & 0x08)) == (0 != (nowstatus & movers)))
            //考虑农夫与移动的物品在同一侧
            {
                newstatus = nowstatus ^ (0x08 | movers); //计算新状态
                //如果新状态时安全的且之前没有出现过
                if (IsSafe(newstatus) && (status[newstatus] == -1))
                {
                    status[newstatus] = nowstatus;  //记录新状态
                    EnQueue_seq(moveTo, newstatus); //新状态入队
                }
            }
    }
    //输出经过的装态路径
    if (status[15] != -1) //到达最终状态
    {
        // printf("the reverse path is:\n");
        for (nowstatus = 15; nowstatus >= 0; nowstatus = status[nowstatus])
        {
            // printf("The nowstatus is:%d\n", nowstatus);
            printf("%d ", nowstatus);
            if (nowstatus == 0)
                return;
        }
    }
    else
        printf("No solution.\n"); //问题无解
}
int main()
{
    FarmerRiver();
    return 0;
}