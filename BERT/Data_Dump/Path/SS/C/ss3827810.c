#include <bits/stdc++.h>
template<typename T>
struct Edge {
    int from, to;
    T cost;
    Edge(int from, int to, T cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};
template<typename T>
using Edges = std::vector<Edge<T>>;
template<typename T>
using Graph = std::vector<Edges<T>>;
template <typename T>
std::vector<T> dijkstra(const Graph<T> &g, int s) {
    int sz = (int)(g.size());
    std::vector<T> dist(sz, std::numeric_limits<T>::max());
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        int now = pq.top().second; pq.pop();
        for(int i=0;i<(int)(g[now].size());++i) {
            int next = g[now][i].to, cost = g[now][i].cost;
            if(dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;
                pq.push({cost, next});
            }
        }
    }
    return dist;
}
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double eps = 1e-10;
const int MOD = 1000000007;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
    cin.tie(0);
    cout << fixed << setprecision(10);
    int n, m, s; cin >> n >> m >> s;
    Graph<ll> g(n);
    for(int i=0;i<m;++i) {
      int u, v, c; cin >> u >> v >> c;
      g[u].push_back(Edge<ll>(u, v, c));
    }
    vector<ll> dist = dijkstra(g, s);
    for(int i=0;i<n;++i) {
      if(dist[i] == LLONG_MAX) cout << "INF" << endl;
      else cout << dist[i] << endl;
    }
}

