#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
static const ll INF = 100000000000000;
struct Node {
  int id;
  ll cost;
  Node() {}
  Node(int id, ll cost) : id(id), cost(cost){}
  bool operator< (const Node& node) const {
    return node.cost < cost;
  } 
};

// N: 頂点数, E: 辺の数, d: 距離 を格納する配列, 
// t: 始点, flag: true なら　無向辺, false なら 有向辺
void dijkstra(int N, int E, ll d[], int t, int from[], int to[], ll cost[], bool flag) {
  static const int WHITE = 0;
  static const int GRAY = 1;
  static const int BLACK = 2;
  
  int color[N];
  vector<Node> adj[N];
  for (int i = 0; i < N; i++) {
    d[i] = INF;
    color[i] = WHITE;
  }
  // 隣接リストの作成
  for (int i = 0; i < E; i++) {
    adj[from[i]].push_back(Node(to[i], cost[i]));
    if (flag) adj[to[i]].push_back(Node(from[i], cost[i]));
  }
  priority_queue<Node> pq;
  d[t] = 0;
  pq.push(Node(t, 0));
  while (!pq.empty()) {
    Node f = pq.top();
    pq.pop();
    int u = f.id;
    color[u] = BLACK;
    if (d[u] < f.cost) continue;
    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j].id;
      if (color[v] == BLACK) continue;
      if (d[v] > d[u] + adj[u][j].cost) {
        d[v] = d[u] + adj[u][j].cost;
        pq.push(Node(v, d[v]));
        color[v] = GRAY;
      }
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int V, E, r;
  cin >> V >> E >> r;
  int s[E], t[E];
  ll d[E];
  for (int i = 0; i < E; i++) {
    cin >> s[i] >> t[i] >> d[i];
  }
  ll ans[V];
  dijkstra(V, E, ans, r, s, t, d, false);
  for (ll i : ans) {
    if (i == INF) {
      cout << "INF\n";
    } else {
      cout << i << "\n";
    }
  }
  return 0;
}
