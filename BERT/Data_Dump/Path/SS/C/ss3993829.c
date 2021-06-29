#include "bits/stdc++.h"
using namespace std;

#define rep(i,N) for(int i=0;i<(int)N;++i)
#define rep1(i,N) for(int i=1;i<=(int)N;++i)

using int64 = long long;
using i64 = long long;

const int inf = 1 << 30;
const i64 inf64 = 1ll << 60;

const int mod = 1e9 + 7;

template<typename T>
vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
   return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

int dy[] = { 0, 1, 0, -1 };
int dx[] = { -1, 0, 1, 0 };

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
   return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) {
   os << "[";
   for (auto& e : v) os << e << ", ";
   return os << "]";
}

template <typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>>& g, int s) {
   const auto inf = numeric_limits<T>::max();
   using P = pair<T, int>;

   vector<T> dist(g.size(), inf);
   priority_queue<P, vector<P>, greater<P>> que;
   dist[s] = 0;
   que.emplace(0, s);
   while (!que.empty()) {
      int u;
      T cost;
      tie(cost, u) = que.top(); que.pop();
      if (dist[u] < cost) continue;
      for (auto& e : g[u]) {
         T next_cost = cost + e.second;
         if (dist[e.first] <= next_cost) continue;
         dist[e.first] = next_cost;
         que.emplace(next_cost, e.first);
      }
   }

   return dist;
}

int main() {
   int V, E, r;
   cin >> V >> E >> r;
   using P = pair<int, int64>;
   vector<vector<P>> g(V);
   rep(i, E) {
      int u, v;
      i64 d;
      cin >> u >> v >> d;
      g[u].emplace_back(v, d);
   }

   auto dist = dijkstra(g, r);
   for (auto e : dist) {
      if (e == INT64_MAX) cout << "INF" << endl;
      else cout << e << endl;
   }
}
