#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

struct Edge { long long to; long long cost; };
typedef std::pair<long long, long long> pii;

int main () {
    long long V, E, R; std::cin >> V >> E >> R;
    std::map<long long, std::vector<Edge>> G;
    for (long long i = 0; i < E; i++) {
        long long S, T, D; std::cin >> S >> T >> D;
        G[S].push_back(Edge{T, D});
    }

    std::vector<long long> dist(V, 1e12);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push(std::make_pair(0, R));
    dist[R] = 0;
    while (!pq.empty()) {
        pii p = pq.top(); pq.pop();
        long long u = p.second;

        if (dist[u] < p.first) continue;
        for (auto e : G[u]) {
            if (dist[u] + e.cost < dist[e.to]) {
                dist[e.to] = dist[u] + e.cost;
                pq.push(std::make_pair(dist[e.to], e.to));
            }
        }
    }

    for (long long i = 0; i < V; i++) {
        if (dist[i] == 1e12) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << dist[i] << std::endl;
        }
    }

}

