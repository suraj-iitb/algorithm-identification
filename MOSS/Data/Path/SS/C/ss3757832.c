#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

struct WeightedEdge {
  int from, to;
  int64 weight;
};

vector<vector<WeightedEdge>> ReadDirectedWeightedGraph(
    int n, int m, bool is_one_indexed=false) {
  vector<vector<WeightedEdge>> graph(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    int64 weight;
    cin >> v1 >> v2 >> weight;
    if (is_one_indexed) {
      v1--;
      v2--;
    }
    graph[v1].push_back(WeightedEdge({v1, v2, weight}));
  }
  return graph;
}

tuple<vector<int64>, vector<int>>
ShortestPathDijkstra(vector<vector<WeightedEdge>>& graph, int s) {
  int n = graph.size();
  vector<int64> distances(n, INT64_MAX);
  vector<int> parents(n, -1);
  struct State {
    int v, parent;
    int64 weight;
  };
  auto compare_state = [](State s1, State s2) {
    return s1.weight > s2.weight;
  };
  priority_queue<State, vector<State>, decltype(compare_state)>
  pq(compare_state);

  pq.push(State({s, -1, 0}));
  vector<int> visited(n);
  while(!pq.empty()) {
    State s = pq.top();
    pq.pop();
    if (visited[s.v]) continue;
    visited[s.v] = true;
    distances[s.v] = s.weight;
    parents[s.v] = s.parent;
    for (const auto& e : graph[s.v]) {
      if (visited[e.to]) continue;
      State next = State({e.to, s.v, s.weight + e.weight});
      pq.push(next);
    }
  }
  return make_tuple(distances, parents);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int v, e, r;
  cin >> v >> e >> r;
  auto graph = ReadDirectedWeightedGraph(v, e);
  vector<int64> distances;
  tie(distances, ignore) = ShortestPathDijkstra(graph, r);
  for (int64 distance : distances) {
    if (distance == INT64_MAX) {
      cout << "INF" << endl;
    } else {
      cout << distance << endl;
    }
  }
}

