#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
void hr() {
   cerr << "--------------" << endl;
}
const int INF = 1001001001;
const int MOD = 1000000007;
// const int MOD = 998244353;
struct edge {
   int to, cost;
};
int d[100005];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int V, E, s;
   cin >> V >> E >> s;
   vector<edge> G[V];
   rep(i, 0, E) {
      int u, v, dd;
      cin >> u >> v >> dd;
      G[u].push_back({v, dd});
   }

   priority_queue<P, vector<P>, greater<P>> que;
   fill(d, d + V, INF);
   d[s] = 0;
   que.push(P(d[s], s));
   while (!que.empty()) {
      P p = que.top();
      que.pop();
      int v = p.second;
      if (d[v] < p.first) continue;
      rep(i, 0, G[v].size()) {
         edge e = G[v][i];
         if (d[e.to] > d[v] + e.cost) {
            d[e.to] = d[v] + e.cost;
            que.push(P(d[e.to], e.to));
         }
      }
   }
   rep(i, 0, V) {
      if (d[i] == INF) {
         cout << "INF" << endl;
         continue;
      }
      cout << d[i] << endl;
   }
   return 0;
}
