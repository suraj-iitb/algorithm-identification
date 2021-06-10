#include <bits/stdc++.h>
using namespace std;
const long long infty = 1e18;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> dst(n, vector<long long>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        dst[i][j] = infty;
      } else {
        dst[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    dst[s][t] = d;
  }  
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dst[i][k] != infty && dst[k][j] != infty) {
          dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (dst[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << '\n';
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dst[i][j] != infty) {
        cout << dst[i][j];
      } else {
        cout << "INF";
      }
      if (j < n - 1) {
        cout << ' ';
      } else {
        cout << '\n';
      }
    }
  }
  return 0;
}
