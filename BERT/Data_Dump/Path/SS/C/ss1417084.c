#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int from, to;
  Edge(int from, int to) : from(from), to(to) {};
};

template<typename Cost> struct WeightedEdge : public Edge {
  typedef Cost CostType;
  Cost cost;
  WeightedEdge(int from, int to, Cost cost) : Edge(from, to), cost(cost) {}
};

template<typename Capacity> struct ResidualEdge : public Edge {
  typedef Capacity CapacityType;
  Capacity cap;
  int rev;
  ResidualEdge(int from, int to, Capacity cap) : Edge(from, to), cap(cap) {}
  ResidualEdge reverse() const {return ResidualEdge(to, from, 0);}
};

template<typename Capacity, typename Cost> struct WeightedResidualEdge : public ResidualEdge<Capacity> {
  Cost cost;
  WeightedResidualEdge(int from, int to, Capacity cap, Cost cost) : ResidualEdge<Capacity>(from, to, cap), cost(cost) {}
  WeightedResidualEdge reverse() const {return WeightedResidualEdge(this->to, this->from, 0, -cost);}
};

template<typename Edge> class Graph {
public:
  virtual int size() const = 0;
  virtual void addEdge(const Edge& edge) = 0;
  virtual void addUndirectedEdge(Edge edge) = 0;
  virtual vector<Edge> getEdges(int from, int to) const = 0;
  virtual int getDegree(int v) const = 0;
};

template<typename Edge> class AdjacencyList : public Graph<Edge> {
protected:
  vector<vector<Edge>> graph;

public:
  AdjacencyList(int n) : graph(n) {}

  int size() const {
    return graph.size();
  }
  
  void addEdge(const Edge& edge) {
    graph[edge.from].emplace_back(edge);
  }

  void addUndirectedEdge(Edge edge) {
    addEdge(edge);
    swap(edge.from, edge.to);
    addEdge(edge);
  }

  vector<Edge> getEdges(int from, int to) const {
    vector<Edge> res;
    for (const auto& edge : graph[from]) {
      if (edge.to == to) res.emplace_back(edge);
    }
    return res;
  }

  int getDegree(int v) const {
    return graph[v].size();
  }

  vector<Edge>& operator[](int v) {
    return graph[v];
  }
};

template<typename Edge, typename State> class Search : public AdjacencyList<Edge> {
protected:
  vector<bool> visited;

  virtual void push(const State& state) = 0;
  virtual State next() = 0;
  virtual bool canPruning(const State& state) = 0;
  virtual bool isRunning() = 0;

  void visit(const State& state) {(void)state;}
  
public:
  Search(int n) : AdjacencyList<Edge>(n), visited(n, false) {}

  void solve(int from) {
    push(State(from));
    while (isRunning()) {
      State now = next();
      if (visited[now.pos]) continue;
      visited[now.pos] = true;
      visit(now);
      for (const Edge& edge : (*this)[now.pos]) {
        State nextState = now.next(edge);
        if (canPruning(nextState)) continue;
        push(nextState);
      }
    }
  }
};

template<typename Edge> struct DijkstraState {
  typedef typename Edge::CostType Cost;
  
  int pos;
  Cost cost;
  
  DijkstraState(int pos, Cost cost = 0) : pos(pos), cost(cost) {}
  
  DijkstraState next(const Edge& edge) {
    return DijkstraState(edge.to, cost + edge.cost);
  }
  
  bool operator<(const DijkstraState& state) const {return cost > state.cost;}
};

template<typename Edge> class Dijkstra : public Search<Edge, DijkstraState<Edge>> {
private:
  typedef typename Edge::CostType Cost;
  typedef DijkstraState<Edge> State;

  priority_queue<State> que;

protected:
  void push(const State& state) {
    this->que.push(state);
    dist[state.pos] = state.cost;
  }
  
  State next() {
    State now = que.top();
    que.pop();
    return now;
  }
  
  bool canPruning(const State& state) {
    return dist[state.pos] <= state.cost;
  }
  
  bool isRunning() {
    return !que.empty();
  }

public:
  const Cost INF;

  vector<Cost> dist;

  Dijkstra(int n) : Search<Edge, State>(n), INF(numeric_limits<Cost>::max()), dist(n, INF) {}
};

int main() {
  int v, e, r;
  cin >> v >> e >> r;
  Dijkstra<WeightedEdge<int>> graph(v);
  for (int i = 0; i < e; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    graph.addEdge(WeightedEdge<int>(s, t, d));
  }
  graph.solve(r);
  for (int c : graph.dist) {
    if (c != graph.INF) cout << c << endl;
    else cout << "INF" << endl;
  }
}
