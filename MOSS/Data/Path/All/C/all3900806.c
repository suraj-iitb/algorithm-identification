#include <iostream>
#include <vector>

using namespace std;

class Edge {
  public:
    int from;
    int to;
    int cost;
    Edge() {
    }
    Edge(int _from, int _to, int _cost) {
      from = _from;
      to = _to;
      cost = _cost;
    }
};

int main()
{
  int nnode, nedge;
  cin >> nnode >> nedge;
  vector<Edge> edge(nedge);
  for (int i = 0; i < nedge; i++) {
    cin >> edge.at(i).from >> edge.at(i).to >> edge.at(i).cost;
  }
  vector<vector<long long>> cost(nnode, vector<long long>(nnode, 1e18));
  for (int i = 0; i < nnode; i++) {
    cost.at(i).at(i) = 0;
  }
  for (const auto& e : edge) {
    cost.at(e.from).at(e.to) = e.cost;
  }

  // Floyd-Warshall
  for (int k = 0; k < nnode; k++) {
    for (int i = 0; i < nnode; i++) {
      for (int j = 0; j < nnode; j++) {
        if (cost.at(i).at(k) + cost.at(k).at(j) < cost.at(i).at(j)) {
          cost.at(i).at(j) = cost.at(i).at(k) + cost.at(k).at(j);
        }
      }
    }
  }

  // negative cycle detection
  // If distance of any vertex from itself becomes negative,
  // there is a negative weight cycle.
  for (int i = 0; i < nnode; i++) {
    if (cost.at(i).at(i) < 0) {
      cout << "NEGATIVE CYCLE\n";
      return 0;
    }
  }

  for (int x = 0; x < nnode; x++) {
    if (1e10 < cost.at(x).at(0)) {
      cout << "INF";
    } else {
      cout << cost.at(x).at(0);
    }
    for (int y = 1; y < nnode; y++) {
      cout << ' ';
      if (1e10 < cost.at(x).at(y)) {
        cout << "INF";
      } else {
        cout << cost.at(x).at(y);
      }
    }
    cout << '\n';
  }

  return 0;
}

