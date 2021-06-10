#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;
using ll = long long;
struct Edge {
  int to;
  ll w;
  Edge(int to, ll w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}
typedef pair<ll, ll> P_ll;
typedef pair<int, int> P;

const ll INF_ll = 1e17;
const int INF = 1e8;

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<ll>> dp(V, vector<ll>(V, INF_ll));
  for (int i = 0; i < E; i++) {
    int s, t;
    ll d;
    cin >> s >> t >> d;
    dp[s][t] = d;
  }

  for (int i = 0; i < V; i++) {
    dp[i][i] = 0;
  }

  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  for (int i = 0; i < V; i++) {
    if (dp[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (j) {
        cout << " ";
      }
      if (dp[i][j] < INF_ll / 2) {
        cout << dp[i][j];
      } else {
        cout << "INF";
      }
    }
    cout << endl;
  }

  return 0;
}
