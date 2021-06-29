#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

using ll = long long;


enum value_class_type {
    finite_class,
    pos_inf_class,
    neg_inf_class
};

template <class T>
struct non_standard {
    value_class_type value_class;
    T value;

    non_standard(T value) : value_class(value_class_type::finite_class), value(value) { }

    non_standard(value_class_type value_class, T value) : value_class(value_class), value(value) { }

    inline bool is_finite() const {
        return value_class == value_class_type::finite_class;
    }

    inline bool is_pos_inf() const {
        return value_class == value_class_type::pos_inf_class;
    }

    inline bool is_neg_inf() const {
        return value_class == value_class_type::neg_inf_class;
    }

    static inline non_standard pos_inf() {
        return non_standard(value_class_type::pos_inf_class, 0);
    }

    static inline non_standard neg_inf() {
        return non_standard(value_class_type::neg_inf_class, 0);
    }

    friend std::ostream& operator<<(std::ostream &os, const non_standard x) {
        if (x.is_finite()) {
            os << x.value;
        } else if (x.is_pos_inf()) {
            os << "INF";
        } else if (x.is_neg_inf()) {
            os << "-INF";
        }
        return os;
    }
};


struct edge {
    typedef size_t weight_type;

    size_t m_to;

    edge(size_t to) : m_to(to) { }

    inline size_t to() const { return m_to; }

    inline weight_type weight() const { return 1; }

    friend std::ostream& operator<<(std::ostream &os, const edge &e) {
        os << "{ to: " << e.m_to << " }";
        return os;
    }
};

template <typename Weight>
struct weighted_edge : public edge {
    typedef Weight weight_type;

    weight_type m_weight;

    weighted_edge(size_t to, weight_type weight) : edge(to), m_weight(weight) { }

    inline weight_type weight() const { return m_weight; }
};

template <class Edge>
struct graph {
    typedef Edge edge_type;

    size_t m_n_vertices;
    vector<vector<edge_type>> m_edges;

    graph(size_t n_vertices) : m_n_vertices(n_vertices), m_edges(n_vertices) { }

    inline size_t n_vertices() const { return m_n_vertices; }

    inline void make_edge(size_t from, size_t to, typename edge_type::weight_type weight) {
        m_edges[from].emplace_back(edge_type(to, weight));
    }

    inline void make_edge(size_t from, size_t to) {
        m_edges[from].emplace_back(edge(to));
    }

    inline void make_edge(size_t from, const edge_type &e) {
        m_edges[from].emplace_back(e);
    }

    inline vector<edge_type> edges_from(size_t v) const {
        return m_edges[v];
    }
};

template <class Graph>
vector<non_standard<typename Graph::edge_type::weight_type>> dijkstra(const Graph &g, size_t start) {
    using Edge = typename Graph::edge_type;
    using Weight = typename Edge::weight_type;
    using ExtendedWeight = non_standard<Weight>;
    using P = pair<Weight, size_t>;

    vector<ExtendedWeight> dp(g.n_vertices(), ExtendedWeight::pos_inf());

    priority_queue<P, vector<P>, greater<P>> q;

    dp[start] = ExtendedWeight(0);
    q.emplace(dp[start].value, start);

    while (!q.empty()) {
        Weight w0;
        size_t v0;
        tie(w0, v0) = q.top();
        q.pop();

        if (dp[v0].value < w0)
            continue;

        for (const Edge &e: g.edges_from(v0)) {
            size_t v1 = e.to();
            Weight w1 = w0 + e.weight();
            if (dp[v1].is_pos_inf() || dp[v1].value > w1) {
                dp[v1] = w1;
                q.emplace(dp[v1].value, v1);
            }
        }
    }

    return dp;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    using Edge = weighted_edge<ll>;
    using Graph = graph<Edge>;

    int V, E, r;
    cin >> V >> E >> r;

    Graph g(V);

    REP(_, E) {
        int s, t, d;
        cin >> s >> t >> d;
        g.make_edge(s, t, d);
    }

    auto dp = dijkstra(g, r);

    REP(i, V) {
        cout << dp[i] << '\n';
    }
    cout << flush;

    return 0;
}

