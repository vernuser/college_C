//有两种情况工人要愤怒，一种是栈溢出，另一种是顺序不是1~N,需要反复折腾货架
#include<stdio.h>
int main()
{
    int N,M,K;
    scanf("%d %d %d\n",&N,&M,&K);//n颜色数量，m货架容量，k需要判断的发货顺序的数量
    int stack[1000];
    int a[N];//保存输出的顺序 
    int k=0,top=-1;
    int t;
    int flag=1;//判断发货顺序有没有问题，没有问题是1，有问题就变成了0
    int i,j;
    for(i=0;i<K;i++)
    {
        k=0;top=-1;flag=1;//初始化变量
        for(j=0;j<N;j++)
        {
            scanf("%d",&t);
            if(t==k+1)//判断是否和预期的货相等
            {
                a[k++]=t;//如果相等，将t的值保存在a【k】中，在进行加一
                while(stack[top]==k+1)//当栈顶的货物编号等于预期的出库顺序时，将其出库并更新栈顶位置。
                {
                    a[k++]=stack[top--];//将栈顶元素弹出并赋值给数组a的第k个元素，然后将k和top的值分别加1
                }
            }
            else
            {
            	if(M-1==top)//判断栈是否已经满了
                {
                    flag=0;
                }
                stack[++top]=t;//先递增top的值，再将t存储到递增后的top位置上
            }
        }
        if(flag==1)
        {
            while(top!=-1)//货如果已经发完了，要把货架上的都输出
            {
                a[k++]=stack[top--];//将栈顶的货物出库并存储再a【k】中并继续执行直到top=-1
            }
            for(j=1;j<=N;j++)//没有按照1~N的发货顺序
            { 
                if(a[j-1]!=j)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}
//a[k++]=t这种表示先讲a[k]赋值给t，然后再将k自增1