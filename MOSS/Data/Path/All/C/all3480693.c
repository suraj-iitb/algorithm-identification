#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)

const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-------------------------------------------------*/
template <typename T>
struct WarshallFloyd {
  vector<vector<T> > graph, dist;

  WarshallFloyd(const vector<vector<T> > &graph_, T TINF_) : graph(graph_), TINF(TINF_) {
    sz = graph.size();
    dist = graph;
    internal.assign(sz, vector<int>(sz, -1));
    REP(k, sz) REP(i, sz) REP(j, sz) {
      if (dist[i][k] != TINF && dist[k][j] != TINF && dist[i][j] > dist[i][k] + dist[k][j]) {
        dist[i][j] = dist[i][k] + dist[k][j];
        internal[i][j] = k;
      }
    }
  }

  void add(vector<tuple<int, int, T> > edges) {
    set<int> ver;
    for (tuple<int, int, T> e : edges) {
      int s = get<0>(e), t = get<1>(e);
      T cost = get<2>(e);
      graph[s][t] = min(graph[s][t], cost);
      if (dist[s][t] >= cost) {
        dist[s][t] = cost;
        internal[s][t] = -1;
      }
      ver.insert(s);
      ver.insert(t);
    }
    for (int v : ver) {
      REP(i, sz) REP(j, sz) {
        if (dist[i][v] != TINF && dist[v][j] != TINF && dist[i][j] > dist[i][v] + dist[v][j]) {
          dist[i][j] = dist[i][v] + dist[v][j];
          internal[i][j] = v;
        }
      }
    }
  }

  bool has_negative_cycle() {
    REP(i, sz) if (dist[i][i] < 0) return true;
    return false;
  }

  vector<int> build_path(int s, int t) {
    vector<int> res;
    if (dist[s][t] != TINF) {
      build_path(s, t, res);
      res.emplace_back(t);
    }
    return res;
  }

private:
  const T TINF;
  int sz;
  vector<vector<int> > internal;

  void build_path(int s, int t, vector<int> &path) {
    int k = internal[s][t];
    if (k == -1) path.emplace_back(s);
    else {
      build_path(s, k, path);
      build_path(k, t, path);
    }
  }
};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int v, e; cin >> v >> e;
  vector<vector<long long> > cost(v, vector<long long>(v, LINF));
  REP(i, v) cost[i][i] = 0;
  REP(i, e) {
    int s, t; cin >> s >> t;
    long long d; cin >> d;
    cost[s][t] = min(cost[s][t], d);
  }
  WarshallFloyd<long long> wf(cost, LINF);
  if (wf.has_negative_cycle()) {
    cout << "NEGATIVE CYCLE\n";
    return 0;
  }
  REP(i, v) {
    REP(j, v - 1) {
      if (wf.dist[i][j] == LINF) cout << "INF ";
      else cout << wf.dist[i][j] << ' ';
    }
    if (wf.dist[i][v-1] == LINF) cout << "INF\n";
    else cout << wf.dist[i][v-1] << '\n';
  }
  return 0;
}

