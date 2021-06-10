#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

typedef pair<int,int> pint;
struct edge{int to,cost;};
const int INF=1e18;

vector<int> dijkstra(vector<vector<edge>> &G,int s)
{
    int N=G.size();
    vector<int> dist(N,INF);
    dist[s]=0;
    priority_queue<pint,vector<pint>,greater<pint>> Q;
    Q.push({0,s});

    vector<bool> finished(N);
    while(!Q.empty()){
        int v=Q.top().second; 
        Q.pop();
        if(finished[v]) continue;
        finished[v]=true;
        for(edge e:G[v]){
            if(chmin(dist[e.to],dist[v]+e.cost)){
                Q.push({dist[e.to],e.to});
            }
        }
    }
    return dist;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,M,s; cin>>N>>M>>s;
    vector<vector<edge>> G(N);
    for(int i=0;i<M;i++){
        int a,b,c; cin>>a>>b>>c;
        G[a].push_back({b,c});
    }
    vector<int> dist=dijkstra(G,s);
    for(int i=0;i<N;i++){
        if(dist[i]==INF) cout<<"INF"<<endl;
        else cout<<dist[i]<<endl;
    }
    return 0;
}
