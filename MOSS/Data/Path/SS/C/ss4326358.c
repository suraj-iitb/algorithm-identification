#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define DEBUG

#ifdef DEBUG

#define printd printf

#else

#define printd(...)

#endif

struct edge {
    int64_t cost;
    int to;
};

struct vertex_routecost {
    int64_t routecost;
    int vertex;

    bool operator>(const vertex_routecost& right) const {
        return routecost > right.routecost;
    }
};

std::vector<edge> edges[100000];
int64_t d[100000];
static const int64_t INF = 1LL << 33;

int main() {
    int v, e, r;
    std::cin >> v >> e >> r;
    std::fill_n(d, v, INF);
    for (int i = 0; i < e; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        edges[s].emplace_back(edge {d, t});
    }

    // dijkstra
    std::priority_queue<vertex_routecost, std::vector<vertex_routecost>, std::greater<vertex_routecost>> que;
    que.emplace(vertex_routecost {0, r});

    while (!que.empty()) {
        auto v = que.top(); que.pop();
        if (v.routecost >= d[v.vertex]) {
            continue;
        }
        d[v.vertex] = v.routecost;
        for (auto& e: edges[v.vertex]) {
            que.emplace(vertex_routecost {v.routecost + e.cost, e.to});
        }
    }


    for (int i = 0; i < v; i++) {
        if (d[i] == INF) {
            std::cout << "INF" << std::endl;
            continue;
        }
        std::cout << d[i] << std::endl;
    }


    return 0;
}

