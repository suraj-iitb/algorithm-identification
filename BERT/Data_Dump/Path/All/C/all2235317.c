#include <bits/stdc++.h>
using namespace std;

template<class Data> struct Graph;

struct DefData {
  struct VData {};
  struct GData {};

  using Len = int;
  struct EData {
    Len len;
    EData() : len(1) {}
  };
  static const Len INF = 0x33433433;
};

template<class Data=DefData>
struct Graph {
  using VData = typename Data::VData;
  using EData = typename Data::EData;
  using GData = typename Data::GData;
  struct Edge {
    int to;
    int rev_idx;
    bool is_es;
    EData dat;
  };
  using Len = decltype(EData::len);
  using Ls = vector<Len>;
  using Es = vector<Edge>;
  Len INF = Data::INF;

  int n;
  GData gdat;
  vector<VData> vdat;
  vector<Es> es;
  vector<Es> res;
  vector<Ls> cost;
  
  Graph() {}
  Graph(int sz) {
    Init(sz);
  }

  void Init(int sz) {
    n = sz;
    vdat.resize(sz);
    es.resize(sz);
    res.resize(sz);
  }

  void AddEdge(int u, int v, EData d, EData r) {
    es[u].emplace_back(Edge{v, 0, true, d});
    res[v].emplace_back(Edge{u, 0, false, r});
    es[u].back().rev_idx = res[v].size()-1;
    res[v].back().rev_idx = es[u].size()-1;
  }

  void AddEdge(int u, int v, EData d=EData()) {
    AddEdge(u, v, d, d);
  }

  Edge *GetRevEdge(Edge *e) {
    int v = e->to;
    if (e->is_es) return &res[v][e->rev_idx];
    return &es[v][e->rev_idx];
  }

  // should be tested
  template<class Cmp>
  void EraseMultipleEdge(Cmp cmp, bool really_erase) {
    auto same = [](const Edge &a, const Edge &b) {
      return a.to == b.to;
    };

    vector<Es> new_res(n);
    for (int v=0; v<n; v++) {
      auto &ves = es[v];
      sort(ves.begin(), ves.end(), cmp);
      auto itr = unique(ves.begin(), ves.end(), same);
      if (really_erase) ves.erase(itr, ves.end());
      for (int i=0; i<ves.size(); i++) {
        auto &e = ves[i];
        int u = e.to;
        new_res[u].emplace_back(Edge{v, i, false, GetRevEdge(&e)->dat});
      }
    }
    res.swap(new_res);
  }

  void CreateAdjMat() {
    cost.clear();
    cost.resize(n, Ls(n, INF));

    auto cmp = [](const Edge &a, const Edge &b) {
      if (a.to != b.to) return a.to < b.to;
      return a.dat.len < b.dat.len;
    };
    EraseMultipleEdge(cmp, false);

    for (int i=0; i<n; i++) {
      int prev = -1;
      for (auto &e : es[i]) {
        int v = e.to;
        if (prev > v) break;
        cost[i][v] = min(cost[i][v], e.dat.len);
        prev = v;
      }
    }
  }

  void DijkstraV(vector<int> &starts, Ls &d) {
    d.clear();
    d.resize(n, INF);
    for (int s : starts) d[s] = 0;

    if (cost.empty()) CreateAdjMat();

    vector<bool> used(n, false);
    for (int i=0; i<n; i++) {
      int v = -1;
      for (int u=0; u<n; u++) {
        if (used[u]) continue;
        if (v == -1 || d[u] < d[v]) {
          v = u;
        }
      }
      if (v == -1) return;

      used[v] = true;
      for (int u=0; u<n; u++) {
        d[u] = mind(d[u], d[v] + cost[v][u]);
      }
    }

    // must not reach here
    assert(0);
  }

  void DijkstraE(vector<int> &starts, Ls &d) {
    using Pair = pair<Len, int>;
    priority_queue<Pair, vector<Pair>, greater<Pair> > q;
    d.clear();
    d.resize(n, INF);
    for (int s : starts) {
      d[s] = 0;
      q.push(Pair(0, s));
    }

    while (!q.empty()) {
      Pair p = q.top(); q.pop();
      int v = p.second;
      if (d[v] < p.first) continue;
      for (auto &e : es[v]) {
        int u = e.to;
        Len nd = d[v] + e.dat.len;
        if (d[u] > nd) {
          d[u] = nd;
          q.push(Pair(nd, u));
        }
      }
    }
  }

  // return true if a graph has a negative cycle in the reachnable scope from starts
  bool SPFA(vector<int> &starts, Ls &d) {
    d.clear();
    d.resize(n, INF);

    if (n == 1) {
      d[0] = 0;
      return false;
    }

    queue<int> q;
    vector<bool> inq(n);
    vector<int> cnt(n);
    for (int s : starts) {
      inq[s] = true;
      q.push(s);
      d[s] = 0;
    }

    while (!q.empty()) {
      int v = q.front(); q.pop();
      inq[v] = false;
      cnt[v]++;
      if (cnt[v] > n) continue;
      for (auto &e : es[v]) {
        int u = e.to;
        Len nd = d[v] + e.dat.len;
        if (d[u] > nd) {
          d[u] = nd;
          if (inq[u]) continue;
          inq[u] = true;
          q.push(u);
        }
      }
    }

    // do DFS if you need the concrete contents of such cycles
    for (int i=0; i<n; i++) {
      if (cnt[i] >= n) return true;
    }

    return false;
  }

  void DijkstraV(int s, Ls &d) {
    vector<int> ss(1, s);
    DijkstraV(ss, d);
  }

  void DijkstraE(int s, Ls &d) {
    vector<int> ss(1, s);
    DijkstraE(ss, d);
  }

  // return true if the graph has a negative cycle
  bool SPFA(int s, Ls &d) {
    vector<int> ss(1, s);
    return SPFA(ss, d);
  }

  // Create "Shortest Path Graph", which should be DAG
  Graph<Data> RestoreShortestPaths(Ls &d) {
    Graph<Data> ret(n);

    for (int i=0; i<n; i++) {
      for (auto &e : es[i]) {
        int v = e.to;
        if (d[v] == d[i] + e.dat.len) {
          ret.AddEdge(i, e.to, e.dat, GetRevEdge(&e)->dat);
        }
      }
    }

    return ret;
  }

  bool hasNegativeCycle() {
    vector<int> s(n);
    Ls d;
    for (int i=0; i<n; i++) s[i] = i;
    return SPFA(s, d);
  }

  // return true if the graph has a negative cycle
  bool FloydWarshall(vector<Ls> &ds) {
    if (cost.empty()) CreateAdjMat();

    ds = vector<Ls>(cost);
    for (int i=0; i<n; i++) {
      ds[i][i] = min(ds[i][i], Len(0));
    }

    for (int k=0; k<n; k++) {
      for (int i=0; i<n; i++) {
        if (ds[i][k] == INF) continue;
        for (int j=0; j<n; j++) {
          if (ds[k][j] == INF) continue;
          Len nd = max(ds[i][k] + ds[k][j], -INF);
          if (ds[i][j] > nd) {
            ds[i][j] = nd;
          }
        }
      }
    }

    for (int i=0; i<n; i++) {
      if (ds[i][i] < 0) return true;
    }
    return false;
  }

  // Karp's Algorithm O(NM)
  // should be tested
  // should be used for SCC
  double MinimumMeanCycle() {
    vector<Ls> dp(n+1, Ls(n, INF));

    dp[0][0] = 0;
    for (int i=1; i<=n; i++) {
      for (int v=0; v<n; v++) {
        for (auto &e : es[v]) {
          int u = e.to;
          dp[i][u] = min(dp[i][u], dp[i-1][v] + e.dat.len);
        }
      }
    }

    double ret = 1.0/0.0;
    for (int v=0; v<n; v++) {
      double alpha = (-1.0)/0.0;
      for (int i=1; i<n; i++) {
        if (dp[n][v] == INF) continue;
        if (dp[i][v] == INF) continue;
        alpha = max(alpha, (dp[n][v]-dp[i][v])/double(n-i));
      }
      ret = min(ret, alpha);
    }
    return ret;
  }
};

template<class Data=DefData>
struct DFSForest {
  using G = Graph<Data>;
  using Edge = typename G::Edge;
  using Brid = pair<int, Edge*>;

  int grp;
  vector<int> ord;
  vector<int> low;
  vector<int> belong;
  vector<int> artic;
  vector<Brid> bridge;

  DFSForest(G &g, bool is_directed) {
    int k = 0;
    int idx = 0;
    int n = g.n;
    vector<int> st(n);

    grp = 0;
    ord.resize(n, -1);
    low.resize(n);
    belong.resize(n, -1);

    function<void(int,int,Edge*)> dfs;
    // to deal with multiple edges, it uses a pointer
    auto update = [&](int v, Edge *e, bool &is_artic, int &cnt) {
      int u = e->to;
      if (ord[u] != -1) {
        if (belong[u] == -1) low[v] = min(low[v], ord[u]);
      } else {
        cnt++;
        dfs(u, v, e);
        low[v] = min(low[v], low[u]);
        if (ord[v] <= low[u]) is_artic = true;
        if (ord[v] < low[u]) bridge.emplace_back(Brid(v, e));
      }
    };

    dfs = [&](int v, int p, Edge *par) {
      bool is_artic = false;
      int cnt = 0;

      st[idx++] = v;
      low[v] = ord[v] = k++;

      for (auto &e : g.es[v]) {
        if (g.GetRevEdge(&e) == par) continue;
        update(v, &e, is_artic, cnt);
      }

      if (!is_directed) {
        for (auto &e : g.res[v]) {
          if (g.GetRevEdge(&e) == par) continue;
          update(v, &e, is_artic, cnt);
        }
      }

      if (p == -1) is_artic = (cnt > 1);
      if (is_artic) artic.emplace_back(v);

      if (low[v] != ord[v]) return;
      while (1) {
        int u = st[--idx];
        belong[u] = grp;
        if (u == v) break;
      }
      grp++;
    };

    for (int i=0; i<n; i++) {
      if (ord[i] == -1) dfs(i, -1, NULL);
    }
  }
};


template<class Data=DefData>
struct SCCData {
  using VD = typename Data::VData;
  using ED = typename Data::EData;
  using GD = typename Data::GData;
  using G = Graph<Data>;
  using Len = int;

  struct VData {
    G g; // the graph consisting of contracted nodes in one component
    vector<int> cont2orig; // the correspondence of the node index: v on SCCVData::g -> cont2orig[v] on the original graph(G)
  };

  struct EData : ED {
    int s;
    int t;
    EData(int a, int b, const ED &dat) : ED(dat), s(a), t(b) {}
  };

  struct GData {
    vector<int> orig2cont; // the correspondence of the node index: v on G -> orig2cont[v] on G's SCC::vdat[belong[v]].g
  };

  static const Len INF = 0x33433433;
};

template<class Data=DefData>
struct SCC : Graph<SCCData<Data> > {
  using ED = typename Data::EData;
  using EData = typename SCCData<Data>::EData;
  using G = Graph<Data>;

  DFSForest<Data> df;
  SCC(G &g) : df(g, true) {
    int n = g.n;

    this->Init(df.grp);
    auto &gdat = this->gdat;
    auto &vdat = this->vdat;

    gdat.orig2cont.resize(n);
    for (int v=0; v<n; v++) {
      auto &vd = vdat[df.belong[v]];
      gdat.orig2cont[v] = vd.cont2orig.size();
      vd.cont2orig.emplace_back(v);
    }

    for (int i=0; i<df.grp; i++) {
      auto &vd = vdat[i];
      vd.g.Init(vd.cont2orig.size());
    }
    
    for (int v=0; v<n; v++) {
      for (auto &e : g.es[v]) {
        int u = e.to;
        ED &rd = g.GetRevEdge(&e)->dat;
        int bv = df.belong[v];
        int bu = df.belong[u];

        if (bv == bu) {
          auto &vd = vdat[bv];
          auto &dic = gdat.orig2cont;
          vd.g.AddEdge(dic[v], dic[u], e.dat, rd);
        } else {
          this->AddEdge(bv, bu, EData(v, u, e.dat), EData(u, v, rd));
        }
      }
    }
  }
};

using LLI = long long int;

struct A {
  struct VData {};
  struct GData {};

  using Len = LLI;
  struct EData {
    Len len;
    EData(LLI a) : len(a) {}
  };
  static const Len INF = 0x334334334334;
};

int n;
int m;

int main() {
  scanf("%d%d", &n, &m);
  Graph<A> g(n);
  while (m--) {
    int s, t;
    LLI d;
    scanf("%d%d%lld", &s, &t, &d);
    g.AddEdge(s, t, d);
  }

  vector<vector<LLI> > ds;
  if (g.FloydWarshall(ds)) {
    puts("NEGATIVE CYCLE");
    return 0;
  }

  for (int i=0; i<n; i++) {
    printf((ds[i][0] >= A::INF ? "INF" : "%lld"), ds[i][0]);
    for (int j=1; j<n; j++) {
      printf((ds[i][j] >= A::INF ? " INF" : " %lld"), ds[i][j]);
    }
    puts("");
  }
}
