#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAX = 100;
static const ll INFTY = (1LL<<32);

int n;
ll d[MAX][MAX];

// A_k :: {1, 2,..,k}のみを経由する頂点i->jの最短コスト
void floyd() {
  for (int k = 0; k < n; k++) { //すべての頂点に対して調べる
    for (int i = 0; i < n; i++) {
      if (d[i][k] == INFTY) continue;
      for (int j = 0; j < n; j++) {
        if (d[k][j] == INFTY) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  int e;
  cin >> n >> e;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      d[i][j] = (i == j ? 0 : INFTY);
    }
  }

  for (int i = 0; i < e; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    d[a][b] = c;
  }

  floyd();

  bool negative = false;
  for (int i = 0; i < n; i++) d[i][i] < 0 ? negative = true : 0;
  //もしi -> i の閉路の合計コストが負になるなら、無限にコストを下げられるのでダメ

  if (negative) {
    cout << "NEGATIVE CYCLE" << endl;
  }
  else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j > 0) cout << " ";
        if (d[i][j] == INFTY) cout << "INF";
        else cout << d[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}

