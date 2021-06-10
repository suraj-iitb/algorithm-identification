#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<climits>
using namespace std;
struct edge{int to, cost;};
typedef pair<int, int> P;

int V, E, r;
vector<edge> G[100000];
int d[100000];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INT_MAX);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<G[v].size(); ++i){
            edge e = G[v][i];
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
int main(){
    cin >> V >> E >> r;
    for(int i=0; i<E; ++i){
        int s, t, d;
        cin >> s >> t >> d;
        edge e;
        e.to = t;
        e.cost = d;
        G[s].push_back(e);
    }
    dijkstra(r);
    for(int i=0; i<V; ++i){
       if(d[i]==INT_MAX) cout << "INF" << endl;
       else cout << d[i] << endl;
    }
}
