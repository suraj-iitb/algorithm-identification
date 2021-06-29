#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

struct edge{
    int to;
    int cost;
};

vector<int> dijkstra(vector<vector<edge>> g, int start_v, int num_v) {
    vector<int> dist(num_v, INF);
    dist[start_v] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start_v));
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        int v = tmp.second;
        if (dist[v] < -tmp.first) continue;
        for (auto e : g[v]) {
            int next_v = e.to;
            int next_cost = e.cost;
            if (dist[v] + next_cost < dist[next_v]) {
                dist[next_v] = dist[v] + next_cost;
                pq.push(make_pair(-dist[next_v], next_v));
            }
        }
    }
    return dist;
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<edge>> g(n);
    rep(i, 0, m) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].push_back(edge{t, d});
    }
    vector<int> dist = dijkstra(g, r, n);
    rep(i, 0, n) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}

