#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INFL = 1ll << 60;

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<ll>> g(V, vector<ll>(V, INFL * 2));
  for (int i = 0; i < E; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    g[s][t] = d;
  }
  for (int i = 0; i < V; i++) g[i][i] = 0;

  for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

  for (int i = 0; i < V; i++) {
    if (g[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  for (int y = 0; y < V; y++) {
    for (int x = 0; x < V; x++) {
      if (g[y][x] >= INFL)
        cout << "INF";
      else
        cout << g[y][x];
      if (x != V - 1) cout << " ";
    }
    cout << endl;
  }
}

