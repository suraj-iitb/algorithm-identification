#include <bits/stdc++.h>

#include <utility>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

template< typename key_t, typename val_t >
struct FibonacchiHeap {
  struct Node {
    key_t key;
    val_t val;
    Node *left, *right, *child, *par;
    int sz;
    bool mark;

    Node(const key_t &key, const val_t &val)
        : key(key), val(val), left(this), right(this), par(nullptr), child(nullptr), sz(0), mark(false) {}
  };

  Node *root;
  size_t sz;
  vector< Node * > rank;

  FibonacchiHeap() : root(nullptr), sz(0) {}

  size_t size() const {
    return sz;
  }

  bool empty() const {
    return sz == 0;
  }

  void update_min(Node *t) {
    if(!root || t->key < root->key) {
      root = t;
    }
  }

  void concat(Node *&r, Node *t) {
    if(!r) {
      r = t;
    } else {
      t->left->right = r->right;
      r->right->left = t->left;
      t->left = r;
      r->right = t;
    }
  }

  void delete_node(Node *t) {
    t->left->right = t->right;
    t->right->left = t->left;
    t->left = t;
    t->right = t;
  }

  Node *push(const key_t &key, const val_t &val) {
    ++sz;
    auto node = new Node(key, val);
    concat(root, node);
    update_min(node);
    return node;
  }


  Node *consolidate(Node *s, Node *t) {
    if(root == s || s->key < t->key) {
      delete_node(t);
      ++s->sz;
      t->par = s;
      concat(s->child, t);
      return s;
    } else {
      delete_node(s);
      ++t->sz;
      s->par = t;
      concat(t->child, s);
      return t;
    }
  }


  pair< key_t, val_t > pop() {
    --sz;

    Node *rem = root;


    auto ret = make_pair(rem->key, rem->val);

    {
      root = root->left == root ? nullptr : root->left;
      delete_node(rem);
    }


    if(rem->child) {
      concat(root, rem->child);
    }


    if(root) {

      {
        Node *base = root, *cur = base;
        do {
          cur->par = nullptr;
          update_min(cur);
          cur = cur->right;
        } while(cur != base);
      }


      {
        Node *base = root;
        int last = -1;
        do {
          Node *nxt = base->right;
          while(base->sz < rank.size() && rank[base->sz]) {
            Node *u = rank[base->sz];
            rank[base->sz] = nullptr;
            base = consolidate(u, base);
          }
          if(base->sz >= rank.size()) rank.resize(base->sz + 1);
          last = max(last, base->sz);
          rank[base->sz] = base;
          base = nxt;
        } while(base != root);

        for(int i = last; i >= 0; i--) rank[i] = nullptr;
      }
    }

    return ret;
  }

  inline void mark_dfs(Node *t) {
    if(!t->par) {
      t->mark = false;
    } else if(t->mark) {
      mark_dfs(t->par);
      t->par->child = t->left == t ? nullptr : t->left;
      delete_node(t);
      t->sz--;
      t->mark = false;
      t->par = nullptr;
      concat(root, t);
    } else {
      t->mark = true;
      t->sz--;
    }
  }


  void decrease_key(Node *t, const key_t &d) {
    t->key -= d;

    if(!t->par) {
      update_min(t);
      return;
    }

    if(t->par->key <= t->key) {
      return;
    }

    t->sz++;
    t->mark = true;
    mark_dfs(t);
    update_min(t);
  }
};


template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }
};

/**
 * @brief Dijkstra-Fibonacchi-Heap(単一始点最短路)
 */
template< typename T >
vector< T > dijkstra_fibonacchi_heap(Graph< T > &g, int s) {
  const auto INF = numeric_limits< T >::max();
  using Heap = FibonacchiHeap< T, int >;
  using Node = typename Heap::Node;
  using Pi = pair< T, int >;

  Heap heap;
  vector< Node * > keep(g.size(), nullptr);
  vector< T > dist;
  dist.assign(g.size(), INF);
  dist[s] = 0;
  keep[s] = heap.push(dist[s], s);

  while(!heap.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = heap.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g.g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      if(keep[e.to] == nullptr) {
        dist[e.to] = next_cost;
        keep[e.to] = heap.push(dist[e.to], e.to);
      } else {
        T d = dist[e.to] - next_cost;
        heap.decrease_key(keep[e.to], d);
        dist[e.to] -= d;
      }
    }
  }
  return dist;
}


int main() {
  int V, E, R;
  cin >> V >> E >> R;
  Graph< int > g(V);
  g.read(E, 0, true, true);
  for(auto &dist : dijkstra_fibonacchi_heap(g, R)) {
    if(dist == numeric_limits< int >::max()) cout << "INF\n";
    else cout << dist << "\n";
  }
}

