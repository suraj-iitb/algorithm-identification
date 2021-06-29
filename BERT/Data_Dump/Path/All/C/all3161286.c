#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long int_t;

const int v_size = 100;
const int e_size = 10000;
int v, e;
int s[e_size];
int t[e_size];
int_t d[e_size];

bool input() {
  if (cin >> v >> e) {
    rep (i, e) cin >> s[i] >> t[i] >> d[i];
    return true;
  }
  return false;
}

const int_t inf = numeric_limits<int_t>::max();
int_t g[v_size][v_size];

void solve() {
  rep (i, v_size) fill(g[i], g[i]+v, inf);
  rep (i, v_size) g[i][i] = 0;
  rep (i, e) g[s[i]][t[i]] = d[i];

  for (int k = 0; k < v; ++k) {
    for (int i = 0; i < v; ++i) {
      for (int j = 0; j < v; ++j) {
        if (g[i][k] == inf || g[k][j] == inf) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  rep (i, v) {
    if (g[i][i] != 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return;
    }
  }

  rep (i, v) {
    rep (j, v) {
      if (j > 0) cout << " ";
      if (g[i][j] == inf) {
        cout << "INF";
      } else {
        cout << g[i][j];
      }
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (input()) {
    solve();
  }
  return 0;
}

