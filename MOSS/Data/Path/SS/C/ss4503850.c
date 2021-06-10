#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
// #define INF (1LL << 31)
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define PRINT(V) for (auto v : (V)) cout << v << " "

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;
 
/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis) {
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

int main() {
    int V; cin >> V;
    int E;
    cin >> E;
    int r; cin >> r;

    Graph G(V);
    Edge e;
    for (int i=0; i<E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        e = {b, c};
        G[a].push_back(e);
        // e = {a, c};
        // G[b].push_back(e);
    }

    VI d;
    dijkstra(G, r, d);
    for (int i=0; i<V; ++i) {
        if(d[i] != INF) {
            cout << d[i] << endl;
        }else{
            cout << "INF" << endl;
        }
    }
}

