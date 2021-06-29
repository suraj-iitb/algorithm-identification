#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1LL<<60;
struct Edge{
    int to;
    ll w;
    Edge(int to,ll w):to(to),w(w){}
};
using Graph=vector<vector<Edge>>;

template<class T> bool chmin(T&a,T b){
    if(a>b){
        a=b;
        return true;
    }
    else return false;
}

void dijkstra(const Graph &G,vector<ll> &dist,int s){
    dist[s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
    que.push(make_pair(dist[s],s));
    while(!que.empty()){
        int v=que.top().second;
        ll d=que.top().first;
        que.pop();
        if(d>dist[v]) continue;
        for(auto e:G[v]){
            if(chmin(dist[e.to],dist[v]+e.w)){
                que.push(make_pair(dist[e.to],e.to));
            }
        }
    }
}

int main(){
    int V,E,r;
    cin>>V>>E>>r;
    Graph G(V);
    for(int i=0;i<E;i++){
        int s,t;
        ll d;
        cin>>s>>t>>d;
        G[s].push_back(Edge(t,d));
    }
    vector<ll> dist(V,INF);
    dijkstra(G,dist,r);
    for(int i=0;i<V;i++){
        if(dist[i]==INF) cout<<"INF"<<endl;
        else cout<<dist[i]<<endl;
    }
    return 0;
}
