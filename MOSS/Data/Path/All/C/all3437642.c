#include <iostream>
#include <vector>
#include <limits>

template <class T>
struct Edge {
    int from, to;
    T cost;
    Edge(int from, int to, T cost) : from(from), to(to), cost(cost){};

    bool operator<(const Edge<T>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<T>& e) const { return this->cost > e.cost; }
};

template <class T = int>
class Graph {
public:
    explicit Graph(int N = 0) : size(N) { path.resize(size); }
    void span(int u, int v, T cost = 1) { path[u].push_back(Edge<T>(u, v, cost)); }
    std::vector<Edge<T>> operator[](int v) const { return path[v]; }

    int size;
    std::vector<std::vector<Edge<T>>> path;
};

const int INF = std::numeric_limits<int>::max();

template <class T>
std::vector<std::vector<T>> warshall_floyd(const Graph<T>& graph) {
    std::vector<std::vector<T>> dist(graph.size, std::vector<T>(graph.size, INF));

    for (int v = 0; v < graph.size; ++v) {
        dist[v][v] = 0;
        for (const auto& e : graph[v]) {
            dist[v][e.to] = e.cost;
        }
    }

    for (int k = 0; k < graph.size; ++k) {
        for (int u = 0; u < graph.size; ++u) {
            for (int v = 0; v < graph.size; ++v) {
                if (dist[u][k] < INF && dist[k][v] < INF) {
                    dist[u][v] = std::min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }

    for (int v = 0; v < graph.size; ++v) {
        if (dist[v][v] < 0) return std::vector<std::vector<T>>();
    }

    return dist;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    Graph<int> graph(N);
    for (int i = 0; i < M; ++i) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph.span(u, v, d);
    }

    auto dist = warshall_floyd(graph);

    if (dist.empty()) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
        return 0;
    }

    for (const auto& d : dist) {
        for (int i = 0; i < d.size(); ++i) {
            if (d[i] == INF) {
                std::cout << "INF";
            } else {
                std::cout << d[i];
            }
            std::cout << " \n"[i == d.size() - 1];
        }
    }
    return 0;
}

