#include <bits/stdc++.h>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n; 0 <= i; i--)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = start; end <= i; i--)
#define ALL(a) a.begin(), a.end()
#define MOD(a) a %= 1'000'000'007
#define INF32 1'050'000'000
#define INF64 4'000'000'000'000'000'000
using ll = long long;
using namespace std;
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

class Dijkstra {
  private:
    struct Graph {
        int to, cost;
    };
    const long long INF = 4'000'000'000'000'000'000;
    using P             = pair<long long, int>;
    int V;
    vector<vector<Graph>> G;
    vector<long long> dist;

  public:
    Dijkstra(int vertex) {
        V = vertex;
        G.resize(vertex);
        dist.resize(vertex, INF);
    }
    // 無向グラフの構築
    void undirected_update(int x, int y, int cost) {
        G[x].push_back({y, cost});
        G[y].push_back({x, cost});
    }
    // 有向グラフの構築
    void directed_update(int from, int to, int cost) {
        G[from].push_back({to, cost});
    }

    // start からの最短経路計算
    void calc(int start) {
        priority_queue<P, vector<P>, greater<P>> que;
        dist[start] = 0;
        que.push({0, start});

        while (!que.empty()) {
            auto p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first)
                continue;
            for (int i = 0; i < G[v].size(); i++) {
                auto e = G[v][i];
                if (dist[v] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[v] + e.cost;
                    que.push({dist[e.to], e.to});
                }
            }
        }
    }

    // calc で渡した start からの最短経路を返す
    // 最短経路が存在しないとき -1 を返す
    long long min_dist(int to) { return dist[to] != INF ? dist[to] : -1; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int v, e, r;
    cin >> v >> e >> r;
    auto dj = Dijkstra(v);
    REP(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        dj.directed_update(s, t, d);
    }
    dj.calc(r);
    REP(i, v) {
        dj.min_dist(i) == -1 ? std::cout << "INF" << '\n'
                             : std::cout << dj.min_dist(i) << '\n';
    }

    return 0;
}
