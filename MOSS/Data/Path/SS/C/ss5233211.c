#include <bits/stdc++.h>
using namespace std;
#define rep(i,k,n) for(int i=k;i<n;i++)
#define INF INT_MAX
#define P pair<int, int>

struct edge{
    int to;
    int cost;
};

int main(){
    int v,e,r;
    cin>>v>>e>>r;
    vector< vector<edge> > G(v);
    rep(i,0,e){
        int s,t,d;
        cin>>s>>t>>d;
        edge tmp;
        tmp.to = t; tmp.cost = d;
        G[s].push_back(tmp);
    }

    vector<int> dis(v,INF);
    vector<bool> visited(v,false);
    dis[r] = 0;

    priority_queue< P, vector<P>, greater<P> > pq;
    pq.push(make_pair(dis[r],r));

    while(!pq.empty()){
        P tmp = pq.top(); pq.pop();
        int cur = tmp.second; 
        if(dis[cur]<tmp.first) continue;
        visited[cur] = true;
        rep(i,0,G[cur].size()){
            if(dis[G[cur][i].to]>dis[cur]+G[cur][i].cost){
                dis[G[cur][i].to] = dis[cur]+G[cur][i].cost;
                pq.push(make_pair(dis[G[cur][i].to],G[cur][i].to));
            }
        }
    }


    rep(i,0,v){
        if(dis[i]==INF) cout<<"INF"<<endl;
        else cout<<dis[i]<<endl;
    }
    return 0;
}
