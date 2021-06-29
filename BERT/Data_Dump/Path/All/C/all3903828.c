#include <iostream>
using namespace std;
using ll = long long;

#define rep(i,n) for(int i=0;i<(n);++i)

#define out(v) cout<<v<<"\n"
const ll INF = 1e10;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int V, E; cin >> V >> E;

  ll cost[V][V];
  rep(s, V) rep(t, V) {
    if (s == t)
      cost[s][t] = 0;
    else
      cost[s][t] = INF;
  }

  rep(i, E) {
    int s, t, d;
    cin >> s >> t >> d;
    cost[s][t] = d;
  }
  rep(k, V) rep(i, V) rep(j, V) {
    if (cost[i][k] == INF || cost[k][j] == INF)
      continue;
    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
  }
  rep(i, V) {
    if (cost[i][i] < 0) {
      cout << "NEGATIVE CYCLE\n";
      return 0;
    }
  }
  rep(i, V) {
    rep(j, V) {
      if (cost[i][j] == INF)
        cout << "INF";
      else
        cout << cost[i][j];
      if (j + 1 != V)
        cout << " ";
    }
    cout << "\n";
  }

  return 0;
}
