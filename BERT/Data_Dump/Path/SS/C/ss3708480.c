#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
// typedef pair<ll, ll> P;
typedef pair<int, int> P;
typedef vector<P> VP;
typedef greater<P> GP;

#define MOD 1000000007
#define INF 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

VP G[100000];
int dist[100000];

void dijkstra(int start) {
  priority_queue<P, VP, GP> que;  // firstの小さい順に取り出す
  REP(i, 100000) dist[i] = INF;
  dist[start] = 0;
  que.push(P(0, start));
  while (que.size()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    REP(i, G[v].size()) {
      int to = G[v][i].first;
      int cost = G[v][i].second;
      if (dist[v] + cost < dist[to]) {
        dist[to] = dist[v] + cost;
        que.push(P(dist[to], to));
      }
    }
  }
}

int main() {
  int V, E, r;
  cin >> V >> E >> r;
  REP(i, E) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s].push_back(P(t, d));  // s -> t
  }
  dijkstra(r);
  REP(i, V) {
    if (dist[i] == INF)
      cout << "INF" << endl;
    else
      cout << dist[i] << endl;
  }
  return 0;
}
