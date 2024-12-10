#include <iostream>
#include <vector>

using namespace std;
//2200320109安东
bool hasCycle(vector<vector<int> >& graph, int start, vector<bool>& visited) {//vector表示的一个数组，所以vector<vector<int> >就表示一个二维数组
    visited[start] = true;
    for (int j = 0; j < graph[start].size(); ++j) {
        int neighbor = graph[start][j];
        if (visited[neighbor]) {
            return true; // 遇到已访问过的顶点，存在回路
        }
        if (hasCycle(graph, neighbor, visited)) {
            return true; // 递归地访问相邻顶点
        }
    }
    visited[start] = false; // 回溯，重置访问状态
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
