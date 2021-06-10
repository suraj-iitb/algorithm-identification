#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
struct edge{
    int to;
    int cost;
};
long long INF =1e18;
int V, E, r;
typedef pair<long long, long long> P;//一つ目は距離、二つ目は頂点番号
vector<vector<edge>> G;
vector<long long> dis;
vector<int> used;
void dijkstra(int r){
    priority_queue<P, vector<P>, greater<P>> q;
    dis[r] = 0;
    q.push(P(0, r));
    while(!q.empty()){
        P v = q.top();
        q.pop();
        if(dis[v.second] < v.first) continue;
        for(edge e: G[v.second]){
            if(dis[e.to] > dis[v.second] + e.cost){
                dis[e.to] = dis[v.second] + e.cost;
                q.push(P(dis[e.to], e.to));
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(dis[i] == INF) cout << "INF" << endl;
        else cout << dis[i] << endl;
    }
}
int main(){
    cin >> V >> E >> r;
    G.resize(V);
    dis.resize(V, INF);
    used.resize(V, 0);
    for(int i = 0; i < E; i++){
        long long s, t, d;
        cin >> s >> t >> d;
        edge e;
        e.to = t;
        e.cost = d;
        G[s].push_back(e);
    }
    dijkstra(r);
}
