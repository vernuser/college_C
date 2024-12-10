#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 加入头文件

#define max 65535
int n;
int a[11000][11000];//存储边信息
int visit[11000];//标记访问
int best[11000];//最佳路径

int start(int st)//初始化
{
    memset(visit, 0, sizeof(int) * 11000);
    memset(best, 0, sizeof(int) * 11000);
    for (int i = 1; i <= n; i++)
        best[i] = a[st][i];
}

void dijkstr(int st)
{
    start(st);//初始化
    visit[st] = 1;//标记访问
    int mid = st;//存储当前点
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) // 修改循环变量的名称
        {
            if (visit[j] == 0 && best[j] != max)//没被访问过 同时在best中有记录（即与该点相连的点被访问过）
            {
                mid = j;//找到满足条件的点，将改点设为当前点
                visit[mid] = 1;
                break;
            }
        }
        for (int j = 1; j <= n; j++)//向外扩展
            if (a[mid][j] + best[mid] < best[j])//只有满足与访问过的点相连的点才会更新最佳距离
                best[j] = best[mid] + a[mid][j];
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    int maxmin = max;//找到每个医院距离的最大值中间的最小值
    int maxminpoint = 1;//maxmin对应的点，即ABCDEF 类似点
    for (int i = 1; i <= n; i++)//思路：找到每个医院距离的最大值中间的最小值
    {
        dijkstr(i);
        int maxx = -1;
        for (int j = 1; j <= n; j++)
            if (best[j] > maxx)
                maxx = best[j];
        if (maxx < maxmin)
        {
            maxmin = maxx;
            maxminpoint = i;
        }
    }
    printf("%c", maxminpoint - 1 + 'a');
}
