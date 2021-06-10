#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

struct edge{
    int to, cost;
    edge(int t, int c) : to(t), cost(c) {}
};
using P = std::pair<int, int>; // pair of distance, node id

std::vector<int> dijkstra(std::vector<std::vector<edge> > G, int s){
    int V = G.size();
    std::vector<int> d(V,INF); d[s] = 0;
    std::priority_queue<P, std::vector<P>, std::greater<P> > que;
    que.emplace(0,s);
    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int j=0; j<G[v].size(); ++j){
            edge e = G[v][j];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.emplace(d[e.to], e.to);
            }
        }
    }
    return d;
}

int main(){
    int V,E,r; std::cin >> V >> E >> r;
    std::vector<std::vector<edge> > graph(V);
    for(int i=0; i<E; ++i){
        int s,t,d; std::cin >> s >> t >> d;
        graph[s].emplace_back(t, d);
    }
    auto distances = dijkstra(graph, r);
    for(auto d : distances){
        if(d == INF)
            std::cout << "INF" << std::endl;
        else
            std::cout << d << std::endl;
    }
    return 0;
}
