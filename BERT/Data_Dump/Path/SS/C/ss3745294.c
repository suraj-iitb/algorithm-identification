#include "bits/stdc++.h"
// Custom Header {{{
#define ALL(x) x.begin(), x.end()
#define endl '\n'
using namespace std;
using i64 = long long;
using pii = pair<i64, i64>;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
// }}}

//@@@@@@@
//@ snippet edge
//@ alias   graph
//@ options  head
struct Edge {
    int src, to;
    i64 cost;
    Edge(int src,  int to, i64 cost) : src(src), to(to), cost(cost) {}
    Edge(int to, i64 cost = 0) : Edge(-1, to, cost) {}
    bool operator< (const Edge &o) const { return cost < o.cost; }
    bool operator> (const Edge &o) const { return cost > o.cost; }
};
using Edges = vector<Edge>;
using WGraph = vector<vector<Edge>>;
using Ugraph = vector<vector<int>>;
//@@@@@@



//@@@@@@@
//@ snippet dijkstra
//@ options head
vector<i64> dijkstra(const WGraph &G, int src)
{
    vector<i64> dist(G.size(), LINF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.emplace(0, src);

    while(!pq.empty()) {
        const i64 nowCost = pq.top().first;
        const int nowNode = pq.top().second;
        pq.pop();
        if (dist[nowNode] < nowCost) continue;

        for (const auto &e : G[nowNode]) {
            const i64 newCost = nowCost + e.cost;
            if (chmin(dist[e.to], newCost)) {
                pq.emplace(newCost, e.to);
            }
        }
    }

    return dist;
}
//@@@@@@@@



//@@@@@@@@
//@ snippet bellmanFord
//@ options head
vector<i64> bellmanFord(const Edges &es, int V, int src)
{
    vector<i64> dist(V, LINF);
    dist[src] = 0;

    int updateCnt = 0;
    bool updated;
    do {
        updated = false;
        for (const auto &e : es) {
            if (dist[e.src] == LINF) continue;
            updated |= chmin(dist[e.to], dist[e.src] + e.cost);
        }
    } while(updated && ++updateCnt < V);

    if (updateCnt >= V) return {};
    return dist;
}
//@@@@@@@



/*
   Verified On: 2019-07-14
   https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
*/
void AOJ_GRL_1_A()
{
    int V, E, src;
    cin >> V >> E >> src;

    WGraph G(V);
    for (int i = 0; i < E; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        G[s].emplace_back(t, c);
    }

    auto dist = dijkstra(G, src);

    for (i64 d : dist) {
        if (d >= LINF) cout << "INF" << endl;
        else cout << d << endl;
    }
}



/*
   Verified On: 2019-07-14
   https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
*/
void AOJ_GRL_1_B()
{
    int V, E, src;
    Edges es;

    cin >> V >> E >> src;
    for (int i = 0; i < E; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        es.emplace_back(s, t, c);
    }

    auto dist = bellmanFord(es, V, src);

    if (dist.empty()) {
        cout << ("NEGATIVE CYCLE") << endl;
    } else {
        for (auto e : dist) {
            if (e >= LINF) cout << "INF" << endl;
            else cout << e << endl;
        }
    }
}


signed main()
{
    AOJ_GRL_1_A();
    return 0;
}

