#include<bits/stdc++.h>
using namespace std;
#define MAX 65535
int n;//村庄个数
int a[11111][11111];//存储边的信息
int visit[11111];//当前 的
int best[11111];//存储最短的时间所需要的权

int start(int st)//初始化
{
    memset(visit,0,sizeof(int)*11111);
    memset(best,0,sizeof(int)*11111);
    for(int i=0;i<=n;i++)
    {
        best[i]=a[st][i];
    }
}

int dijistra(int st)
{
    start(st);//初始化
    visit[st]=1;
    int mid = st;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(visit[j]=0&&best[j]!=MAX)
            {
                mid=j;
                visit[j]=1;
                break;
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(a[mid][j]+best[mid]<best[j])
            best[mid]=a[mid][j]+best[mid];
        }
    }
}


int main()
{
    cin>>n;
    int maxmin = MAX;
    int maxminpoint =1;
    for(int i=1;i<=n;i++)
    {
        dijistra(i);
        int maxx=-1;
        for(int j=1;j<=n;j++)
        {
            if(best[j]>maxx)
            {
                maxx=best[j];
            }
            if(maxx<maxmin)
            {
                maxmin =maxx;
                maxminpoint=i;
            }
        }
    }
    printf("%c", maxminpoint - 1 + 'a');
}