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
const ll INF = ll(1e18);
const int MOD = 1000000007;
// const int MOD = 998244353;

const int MAX_V = 105;
ll dp[MAX_V][MAX_V];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int V, E;
   cin >> V >> E;
   rep(i, 0, V) rep(j, 0, V) {
      if (i == j)
         dp[i][j] = 0;
      else
         dp[i][j] = INF;
   }
   rep(i, 0, E) {
      int s, t, d;
      cin >> s >> t >> d;
      dp[s][t] = d;
   }
   rep(k, 0, V) rep(u, 0, V) rep(v, 0, V) {
      if (dp[u][k] == INF || dp[k][v] == INF) continue;
      dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
   }
   rep(i, 0, V) if (dp[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
   }

   rep(i, 0, V) rep(j, 0, V) {
      if (dp[i][j] >= INF)
         cout << "INF";
      else
         cout << dp[i][j];
      if (j == V - 1)
         cout << endl;
      else
         cout << " ";
   }
   return 0;
}
