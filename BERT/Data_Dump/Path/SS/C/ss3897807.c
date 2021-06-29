//AOJ-GRL-1-A
#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

#define MAX_V 100000

struct edge { int to, cost; };

int V;//頂点数
vector<edge> G[MAX_V];//辺の張り方 : G[from].push_back((edge){to, cost});
int dist[MAX_V];//頂点sからの最短距離

//始点sから各頂点への最短距離を求める
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist, dist + V, INF);
    dist[s] = 0;
    que.push(P(0, s));
    
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

signed main(){
    int E,r;
    cin >> V >> E >> r;
    int s,t,d;
    REP(i,E){
        cin >> s >> t >> d;
        G[s].push_back(edge{t, d});
    }
    dijkstra(r);
    REP(i,V){
        if(dist[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << dist[i] << endl;
        }
    }
    return 0;
}
