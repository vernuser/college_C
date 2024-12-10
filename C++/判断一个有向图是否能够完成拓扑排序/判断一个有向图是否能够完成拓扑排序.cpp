#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 10010;
int inDegree[MAXN];
vector<int> G[MAXN]; // 邻接表表示图

bool topsort(int n) {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return cnt == n;
}

int main() {
    int u, v;
    int n = 0; // 节点个数
    while (cin >> u >> v) {
        if (u == -1 && v == -1) {
            break;
        }
        G[u].push_back(v);
        inDegree[v]++;
        n = max(n, max(u, v) + 1);
    }

    bool res = topsort(n);
    cout << (res ? 1 : 0) << endl;

    return 0;
}
