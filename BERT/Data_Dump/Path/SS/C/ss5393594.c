#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int to;
    long long cost;

    Edge(int a, long long b){
        to = a;
        cost = b;
    }
};

using Graph = vector<vector<Edge>>;

long long dist[100100];

int main(){
    int V,E,r;
    cin >> V >> E >> r;
    Graph G(V);
    for(int i=0;i<E;i++){
        int s,t;
        long long d;
        cin >> s >> t >> d;
        G[s].emplace_back(t,d);
    }
    for(int i=0;i<V;i++){
        dist[i] = -1;
    }
    dist[r] = 0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.emplace(0,r);
    while(!pq.empty()){
        int v = pq.top().second;
        long long v_dist = pq.top().first;
        pq.pop();
        for(int i=0;i<G[v].size();i++){
            int nv = G[v][i].to;
            long long nv_dist = G[v][i].cost;
            if(dist[nv]==-1){
                dist[nv] = v_dist + nv_dist;
                pq.emplace(dist[nv],nv);
            }else if(dist[nv]<=v_dist+nv_dist){
                continue;
            }
            dist[nv] = v_dist + nv_dist;
            pq.emplace(dist[nv],nv);
        }
    }
    for(int i=0;i<V;i++){
        if(dist[i]==-1){
            cout << "INF" << endl;
        }else{
            cout << dist[i] << endl;
        }
    }
}
