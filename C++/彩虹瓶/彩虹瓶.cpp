#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;//n颜色数量，m货架容量，k需要判断的发货顺序的数量 
	int a;//工厂的发货顺序 
	scanf("%d %d %d\n",&n,&m,&k);//可以用cin>>n>>m>>k;
	while(k--)
	{
		stack<int>s;
		int c=1;//需要的编号
		int flag=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);//cin>>a;
			if(a==c)//如果刚来的这个和需要的这个一样 
			{
				c++;
				while(s.size())//s.size()返回栈中元素数目，判断货架上是不是有东西 
				{
					if(s.top()==c)//判断栈顶元素与需要的那个是不是一致的
					{
						s.pop();
						c++;
					}
					else 
                        break;
				}
			}
			else
			{
				s.push(a);
				if(s.size()>m) 
                    flag=1;//栈溢出了，标记一下
			}
		 } 
		 if(flag||c<n) //如果flag为真（1）或者c小于n,如果flag=1,说明栈溢出了，如果c小于n，表示还有未放入货架上的货品，即无法将所有货品按照指定顺序发货。
            printf("NO\n");//cout<<"No"<<endl;
		 else 
            printf("YES\n");
	}
	return 0;
} 
