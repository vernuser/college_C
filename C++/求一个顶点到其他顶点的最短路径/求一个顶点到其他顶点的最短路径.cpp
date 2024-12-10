#include <bits/stdc++.h>
using namespace std;
const int INF = std::numeric_limits<int>::max();

struct Edge {
    int destination;
    int weight;
};

struct Vertex {
    int id;
    int distance;
    std::vector<int> path;

    bool operator<(const Vertex& other) const {
        return distance > other.distance;
    }
};

void dijkstra(const std::vector<std::vector<Edge> >& graph, int source) {
    int n = graph.size();
    std::vector<Vertex> vertices(n);

    for (int i = 0; i < n; i++) {
        vertices[i].id = i;
        vertices[i].distance = INF;
    }

    vertices[source].distance = 0;
    std::priority_queue<Vertex> pq;
    pq.push(vertices[source]);

    while (!pq.empty()) {
        const Vertex u = pq.top();
        pq.pop();

        if (u.distance == INF) {
            break;
        }

        for (size_t i = 0; i < graph[u.id].size(); i++) {
            const Edge& edge = graph[u.id][i];
            const Vertex v = vertices[edge.destination];

            if (u.distance + edge.weight < v.distance) {
                vertices[edge.destination].distance = u.distance + edge.weight;
                vertices[edge.destination].path = u.path;
                vertices[edge.destination].path.push_back(edge.destination);
                pq.push(vertices[edge.destination]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == source) {
            continue;
        }

        std::cout << source << "->" << i << ":" << vertices[i].distance << std::endl;
        std::cout << source;
        for (size_t j = 0; j < vertices[i].path.size(); j++) {
            std::cout << "->" << vertices[i].path[j];
        }
        std::cout << std::endl;
    }
}

int main() {
    int n = 6; // 顶点个数
    std::vector<std::vector<Edge> > graph(n);

    // 读取输入
    int u, v, w;
    while (std::cin >> u >> v >> w && (u != 0 || v != 0 || w != 0)) {
        graph[u].push_back((Edge){v, w});
    }

    int source = 0; // 源顶点为 0
    dijkstra(graph, source);

    return 0;
}
