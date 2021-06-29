#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e10;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  for (int i = 0; i < n; ++i) dist[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    int s, t, d; cin >> s >> t >> d;
    dist[s][t] = d;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] == INF || dist[k][j] == INF) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (dist[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j) cout << ' ';
      cout << ( (dist[i][j] == INF) ? "INF" : to_string(dist[i][j]) );
    }
    cout << endl;
  }
  return 0;
}

