#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const long long INF = 1LL << 60;
const int Inf = 1 << 29;
const int MOD = 1000000007;

int main() {
    long long V, E, r; cin >> V >> E >> r;
    vector<vector<pair<int, int>>> Graph(V);
    for (int i = 0; i < E; ++i) {
        long long s, t, d; cin >> s >> t >> d;
        Graph[s].push_back({t, d});
    }
    vector<long long> dist(V, INF);
    vector<bool> used(V, false);
    dist[r] = 0;
    priority_queue<pair<long long,long long>> pq;
    pq.push({0, r});
    while (!pq.empty()) {
        long long v = pq.top().second;
        pq.pop();
        used[v] = true;
        for (auto np : Graph[v]) {
            long long nv = np.first;
            long long nd = np.second;
            if (used[nv]) continue;
            if (dist[v] + nd < dist[nv]) {
                dist[nv] = dist[v] + nd;
                pq.push({-1*(dist[nv]), nv});
            }
        }
    }
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
