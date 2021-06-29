#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = 1e18;
int main(){
  int V, E, r;
  cin >> V >> E >> r;
  vector<vector<P>> g(V);
  rep(i,E) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].emplace_back(make_pair(v,c));
  }
  
  auto dijkstra = [&](int s) {
    vector<ll> d(V,INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que;
    que.push(make_pair(0LL,s));
    d[s] = 0LL;
    while (!que.empty()) {
      auto p = que.top(); que.pop();
      int u = p.second;
      if (d[u] < p.first) continue;
      for (auto v : g[u]) {
        if (d[u] + v.second < d[v.first]) {
          que.push(make_pair(d[u] + v.second, v.first));
          d[v.first] = d[u] + v.second;
        }
      }
    }
    return d;
  };

  auto res = dijkstra(r);

  for (auto ans : res) {
    if (ans == INF) cout << "INF" << endl;
    else cout << ans << endl;
  }
  return 0;
} 
