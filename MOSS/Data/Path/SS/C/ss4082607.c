#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
int popcount(int val) { return __builtin_popcount(val); }
int popcountll(ll val) { return __builtin_popcountll(val); }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

using CostType = ll;
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &rhs) const {
    return cost != rhs.cost ? cost < rhs.cost : dst != rhs.dst ? dst < rhs.dst : src < rhs.src;
  }
  inline bool operator<=(const Edge &rhs) const { return !(rhs < *this); }
  inline bool operator>(const Edge &rhs) const { return rhs < *this; }
  inline bool operator>=(const Edge &rhs) const { return !(*this < rhs); }
};

struct Dijkstra {
  using Pci = pair<CostType, int>;

  Dijkstra(const vector<vector<Edge> > &graph, const CostType CINF = LINF) : graph(graph), CINF(CINF) {}

  vector<CostType> build(int s) {
    int n = graph.size();
    vector<CostType> dist(n, CINF);
    dist[s] = 0;
    prev.assign(n, -1);
    posteriority_queue<Pci> que;
    que.emplace(0, s);
    while (!que.empty()) {
      CostType cost; int ver; tie(cost, ver) = que.top(); que.pop();
      if (dist[ver] < cost) continue;
      for (const Edge &e : graph[ver]) {
        if (dist[e.dst] > dist[ver] + e.cost) {
          dist[e.dst] = dist[ver] + e.cost;
          prev[e.dst] = ver;
          que.emplace(dist[e.dst], e.dst);
        }
      }
    }
    return dist;
  }

  vector<int> build_path(int t) {
    vector<int> res;
    for (; t != -1; t = prev[t]) res.emplace_back(t);
    reverse(ALL(res));
    return res;
  }

private:
  vector<vector<Edge> > graph;
  const CostType CINF;
  vector<int> prev;
};

int main() {
  int v, e, r; cin >> v >> e >> r;
  vector<vector<Edge> > graph(v);
  REP(i, e) {
    int s, t, d; cin >> s >> t >> d;
    graph[s].emplace_back(s, t, d);
  }
  Dijkstra dij(graph);
  vector<ll> dist = dij.build(r);
  REP(i, v) {
    if (dist[i] == LINF) {
      cout << "INF\n";
    } else {
      cout << dist[i] << '\n';
    }
  }
  return 0;
}

