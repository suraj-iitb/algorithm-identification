#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template< typename T >
struct edge {
    int src,to;
    T cost;

    edge() = default;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    bool operator<(const edge &e) const {
        return cost < e.cost;
    }
};

////////////////////////////////////////////////////////////////////////

template<typename T>
vector<T> Dijkstra(vector<vector<edge<T>>> &G, int s, T inf) {
    vector<T> dist(G.size(),inf);

    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    dist[s] = 0;
    pq.emplace(dist[s],s);
    while (!pq.empty()) {
        T d; int v;
        tie(d,v) = pq.top(); pq.pop();
        if (d > dist[v]) continue;
        for (auto &e : G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                pq.emplace(dist[e.to],e.to);
            }
        }
    }

    return dist;
}

//////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N,M,s; cin >> N >> M >> s;
    vector<vector<edge<ll>>> G(N);
    for (int i = 0; i < M; ++i) {
        ll u,v,d; cin >> u >> v >> d;
        G[u].emplace_back(v,d);
    }

    auto dist = Dijkstra<ll>(G,s,1e18);
    for (int i = 0; i < N; ++i) {
        if (dist[i] == 1e18) {
            cout << "INF" << endl;
        } else cout << dist[i] << endl;
    }
}

/*
  verified on 2020/02/09
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
*/
