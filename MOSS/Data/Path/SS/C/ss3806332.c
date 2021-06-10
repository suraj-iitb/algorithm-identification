#include <bits/stdc++.h>

using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

// ダイクストラ法
// T: コスト (非負)
template<typename T>
class Dijkstra {
    struct edge {
        int to;
        T cost;
    };
    const int n;
    const T ZERO, INF;
    std::vector<std::vector<edge> > G;
public:
    // 頂点数と零元と十分大きな値を指定して初期化
    Dijkstra(int n, T ZERO, T INF) : n(n), ZERO(ZERO), INF(INF), G(n) {}

    // 始点、終点、コストを指定して辺を追加
    void addEdge(int from, int to, T cost) { G[from].push_back({to, cost}); }

    // 頂点sからの最短距離列を取得
    std::vector<T> getDist(int s) {
        typedef std::pair<T, int> P;
        std::priority_queue<P, std::vector<P>, std::greater<P> > pq;
        std::vector<T> d(n);
        std::fill(d.begin(), d.end(), INF);
        d[s] = ZERO;
        pq.push(P(ZERO, s));
        while (!pq.empty()) {
            P p = pq.top();
            pq.pop();
            int v = p.second;
            if (d[v] < p.first)continue;
            for (int i = 0; i < G[v].size(); i++) {
                edge e = G[v][i];
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    pq.push(P(d[e.to], e.to));
                }
            }
        }
        return d;
    }
};

int V, E, r;
int s[550000], t[550000], d[550000];

signed main() {
    cin >> V >> E >> r;
    Dijkstra<int> dij(V, 0, 1e12);
    for (int i = 0; i < E; i++) {
        cin >> s[i] >> t[i] >> d[i];
        dij.addEdge(s[i], t[i], d[i]);
    }
    vint d = dij.getDist(r);
    for (int i = 0; i < V; i++) {
        if (d[i] == 1e12)cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}
