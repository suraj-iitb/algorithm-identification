#include "bits/stdc++.h"
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define Endl endl

using namespace std;
const int MOD    = (int)(1e9 + 7);
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int x, int y) {                                                             //return x^y in order(log(y))
  if (x == 0) return 0;
  if (y == 0) return 1;
  int ans   = 1;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  x %= MOD;
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}

template<class T>
struct Dijkstra {
private:
  int n;
  vector<vector<pair<T, T>>> graph;

public:
  vector<T> shortest_path;
  Dijkstra(vector<vector<pair<T, T>>> &G): n(G.size()) { //
    graph = G;
    shortest_path.assign(n, (T)INF);
  }
  void dijkstra(int s) {
    rep(i, n) {
      shortest_path[i] = (T)INF;
    }
    shortest_path[s] = 0;
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<>> que;
    que.push({0, s});
    while (!que.empty()) {
      pair<T, T> p = que.top();
      que.pop();
      int v = p.second;
      if (shortest_path[v] < p.first) continue;
      for (auto e: graph[v]) {
        if (shortest_path[e.first] > shortest_path[v] + e.second) {
          shortest_path[e.first] = shortest_path[v] + e.second;
          que.push({shortest_path[e.first], e.first});
        }
      }
    }
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int V, E, r;
  cin >> V >> E >> r;
  vector<vector<pair<int, int>>> graph(V);
  rep(i, E) {
    int s, t, d;
    cin >> s >> t >> d;
    graph[s].emplace_back(t, d);
  }
  Dijkstra<int> s(graph);
  s.dijkstra(r);
  FOR(i, s.shortest_path) {
    if (i != INF)
      cout << i << endl;
    else
      cout << "INF" << endl;
  }
}
