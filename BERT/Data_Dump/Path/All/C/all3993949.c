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
void warshall_floyd(vector<vector<T>>& g, T inf) {
   for (int k = 0; k < g.size(); ++k) {
      for (int i = 0; i < g.size(); ++i) {
         for (int j = 0; j < g.size(); ++j) {
            if (g[i][k] == inf || g[k][j] == inf) continue;
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
         }
      }
   }
}

int main() {
   int V, E; cin >> V >> E;
   auto g = make_v(V, V, inf64);
   rep(i, E) {
      int u, v;
      i64 d;
      cin >> u >> v >> d;
      g[u][v] = d;
   }
   rep(i, V) g[i][i] = 0;

   warshall_floyd(g, inf64);
   rep(i, V) if (g[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
   }

   rep(i, V) {
      rep(j, V) {
         if (j == 0) {
            if (g[i][j] == inf64) cout << "INF";
            else cout << g[i][j];
         } else {
            if (g[i][j] == inf64) cout << " INF";
            else cout << " " << g[i][j];
         }
      }
      cout << endl;
   }
}
