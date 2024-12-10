#include <bits/stdc++.h>
using namespace std;
const int INF = std::numeric_limits<int>::max();
//定义了一个常量INF，表示整数类型的最大值,std::numeric_limits
//是C++的模板类，，用于提供基本数据类型的特征信息。它包含了各种基本数据类型（如int、float、double、char等）的极值、精度、范围等信息，为开发者提供了一些非常方便的编程工具。
//该模板类中最常用的函数是max()和min()，用于返回指定类型的最大值和最小值。
//在代码中，使用std::numeric_limits<int>::max()来获取整数类型int的最大值，
//这相当于写成INT_MAX（INT_MAX也是一个表示整数类型的最大值的常量）。
struct Edge {
    int destination;//目标定点的索引
    int weight;//边的权重
};

struct Vertex {
    int id;//顶点的索引
    int distance;//到源顶点之间的距离
    std::vector<int> path;//到源顶点之间所有的顶点索引

    bool operator<(const Vertex& other) const {
        return distance > other.distance;
    }
};
//bool里面这玩意就离谱，重载了<，第二个const是用来写实operator<的，第一个是修饰
//vertes和other,
//该语句定义了如果vertex的distance大于第二个的，则说明前者小于后者

void dijkstra(const std::vector<std::vector<Edge> >& graph, int source) {
    int n = graph.size();
    std::vector<Vertex> vertices(n);

    for (int i = 0; i < n; i++) {
        vertices[i].id = i;
        vertices[i].distance = INF;
    }//初始化vertices

    vertices[source].distance = 0;//源顶点的距离设置成0
    std::priority_queue<Vertex> pq;//定义一个Vertex类型的pq
    pq.push(vertices[source]);//源顶点入队


    while (!pq.empty()) {
        const Vertex u = pq.top();
        pq.pop();

        if (u.distance == INF) {
            break;
        }

        for (size_t i = 0; i < graph[u.id].size(); i++) {
//size_t是一种无符号整数类型，通常用来哦表示对象或内存块的大小，元素的数量
            const Edge& edge = graph[u.id][i];
            const Vertex v = vertices[edge.destination];

            if (u.distance + edge.weight < v.distance) {
                vertices[edge.destination].distance = u.distance + edge.weight;
                vertices[edge.destination].path = u.path;
                vertices[edge.destination].path.push_back(edge.destination);
    // push_back 函数将目标顶点的编号添加到最短路径的末尾
                pq.push(vertices[edge.destination]);
    //将目标定点加入队列中保证下一次弹出的顶电视剧里定点最近的
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == source) {
            continue;
        }

        std::cout << source << "->" << i << ":" << vertices[i].distance << std::endl;
//输出形如"source->i:distance"的信息，source是源顶点，i是目标定点,vertices[i].distance是从源顶点到目标定点的最短距离
        std::cout << source;
        for (size_t j = 0; j < vertices[i].path.size(); j++) {
            std::cout << "->" << vertices[i].path[j];
        }//循环遍历vertices[i].path，即目标顶点的最短路径
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
