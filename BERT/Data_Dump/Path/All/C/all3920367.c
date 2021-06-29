#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;

const int MAX = 105;
const ll INF = 10000000005;

int n;
ll d[MAX][MAX];

void floyd() {
  rep(k, n) {
    rep(i, n) {
      if (d[i][k] == INF) continue;
      rep(j, n) {
        if (d[k][j] == INF) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  int e, u, v, c;
  cin >> n >> e;
  rep(i, n) {
    rep(j, n) {
      d[i][j] = INF;
      if (i == j) d[i][i] = 0;
    }
  }
  rep(i, e) {
    cin >> u >> v >> c;
    d[u][v] = c;
  }
  floyd();
  rep(i, n) {
    if (d[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  rep(i, n) {
    rep(j, n) {
      if (j) cout << " ";
      if (d[i][j] == INF) cout << "INF";
      else cout << d[i][j];
    }
    cout << endl;
  }
  
  return 0;
}
