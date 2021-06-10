#include <limits>
#include <iostream>
#include <queue>
#include <vector>

#define SZ(obj) static_cast<int>(obj.size())

template<typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) { }
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) { }
    edge &operator=(const int& x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};

template<typename T>
using Edges = std::vector<edge<T>>;

template<typename T>
using WeightedGraph = std::vector<Edges<T>>;

using UnWeightedGraph = std::vector<std::vector<int>>;

template<typename T>
using Matrix = std::vector<std::vector<T>>;

template<typename T>
std::vector<T> showrest_path_faster_algorithm(WeightedGraph<T>& g, int s) {
    const auto INF = std::numeric_limits<T>::max();
    std::vector<T> dist(SZ(g), INF);
    std::vector<int> pending(SZ(g), 0), times(SZ(g), 0);
    std::queue<int> que;

    que.emplace(s);
    pending[s] = true;
    ++times[s];
    dist[s] = 0;

    while (!que.empty()) {
        int p = que.front(); que.pop();
        pending[p] = false;
        for (auto& e : g[p]) {
            T next_cost = dist[p] + e.cost;
            if (next_cost >= dist[e.to]) continue;
            dist[e.to] = next_cost;
            if (!pending[e.to]) {
                if (++times[e.to] >= SZ(g)) return std::vector<T>();
                pending[e.to] = true;
                que.emplace(e.to);
            }
        }
    }

    return dist;
}


int main() {
    using namespace std;
    int v, e, r; cin >> v >> e >> r;
    WeightedGraph<int> g(v);
    while(e--) {
        int a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }
    auto dists = showrest_path_faster_algorithm(g, r);
    for (auto& e : dists) {
        if (e == numeric_limits<int>::max()) cout << "INF" << endl;
        else cout << e << endl;
    }

    return 0;
}
