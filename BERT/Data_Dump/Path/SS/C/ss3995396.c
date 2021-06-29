#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
template <typename T> class dijkstra {
private:
  using ll = long long;
  using pp = pair<int, ll>;
public:
  ll INF_DIST = std::numeric_limits<ll>::max() / 2;
private:
  int start = 0;
  int siz = 0;
  void calc (const vector<vector<pair<int, T>>>& g) {
    dist.resize(siz);
    fill(dist.begin(), dist.end(), INF_DIST);
    dist[start] = 0;
    priority_queue<pp, vector<pp>, greater<pp>> que;
    que.emplace(0, start);
    while (que.size()) {
      pp cur = que.top();
      que.pop();
      int idx = cur.second;
      ll d = cur.first;
      if (d > dist[idx]) continue;
      for (const pp& nxt : g[idx]) {
        int j = nxt.first;
        ll d2 = d + nxt.second;
        if (d2 <  dist[j]) {
          dist[j] = d2;
          que.emplace(dist[j], j);
        }
      }
    }
  }
public:
  dijkstra (const vector<vector<pair<int, T>>>& g, int st, int n = -1) : start(st) {if (n < 0) siz = (int) g.size(); calc(g); }
  dijkstra (const vector<pair<int, T>> in[], int st, int n) : start(st), siz(n) {
    vector<vector<pair<int, T>>> g(n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < (int) in[i].size(); j++) g[i].push_back(in[i][j]);
    calc(g);
  }
  vector<ll> dist;
  vector<ll> get() {return dist;}
};
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, r;
  cin >> n >> m >> r;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int s, t, c;
    cin >> s >> t >> c;
    g[s].emplace_back(t, c);
    //g[t].emplace_back(s, c);
  }
  dijkstra<int> di(g, r);
  for (int i = 0; i < n; i++) {
    if (di.dist[i] != di.INF_DIST) cout << di.dist[i] << '\n';
    else cout << "INF\n";
  }
  // int n, m;
  // cin >> n >> m;
  // vector<vector<pair<int, int>>> g(m + 1);
  // for (int i = 1; i <= m; i++) g[i].emplace_back(i - 1, 0);
  // for (int i = 0; i < n; i++) {
  //   int x, s;
  //   cin >> x >> s;
  //   for (int left = max(0, x - s), right = min(m, x + s), cost = 0; left > 0 || right < m; left = max(0, --left), right = min(m, ++right), cost++) {
  //     g[left].emplace_back(right, cost);
  //   }
  // }
  // dijkstra dkt(g, 0);
  // cout << dkt.dist[m] << '\n';
  return 0;
}
