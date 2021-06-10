#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

// =================グラフテンプレート==================

// costの部分の型は指定できます
template <typename T>
struct edge {
  int from, to;
  T cost;

  edge(int to, T cost) : from(-1), to(to), cost(cost) {}
  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

  // 行き先を代入できる
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  // その他便利機能、って感じ
  operator int() const { return to; }
  bool operator<(edge x) { return this->cost < x.cost; }
};

template <typename T>
using Edges = vector<edge<T>>;

template <typename T>
using WeightedGraph = vector<Edges<T>>;

template <typename T>
using Matrix = vector<vector<T>>;

using UnWeightedGraph = vector<vector<int>>;

//=====================Dijkstra法=======================
// 重み付きグラフと始点を与えると、距離が入ったvectorが帰ってきます
// 距離の型はintでもllでもいいです

template <typename T>
vector<T> dijkstra(WeightedGraph<T> &g, int s) {
  const auto INF = numeric_limits<T>::max();
  vector<T> dist(g.size(), INF);  // 距離をINFで埋める

  using P = pair<T, int>;
  priority_queue<P, vector<P>, greater<P>> que;
  dist[s] = 0;
  que.emplace(0, s);

  while (!que.empty()) {
    T cost;
    int now;
    tie(cost, now) = que.top();
    que.pop();
    if (dist[now] < cost) continue;
    for (auto &e : g[now]) {
      auto next_cost = cost + e.cost;
      if (dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  cout << "}";
  return os;
}

// ====================================================================

int main() {
  ll n, m, s;
  cin >> n >> m >> s;

  WeightedGraph<ll> g(n);  // rgは逆辺を張る
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    g[a].push_back(edge<ll>{b, c});
  }

  vector<ll> iki = dijkstra(g, s);

  for (int i = 0; i < n; i++) {
    if (INFL <= iki[i])
      cout << "INF" << endl;
    else
      cout << iki[i] << endl;
  }
}

