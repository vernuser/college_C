#include <bits/stdc++.h>
using namespace std;
struct node
{
   int book;
   double x,y,sum;
};
struct node a[110],b[110];//a栈用来保存所有鳄鱼的位置，B用来模拟栈，去掉不能成为路径的鳄鱼
int main()
{
    int n,i,head,tail;//n鳄鱼数量，i循环中的计数器,head和tail分别模拟栈的头部和尾部位置
    double d;//距离测量
    cin>>n>>d;
    for(i=1;i<=n;i++)
    {
      a[i].book=-1;//初始化表示没访问过
      cin>>a[i].x>>a[i].y;
      a[i].sum=sqrt(a[i].x*a[i].x+a[i].y*a[i].y);//计算该鳄鱼到原点的距离
    }
    head=1;
    tail=1;
    for(i=1;i<=n;i++)
    {
       if(a[i].sum<=d+7.5)//如果小于则进入模拟栈，筛选出那些距离原点较远的鳄鱼
       {
         a[i].book=1;
         b[tail++]=a[i];
       }
    }
    while(head<tail)
    {
      double x,y,dd;
      for(i=1;i<=n;i++)
      {
         if(a[i].book==-1)//没访问过
         {
            x=b[head].x-a[i].x;
            y=b[head].y-a[i].y; 
           dd=sqrt(x*x+y*y);//距离
           if(dd<=d)
           {
             a[i].book=1;
             b[tail++]=a[i];//能当路径
           }
         }
      }
      head++;//模拟栈的第一个鳄鱼出队，换下一轮
    }
    int flag=0;
    for(i=1;i<tail;i++)
    {
      if(b[i].x+d>=50||b[i].y+d>=50||b[i].x-d<=-50||b[i].y-d<=-50)
      {
        flag=1;
        break;
      }
    }
    if(flag==1)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    return 0;
}
