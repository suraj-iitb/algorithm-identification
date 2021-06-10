#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 1000010
#define INF 10000000000

struct edge{int to, cost;};
typedef pair<int, int> P; //first is shortest distance, second is number.

vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(int s, int V){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    int V, E, r; cin >> V >> E >> r;
    for(int i = 0; i < E; i++){
        int a, b, c; 
        cin >> a >>b >> c;
        edge e = {b, c};
        G[a].push_back(e);
    }
    dijkstra(r, V);
    for(int i = 0; i < V; i++){
        if(d[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << d[i] << endl;
        }
    }
}
