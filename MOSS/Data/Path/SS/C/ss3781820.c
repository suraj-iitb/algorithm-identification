#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll LINF = 1LL << 60;

int V, E, r;
vector<vector<pair<int, int>>> graph;
vector<ll> dist;

void dijkstra(int s) {
    dist.assign(V, LINF);
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, s);
    int cnt_visited = 0;

    while (!pq.empty()) {
        auto v = pq.top(); pq.pop();
        if (v.first > dist[v.second]) continue;
        else if (++cnt_visited == V) break;

        for (auto& u : graph[v.second]) {
            if (v.first + u.first < dist[u.second]) {
                dist[u.second] = v.first + u.first;
                pq.emplace(v.first + u.first, u.second);
            }
        }
    }
}

int main() {
    cin >> V >> E >> r;
    graph.resize(V);
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].emplace_back(d, t);
    }

    dijkstra(r);

    for (ll d : dist) {
        if (d == LINF) cout << "INF" << endl;
        else cout << d << endl;
    }
}
