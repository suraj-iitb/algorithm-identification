#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;

struct edge {
  int to, cost;
};

vector<int> dijkstra(vector<vector<edge>> g, int start, int v_count, int e_count) {
  vector<int> d(v_count);
  rep(i, v_count) d[i] = 1 << 30;
  d[start] = 0;
  priority_queue<Pii, vector<Pii>, greater<Pii>> que;
  que.emplace(d[start], start);
  while (!que.empty()) {
    Pii p = que.top();
    que.pop();
    int v = p.second;
    if (p.first > d[v]) continue;
    rep(i, g[v].size()) {
      edge e = g[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(Pii(d[e.to], e.to));
      }
    }
  }
  return d;
}

int main() {
  int vc,ec,r; cin>>vc>>ec>>r;
  vector<vector<edge>> g(500000);
  rep(i,ec) {
    int s,t,d; cin>>s>>t>>d;
    g[s].push_back({t, d});
  }

  vector<int> d = dijkstra(g, r, vc, ec);

  rep(i, vc) {
    if (d[i] == 1 << 30) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
}

