#include<bits/stdc++.h>
using namespace std;
bool hasCycle(vector<vector<int> > &graph,int start,vector<bool>&visited){
    visited[start]=true;//初始值已经访问过了
    for(int j=0;j<graph[start].size();j++){//graph[start]表示所有以start为起点的有向边连接的终点集合
        int neighbor=graph[start][j];
        if(visited[neighbor]){
            return true;
        }
        if(hasCycle(graph,neighbor,visited)){
            return true;
        }
    }
    visited[start]=false;
    return false;
}

int  main()
{
    vector<vector<int> > graph;
    int u,v;
    while(cin>>u>>v&&(u!=-1||v!=-1)){
        graph.resize(max(u+1,v+1));//扩大邻接表，max求取u+1和v+1中大的
        graph[u].push_back(v);//将v使用.push_back添加到graph的尾部
    }

    int n=graph.size();
    vector<bool> visited(n,false);//生成一个bool类型的名为visited的数组，初始大小是n，初始值都是false
    for(int i=0;i<n;i++){
        if(!visited[i]&&hasCycle(graph,i,visited)){
            cout<<"1"<<endl;
            return 0;
        }
    }
    cout<<"0"<<endl;
    return 0;
}