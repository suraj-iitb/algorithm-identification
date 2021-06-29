#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif


using P = pair<ll, ll>;

struct Edge { ll to; ll cost; };
vector<Edge> G[100010];
ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll V, E; cin >> V >> E;
  vector<ll> d(V, INF);
  ll v0; cin >> v0;

  for (ll i = 0; i < E; i++) {
    ll a, b; cin >> a >> b;
    // a--; b--;
    ll c; cin >> c;
    G[a].emplace_back(Edge({b, c}));
    // G[b].emplace_back(Edge({a, c}));
  }

  priority_queue<P, vector<P>, greater<P>> q;
  d[v0] = 0;
  q.push(P(0, v0));

  while (!q.empty()) {
    P p = q.top(); q.pop();
    ll v = p.second;
    if (d[v] < p.first) continue;
    for (ll i = 0; i < G[v].size(); i++) {
      Edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        q.push(P(d[e.to], e.to));
      }
    }
  }

  for (ll i = 0; i < V; i++) {
    if (d[i] == INF) cout << "INF\n";
    else cout << d[i] << '\n';
  }

  return 0;
}
