#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int Max=1e6+5;
const ll INF=1e10;
stack<int>s;//盒子
queue<int>q;//推子
 
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		int t;cin>>t;
		q.push(t);
	}
	
	while(1)
	{
		vector<int>v;
		while(!s.empty())
		{
			int num=s.top();
			if(v.size()==0) 
				v.pb(num),s.pop();
			else
			{
				if(num<=v[v.size()-1]&&v.size()<k)
				{
					v.pb(num),s.pop();
				}else break;
			}
		}//先送盒子里面取松针
		if(v.size()==k)
		{
			for(int i=0;i<k;i++)
			{
				if(i==0) cout<<v[i];
				else cout<<" "<<v[i];
			}
			cout<<endl;
		}//松枝满了直接输出，不满再从推子里面取
        else{
			while(!q.empty())
			{
				int num=q.front();
				if(v.size()==0) v.pb(num),q.pop();
				else{
					if(v.size()==k) break;
					if(num<=v[v.size()-1])
					{
						v.pb(num),q.pop();
					}else{
						if(s.size()<m)
						{
							s.push(num);q.pop();
						}else break;
					}
				}
			}
			if(v.size()==0) break;
			for(int i=0;i<v.size();i++)
			{
				if(i==0) cout<<v[i];
				else cout<<" "<<v[i];
			}
			cout<<endl;
		}
	}
}