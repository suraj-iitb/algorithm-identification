#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

struct edge {
  ll to, cost;
};

struct graph {
  ll V;
  vector<vector<edge>> G;  //グラフを表す
  vector<ll> d;            //距離

  graph(ll n) { init(n); }

  void init(ll n) {
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i, V) { d[i] = INF; }
  }

  void add_edge(ll s, ll t, ll cost) {
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s) {
    rep(i, V) { d[i] = INF; }
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    while (!que.empty()) {
      P p = que.top();
      que.pop();
      ll v = p.second;
      if (d[v] < p.first) continue;
      for (auto e : G[v]) {
        if (d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          que.push(P(d[e.to], e.to));
        }
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  int n, m, r;
  cin >> n >> m >> r;
  graph g(n);
  rep(i, m) {
    int s, t, d;
    cin >> s >> t >> d;
    g.add_edge(s, t, d);
  }
  g.dijkstra(r);
  rep(i, n) {
    if (g.d[i] == INF)
      cout << "INF" << endl;
    else
      cout << g.d[i] << endl;
  }
  return 0;
}

