#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
template <class T>
/*  ワーシャルフロイド
    O(V)，全店最短路
    dis[i][i]=0を入力しておく
    dis[i][j]に，辺i-jのコストを入力しておく
    辺がなかったらINF
    負の閉路があったらdis[i][i]が負になるものが存在する*/
void warshall_floyd(T &dis) {
  int V = dis.size();
  REP(k, V)
  REP(i, V) {
    if (dis[i][k] == INF) continue;
    REP(j, V) {
      if (dis[k][j] == INF) continue;
      dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
  }
}
int main() {
  ll v, e;
  cin >> v >> e;
  vector<vector<ll>> G(v, vector<ll>(v, INF));
  REP(i, e) {
    int a, b, c;
    cin >> a >> b >> c;
    G[a][b] = c;
  }
  REP(i, v) G[i][i] = 0;
  warshall_floyd(G);
  REP(i, v) {
    if (G[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  REP(i, v) {
    REP(j, v) {
      if (j != 0) cout << " ";
      if (G[i][j] == INF)
        cout << "INF";
      else
        cout << G[i][j];
    }
    cout << endl;
  }
}
