#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n,d,g[N][N],v[N][N];

int line(int a,int b,int c,int d)
{
	return ((c-a)*(c-a)+(d-b)*(d-b));
}

class node{
	public :
	int x,y;
	node(){
	}
	node(int a,int b){
		x=a;y=b;
	}
};
node ns[N];
bool bfs(){
	queue<node> q;
	for(int i=0;i<=100;++i){
		q.push(node(i,0));
		q.push(node(i,100));
		q.push(node(0,i));
		q.push(node(100,i));
	}
	while(!q.empty()){
		node t=q.front();q.pop();
		if(line(t.x,t.y,50,50)<=(d+15)*(d+15)){
			return true;
		}
		for(int i=0;i<n;i++){
			int x=ns[i].x,y=ns[i].y;
			if(v[x][y])continue;
			int len=line(t.x,t.y,x,y);
			if(len<=d*d){
				v[x][y]=1;
				q.push(node(x,y));
			}
		}
	}
	return false;
}
int main()
{
	cin>>n>>d;
	for(int i=0;i<n;++i)
	{
		int x,y;cin>>x>>y;
		x+=50;y+=50;
		ns[i]=node(x,y);
		g[x][y]=1;
	}
	if(bfs())cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
