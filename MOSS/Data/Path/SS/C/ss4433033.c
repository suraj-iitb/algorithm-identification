#pragma GCC target("avx")

#include <vector>
#include <algorithm>

template<class T>
struct radix_heap {
  using key_type = unsigned;
  std::vector<std::pair<key_type, T>> bucket[33];
  key_type size, last;

  radix_heap(): size(0), last(0) {}
  bool empty() const { return size == 0; }
  inline int getbit(int a) {
    return a ? 32 - __builtin_clz(a) : 0;
  }
  void push(key_type key, const T& value) {
    size++;
    bucket[getbit(key ^ last)].emplace_back(key, value);
  }
  std::pair<key_type, T> pop() { 
    if(bucket[0].empty()) {
      int idx = 1;
      while(bucket[idx].empty()) idx++;
      last = std::min_element(std::begin(bucket[idx]), end(bucket[idx]))->first;
      for(auto& p: bucket[idx]) bucket[getbit(p.first ^ last)].emplace_back(p);
      bucket[idx].clear();
    }
    size--;
    auto ret = bucket[0].back();
    bucket[0].pop_back();
    return ret;
  }
};

using namespace std;

template<class T, class Compare>
struct pairing_heap {
  struct node {
    T val;
    node* head;
    node* next;
    node() : head(nullptr), next(nullptr) {}
    node(const T& v) : val(v), head(nullptr), next(nullptr) {  }
  };
  static size_t ni;
  static node n[505050];
  size_t sz;
  node* root;
  Compare comp;
  pairing_heap() : sz(0), root(nullptr) {  }
  node* merge(node* x, node* y) {
    if(!y) return x;
    if(!x) return y;
    if(comp(y->val, x->val)) swap(x,y);
    y->next = x->head;
    x->head = y;
    return x;
  }
  node* mergeList(node * x) {
    node* nn = nullptr;
    while(x) {
      node* a = x;
      node* b = nullptr;
      x = x->next;
      a->next = nullptr;
      if(x) {
        b = x;
        x = x->next;
        b->next = nullptr;
      }
      a = merge(a, b);
      a->next = nn;
      nn = a;
    }
    while(nn) {
      node* j = nn;
      nn = nn->next;
      x = merge(j,x);
    }
    return x;
  }
  
  /* return compest element */
  T top() {
    return root->val;
  }

  /* pop compest element */
  void pop() {
    --sz;
    node* te = root;
    root = mergeList(root->head);
  }
  
  /* add element */
  void push(const T& x) {
    ++sz;
    n[ni].val = x;
    root = merge(&n[ni++], root);
  }
  
  /* size */
  size_t size() {
    return sz;
  }

  bool empty() const {
    return sz == 0;
  }
  
  /* merge heap */
  void meld(pairing_heap<T,Compare>& h) {
    root = merge(root, h.root);
    h.root = nullptr;
    h.sz = 0;
  }
};



#include <vector>
#include <queue>

template<class T, class Comp>
typename pairing_heap<T, Comp>::node pairing_heap<T, Comp>::n[505050];
template<class T, class Comp>
std::size_t pairing_heap<T, Comp>::ni = 0;

/*
 * delta(V v, fn (V t, W weight))
 * index(V v) -> int
 */
template<class V, class W, class Delta, class Index>
std::vector<W> dijkstra(std::size_t N, W inf, V s, Delta delta, Index index) {
  std::vector<W> dist(N, inf);
  using P = std::pair<W, V>;
  radix_heap<V> que;
  que.push(dist[index(s)] = W(), s);
  while(!que.empty()) {
    auto p = que.pop();
    W d = p.first;
    V v = p.second;
    if(dist[index(v)] < d) continue;
    delta(v, [&](V t, W weight) {
        if(dist[index(t)] > dist[index(v)] + weight) {
          que.push(dist[index(t)] = dist[index(v)] + weight, t);
        }
    });
  }
  return dist;
}

#include <vector>
#include <queue>

/*
 * delta(V v, fn (V t, W weight))
 * index(V v) -> int
 */
template<class V, class W, class Delta, class Index>
std::vector<W> dijkstra2(std::size_t N, W inf, V s, Delta delta, Index index) {
  std::vector<W> dist(N, inf);
  using P = std::pair<W, V>;
  pairing_heap<P, std::less<P>> que;
  que.push({ dist[index(s)] = W(), s });
  while(!que.empty()) {
    W d = que.top().first;
    V v = que.top().second;
    que.pop();
    if(dist[index(v)] < d) continue;
    delta(v, [&](V t, W weight) {
        if(dist[index(t)] > dist[index(v)] + weight) {
          que.push({ dist[index(t)] = dist[index(v)] + weight, t });
        }
    });
  }
  return dist;
}


#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int N, M, R;
  std::cin >> N >> M >> R;
  std::vector<std::vector<std::pair<int, unsigned>>> G(N);
  for(int i = 0; i < M; i++) {
    int s, t;
    unsigned d;
    std::cin >> s >> t >> d;
    G[s].emplace_back(t, d);
  }
  auto res = dijkstra2(N, unsigned(1e9 + 1), R, [&](int v, auto func) {
        for(const auto& e: G[v]) {
          func(e.first, e.second);
        }
      }, [&](int v) {
        return v;
      });

  for(int i = 0;i < N;i++) {
    if(res[i] == unsigned(1e9 + 1))
      std::cout << "INF\n";
    else
      std::cout << res[i] << "\n";
  }
}

