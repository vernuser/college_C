#include<bits/stdc++.h>
using namespace std;
bool hasCycle(vector<vector<int> > &graph,int start,vector<bool>&visited){
    visited[start]=true;//��ʼֵ�Ѿ����ʹ���
    for(int j=0;j<graph[start].size();j++){//graph[start]��ʾ������startΪ������������ӵ��յ㼯��
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
        graph.resize(max(u+1,v+1));//�����ڽӱ�max��ȡu+1��v+1�д��
        graph[u].push_back(v);//��vʹ��.push_back��ӵ�graph��β��
    }

    int n=graph.size();
    vector<bool> visited(n,false);//����һ��bool���͵���Ϊvisited�����飬��ʼ��С��n����ʼֵ����false
    for(int i=0;i<n;i++){
        if(!visited[i]&&hasCycle(graph,i,visited)){
            cout<<"1"<<endl;
            return 0;
        }
    }
    cout<<"0"<<endl;
    return 0;
}