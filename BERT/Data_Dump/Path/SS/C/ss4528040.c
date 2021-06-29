/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

struct Vertex {
  int64_t distance{INT64_MAX};
  vector<pair<int64_t, int64_t>> edges;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t V, E, r;
  cin >> V >> E >> r;
  vector<Vertex> vertices(V);
  for (int64_t i = 0; i < E; ++i) {
    int64_t start, to, weight;
    cin >> start >> to >> weight;
    vertices[start].edges.push_back(pair<int64_t, int64_t>(weight, to));
  }

  priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> q;
  q.push(pair<int64_t, int64_t>(0, r));
  vertices[r].distance = 0;
  while (q.size() > 0) {
    pair<int64_t, int64_t> t = q.top();
    q.pop();
    const int64_t c_distance = t.first;
    const int64_t c_index = t.second;
    for (const pair<int64_t, int64_t> edge : vertices[c_index].edges) {
      const int64_t weight = edge.first;
      const int64_t to = edge.second;
      const int64_t temp_distance = c_distance + weight;
      if (temp_distance < vertices[to].distance) {
        vertices[to].distance = temp_distance;
        q.push(pair<int64_t, int64_t>(temp_distance, to));
      }
    }
  }
  for (int64_t i = 0; i < V; ++i) {
    if (vertices[i].distance == INT64_MAX) {
      cout << "INF" << endl;
    } else {
      cout << vertices[i].distance << endl;
    }
  }

  return 0;
}

