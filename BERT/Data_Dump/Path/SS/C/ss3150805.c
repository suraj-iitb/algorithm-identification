#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

typedef long long int_t;

const int size = 500000;
int_t v, e, r;
int_t s[size];
int_t t[size];
int_t d[size];

bool input() {
  if (cin >> v >> e >> r) {
    rep(i, e) cin >> s[i] >> t[i] >> d[i];
    return true;
  }
  return false;
}

typedef tuple<int, int> node_t;
typedef queue<node_t> queue_t;

const int_t inf = numeric_limits<int_t>::max();
queue_t q;
int_t mincost[size];
vector<int> g[size];

void init() {
  fill(mincost, mincost+size, inf);
  fill(g, g+size, vector<int>());
  q = queue_t();
}

void solve() {
  // generate graph
  rep (i, e) {
    g[s[i]].push_back(i);
  }

  mincost[r] = 0;
  q.emplace(0, r);
  while (!q.empty()) {
    auto node = q.front();
    q.pop();

    auto cost = get<0>(node);
    auto v = get<1>(node);

    for (auto ni : g[v]) {
      int_t next_cost = cost + d[ni];
      int_t next_v = t[ni];

      if (next_cost >= mincost[next_v]) continue;
      mincost[next_v] = next_cost;
      q.emplace(next_cost, next_v);
    }
  }

  rep (i, v) {
    if (mincost[i] == inf) {
      cout << "INF" << endl;
    } else {
      cout << mincost[i] << endl;
    }
  }
}

int main() {
  while (input()) {
    init();
    solve();
  }
  return 0;
}

