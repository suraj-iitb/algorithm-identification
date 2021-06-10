#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

const int MAX_V=100000;
const int INF=1e18;
struct edge{ int to,cost; };

int V,E,dist[MAX_V];
vector<edge> G[MAX_V];

void dijkstra(int s)
{
    REP(i,V) dist[i]=INF; 
    dist[s]=0;
    priority_queue<pint,vector<pint>,greater<pint>> Q;
    Q.push(pint(0,s));

    while(!Q.empty()){
        pint p=Q.top(); Q.pop();
        int v=p.second;
        if(p.first>dist[v]) continue;
        for(edge e:G[v]){
            if(dist[e.to]>dist[v]+e.cost){
                dist[e.to]=dist[v]+e.cost;
                Q.push(pint(dist[e.to],e.to));
            }
        }
    }
}

signed main()
{   
    int r; cin>>V>>E>>r;
    REP(i,E){
        int a,b,c; cin>>a>>b>>c;
        G[a].push_back((edge){b,c});
    }
    dijkstra(r);
    REP(i,V){
        if(dist[i]==INF) cout<<"INF"<<endl;
        else cout<<dist[i]<<endl;
    }
}
