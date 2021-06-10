#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

vector<pair<ll, int>> g[100000];
vector<ll> dijkstra(int num, int start) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
  vector<ll> dp(num, 1e18);
  dp[start] = 0;
  que.push(make_pair(0, start));
  while (!que.empty()) {
    pair<ll, int> v = que.top();
    que.pop();
    if (dp[v.second] < v.first) continue;
    for (auto u : g[v.second]) {
      if (dp[v.second] + u.first < dp[u.second]) {
        dp[u.second] = dp[v.second] + u.first;
        que.push(make_pair(dp[u.second], u.second));
      }
    }
  }
  return dp;
}

int main() {
  int v, e, r;
  cin >> v >> e >> r;
  for (int i = 0; i < e; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    g[s].push_back(make_pair(d, t));
  }
  vector<ll> ans = dijkstra(v, r);
  for (int i = 0; i < v; ++i) {
    if (ans[i] == 1e18) {
      cout << "INF" << endl;
    } else {
      cout << ans[i] << endl;
    }
  }
  return 0;
}

