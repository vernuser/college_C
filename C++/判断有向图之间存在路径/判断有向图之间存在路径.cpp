#include <iostream>
#include <vector>

using namespace std;

bool hasCycle(vector<vector<int> >& graph, int start, vector<bool>& visited) {
    // visited[start] 表示顶点 start 是否被访问过
    visited[start] = true; // 标记顶点 start 已被访问过

    // 遍历以 start 为起点的所有有向边
    for (int j = 0; j < graph[start].size(); ++j) {
        // graph[start][j] 表示从顶点 start 出发的第 j 条有向边的终点
        int neighbor = graph[start][j];
        
        // 如果终点 neighbor 之前已经访问过，则存在回路，直接返回 true
        if (visited[neighbor]) {
            return true; // 遇到已访问过的顶点，存在回路
        }
        
        // 否则递归访问终点 neighbor 的相邻顶点，并判断是否存在回路
        if (hasCycle(graph, neighbor, visited)) {
            return true; // 递归地访问相邻顶点
        }
    }
    
    // 回溯时重置顶点的访问状态
    visited[start] = false;
    
    // 未发现回路，返回 false
    return false;
}


int main() {
    vector<vector<int> > graph;

    // 读取邻接矩阵表示的有向图
    int u, v;
    while (cin >> u >> v && (u != -1 || v != -1)) {
        graph.resize(max(u + 1, v + 1));
        graph[u].push_back(v);
    }

    // 对每个顶点进行深度优先搜索
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && hasCycle(graph, i, visited)) {
            cout << "1" << endl; // 存在回路
            return 0;
        }
    }

    cout << "0" << endl; // 不存在回路
    return 0;
}
