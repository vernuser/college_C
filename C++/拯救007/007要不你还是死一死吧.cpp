#include <bits/stdc++.h>
using namespace std;
struct node
{
   int book;
   double x,y,sum;
};
struct node a[110],b[110];//aջ�����������������λ�ã�B����ģ��ջ��ȥ�����ܳ�Ϊ·��������
int main()
{
    int n,i,head,tail;//n����������iѭ���еļ�����,head��tail�ֱ�ģ��ջ��ͷ����β��λ��
    double d;//�������
    cin>>n>>d;
    for(i=1;i<=n;i++)
    {
      a[i].book=-1;//��ʼ����ʾû���ʹ�
      cin>>a[i].x>>a[i].y;
      a[i].sum=sqrt(a[i].x*a[i].x+a[i].y*a[i].y);//��������㵽ԭ��ľ���
    }
    head=1;
    tail=1;
    for(i=1;i<=n;i++)
    {
       if(a[i].sum<=d+7.5)//���С�������ģ��ջ��ɸѡ����Щ����ԭ���Զ������
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
         if(a[i].book==-1)//û���ʹ�
         {
            x=b[head].x-a[i].x;
            y=b[head].y-a[i].y; 
           dd=sqrt(x*x+y*y);//����
           if(dd<=d)
           {
             a[i].book=1;
             b[tail++]=a[i];//�ܵ�·��
           }
         }
      }
      head++;//ģ��ջ�ĵ�һ��������ӣ�����һ��
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
