#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)

static const int MAX = 100;
static const ll INFTY = (1LL << 32);

int n;
vector<vector<ll>> d(MAX, vector<ll>(MAX));

void floyd() {
  rep(k, 0, n) {
    rep(i, 0, n) {
      if (d[i][k] == INFTY) {
        continue;
      }
      rep(j, 0, n) {
        if (d[k][j] == INFTY) {
          continue;
        }
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
};

int main() {
  int e, u, v, c;
  cin >> n >> e;
  rep(i, 0, n) {
    rep(j, 0, n) {
      d[i][j] = ((i == j) ? 0 : INFTY);
    }
  }
  rep(i, 0, e) {
    cin >> u >> v >> c;
    d[u][v] = c;
  }

  floyd();

  bool negative = false;
  rep(i, 0, n) {
    if (d[i][i] < 0) negative = true;
  }

  if (negative) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    rep(i, 0, n) {
      rep(j, 0, n) {
        if (j)  cout << " ";
        if (d[i][j] == INFTY) cout << "INF";
        else cout << d[i][j];
      }
      cout << endl;
    }
  }
};

