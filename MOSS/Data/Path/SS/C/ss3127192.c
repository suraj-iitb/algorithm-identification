#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
int V, E, r;
struct edge{int to, cost; };

typedef pair<int, int> P; //firstは最短距離, secondは頂点の番号
vector<vector<edge> > G(100010);
int d[100010];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    for(int i=0; i<V; ++i) d[i]=1e9+7;
    d[s]=0;
    que.push(P(0, s));
    
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<(int)G[v].size(); ++i){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] +e.cost;
                que.push(P(d[e.to], e.to));
            }
        }  
    }
}
int main(){
    cin >> V >> E >> r;
    for(int i=0; i<E; ++i){
        edge da;
        int s, t, d; cin >> s >> t >> d;
        da.to = t; da.cost = d;
        G[s].push_back(da);
    }
    dijkstra(r);
    for(int i=0; i<V; ++i){
        if(d[i]!=1e9+7) cout << d[i] << endl;
        else cout << "INF" << endl;
    }
    return 0;
}


