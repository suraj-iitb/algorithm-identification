#include <bits/stdc++.h>
#define INF INT_MAX

using namespace std;

// エッジの定義
struct edge {
  int to;
  int cost;
};

// firstは未確定の最短距離，secondは頂点の番号となるペアPを定義
typedef pair<int, int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 入力データの代入
  int V, E, r;
  cin >> V >> E >> r;
  
  vector<vector<edge>> G(V, vector<edge>());
  for (int i = 0; i < E; i ++) {
    int s_i, t_i, d_i;
    cin >> s_i >> t_i >> d_i;
    G[s_i].push_back({ t_i, d_i });
  }

  /* 負の辺がないため，ダイクストラ法を用いる */
  // 確定した各頂点までの最短距離のリストdを初期化
  vector<int> d(V);
  fill(d.begin(), d.end(), INF);
  d[r] = 0;
  
  // 未確定ペアのプライオリティキューを初期化
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, r));

  while(!que.empty()) {
    P p = que.top(); que.pop(); // 未確定の最短距離の中で最小のペアを取り出す
    int v = p.second;
    if (d[v] < p.first) continue;
    for (uint j = 0; j < G[v].size(); j ++) { // 隣接する頂点を取り出す
      edge e = G[v][j];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }

  for (int i = 0; i < V; i ++) {
    if (d[i] == INF) {
      cout << "INF" << endl;
    } else {
      cout << d[i] << endl;
    }
  }
}
