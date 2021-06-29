#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
const ld EPS = 1e-12L;
const ld PI = 3.1415926535897932385L;
template<typename T> struct Edge {
    int from, to;
    T cost;
    Edge(int from, int to, T cost): from(from), to(to), cost(cost) {}
    Edge(int from, int to): from(from), to(to), cost(1) {}
    bool operator<(Edge<T> &r) {
        return cost < r.cost;
    }
};
template<typename T>
ostream &operator<<(ostream &os, Edge<T> edge) {
    os << edge.from << " -> " << edge.to << " (" << edge.cost << ")";
    return os;
}

// グラフテンプレート(隣接リスト)
template<typename E = Edge<ll>> struct GraphL {
    // 頂点数、辺数
    int n, m;
    // 隣接リスト
    vector<vector<E>> adj;
    GraphL(int n)
        : n(n), m(0), adj(n) {}
    
    template<typename... Args>
    void add_edge(int from, int to, Args... args) {
        adj[from].emplace_back(from, to, args...);
        m++;
    }
};
template<typename E = Edge<ll>>
ostream &operator<<(ostream &os, GraphL<E> graph) {
    os << "V = " << graph.n << ", E = " << graph.m << "\n";
    for(const auto& ev: graph.adj){
        for(const auto& e: ev){
            os << e << "\n";
        }
    }
    return os;
}
// グラフテンプレート(隣接行列)
template<typename T> struct GraphM {
    // 頂点数
    int n;
    // 無辺を表す
    const T NIL = INF;
    // 隣接行列
    vector<vector<T>> mat;
    GraphM(int n)
        : n(n), mat(n, vector<T>(n, NIL)) {}
    template<typename... Args>
    void add_edge(int from, int to, T cost = 1) {
        mat[from][to] = cost;
    }
};
template<typename T>
ostream &operator<<(ostream &os, GraphM<T> graph) {
    os << "V = " << graph.n << "\n";
    for(int i = 0; i < graph.n; i++) {
        for(int j = 0; j < graph.n; j++) {
            os << graph.mat[i][j] << " \n"[j == graph.n - 1];
        }
    }
    return os;
}
// ワーシャルフロイド法
// 隣接行列はdist[i][i] = 0, dist[i][j] = INF (no edge)
// 負閉路検出はdist[i][i]がすべて0ならok
template<typename T>
vector<vector<T>> WarshallFloyd(GraphM<T> &graph) {
    vector<vector<T>> dist(graph.mat);
    for(int i = 0; i < graph.n; i++)
        for(int j = 0; j < graph.n; j++)
            if(i == j) dist[i][j] = 0;
            else if(dist[i][j] == graph.NIL) dist[i][j] = INF;
    for(int k = 0; k < graph.n; k++)
        for(int i = 0; i < graph.n; i++)
            for(int j = 0; j < graph.n; j++)
                if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
}

template<typename E, typename T = ll>
vector<vector<T>> WarshallFloyd(GraphL<E> &graph) {
    GraphM<T> graph2(graph.n);
    for(const auto& ev: graph.adj) {
        for(const auto& e: ev) {
            graph2.add_edge(e.from, e.to, e.cost);
        }
    }
    return WarshallFloyd(graph2);
}
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll V, E;
    cin >> V >> E;
    GraphL<> g(V);
    for(int i = 0; i < E; i++) {
        ll s, t, d;
        cin >> s >> t >> d;
        g.add_edge(s, t, d);
    }
    vector<vector<ll>> ans = WarshallFloyd(g);
    for(int i = 0; i < V; i++) {
        if(ans[i][i] != 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(ans[i][j] == INF) {
                cout << "INF" << " \n"[j == V - 1];
            } else {
                cout << ans[i][j] << " \n"[j == V - 1];
            }
        }
    }
    return 0;
}
