#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int, int>;
using Matrix = vector<vector<int>>;


const int INF = 1000000000;

struct edge {
    int to;
    int cost;
    edge(int to, int cost) : to(to), cost(cost){ }
};
using Graph = vector<vector<edge>>;
int V;
Graph G;
vector<int> dist;

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    dist = vector<int>(V, INF);
    dist[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(dist[v] < p.first)
            continue;
        for (int i = 0; i < G[v].size(); ++i){
            edge e = G[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main(){
    cin >> V;
    int E;
    cin >> E;
    int r;
    cin >> r;
    G.resize(V);
    rep(i, E)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        G[from].push_back(edge(to, cost));
    }
    dijkstra(r);
    rep(i,V){
        if(dist[i]!= INF){
            cout << dist[i] << endl;
        }else{
            cout << "INF" << endl;
        }
    }
}
