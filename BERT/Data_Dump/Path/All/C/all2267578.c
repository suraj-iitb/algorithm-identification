// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i = 0; i < (int)(j); i++)
constexpr int INF = 1 << 28;
struct Edge{
    int to;
    ll cost;
    Edge(int to, ll cost):to(to), cost(cost){}
};
using EdgeList = vector<vector<Edge>>;
using Vatex = int;
constexpr ll INFL = 1LL << 60;
// O(V^3)
vector<vector<ll>> warshall_floyd(const EdgeList &G) {
    int N = G.size();
    vector<vector<ll>> dist(N, vector<ll>(N, INFL));
    rep(i, N) for(const Edge &e : G[i]) dist[i][e.to] = e.cost;
    rep(k, N) rep(i, N) rep(j, N)
            if(dist[i][k] < INFL and dist[k][j] < INFL)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
}
// warshall floyd?????????????????????????????????
bool has_negative_cycle(vector<vector<ll>> &dist) {
    rep(i, dist.size()) if(dist[i][i] < 0) return true;
    return false;
}
int main() {
    int N, M; cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        E[a].push_back(Edge(b, c));
    }
    rep(i, N) E[i].push_back(Edge(i, 0));
    auto dist = warshall_floyd(E);
    if(has_negative_cycle(dist)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i, N) {
            rep(j, N) cout << (dist[i][j] < INFL ? to_string(dist[i][j]) : "INF") << (j == N - 1 ? "\n" : " ");
        }
    }
    return 0;
}
