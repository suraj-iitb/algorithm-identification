// DP F

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1e9;
const long long INFL = 1LL<<60;

void dump(const vector<pair<int, int>>& a)
{
  for (auto v : a) {
    cerr << v.first << " " << v.second << endl;
  }
}

////////////////////////////////////////////////////

static const int MAX = 100;

int n;
ll d[MAX][MAX];

void floyd()
{
  rep(k, n) {
    rep(i, n) {
      if (d[i][k] == INFL) {
        continue;
      }
      rep(j, n) {
        if (d[k][j] == INFL) {
          continue;
        }
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main()
{
  int e, u, v, c;
  cin >> n >> e;

  rep(i, n) {
    rep(j, n) {
      d[i][j] = ((i == j) ? 0 : INFL);
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
      if (j) {
        cout << " ";
      }
      if (d[i][j] == INFL) {
        cout << "INF";
      } else {
        cout << d[i][j];
      }
    }
    cout << endl;
  }

  return 0;
}

