#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>

template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};
};

template <class Cost = int>
using Graph = std::vector<std::vector<Edge<Cost>>>;

template <class Cost>
std::vector<Cost> dijkstra(const Graph<Cost>& graph, int s) {
    constexpr Cost INF = std::numeric_limits<Cost>::max();

    std::vector<Cost> dist(graph.size(), INF);
    dist[s] = 0;
    MinHeap<std::pair<Cost, int>> que;
    que.emplace(0, s);

    while (!que.empty()) {
        int v;
        Cost d;
        std::tie(d, v) = que.top();
        que.pop();
        if (d > dist[v]) continue;

        for (auto e : graph[v]) {
            if (dist[e.dst] <= dist[v] + e.cost) continue;
            dist[e.dst] = dist[v] + e.cost;
            que.emplace(dist[e.dst], e.dst);
        }
    }
    return dist;
}

constexpr int INF = std::numeric_limits<int>::max();

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;

    Graph<int> graph(n);
    while (m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph[u].emplace_back(u, v, d);
    }

    auto dist = dijkstra(graph, s);
    for (auto d : dist) {
        if (d == INF) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << d << std::endl;
        }
    }
    return 0;
}

