#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;
const long long INF = 1e18;
using ll = long long;

template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

struct Edge {
  ll to;
  ll cost;
};

using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;

/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<ll> &dis) {
  int N = G.size();
  dis.resize(N, INF);
  priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) {  // 最短距離で無ければ無視
      continue;
    }
    for (auto &e : G[v]) {
      if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
        dis[e.to] = dis[v] + e.cost;
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}

int main() {
  ll V, E, r;
  cin >> V >> E >> r;

  Graph g;
  g.assign(V, vector<Edge>());  // numV点分の空要素を作成

  for (int i = 0; i < E; ++i) {
    ll s, t, d;
    cin >> s >> t >> d;
    Edge e = {t, d};
    g[s].emplace_back(e);
  }

  vector<ll> dis;

  dijkstra(g, r, dis);

  // for (auto hoge : g.L) {
  //   for (auto h : hoge) {
  //     cout << h.first << ", " << h.second << endl;
  //   }
  // }
  for (auto d : dis) {
    if (d == INF) {
      cout << "INF" << endl;
      continue;
    }
    cout << d << endl;
  }

  return 0;
}

