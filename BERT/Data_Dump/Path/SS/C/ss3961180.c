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
    for(int i = 0; i < graph.n; i++){
        for(const auto& e: graph.adj[i]){
            os << e << "\n";
        }
    }
    return os;
}

template<typename E>
vector<ll> Dijkstra(GraphL<E> &graph, int start_node) {
    using P = pair<ll, int>;
    vector<ll> dist(graph.n, INF);
    dist[start_node] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, start_node);
    while(!que.empty()){
        P p = que.top();
        que.pop();
        ll v = p.second;
        if(dist[v] < p.first){
            continue;
        }
        for(auto&& e: graph.adj[v]){
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                que.emplace(dist[e.to], e.to);
            }
        }
    }
    return dist;
}
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll V, E, r;
    cin >> V >> E >> r;
    GraphL<> g(V);
    for(int i = 0; i < E; i++){
        ll s, t, d;
        cin >> s >> t >> d;
        g.add_edge(s, t, d);
    }
    vector<ll> ans = Dijkstra(g, r);
    for(auto&& e: ans){
        if(e == INF) cout << "INF\n";
        else cout << e << "\n";
    }
    return 0;
}
