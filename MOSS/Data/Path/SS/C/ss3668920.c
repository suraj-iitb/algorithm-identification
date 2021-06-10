#include <queue>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Edge {
  public:
    int from;
    int to;
    int cost;
    Edge(int _from, int _to, int _cost) { from = _from; to = _to; cost = _cost; }
};

class Node {
  public:
    bool is_visited;
    int cost;
    vector<Edge> edges;
    Node() { cost = INT_MAX; is_visited = false; }
};

class SimpleNode {
  public:
    int cost;
    int index;
    SimpleNode(int _cost, int _index) { cost = _cost; index = _index; }
};

bool has_larger_cost(const SimpleNode& a, const SimpleNode& b) {
  return a.cost > b.cost;
}

int main()
{
  int nnodes, nedges, start;
  cin >> nnodes >> nedges >> start;
  priority_queue<SimpleNode, vector<SimpleNode>, decltype(&has_larger_cost)> pq(&has_larger_cost);
  vector<Node> nodes(nnodes);
  for (int i = 0; i < nedges; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    nodes.at(from).edges.emplace_back(from, to, cost);
  }
  nodes.at(start).cost = 0;
  pq.push(SimpleNode(0, start));
  while (!pq.empty()) {
    SimpleNode node(pq.top().cost, pq.top().index);
    pq.pop();
    if (nodes.at(node.index).cost < node.cost) {
      continue;
    }
    for (const auto& edge : nodes.at(node.index).edges) {
      if (node.cost + edge.cost < nodes.at(edge.to).cost) {
        nodes.at(edge.to).cost = node.cost + edge.cost;
        pq.push(SimpleNode(node.cost + edge.cost, edge.to));
      }
    }
  }
  for (const auto& node : nodes) {
    if (node.cost == INT_MAX) {
      cout << "INF\n";
    } else {
      cout << node.cost << '\n';
    }
  }
  return 0;
}

