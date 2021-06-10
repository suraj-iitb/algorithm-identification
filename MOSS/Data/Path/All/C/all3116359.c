/* 1C Floyd Warshall w/ negative-cycle detection
 * Constraints
 * 1 ≤ |V| ≤ 100
 * 0 ≤ |E| ≤ 9900
 * -2 × 10^7 ≤ di ≤ 2 × 10^7
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
using namespace std;

#define INF numeric_limits<int>::max()

int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> adj[n + 1];
  for (int src, dst, cost; cin >> src >> dst >> cost;) {
    adj[src + 1][dst + 1] = cost;
  }

  // dp[u][v][k] = shortest u-v path with intermediate nodes
  //               of ID at most k
  int dp[101][101][101];
  for (int i = 0; i < 101; ++i)
    for (int j = 0; j < 101; ++j)
      for (int k = 0; k < 101; ++k)
        dp[i][j][k] = INF;

  for (int u = 1; u <= n; ++u) {
    dp[0][u][u] = 0;
    for (auto vcost : adj[u]) {
      dp[0][u][vcost.first] = vcost.second;
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int u = 1; u <= n; ++u) {
      for (int v = 1; v <= n; ++v) {
        dp[k][u][v] = dp[k - 1][u][v];
        if (dp[k - 1][u][k] != INF and dp[k - 1][k][v] != INF)
          dp[k][u][v] = min(dp[k - 1][u][v], dp[k - 1][u][k] + dp[k - 1][k][v]);
      }
    }
  }

  for (int u = 1; u <= n; ++u) {
    for (int t = 1; t <= n; ++t) {
      for (auto v_costtv : adj[t]) {
        if (dp[n][u][t] == INF)
          continue;
        if (dp[n][u][t] + v_costtv.second < dp[n][u][v_costtv.first]) {
          cout << "NEGATIVE CYCLE\n";
          exit(0);
        }
      }
    }
  }

  for (int u = 1; u <= n; ++u) {
    for (int v = 1; v <= n; ++v) {
      if (v > 1)
        cout << " ";
      if (dp[n][u][v] == INF) {
        cout << "INF";
      } else {
        cout << dp[n][u][v];
      }
    }
    cout << endl;
  }
}
