#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

// dijkstra O(ElogV)
// verify : https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
// ※拡張ダイクストラ
template<typename T>
struct Dijkstra {
private:
    int V;
    struct edge { int to; T cost; };
    vector<vector<edge>> G;
public:
    const T inf = numeric_limits<T>::max();

    // s から i の最小コスト
    // 経路がない場合は inf
    vector<T> d; // (頂点) ※

    Dijkstra(int V) : V(V) {
        G.resize(V);
    }

    // 辺の追加
    // 有向の場合　directed = true
    void add_edge(int from, int to, T weight, bool directed = false) {
        G[from].push_back({to,weight});
        if (!directed) G[to].push_back({from,weight});
    }

    void build(int s) {
        d.assign(V, inf); // ※
        typedef tuple<T, int> P; //(距離,頂点) ※
        priority_queue<P, vector<P>, greater<P>> pq;
        d[s] = 0; // ※
        pq.push(P(d[s], s)); // ※
        while (!pq.empty()) {
            P p = pq.top(); pq.pop();
            int v = get<1>(p);
            // ※
            if (d[v] < get<0>(p)) continue; // ※
            for (const edge &e : G[v])
            {
                // ※
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    pq.push(P(d[e.to], e.to));
                }
            }
        }
    }
};

int main() {
    int n, m, r; cin >> n >> m >> r;
    Dijkstra<ll> G(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        G.add_edge(a, b, c, true);
    }
    G.build(r);
    for (int i = 0; i < n; i++) {
        if (G.d[i] == G.inf) cout << "INF" << endl;
        else cout << G.d[i] << endl;
    }
    return 0;
}
