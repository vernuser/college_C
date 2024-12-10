#include <iostream>
#include <vector>

using namespace std;
//2200320109����
bool hasCycle(vector<vector<int> >& graph, int start, vector<bool>& visited) {//vector��ʾ��һ�����飬����vector<vector<int> >�ͱ�ʾһ����ά����
    visited[start] = true;
    for (int j = 0; j < graph[start].size(); ++j) {
        int neighbor = graph[start][j];
        if (visited[neighbor]) {
            return true; // �����ѷ��ʹ��Ķ��㣬���ڻ�·
        }
        if (hasCycle(graph, neighbor, visited)) {
            return true; // �ݹ�ط������ڶ���
        }
    }
    visited[start] = false; // ���ݣ����÷���״̬
    return false;
}

int main() {
    vector<vector<int> > graph;

    // ��ȡ�ڽӾ����ʾ������ͼ
    int u, v;
    while (cin >> u >> v && (u != -1 || v != -1)) {
        graph.resize(max(u + 1, v + 1));
        graph[u].push_back(v);
    }

    // ��ÿ��������������������
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && hasCycle(graph, i, visited)) {
            cout << "1" << endl; // ���ڻ�·
            return 0;
        }
    }

    cout << "0" << endl; // �����ڻ�·
    return 0;
}
