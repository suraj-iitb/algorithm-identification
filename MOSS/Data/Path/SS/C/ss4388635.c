#include <bits/stdc++.h>
struct Edge {
    int to;
    int cost;
};

class Dijkstra {
public:
    using P = std::pair<int, int>;

    Dijkstra(int v) : vnum(v) {
        this->edges.resize(v);       
    }
    ~Dijkstra() = default;

    void addEdge(int n, int t, int c) noexcept {
        this->edges[n].push_back({t, c});
    }

    // - return the shortest path lengths from s to each vertex
    // - if a vertex is unreachable from s, the value is INT32_MAX  
    std::vector<int> shortestPath(int s) const noexcept {
        std::vector<int> d(vnum, INT32_MAX);

        std::priority_queue<P, std::vector<P>, std::greater<P>> que;
        d[s] = 0;
        que.push(P(0, s));

        while (que.empty() == false) {
            const P p = que.top(); que.pop();
            const int v = p.second;
            if (d[v] < p.first) {
                continue;
            }

            for (const Edge& e : this->edges[v]) {
                if ((d[v] + e.cost) < d[e.to]) {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }

        }

        return d;
    }
            
private:
    std::vector<std::vector<Edge>> edges;
    int vnum;
};

int main() {
    int V, E, r;
    std::cin >> V >> E >> r;

    Dijkstra dk(V);

    int s, t, d;
    for (int i = 0; i < E; ++i) {
        std::cin >> s >> t >> d;
        dk.addEdge(s, t, d);
    }

    const std::vector<int> paths = dk.shortestPath(r);
    for (int p : paths) {
        if (p == INT32_MAX) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << p << std::endl;
        }
    }

    return 0;
}

