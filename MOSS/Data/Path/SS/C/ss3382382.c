#include <bits/stdc++.h>

template <typename Edge>
class graph {
    using graph_t = std::vector<std::vector<Edge>>;
public:
    using reference = std::vector<Edge>&;
    using const_reference = std::vector<Edge> const&;
    using iterator = typename graph_t::iterator;
    using const_iterator = typename graph_t::const_iterator;
    using reverse_iterator = typename graph_t::reverse_iterator;

    graph() : g() {}
    graph(int n) : g(n) {}

    reference operator[](int x) { return g[x]; }
    const_reference operator[](int x) const { return g[x]; }

    iterator begin() { return std::begin(g); }
    iterator end() { return std::end(g); }
    reverse_iterator rbegin() { return std::rbegin(g); }
    reverse_iterator rend() { return std::rend(g); }

    int size() const { return g.size(); }

    void add_node(std::vector<Edge> es) {
        g.push_back(std::move(es));
    }

    void add_edge(int node_idx, Edge e) {
        g[node_idx].push_back(std::move(e));
    }

private:
    std::vector<std::vector<Edge>> g;
};


class directed_edge {
public:
    directed_edge(int t) : to(t) {}

    int to;
};

class directed_graph : public graph<directed_edge> {
public:
    directed_graph(int n) : graph(n) {}

    using graph::add_edge;
    void add_edge(int from, int to) {
        add_edge(from, directed_edge{to});
    }
};

template <typename Cost>
class weighted_edge {
public:
    using cost_type = Cost;

    weighted_edge(int t, Cost c) : to(t), cost(c) {}

    int to;
    cost_type cost;
};

template <typename Cost>
class weighted_graph : public graph<weighted_edge<Cost>> {
    using base_t = graph<weighted_edge<Cost>>;
public:
    weighted_graph(int n) : base_t(n) {}

    using base_t::add_edge;
    void add_edge(int from, int to, Cost cost) {
        add_edge(from, weighted_edge<Cost>{to, cost});
    }
};

template <typename Edge, typename Cost = typename Edge::cost_type>
std::vector<Cost> spfa(graph<Edge> const& g, int s, Cost inf = std::numeric_limits<Cost>::max() / 2) {
    std::vector<Cost> d(g.size(), inf);
    std::vector<int> in_q(g.size()), count(g.size());
    std::queue<int> que;
    d[s] = Cost(0);
    in_q[s] = true;
    count[s] = 1;
    que.push(s);
    while(!que.empty()) {
        const int v = que.front();
        que.pop();
        in_q[v] = false;
        for(const auto& e : g[v]) {
            if(d[e.to] <= d[v] + e.cost) continue;
            d[e.to] = d[v] + e.cost;
            if(in_q[e.to]) continue;
            que.emplace(e.to);
            in_q[e.to] = true;
            if(++count[e.to] >= static_cast<int>(g.size())) {
                return std::vector<Cost>{};
            }
        }
    }
    return d;
}

using namespace std;

constexpr int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, r; cin >> n >> m >> r;
    weighted_graph<int> g(n);
    for(int i = 0; i < m; ++i) {
        int s, t, d; cin >> s >> t >> d;
        g.add_edge(s, t, d);
    }
    auto ans = spfa(g, r, INF);
    for(int i = 0; i < n; ++i) {
        if(INF == ans[i]) {
            cout << "INF" << "\n";
        } else {
            cout << ans[i] << "\n";
        }
    }
}

