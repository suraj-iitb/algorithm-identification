#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define PI 3.14159265358979323846
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pll pair<long long, long long>
using namespace std;
using ll = long long;
using ld = long double;

// ----本問について----
// 問題：単一始点最短経路
// 問題文URL：https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
// 所要時間：
// 学んだこと：
// ------------------

// ----ここから本問のソースコード----

const ll INF = (ll)pow(10, 11);

// グローバル変数（入力）
ll v, e, r;
vector<vector<pll>> E; // 隣接リスト．pairは(終点,重み)．大きさv

// 入力
void input() {
  cin >> v >> e >> r;
  E.resize(v);
  rep(i, e) {
    ll s, e, w;
    cin >> s >> e >> w;
    E[s].push_back(make_pair(e, w)); // (sに接続する頂点，重み)
  }
  /*
  rep(i, v) {
    cout << "E[" << i << "] = {";
    rep(j, E[i].size()) {
      cout << "{" << E[i][j].first << ", " << E[i][j].second << "}";
      if (j != (ll)E[i].size()-1) { cout << ", "; }
    }
    cout << "}" << endl;
  }
  */
}

// ダイクストラ法
void solve() {
  vll d(v);
  rep(i, v) { d[i] = INF; }
  d[r] = 0;
  // 比較関数（昇順）
  auto comp = [](pll a, pll b) { return a.first > b.first; };
  // ↓pairは(始点からの距離,頂点番号)
  priority_queue<pll, vector<pll>, decltype(comp)> Q{comp};
  vll s(v, 0);                // 確定したら1にする
  Q.push(make_pair(d[r], r)); // 始点を追加
  while (!Q.empty()) {
    ll u = Q.top().second;
    // cout << "u:" << u << endl;
    Q.pop();
    if (s[u] == 0) { // 未確定なら
      rep(i, E[u].size()) {
        ll V = E[u][i].first;
        if (s[V] == 0) { // uと接続する頂点が未確定なら
          d[V] = min(d[V], d[u] + E[u][i].second); // 緩和
          // cout << "d[" << V << "]:" << d[V] << endl;
          Q.push(make_pair(d[V], V));
        }
      }
    }
    s[u] = 1;
  }
  rep(i, v) {
    if (d[i] == INF) {
      cout << "INF" << endl;
    } else {
      cout << d[i] << endl;
    }
  }
}

int main() {
  input();
  solve();
  return 0;
}

