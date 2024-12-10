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
int FarmerOnRight(int status) //�жϵ�ǰ������ũ���λ���Ƿ����Ҳ�
{
    return (0 != (status & 0x08));
}
int WorfOnRight(int status) //�жϵ�ǰλ�����ǵ�λ���Ƿ����Ҳ�
{
    return (0 != (status & 0x04));
}
int CabbageOnRight(int status) //�жϵ�ǰλ���°ײ˵�λ���Ƿ����Ҳ�
{
    return (0 != (status & 0x02));
}
int GoatOnRight(int status) //�жϵ�ǰλ�������Ƿ����Ҳ�
{
    return (0 != (status & 0x01));
}
int IsSafe(int status) //�жϵ�ǰλ�������Ƿ�ȫ
{
    if ((GoatOnRight(status) == CabbageOnRight(status)) && (GoatOnRight(status) != FarmerOnRight(status)))
        return 0; //��԰ײ�
    if ((GoatOnRight(status) == WorfOnRight(status)) && (GoatOnRight(status) != FarmerOnRight(status)))
        return 0; //�ǳ���
    return 1;     //����״̬ʱ��ȫ��
}
void FarmerRiver()
{
    int i, movers, nowstatus, newstatus;
    int status[16];                //���ڼ�¼�ѿ��ǵ�״̬·���������16����Ϊ��Ʒ�������̶�Ϊ3�������������16�ֿ��ܵ�״̬
    SeqQueue moveTo;               //���ڼ�¼���԰�ȫ������м�״̬
    moveTo = SetNullQueue_seq(20); //�����ն��У������20����ΪҪ����һ���㹻��Ķ��з�ֹ�㷨��ʵ���г�������Խ�������
    EnQueue_seq(moveTo, 0x00);     //��ʼ״̬ʱ������Ʒ���Ҳ�
    for (i = 0; i < 16; i++)       //����status��ʼ��λ-1
        status[i] = -1;
    status[0] = 0;
    while (!IsNullQueue_seq(moveTo) && (status[15] == -1))
    //moveTo��Ϊ�ղ���status[15]��Ϊ-1��ʱ������ѭ��
    {
        nowstatus = FrontQueue_seq(moveTo); //ȡ��ͷ״̬Ϊ��ǰ״̬
        DeQueue_seq(moveTo);
        for (movers = 1; movers <= 8; movers <<= 1) //��������Ҫ�ƶ�����Ʒ
                                                    //���Ǹ�����Ʒ�ƶ�
            if ((0 != (nowstatus & 0x08)) == (0 != (nowstatus & movers)))
            //����ũ�����ƶ�����Ʒ��ͬһ��
            {
                newstatus = nowstatus ^ (0x08 | movers); //������״̬
                //�����״̬ʱ��ȫ����֮ǰû�г��ֹ�
                if (IsSafe(newstatus) && (status[newstatus] == -1))
                {
                    status[newstatus] = nowstatus;  //��¼��״̬
                    EnQueue_seq(moveTo, newstatus); //��״̬���
                }
            }
    }
    //���������װ̬·��
    if (status[15] != -1) //��������״̬
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
        printf("No solution.\n"); //�����޽�
}
int main()
{
    FarmerRiver();
    return 0;
}