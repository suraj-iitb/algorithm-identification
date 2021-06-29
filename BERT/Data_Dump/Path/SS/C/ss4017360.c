#include <bits/stdc++.h>
using namespace std;


template <typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>> &G, int source) {
    const T INF = numeric_limits<T>::max();
    using P = pair<T, int>;

    vector<T> dist(G.size(), INF);
    dist[source] = 0;

    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, source);

    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;

        for(auto edge : G[v]) {
            if(dist[edge.first] > dist[v] + edge.second) {
                dist[edge.first] = dist[v] + edge.second;
                que.emplace(dist[edge.first], edge.first);
            }
        }
    }

    return dist;
}

int main() {
    int N, M; cin >> N >> M;
    int r; cin >> r;
    vector<vector<pair<int, long long>>> G(N);
    for(int i=0; i<M; ++i) {
        int x, y; cin >> x >> y;
        long long d; cin >> d;
        G[x].emplace_back(y, d);
    }

    auto dist = dijkstra(G, r);
    for(int i=0; i<N; ++i) {
        if(dist[i] == numeric_limits<long long>::max()) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}
