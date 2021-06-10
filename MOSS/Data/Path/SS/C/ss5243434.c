//参考にしたサイト
//https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A 問題
//http://nw.tsuda.ac.jp/lec/dijkstra/ アルゴリズムの説明
// 利哉のライブラリを丸パクリ
#include <bits/stdc++.h>
#define ll long long int
#define P pair<ll,ll>
#define INF 1000000000000000000
template<typename T>
struct dijk_graph {
  public:
    T inf = std::numeric_limits<T>::max();
    dijk_graph() : _n(0) {}
    dijk_graph(int n) : _n(n), g(n), dist(n), prev(n) {}
    void add_edge(int from, int to, T cap){
      assert(0 <= from && from < _n);
      assert(0 <= to && to < _n);
      assert(0 <= cap);
      g[from].push_back(_edge{to, cap});
    }
    void run(int start){
      assert(0 <= start && start < _n);
      std::fill(dist.begin(), dist.end(), inf);
      prev[start] = -1;
      q.push(q_data(0, start));
      while (q.size() != 0){
        auto p = q.top();
        q.pop();
        T ud = p.first;
        int u = p.second;
        if (dist[u] < ud){
          continue;
        }
        dist[u] = ud;
        for (auto t : g[u]){
          int v = t.to;
          T vd = ud + t.cap;
          if (dist[v] > vd){
            dist[v] = vd;
            q.push(q_data(vd, v));
            prev[v] = u;
          }
        }
      }
    }
    T get_dist(int u){
      return dist[u];
    }
    int get_prev(int u){
      return prev[u];
    }
  private:
    int _n;
    struct _edge {
        int to;
        T cap;
    };
    std::vector<std::vector<_edge>> g;
    std::vector<T> dist;
    std::vector<int> prev;
    using q_data = std::pair<T, int>;
    std::priority_queue<q_data, std::vector<q_data>, std::greater<q_data>> q;
};
using namespace std;
int main(void){
  ll n, m, s;
  cin >> n >> m >> s;
  dijk_graph<ll> g(n);
  for (ll i = 0; i < m; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    g.add_edge(a, b, c);
  }
  g.run(s);
  for (ll i = 0; i < n; i++){
    if (g.get_dist(i) == g.inf)
      cout << "INF" << endl;
    else
      cout << g.get_dist(i) << endl;
  }
  return 0;
}
