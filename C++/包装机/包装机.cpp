#include<bits/stdc++.h>
using namespace std;
 
const int N=1010,M=1010;
 
int n,m,s,x;
string str;
queue<char>q[N];
stack<char>stk;
 
int main(){
    
    cin>>n>>m>>s;
    
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        for(int j=0;j<m;j++)
        {
            q[i].push(str[j]);
        }
        
    }
    
    while(scanf("%d",&x),x!=-1)
    {
        if(!x)
        {
            if(stk.size())
            {
                printf("%c",stk.top());
                stk.pop();
            }
        }
        else
        {
            if(q[x].size())//轨道不空是框运行的条件
            {
                if(stk.size()==s)
                {
                    printf("%c",stk.top());
                    stk.pop();
                }
                stk.push(q[x].front());
                q[x].pop();
            }
        }
    }
    
    return 0;
}