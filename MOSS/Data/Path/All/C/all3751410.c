// Last Change: 07/15/2019 20:06:39.
//////////////////////////////////////////////////////////////////////////////
//ワーシャルフロイド法：全点対最短経路問題, O(V^3)
//下記は無向グラフの場合。
//
// Reference:
//   https://triple-four.hatenablog.com/entry/2019/04/02/143939
//   http://dai1741.github.io/maximum-algo-2012/docs/shortest-path/
// 上がわかりやすい。
//////////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

//'100'は適宜変更。入れないとあふれる。
const ll INF = numeric_limits<ll>::max() / 100;
// cost[i][j]:iからjへ行くまでの最短コスト
vector<vector<ll>> cost;

// i->jへの既知のルートと、kを経由していくのとでどちらが近いか。
bool WarshallFloyd(int V) {
  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (cost[i][k] != INF and cost[k][j] != INF)
          cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }

  //負の経路判定
  for (int i = 0; i < V; ++i) {
    if (cost[i][i] < 0) {
      return true;
    }
  }

  return false;
}

int main() {
  //頂点数, 辺の数
  int V, E;
  cin >> V >> E;

  cost.assign(V, vector<ll>(V, INF));

  for (int i = 0; i < V; ++i) {
    cost[i][i] = 0;
  }

  // 辺
  for (int i = 0; i < E; ++i) {
    int u, v;
    ll c;
    cin >> u >> v >> c;

    cost[u][v] = min(cost[u][v], c);
  }

  bool flag = WarshallFloyd(V);

  if (flag) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (cost[i][j] == INF) {
          cout << "INF";
        } else {
          cout << cost[i][j];
        }
        if (j < V - 1) {
          cout << " ";
        }
      }
      cout << endl;
    }
  }
}


