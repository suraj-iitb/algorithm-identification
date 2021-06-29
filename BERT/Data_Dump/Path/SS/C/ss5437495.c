#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll v, e, r;
ll s[514514], t[514514], d[514514];
ll dist[114514];
vector<pair<int, ll>> G[114514];

void dijkstra(int stt) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    rep(i, v) dist[i] = 1145141919;
    dist[stt] = 0;
    Q.push(make_pair(0, stt));
    while(!Q.empty()) {
       int pos = Q.top().second; Q.pop();
        rep(i, G[pos].size()) {
            ll to = G[pos][i].first;
            ll cost = G[pos][i].second;
            if(dist[to] > dist[pos] + cost) {
                dist[to] = dist[pos] + cost;
                Q.push(make_pair(dist[to], to));
            }
        }
    }
}

int main() {
    cin >> v >> e >> r;
    rep(i, e) {
        cin >> s[i] >> t[i] >> d[i];
        G[s[i]].push_back(make_pair(t[i], d[i]));
    }
    dijkstra(r);
    rep(i, v) {
        if(dist[i] != 1145141919) {
            cout << dist[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }
    return 0;
}
