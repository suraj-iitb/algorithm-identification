#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

const int maxv = 1e5 + 10;
const int maxe = 5e5 + 10;
const int INF = 1 << 30;

struct edge{
    int cost,to;
};
vector<edge> G[maxv];
int d[maxv];
int V,E,r;
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    for(int i = 0;i<V;i++){
        d[i] = INF;
    }
    d[s] = 0;
    que.push(P(0,s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0;i<G[v].size();i++){
            edge eg = G[v][i];
            if(d[v] + eg.cost < d[eg.to]){
                d[eg.to] = d[v] + eg.cost;
                que.push(P(d[eg.to],eg.to));
            }
        }
    }
}
int main(){
    cin >> V >> E >> r;
    for(int i = 0;i< E;i++){
        int f,t,c;
        scanf("%d%d%d",&f,&t,&c);
        edge eg;
        eg.to = t;
        eg.cost = c;
        G[f].push_back(eg);
    }
    dijkstra(r);
    for(int i = 0;i<V;i++){
        if(d[i]!=INF) cout << d[i] << endl;
        else cout << "INF" << endl;
    }
    
    return 0;
}
