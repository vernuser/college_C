#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;//n��ɫ������m����������k��Ҫ�жϵķ���˳������� 
	int a;//�����ķ���˳�� 
	scanf("%d %d %d\n",&n,&m,&k);//������cin>>n>>m>>k;
	while(k--)
	{
		stack<int>s;
		int c=1;//��Ҫ�ı��
		int flag=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);//cin>>a;
			if(a==c)//����������������Ҫ�����һ�� 
			{
				c++;
				while(s.size())//s.size()����ջ��Ԫ����Ŀ���жϻ������ǲ����ж��� 
				{
					if(s.top()==c)//�ж�ջ��Ԫ������Ҫ���Ǹ��ǲ���һ�µ�
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
                    flag=1;//ջ����ˣ����һ��
			}
		 } 
		 if(flag||c<n) //���flagΪ�棨1������cС��n,���flag=1,˵��ջ����ˣ����cС��n����ʾ����δ��������ϵĻ�Ʒ�����޷������л�Ʒ����ָ��˳�򷢻���
            printf("NO\n");//cout<<"No"<<endl;
		 else 
            printf("YES\n");
	}
	return 0;
} 
