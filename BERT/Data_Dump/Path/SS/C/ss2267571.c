
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
struct State{
    int index;
    ll cost;
    State(int i, ll c):index(i), cost(c) {}
    bool operator > (const State &r) const { return cost > r.cost; }
};
//
//
vector<ll> dijkstra(const EdgeList &G, int start) {
    priority_queue<State, vector<State>, greater<State>> que;
    vector<ll> dist(G.size(), INFL);
    que.emplace(start, 0);
    dist[start] = 0;
    while(not que.empty()){
        State now = que.top(); que.pop();
        for(Edge e : G[now.index]){
            if(dist[e.to] > now.cost + e.cost){
                State nxt = State(e.to, now.cost + e.cost);
                dist[e.to] = nxt.cost;                
                que.push(nxt);
            }
        }
    }
    return dist;
}
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
int main() {
    int N, M, R; cin >> N >> M >> R;
    EdgeList E(N);
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        E[a].push_back(Edge(b, c));
    }
    auto dist = dijkstra(E, R);
    for(ll d : dist) cout << (d < INFL ? to_string(d) : "INF") << endl;
    return 0;
}
