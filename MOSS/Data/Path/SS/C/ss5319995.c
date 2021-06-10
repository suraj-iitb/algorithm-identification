#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//TEMPLATE_BEGIN
struct Node{
    int to;
    ll w;
};
using graph = vector<vector<Node>>;
constexpr auto infty = numeric_limits<ll>::max();
vector<ll> dijkstra(const graph &g, const int s){
    vector<ll> d(g.size(), infty);
    d[s] = 0;
    auto cmp = [](const Node &a, const Node &b){return a.w > b.w;};
    priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
    pq.push(Node{s, 0});
    while(!pq.empty()){
        const auto q = pq.top();
        pq.pop();
        for(const auto &t: g[q.to]){
            const auto alt = d[q.to] + t.w;
            if(alt < d[t.to]){
                d[t.to] = alt;
                pq.push(Node{t.to, alt});
            }
        }
    }
    return d;
}
//TEMPLATE_END

void solve_aoj_grl_1_a(){
    int v, e, r;
    cin >> v >> e >> r;
    graph g(v);
    for(int i=0; i<e; ++i){
        int s, t, d;
        cin >> s >> t >> d;
        g[s].push_back(Node{t, d});
    }
    const auto ret = dijkstra(g, r);
    for(int i=0; i<v; ++i){
        if(ret[i] == infty){
            cout << "INF" << endl;
        }else{
            cout << ret[i] << endl;
        }
    }
}

int main(){
    solve_aoj_grl_1_a();
}
