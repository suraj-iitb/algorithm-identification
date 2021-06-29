//verified against interviewbit knight problem and AOJ GRL_1_A
//following is a implementation on directed graph

#include <bits/stdc++.h>

using namespace std;

const int pinf = (1U << 31) - 1;

struct Edge {
  int dst;
  int wgt;
  Edge(int idst, int iwgt) : dst(idst), wgt(iwgt) {};
};

class Graph {
  private:
    int V;
    int E;
    vector <vector <Edge>> adj;
  public:
    Graph(int n, int m);
    void addEdge(int src, int dst, int wgt);
    void dijkstra(int src);
};

Graph::Graph(int n, int m) {
  this->V = n;
  this->E = m;
  adj.resize(n);
}

void Graph::addEdge(int src, int dst, int wgt) {
  adj[src].push_back(Edge(dst, wgt));
}

void Graph::dijkstra(int src) {
  set <pair <int, int>> st;
  vector <int> dist(V, pinf);
  dist[src] = 0;
  st.emplace(dist[src], src);

  while (!st.empty()) {
    pair <int, int> pr = *(st.begin());
    st.erase(st.begin());
    int u = pr.second;

    for (Edge &edge : adj[u]) {
      int v = edge.dst;
      int w = edge.wgt;

      if (dist[u] + w < dist[v]) {
        if (dist[v] != pinf) {
          st.erase(st.find(make_pair(dist[v], v)));
        }
        dist[v] = w + dist[u];
        st.emplace(dist[v], v);
      }
    }
  }

  
  //..printing distances from source
  for (int i = 0; i < V; i++) {
    if (dist[i] == pinf) {
      cout << "INF" << endl;
    } else {
      cout << dist[i] << endl;
    }
  }
}

int main() {
  int n, m, src;
  cin >> n >> m >> src;
  Graph g(n, m);
  int s, t, w;
  for (int i = 0; i < m; i++) {
    cin >> s >> t >> w;
    g.addEdge(s, t, w);
  }
  g.dijkstra(src);
  return 0;
}
