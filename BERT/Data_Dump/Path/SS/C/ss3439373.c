// This is free and unencumbered software released into the public domain.

// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.

// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

// For more information, please refer to <http://unlicense.org>

/****************/
/* template.hpp */
/****************/

#include <algorithm>
#include <cassert>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>

using std::abs;
using std::cerr;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::numeric_limits;
using std::swap;

struct BoolName : std::numpunct<char> {
  std::string t, f;
  BoolName (std::string t, std::string f) : t(t), f(f) {}
  std::string do_truename() const {return t;}
  std::string do_falsename() const {return f;}
};

void set_bool_name(std::string t, std::string f) {
  cout.imbue(std::locale(cout.getloc(), new BoolName(t, f)));
}

struct Initializer {
  Initializer() {
    cout << std::fixed << std::setprecision(15) << std::boolalpha;
    set_bool_name("Yes", "No");
  }
} initializer;

struct Input {
  bool eof;

  Input() : eof(false) {}

  operator char() {
    char v;
    this->eof = (std::scanf("%c", &v) != 1);
    return v;
  }

  operator int() {
    int v;
    this->eof = (std::scanf("%d", &v) != 1);
    return v;
  }

  operator long() {
    long v;
    this->eof = (std::scanf("%ld", &v) != 1);
    return v;
  }

  operator long long() {
    long long v;
    this->eof = (std::scanf("%lld", &v) != 1);
    return v;
  }

  operator double() {
    double v;
    this->eof = (std::scanf("%lf", &v) != 1);
    return v;
  }

  operator long double() {
    long double v;
    this->eof = (std::scanf("%Lf", &v) != 1);
    return v;
  }

  void ignore() const {
    getchar();
  }
} in;

template<typename T> bool chmin(T& a, T b) {return a > b ? a = b, true : false;}

template<typename T> bool chmax(T& a, T b) {return a < b ? a = b, true : false;}

template<typename T, typename S> std::function<S(T)> cast() {
  return [](const T& t) { return static_cast<S>(t); };
}

/******************/
/* graph/edge.hpp */
/******************/

template<typename Edge> struct FullEdge : public Edge {
  int from;

  FullEdge() = default;

  FullEdge(const int from, const Edge& edge) : Edge(edge), from(from) {}

  FullEdge(Input &in) {
    int from(in);
    Edge edge(in);
    *this = FullEdge(from, edge);
  }
};

struct Edge {
  using CostType = int;
  const static int cost = 1;
  int to;
  Edge(int to = -1) : to(to) {}

  Edge(Input &in) : to(in) {}

  bool isNone() const {return to == -1;}

  operator int() const {return to;}
};

std::ostream& operator<<(std::ostream& s, const FullEdge<Edge>& edge) {
  s << '(' << edge.from << ',' << edge.to << ')';
  return s;
}

template<typename Cost> struct WeightedEdge : public Edge {
  using CostType = Cost;
  Cost cost;
  WeightedEdge(int to = -1, Cost cost = 0) : Edge(to), cost(cost) {}

  WeightedEdge(Input &in) : Edge(in), cost(in) {}
};

template<typename Cost> std::ostream& operator<<(std::ostream& s, const FullEdge<WeightedEdge<Cost>>& edge) {
  s << '(' << edge.from << ',' << edge.to << ',' << edge.cost << ')';
  return s;
}

template<typename Capacity> struct ResidualEdge : public Edge {
  using CapacityType = Capacity;
  Capacity cap;
  int rev;
  ResidualEdge(int to = -1, Capacity cap = 0) : Edge(to), cap(cap) {}
  ResidualEdge reverse(int from) const {return ResidualEdge(from, 0);}
};

template<typename Capacity, typename Cost> struct WeightedResidualEdge : public ResidualEdge<Capacity> {
  Cost cost;
  WeightedResidualEdge(int to = -1, Capacity cap = 0, Cost cost = 0) : ResidualEdge<Capacity>(to, cap), cost(cost) {}
  WeightedResidualEdge reverse(int from) const {return WeightedResidualEdge(from, 0, -cost);}
};

/******************/
/* arithmetic.hpp */
/******************/

template<typename T> class Addition {
public:
  template<typename V> T operator+(const V& v) const {
    return T(static_cast<const T&>(*this)) += v;
  }

  T operator++() {
    return static_cast<T&>(*this) += 1;
  }
};

template<typename T> class Subtraction {
public:
  template<typename V> T operator-(const V& v) const {
    return T(static_cast<const T&>(*this)) -= v;
  }
};

template<typename T> class Multiplication {
public:
  template<typename V> T operator*(const V& v) const {
    return T(static_cast<const T&>(*this)) *= v;
  }
};

template<typename T> class Division {
public:
  template<typename V> T operator/(const V& v) const {
    return T(static_cast<const T&>(*this)) /= v;
  }
};

template<typename T> class Modulus {
public:
  template<typename V> T operator%(const V& v) const {
    return T(static_cast<const T&>(*this)) %= v;
  }
};

template<typename T> class IndivisibleArithmetic : public Addition<T>, public Subtraction<T>, public Multiplication<T> {};

template<typename T> class Arithmetic : public IndivisibleArithmetic<T>, public Division<T> {};

/*****************/
/* container.hpp */
/*****************/

#include <vector>

template<typename T> class Container : public T {
private:
  using S = typename T::value_type;

public:
  Container() : T() {}

  Container(int n) : T(n) {}

  Container(int n, S s) : T(n, s) {}

  template<typename Itr> Container(Itr first, Itr last) : T(first, last) {}

  Container(const std::initializer_list<S>& v) : T(v) {}

  Container(int n, Input& in) {
    std::vector<S> v(n);
    for (auto& i : v) {
      i = in;
    }
    *this = Container<T>(v.begin(), v.end());
  }

  bool in(const S& a) const {
    return find(this->begin(), this->end(), a) != this->end();
  }
};

/***************/
/* ordered.hpp */
/***************/

template<typename T> class Ordered {
public:
  template<typename V> bool operator==(const V& v) const {
    return !(static_cast<T>(v) < static_cast<const T&>(*this) || static_cast<const T&>(*this) < static_cast<T>(v));
  }
  
  template<typename V> bool operator!=(const V& v) const {
    return static_cast<T>(v) < static_cast<const T&>(*this) || static_cast<const T&>(*this) < static_cast<T>(v);
  }

  template<typename V> bool operator>(const V& v) const {
    return static_cast<T>(v) < static_cast<const T&>(*this);
  }

  template<typename V> bool operator<=(const V& v) const {
    return !(static_cast<T>(v) < static_cast<const T&>(*this));
  }

  template<typename V> bool operator>=(const V& v) const {
    return !(static_cast<const T&>(*this) < static_cast<T>(v));
  }
};

/**************/
/* vector.hpp */
/**************/

template<typename T> class Vector : public Container<std::vector<T>>, public Arithmetic<Vector<T>>, public Modulus<Vector<T>>, public Ordered<Vector<T>> {
public:
  Vector() = default;

  Vector(const Vector<T>& v) = default;

  Vector(int n) : Container<std::vector<T>>(n) {}

  Vector(int n, T t) : Container<std::vector<T>>(n, t) {}

  template<typename Itr> Vector(Itr first, Itr last) : Container<std::vector<T>>(first, last) {}

  Vector(const std::initializer_list<T>& v) : Container<std::vector<T>>(v) {}

  Vector(int n, Input& in) : Container<std::vector<T>>(n, in) {}

  Vector operator+=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] += v[i];
    return *this;
  }

  Vector operator+=(const T& v) {
    for (auto& i : *this) {
      i += v;
    }
    return *this;
  }

  Vector operator-=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] -= v[i];
    return *this;
  }

  Vector operator*=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] *= v[i];
    return *this;
  }

  Vector operator/=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] /= v[i];
    return *this;
  }

  Vector operator%=(const Vector& v) {
    for (unsigned i = 0; i < this->size(); ++i) (*this)[i] %= v[i];
    return *this;
  }

  bool operator<(const Vector& v) const {
    if (this->size() != v.size()) return this->size() < v.size();
    for (unsigned i = 0; i < this->size(); ++i) {
      if ((*this)[i] != v[i]) {
        return (*this)[i] < v[i];
      }
    }
    return false;
  }

  T inner_product(const Vector<T>& v) const {
    return std::inner_product(this->begin(), this->end(), v.begin(), T(0));
  }

  void output(char sep = '\n', char end = '\n') const {
    if (!this->empty()) {
      cout << (*this)[0];
    }
    for (unsigned i = 1; i < this->size(); ++i) {
      cout << sep << (*this)[i];
    }
    cout << end;
  }

  void partial_sort(int k, bool reverse = false) {
    if (!reverse) {
      std::partial_sort(this->begin(), this->begin() + k, this->end());
    } else {
      std::partial_sort(this->begin(), this->begin() + k, this->end(), std::greater<T>());
    }
  }

  Vector<T> sort() {
    std::sort(this->begin(), this->end());
    return *this;
  }

  Vector<T> rsort() {
    std::sort(this->rbegin(), this->rend());
    return *this;
  }

  Vector<T> subvector(int a) const {
    return Vector<T>(this->begin(), this->begin() + a);
  }

  Vector<T> subvector(int a, int b) const {
    return Vector<T>(this->begin() + a, this->begin() + b);
  }

  template<typename Function> auto transform(Function func) const -> Vector<decltype(func(T()))> {
    Vector<decltype(func(T()))> res;
    std::transform(this->begin(), this->end(), std::back_inserter(res), func);
    return res;
  }

  Vector<T> partial_sum() const {
    Vector<T> res;
    std::partial_sum(this->begin(), this->end(), std::back_inserter(res));
    return res;
  }

  Vector<T> reverse() {
    std::reverse(this->begin(), this->end());
    return *this;
  }

  template<typename Function> bool all_of(Function func) {
    return std::all_of(this->begin(), this->end(), func);
  }

  Vector<T> adjacent_difference() const {
    Vector<T> res;
    std::adjacent_difference(this->begin(), this->end(), std::back_inserter(res));
    return res;
  }

  T max() const {
    return *max_element(this->begin(), this->end());
  }

  T min() const {
    return *min_element(this->begin(), this->end());
  }

  int argmax() const {
    return max_element(this->begin(), this->end()) - this->begin();
  }

  int argmin() const {
    return min_element(this->begin(), this->end()) - this->begin();
  }
};

template<typename T> Vector<T> iota(int n) {
  Vector<T> v(n);
  std::iota(v.begin(), v.end(), T(0));
  return v;
}

/*******************/
/* graph/graph.hpp */
/*******************/

template<typename Edge> class Graph {
public:
  using EdgeType = Edge;

  virtual int size() const = 0;
  template<typename... Args> void addEdge(int from, int to, Args...) {
    (void)from;
    (void)to;
  }
  template<typename... Args> void addUndirectedEdge(int from, int to, Args...) {
    (void)from;
    (void)to;
  }

  Vector<FullEdge<Edge>> getAllEdges() const {
    Vector<FullEdge<Edge>> res;
    for (int i = 0; i < size(); ++i) {
      for (const auto& edge : getEdges(i)) {
        res.emplace_back(i, edge);
      }
    }
    return res;
  }

  virtual Vector<Edge> getEdges(int from) const = 0;
  virtual Edge getEdge(int from, int to) const = 0;
  virtual bool hasEdge(int from, int to) const = 0;

  int getDegree(int v) const {
    return getEdges(v).size();
  }

  Vector<int> getIndegree() const {
    Vector<int> degree(size());
    for (const auto& edge : getAllEdges()) ++degree[edge.to];
    return degree;
  }
};

template<typename Graph> Graph readGraph(Input &in, int n, int m, bool undirected = true, bool one_origin = true) {
  Graph graph(n);
  for (int i = 0; i < m; ++i) {
    FullEdge<typename Graph::EdgeType> edge(in);
    if (one_origin) {
      --edge.from;
      --edge.to;
    }
    if (undirected) graph.addUndirectedEdge(edge);
    else graph.addEdge(edge);
  }
  return graph;
}

/****************************/
/* graph/adjacency_list.hpp */
/****************************/

template<typename Edge> class AdjacencyList : public Graph<Edge> {
protected:
  Vector<Vector<Edge>> graph;

public:
  using EdgeType = Edge;

  AdjacencyList() = default;

  AdjacencyList(int n) : graph(n) {}

  AdjacencyList(Input &in, int n, int m, bool undirected = true, bool one_origin = true) {
    *this = readGraph<AdjacencyList<Edge>>(in, n, m, undirected, one_origin);
  }

  int size() const {
    return graph.size();
  }
  
  template<typename... Args> void addEdge(int from, int to, Args... args) {
    graph[from].emplace_back(to, args...);
  }

  void addEdge(const FullEdge<Edge>& edge) {
    graph[edge.from].emplace_back(edge);
  }

  template<typename... Args> void addUndirectedEdge(int from, int to, Args... args) {
    addEdge(from, to, args...);
    addEdge(to, from, args...);
  }

  void addUndirectedEdge(FullEdge<Edge> edge) {
    graph[edge.from].emplace_back(edge);
    swap(edge.from, edge.to);
    graph[edge.from].emplace_back(edge);
  }

  Vector<Edge> getEdges(int from) const {
    return graph[from];
  }

  Edge getEdge(int from, int to) const {
    Edge res;
    for (const auto& edge : graph[from]) {
      if (edge.to == to) res = edge;
    }
    return res;
  }

  bool hasEdge(int from, int to) const {
    for (const auto& edge : graph[from]) {
      if (edge.to == to) return true;
    }
    return false;
  }

  Vector<Edge>& operator[](int v) {
    return graph[v];
  }

  const Vector<Edge>& operator[](int v) const {
    return graph[v];
  }
};

/********************/
/* graph/search.hpp */
/********************/

template<typename Graph, typename State> class Search {
protected:
  using Edge = typename Graph::EdgeType;

  const Graph graph;
  Vector<bool> visited;

  virtual void push(const State&) = 0;
  virtual State next() = 0;
  virtual bool isRunning() = 0;

  virtual void visit(const State&) {}

public:
  Search(const Graph& graph) : graph(graph), visited(graph.size(), false) {}

  void solve(Vector<int> from) {
    for (int i : from) push(State(i));
    while (isRunning()) {
      State now = next();
      int pos = now.getPos();
      if (visited[pos]) continue;
      visited[pos] = true;
      visit(now);
      for (const Edge& edge : graph.getEdges(pos)) {
        State nextState = now.next(pos, edge);
        if (visited[nextState.getPos()]) continue;
        push(nextState);
      }
    }
  }

  void solve(int from) { solve(Vector<int>({from})); }

  bool isReachable(int v) { return visited[v]; }
};

/******************/
/* graph/tree.hpp */
/******************/

template<typename Edge> class Tree {
public:
  using EdgeType = Edge;

  Vector<Edge> parent;
  Vector<Vector<int>> children;
  Vector<int> depth;

  Tree() {}

  Tree(int n) : children(n), depth(n, -1) {
    for (int i = 0; i < n; ++i) parent.emplace_back(i);
  }

  int size() const {
    return parent.size();
  }
  
  template<typename... Args> void addEdge(int from, int to, Args... args) {
    parent[from] = Edge(to, args...);
    children[to].emplace_back(from);
  }

  void addEdge(int from, const Edge& edge) {
    parent[from] = edge;
    children[edge.to].emplace_back(from);
  }

  Vector<Edge> getEdges(int from) const {
    Vector<Edge> res;
    for (int v : children[from]) {
      auto e = parent[v];
      e.to = v;
      res.emplace_back(e);
    }
    if (from != parent[from].to) res.emplace_back(parent[from]);
    return res;
  }

  int getDepth(int v) {
    if (depth[v] != -1) return depth[v];
    if (parent[v].to == v) return depth[v] = 0;
    return depth[v] = getDepth(parent[v].to) + 1;
  }

  Vector<int> getPath(int v) {
    Vector<int> res{v};
    while (v != parent[v].to) {
      v = parent[v].to;
      res.emplace_back(v);
    }
    return res;
  }
};

/**********************/
/* priority_queue.hpp */
/**********************/
#include <queue>

template<typename T> class PriorityQueue : public std::priority_queue<T> {
public:
  PriorityQueue() : std::priority_queue<T>() {}

  PriorityQueue(const std::initializer_list<T>& s) : std::priority_queue<T>(s) {}

  T top() {
    T res = std::priority_queue<T>::top();
    this->pop();
    return res;
  }

  T peek() const {
    return std::priority_queue<T>::top();
  }
};

/***************************/
/* graph/shortest_path.hpp */
/***************************/

template<typename Edge> struct DijkstraState {
  using Cost = typename Edge::CostType;

  int from;
  Edge edge;
  Cost cost;

  DijkstraState(const int pos) : from(pos), edge(pos), cost(0) {}

  DijkstraState(const int from, const Edge& edge, const Cost cost) : from(from), edge(edge), cost(cost) {}

  DijkstraState next(const int from, const Edge& edge) const {return DijkstraState(from, edge, cost + edge.cost);}

  bool operator<(const DijkstraState& state) const {return cost > state.cost;}

  int getPos() const {return edge.to;}
};

template<typename Graph, bool Restoration = false, typename State = DijkstraState<typename Graph::EdgeType>> class Dijkstra : public Search<Graph, State> {
protected:
  using Edge = typename Graph::EdgeType;
  using Cost = typename Edge::CostType;

  constexpr static Cost INF = numeric_limits<Cost>::max();

  PriorityQueue<State> que;

  void push(const State& state) {
    if (dis[state.getPos()] <= state.cost) return;
    que.push(state);
    dis[state.getPos()] = state.cost;
  }

  State next() {
    State now = que.top();
    return now;
  }

  bool isRunning() {return !que.empty();}

  void visit(const State& state) {
    if (Restoration) {
      int from = state.from, to = state.edge.to;
      if (from != to) {
        auto e = state.edge;
        e.to = from;
        shortestPathTree.addEdge(to, e);
      }
    }
  }

public:
  Vector<Cost> dis;
  Tree<Edge> shortestPathTree;

  Dijkstra(const Graph& graph) : Search<Graph, State>(graph), dis(graph.size(), INF) {
    if (Restoration) shortestPathTree = Tree<Edge>(graph.size());
  }
};

template<typename Graph> Dijkstra<Graph> shortestPath(Graph& graph, int from) {
  Dijkstra<Graph> dijkstra(graph);
  dijkstra.solve(from);
  return dijkstra;
}

template<typename Graph> typename Graph::EdgeType::CostType shortestPath(Graph& graph, int from, int to) {
  return shortestPath(graph, from).dis[to];
}

template<typename Graph> Dijkstra<Graph, true> shortestPathTree(Graph& graph, int from) {
  Dijkstra<Graph, true> dijkstra(graph);
  dijkstra.solve(from);
  return dijkstra;
}

/************/
/* main.cpp */
/************/

int main() {
  int v(in), e(in), r(in);
  AdjacencyList<WeightedEdge<int>> graph(in, v, e, false, false);
  auto info = shortestPath(graph, r);
  for (int i = 0; i < v; ++i) {
    if (info.isReachable(i)) {
      cout << info.dis[i] << endl;
    } else {
      cout << "INF" << endl;
    }
  }
}


