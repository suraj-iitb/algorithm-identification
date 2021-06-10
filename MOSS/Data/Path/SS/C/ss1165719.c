#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000007;

typedef long long ll;
typedef pair<int, int> pr;

struct edge{
    int to;
    int cost;
    edge(){}
    ~edge(){}
    edge(int a, int b): to(a), cost(b){}
};

struct state{
    int pos;
    int cost;
    state(){}
    ~state(){}
    state(int a, int b): pos(a), cost(b){}
    bool operator <(const state& b) const {
        return cost > b.cost;
    }
};

typedef vector<vector<edge> > graph;

vector<int> d;

void dijkstra(int src, graph& G){
    d.resize(G.size());
    fill(d.begin(), d.end(), INF);
    d[src] = 0;
    priority_queue<state> que;
    que.push(state(src, 0));
    while(!que.empty()){
        state s = que.top(); que.pop();
        int pos = s.pos;
        if(d[pos] < s.cost) continue;
        for(int i = 0; i < G[pos].size(); i++){
            int nxt = G[pos][i].to, e_cost = G[pos][i].cost;
            if(s.cost + e_cost < d[nxt]){
                d[nxt] = s.cost + e_cost;
                que.push(state(nxt, d[nxt]));
            }
        }
    }
}

int main(){
    int V, E, r;
    scanf("%d%d%d", &V, &E, &r);
    graph G(V);
    for(int i = 0; i < E; i++){
        int s, t, d;
        scanf("%d%d%d", &s, &t, &d);
        G[s].push_back(edge(t, d));
    }
    dijkstra(r, G);
    for(int i = 0; i < G.size(); i++){
        if(d[i] == INF){
            puts("INF");
        }else{
            printf("%d\n", d[i]);
        }
    }
    
    return 0;
}
