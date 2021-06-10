#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cassert>
#include <climits>
#include <algorithm>
#include <memory>
#include <utility>
#include <list>
#include <vector>
#include <functional>
#include <complex>
#include <tuple>

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
// constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

namespace bit {
template <typename Tp>
int log2p1(Tp n) {
  if (n == 0) return 0;
  return (CHAR_BIT * sizeof(long long)) - __builtin_clzll(n);
}
}  // bit::

template <typename Key, typename Tp, typename Compare = std::less<>>
class fibonacci_heap {
public:
  using size_type = size_t;
  using key_type = Key;
  using mapped_type = Tp;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = value_type const&;
  using key_compare = Compare;
  class node_handle;

private:
  class node;
  using pointer = std::shared_ptr<node>;

  class node {
    friend fibonacci_heap;

  public:
    using size_type = size_t;
    using key_type = Key;
    using mapped_type = Tp;
    using value_type = std::pair<key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = value_type const&;
    using key_compare = Compare;

  private:
    pointer M_parent{nullptr};
    pointer M_child{nullptr};
    pointer M_left{nullptr};
    pointer M_right{nullptr};
    bool M_damaged = false;
    size_type M_order = 0;
    value_type M_value;  // {priority, element}

  public:
    node() = default;
    node(node const&) = default;
    node(node&&) = default;
    node& operator =(node const&) = default;
    node& operator =(node&&) = default;

    node(key_type const& key, mapped_type const& mapped):
      M_value(key, mapped) {}
  };

  static void S_add_child(pointer parent, pointer child) {
    ++parent->M_order;
    child->M_parent = parent;
    if (!parent->M_child) {
      parent->M_child = child;
      // child->M_left = child->M_right = child;
      child->M_left = child->M_right = nullptr;
    } else if (!parent->M_child->M_left) {
      parent->M_child->M_left = parent->M_child->M_right = child;
      child->M_left = child->M_right = parent->M_child;
    } else {
      child->M_left = parent->M_child->M_left;
      child->M_right = parent->M_child;
      parent->M_child->M_left->M_right = child;
      parent->M_child->M_left = child;
    }
  }

  static bool S_detach_child(pointer parent, pointer child) {
    // returns true if the resulting heap is valid, false otherwise
    bool res = !parent->M_damaged;
    if (parent->M_parent) parent->M_damaged = true;
    --parent->M_order;

    if (parent->M_child == child) {
      // if (child->M_left == child->M_right) {
      //   parent->M_child = nullptr;
      // } else {
        parent->M_child = child->M_right;
      // }
    }
    child->M_parent = nullptr;
    child->M_damaged = false;

    if (child->M_left) {
      if (child->M_left == child->M_right) {
        child->M_left->M_right = child->M_right->M_left = nullptr;
      } else {
        child->M_left->M_right = child->M_right;
        child->M_right->M_left = child->M_left;
      }
      child->M_left = child->M_right = nullptr;
    }
    // // if (child->M_left) {
    //   child->M_left->M_right = child->M_right;
    //   child->M_right->M_left = child->M_left;
    //   // child->M_left = child->M_right = nullptr;
    //   child->M_left = child->M_right = child;
    // // }
    return res;
  }

public:
  class node_handle {
    friend fibonacci_heap;

  public:
    using size_type = size_t;
    using key_type = Key;
    using mapped_type = Tp;
    using value_type = std::pair<key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = value_type const&;
    using key_compare = Compare;
    using pointer = std::weak_ptr<node>;

  private:
    pointer M_node;

  public:
    node_handle() = default;
    node_handle(pointer node): M_node(node) {}
    const_reference operator *() const { return (*M_node)->M_value; }
    bool expired() const { return M_node.expired(); }
  };

private:
  size_type M_size = 0;
  std::list<pointer> M_roots;  // list for pop()
  pointer M_top;  // pointer (not iterator) for prioritize()
  key_compare M_comp = key_compare();

  static void S_deep_copy_dfs(pointer& dst, pointer& src) {
    // ???
  }

  void M_deep_copy(fibonacci_heap const& other) {
    M_size = other.M_size;
    M_roots.clear();
    for (auto const& root: other.M_roots) {
      pointer r;
      S_deep_copy_dfs(root);
      M_roots.push_back(r);
      if (root == other.M_top) M_top = r;
    }
  }

  static size_type S_num_nodes(pointer cur) {
    pointer child = cur->M_child;
    if (!child) return 1;
    size_type res = 1;
    do {
      res += S_num_nodes(child);
      child = child->M_right;
    } while (child && child != cur->M_child);
    return res;
  }

  void M_inspect_roots(const char* s) const {
    return;
    fprintf(stderr, "%s", s);
    size_type n = 0;
    for (auto r: M_roots) {
      size_type tmp = S_num_nodes(r);
      fprintf(stderr, " %zu(%zu)", r->M_order, tmp);
      n += tmp;
    }
    fprintf(stderr, "\n");
    if (n != M_size) fprintf(stderr, "\x1b[1;91m======\x1b[m\n");
  }

  void M_coleasce() {
    if (M_size == 0) {
      M_roots.clear();
      M_top = nullptr;
      return;
    }

    size_type size = 0;
    for (auto r: M_roots) size += 1_zu << r->M_order;
    std::vector<pointer> roots(bit::log2p1(size));

    M_inspect_roots("<");
    for (auto r: M_roots) {
      assert(!r->M_parent);
      size_type i = r->M_order;
      while (roots[i]) {
        if (M_comp(r->M_value.first, roots[i]->M_value.first))
          std::swap(r, roots[i]);

        S_add_child(r, roots[i]);
        roots[i] = nullptr;
        ++i;
      }
      roots[i] = r;
    }
    // fprintf(stderr, "size: %zu, M_size: %zu, M_roots.size(): %zu\n", size, M_size, M_roots.size());
    M_roots.clear();

    for (auto r: roots) if (r) M_roots.push_back(r);
    M_top = *M_roots.begin();
    for (auto p: M_roots)
      if (M_comp(M_top->M_value.first, p->M_value.first)) M_top = p;

    M_inspect_roots(">");
  }

public:
  fibonacci_heap() = default;
  fibonacci_heap(fibonacci_heap const& other) { M_deep_copy(other); }
  fibonacci_heap(fibonacci_heap&&) = default;
  fibonacci_heap& operator =(fibonacci_heap const& other) {
    M_deep_copy(other);
  }
  fibonacci_heap& operator =(fibonacci_heap&&) = default;

  template <typename InputIt>
  fibonacci_heap(InputIt first, InputIt last) { assign(first, last); }
  fibonacci_heap(std::initializer_list<value_type> il) { assign(il); }

  size_type size() const noexcept { return M_size; }
  bool empty() const noexcept { return M_size == 0; }

  const_reference const& top() const { return M_top->M_value; }
  void pop() {
    pointer root = M_top;
    for (auto it = M_roots.begin(); it != M_roots.end(); ++it) {
      if (*it == M_top) {
        M_roots.erase(it);
        break;
      }
    }
    if (root->M_child) {
      pointer cur = root->M_child;
      do {
        pointer tmp = cur->M_right;
        cur->M_left = cur->M_right = cur->M_parent = nullptr;
        // cur->M_left = cur->M_right = cur;
        // cur->M_parent = nullptr;
        cur->M_damaged = false;
        M_roots.push_back(cur);
        cur = tmp;
      } while (cur && cur != root->M_child);
      root->M_child = nullptr;
    }
    --M_size;
    M_coleasce();
  }

  node_handle push(key_type const& key, mapped_type const& mapped) {
    pointer newnode = std::make_shared<node>(key, mapped);
    // newnode->M_left = newnode->M_right = newnode;
    newnode->M_left = newnode->M_right = nullptr;
    M_roots.push_back(newnode);
    if (M_size == 0 || M_comp(M_top->M_value.first, key)) M_top = newnode;
    ++M_size;
    M_inspect_roots("+");
    return node_handle(newnode);
  }

  void meld(fibonacci_heap& other) {
    M_size += other.M_size;
    other.M_size = 0;

    M_roots.splice(M_roots.end(), other.M_roots);
    if (M_comp(M_top->M_value.first, other.M_top->M_value.first))
      M_top = other.M_top;
  }

  void prioritize(node_handle& nh, mapped_type const& key) {
    pointer cur(nh.M_node);
    assert(M_comp(cur->M_value.first, key));
    cur->M_value.first = key;
    if (M_comp(M_top->M_value.first, key)) M_top = cur;
    if (!cur->M_parent || !M_comp(cur->M_parent->M_value.first, key)) {
      // assert(M_top != cur);  // ?
      return;
    }

    bool more_cut = true;
    // fprintf(stderr, "prioritize, M_roots.size(): %zu", M_roots.size());
    while (more_cut) {
      pointer parent = cur->M_parent;
      more_cut = !S_detach_child(parent, cur);
      M_roots.push_back(cur);
      cur = parent;
    }
    // fprintf(stderr, " -> %zu\n", M_roots.size());
    M_inspect_roots("x");
  }
};

template <typename WeightType>
class weighted_edge {
public:
  using size_type = size_t;
  using weight_type = WeightType;

protected:
  size_type M_src, M_dst;
  weight_type M_weight;

public:
  weighted_edge() = default;
  weighted_edge(weighted_edge const&) = default;
  weighted_edge(weighted_edge&&) = default;

  weighted_edge(size_type s, size_type d, weight_type w):
    M_src(s), M_dst(d), M_weight(w)
  {}

  weighted_edge& operator =(weighted_edge const&) = default;
  weighted_edge& operator =(weighted_edge&&) = default;

  bool operator <(weighted_edge const& other) const {
    if (M_weight < other.M_weight) return true;
    if (other.M_weight < M_weight) return false;
    if (M_src != other.M_src) return M_src < other.M_src;
    return M_dst < other.M_dst;
  }

  size_type source() const { return M_src; }
  size_type target() const { return M_dst; }
  weight_type weight() const { return M_weight; }
};

struct directed_tag {};
struct undirected_tag {};

template <typename Edge, typename Directedness>
class adjacency_list {
public:
  using size_type = size_t;
  using edge_type = Edge;
  using weight_type = typename Edge::weight_type;
  static constexpr weight_type inf = std::numeric_limits<weight_type>::max();

private:
  std::vector<std::vector<edge_type>> M_g;

public:
  adjacency_list() = default;
  adjacency_list(adjacency_list const&) = default;
  adjacency_list(adjacency_list&&) = default;
  adjacency_list(size_type n): M_g(n) {}

  template <typename... Args>
  void emplace(size_type src, size_type dst, Args... args) {
    M_g[src].emplace_back(src, dst, args...);
    if (std::is_same<Directedness, undirected_tag>::value)
      M_g[dst].emplace_back(dst, src, args...);
  }

  size_type size() const { return M_g.size(); }
  std::vector<edge_type> const& operator [](size_type i) const { return M_g[i]; }
};

template <typename Edge, typename Directedness>
constexpr typename Edge::weight_type adjacency_list<Edge, Directedness>::inf;

struct dijkstra_tag {} dijkstra;

template <typename Edge, typename Directedness>
auto shortest(adjacency_list<Edge, Directedness> const& g, size_t s, dijkstra_tag) {
  using weight_type = typename Edge::weight_type;
  size_t n = g.size();
  std::vector<weight_type> dp(n, g.inf);
  dp[s] = weight_type(0);
  using heap = fibonacci_heap<weight_type, size_t, std::greater<>>;
  heap fh;
  fh.push(weight_type(0), s);
  std::vector<typename heap::node_handle> nh(n);
  while (!fh.empty()) {
    weight_type w;
    size_t v;
    std::tie(w, v) = fh.top();
    fh.pop();
    if (dp[v] < w) continue;
    for (auto const& e: g[v]) {
      weight_type nw = dp[e.source()] + e.weight();
      size_t nv = e.target();
      if (nw < dp[nv]) {
        dp[nv] = nw;
        if (nh[nv].expired()) {
          nh[nv] = fh.push(nw, nv);
        } else {
          fh.prioritize(nh[nv], nw);
        }
      }
    }
  }
  return dp;
}

int main() {
  size_t n, m, r;
  scanf("%zu %zu %zu", &n, &m, &r);

  adjacency_list<weighted_edge<intmax_t>, directed_tag> g(n);
  for (size_t i = 0; i < m; ++i) {
    size_t s, t;
    intmax_t d;
    scanf("%zu %zu %jd", &s, &t, &d);
    g.emplace(s, t, d);
  }

  auto res = shortest(g, r, dijkstra);
  for (auto ri: res) {
    if (ri == g.inf) {
      puts("INF");
    } else {
      printf("%jd\n", ri);
    }
  }
}

