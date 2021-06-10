#line 1 "dijkstra.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define all(i) i.begin(), i.end()
template<class T, class U> bool cmax(T& a, U b) { if (a<b) {a = b; return true;} else return false; }
template<class T, class U> bool cmin(T& a, U b) { if (a>b) {a = b; return true;} else return false; }

#line 1 "../dijkstra.cpp"
ll INF = 1LL<<60;
using pll = pair<ll, ll>;

vl dijkstra(ll n, ll s, vector<vector<pll>> G) {
  priority_queue<pll, vector<pll>, greater<pll>> que;
  vl d(n, INF);
  d[s] = 0;
  que.push(pll(0, s));

  while(!que.empty()) {
    pll p = que.top();
    que.pop();
    ll v = p.second;
    if (d[v] < p.first) continue;
    for (auto&& e : G[v]) {
      if (d[e.first] > d[v] + e.second) {
        d[e.first] = d[v] + e.second;
        que.push(pll(d[e.first], e.first));
      }
    }
  }
  return d;
}
#line 15 "dijkstra.test.cpp"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  ll v, e, r;
  cin >> v >> e >> r;
  vector<vector<pll>> g(v);
  rep(i, e) {
    ll s, t, d;
    cin >> s >> t >> d;
    g[s].emplace_back(t, d);
  }

  vl vec = dijkstra(v, r, g);

  for (auto&& i : vec) {
    if (i == INF) cout << "INF" << endl;
    else cout << i << endl;
  }
}

