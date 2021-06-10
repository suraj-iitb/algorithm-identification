#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int INF = (int)2e9;
constexpr ll INFll = (ll)9e18;
constexpr int MOD = 10000;

using P = pair<ll, int>;

struct edge {
  int to, cost;
};

int main() {
  int V, E, r;
  cin >> V >> E >> r;

  vector<vector<edge>> G(V);
  for (int i = 0; i < E; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s].push_back(edge {t, d});
  }

  vector<ll> d(V, INFll);
  d[r] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.emplace(0ll, r);
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    if (p.first > d[p.second]) continue;
    for (auto e : G[p.second]) {
      if (d[e.to] > p.first + e.cost) {
        d[e.to] = p.first + e.cost;
        que.emplace(d[e.to], e.to);
      }
    }
  }

  for (int v = 0; v < V; ++v) {
    if (d[v] == INFll)
      cout << "INF" << endl;
    else
      cout << d[v] << endl;
  }
}
