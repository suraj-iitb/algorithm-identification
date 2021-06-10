#include <bits/stdc++.h>
using namespace std;

struct edge { int to, cost; };

typedef pair<long long, int> plli;
int main() {
  int n, m, r;
  cin>>n>>m>>r;
  vector<edge> graph[n];
  for (int i=0; i<m; i++) {
    int s, t, d;
    cin>>s>>t>>d;
    graph[s].push_back({t, d});
  }
  long long inf = 1e5 * 1e4 + 1;
  long long d[n];
  bool used[n];
  for (int i=0; i<n; i++) {
    d[i] = inf;
    used[i] = false;
  }
  d[r] = 0;
  priority_queue<plli, vector<plli>, greater<plli> > que;
  que.push(make_pair(0, r));


  while (!que.empty()) {
    auto t = que.top(); que.pop();
    if (used[t.second]) {
      continue;
    }
    for (auto e: graph[t.second]) {
      if (d[t.second] != inf && d[e.to] > d[t.second] + e.cost) {
        long long cost = d[t.second] + e.cost;
        d[e.to] = cost;
        que.push(make_pair(cost, e.to));
      }
    }
  }
  for (auto di: d) {
    if (di == inf) {
      cout<<"INF"<<endl;
    } else {
      cout<<di<<endl;
    }
  }
}
