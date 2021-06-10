#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(obj) (obj).begin(), (obj).end()


struct edge{
    int to, cost;
    edge(int t, int c) { to = t; cost = c;}
};
struct vertex{
    int number, cost;
    vertex(int n, int c) { number = n; cost = c;}
    bool operator> (const vertex &a) const{
        return cost > a.cost;
    }
};

vector<vector<edge>> graph;
const int INF = INT_MAX;
vector<int> dist;
vector<int> prv;

void dijkstra(int n, int start){
    dist = vector<int>(n,INF); //各ノードへの距離
    prv  = vector<int>(n,-1); //前のノード
    dist[start] = 0;
    
    priority_queue<vertex, vector<vertex>, greater<vertex>> que;
    que.push(vertex(start,0));
    
    while(!que.empty()){
        vertex Vn = que.top();
        que.pop();
        int n = Vn.number;
        if(dist[n] < Vn.cost) continue;
        for(int i=0; i<graph[n].size(); i++){
            edge e = graph[n][i];
            if(dist[e.to] <= dist[n] + e.cost) continue;
            dist[e.to] = dist[n] + e.cost;
            prv[e.to] = n;
            que.push(vertex(e.to, dist[e.to]));
        }
    }
}

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    graph = vector<vector<edge>>(V);
    rep(i,E){
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back(edge(t,d));
    }
    dijkstra(V, r);
    rep(i,V){
        if(dist[i]!=INF){
            cout << dist[i] << endl;
        }else{
            cout << "INF" << endl;
        }
    }
}
