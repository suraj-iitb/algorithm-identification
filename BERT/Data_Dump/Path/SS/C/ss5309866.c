#include <bits/stdc++.h>
using namespace std;

long long INF = 10000000000000;

struct Edge{
    int to;
    int cost;
};



int main(){
    int V,E,r;
    cin >> V >> E >> r;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector< vector< Edge > > G(V);
    for(int i=0;i<E;i++){
        int s,t,d;
        cin >> s >> t >> d;
        Edge e;
        e.to = t;
        e.cost = d;
        G[s].push_back(e);
    }
    /*
    for(int i=0;i<V;i++){
        cout << i << " : ";
        for(int j=0;j<G[i].size();j++){
            cout << '<' << G[i][j].to << ' ' << G[i][j].cost << "> ";
        }
        cout << endl;
    }
    */
    long long dist[100100];
    for(int i=0;i<100100;i++){
        dist[i]=INF;
    }
    dist[r] = 0;
    pq.push(make_pair(dist[r],r));
    while(!pq.empty()){
        int v = pq.top().second;
        int v_dist = pq.top().first;
        pq.pop();
        for(int i=0;i<G[v].size();i++){
            int next_v = G[v][i].to;
            int next_v_cost = G[v][i].cost;
            if(dist[next_v]<=dist[v]+next_v_cost){
                continue;
            }
            dist[next_v]=dist[v]+next_v_cost;
            pq.push(make_pair(dist[next_v],next_v));
        }
    }
    for(int i=0;i<V;i++){
        if(dist[i]==INF){
            cout << "INF" << endl;
            continue;
        }
        cout << dist[i] << endl;
    }
}
