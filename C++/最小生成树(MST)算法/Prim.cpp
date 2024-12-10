#include <bits/stdc++.h>
using namespace std;
const int N=501,INF=0x3f3f3f3f;//const设置一个数值为常量，INF=0x3f3f3f3f表示设置一个极大的数可以理解成无穷大
int d[N][N],dist[N];
bool st1[N],st2[N];//记录当前点在集合内还是集合外
int n,m;
int prim()
{
    memset(dist,0x3f,sizeof dist);//memset将一块内存区域的值设定为指定的字节
    dist[1]=0;//设置初始的结点
    int i,j,res=0;
    for(i=0;i<n;i++)//要遍历n个点，找一个最短边权的点 
    {
        int t=-1;// 初始化为没有找到的点 
        for(j=1;j<=n;j++)
        {
            if(!st1[j]&&(t==-1||dist[t]>dist[j])) //str[j]表示j还没有被访问过也就是说还没有加入到集合中的t==-1||dist[t]>dist[j]表示顶点j的距离更近
                t=j;
        }//不是第一个取出的结点 ，并且当前结点的距离为INF,则表示没有和集合中点相连的边 
        if(dist[t]==INF) 
            return INF;
        st1[t]=1;
        res += dist[t];
      //更新当前最短边权点t到集合的距离（保留最小的值，如果比之前最短t到集合的距离还小，更新） 
        for(j=1;j<=n;j++)
        {
            if(!st1[j]) 
                dist[j] = min(dist[j],d[t][j]);//d[t][j]表示t到j之间的边
        }
    }
    return res;
}
int main()
{
    memset(d,0x3f,sizeof d);
    int x,y,z,i,j;
    while(~scanf("%d %d %d",&x,&y,&z))//一种奇怪的输入当 scanf 成功读取到输入时，它会返回成功读取的变量数量，在这里是 3。由于 C/C++ 中 0 被视为“假”，非 0 值被视为“真”，因此使用 ~ 运算符对 scanf 的返回值进行取反，将其转换为 -1（0b111...111 的补码）或者 0 的形式。
                                      //这样一来，只要 scanf 成功读取到了输入，就会进入循环体内执行相应的操作。如果读取失败，则 scanf 返回值为 -1，取反后变为 0，循环结束。
    {
        if(x==0&&y==0&&z==0) 
            break;
        st2[x] = st2[y] = 1;//st2表示圈外的
        d[x+1][y+1] = d[y+1][x+1] = min(d[x+1][y+1],z);//表示将原来的边权值 d[x+1][y+1] 与新的边权值 z 进行比较
    }
    for(i=0;i<500;i++)
    {
        if(st2[i]) 
            n++;
    }//计算顶点数目n
    int t=prim();
    cout<<t;
    return 0;
}