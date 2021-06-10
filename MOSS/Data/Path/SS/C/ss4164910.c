#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int INF = 1001001001;
constexpr int MOD = 1000000007;

struct Edge {
  int to;
  int cost;
};

// 隣接リスト
vector<Edge> g[200000];
// g[i] = 頂点iから生えてる全ての辺のリスト
// g[i][j].to = 頂点iからtoへの辺
// g[i][j].cost = その辺のコスト

int d[200000]; // 頂点d[v]への最短距離

void dijkstra(int s) {
  d[s] = 0;  // 始点の最短距離 = 0

  // firstを最短距離、secondを頂点番号
  priority_queue<P, vector<P>, greater<P>> pq;

  pq.push(P(d[s], s));

  while (!pq.empty()) {
    int v_cost = pq.top().first;
    int v = pq.top().second;
    pq.pop();

    if (d[v] < v_cost) continue; //無駄な探索を減らす

    for (int i = 0; i < g[v].size(); i++) {
      int c = g[v][i].to;
      int c_cost = g[v][i].cost;  // 辺vcのコスト

      int cost = v_cost + c_cost;  // 頂点cへの合計コスト
      if (d[c] > cost) { // すでに記録されてるものより低コストなら更新
        d[c] = cost;
        pq.push(P(cost, c));
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int V, E, r;
  cin >> V >> E >> r;

  fill(d, d + V, INF);

  // 隣接リストの作成
  for (int i = 0; i < E; i++) {
    int s, t, cost;
    cin >> s >> t >> cost;

    Edge edge = {t, cost};

    g[s].emplace_back(edge);
  }

  dijkstra(r);

  for (int i = 0; i < V; i++) {
    if (d[i] == INF) {
      cout << "INF" << endl;
    } else {
      cout << d[i] << endl;
    }
  }

  return 0;
}
