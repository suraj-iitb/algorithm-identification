#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using P = pair<int, int>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int v, e, r;
  cin >> v >> e >> r;
  vector<vector<int>> to(v), co(v);
  rep(i, e) {
    int a, b, c;
    cin >> a >> b >> c;
    to[a].push_back(b);
    co[a].push_back(c);
  }
  vector<int> dist(v, INF);
  priority_queue<P, vector<P>, greater<P>> que;
  que.push({0, r});
  dist[r] = 0;
  while (!que.empty()) {
    int now, cost;
    tie(cost, now) = que.top();
    que.pop();
    if (cost > dist[now])
      continue;
    rep(i, to[now].size()) {
      if (chmin(dist[to[now][i]], dist[now]+co[now][i]))
        que.push({dist[to[now][i]], to[now][i]});
    }
  }
  rep(i, v) {
    if (dist[i] == INF)
      cout << "INF" << endl;
    else
      cout << dist[i] << endl;
  }
  return 0;
}
