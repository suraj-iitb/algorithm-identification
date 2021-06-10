#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = (int)1e9;

struct Edge {
  int src, dst, cost;
  Edge(int s, int d, int c) : src(s), dst(d), cost(c) { }
};

struct State {
  int pos, cost;
  State(int p, int c) : pos(p), cost(c) { }
  bool operator <(const State &rhs) const {
    return cost > rhs.cost;
  }
};

typedef vector<vector<Edge>> Graph;

int main() {
  ios::sync_with_stdio(false);
  int V, E, r;
  cin >> V >> E >> r;
  Graph G(V);
  for(int i = 0; i < E; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s].push_back(Edge(s, t, d));
  }
  vector<int> d(V, INF);
  priority_queue<State> Q;
  Q.push(State(r, 0));
  d[r] = 0;
  while(!Q.empty()) {
    State s = Q.top(); Q.pop();
    if(s.cost > d[s.pos]) continue;
    for(const Edge &e : G[s.pos]) {
      if(d[e.dst] > d[e.src] + e.cost) {
        d[e.dst] = d[e.src] + e.cost;
        Q.push(State(e.dst, d[e.dst]));
      }
    }
  }
  for(int i = 0;  i < V; i++) {
    if(d[i] == INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
}
