#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 1e+5, INF = 1e+9;
struct edge {int to, cost;};
typedef pair<int, int> P;
int V, E, r, D[MAX_V]; vector<edge> G[MAX_V];

void dijkstra(int s) {
  fill(D, D+V, INF); D[r] = 0;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push(P(0, s));
  while(!q.empty()) {
    P p = q.top(); q.pop();
    int now = p.second;
    if(D[now] < p.first) continue;
    for(int i = 0; i < G[now].size(); ++i) {
      edge e = G[now][i];
      if(D[e.to] > D[now] + e.cost) {
        D[e.to] = D[now] + e.cost;
        q.push(P(D[e.to], e.to));
      }
    }
  }
}
int main() {
  scanf("%d %d %d", &V, &E, &r);
  for(int i = 0, s, t, d; i < E; ++i) {
    scanf("%d %d %d", &s, &t, &d);
    edge e = {t, d};
    G[s].push_back(e);
  }
  dijkstra(r);
  for(int i = 0; i < V; ++i) {
    if(D[i] == INF) {
      printf("%s\n", "INF");
    } else {
      printf("%d\n", D[i]);
    }
  }
}
