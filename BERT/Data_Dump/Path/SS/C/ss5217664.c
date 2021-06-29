#include <bits/stdc++.h>
using namespace std;

const long long INF=1LL<<60;

struct Edge{
    int to;
    long long w;
    Edge(int to,long long w):to(to),w(w){}
};

using Graph=vector<vector<Edge>>;

template<class T> bool chmin(T& a,T b){
    if(a>b){
        a=b;
        return true;
    }else{
        return false;
    }
}

int main(){
    int n,e,r;
    cin>>n>>e>>r;

    Graph G(n);
    for(int i=0;i<e;i++){
        int s,t,d;
        cin>>s>>t>>d;
        G[s].push_back(Edge(t,d));
    }

    vector<long long> dist(n,INF);
    dist[r]=0;

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> que;
    que.push(make_pair(dist[r],r));

    while(!que.empty()){
        int v=que.top().second;
        long long d=que.top().first;
        que.pop();

        if(dist[v]<d)continue;

        for(auto e:G[v]){
            if(chmin(dist[e.to],dist[v]+e.w)){
                que.push(make_pair(dist[e.to],e.to));
            }
        }
    }

    for(int i=0;i<n;i++){
        if(dist[i]<INF)cout<<dist[i]<<endl;
        else cout<<"INF"<<endl;
    }
 
    return 0;
}
