#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
#define INF 1e18
using namespace std;

//-----------------------------------------------------------------------

typedef pair<int,int> pii;
struct edge{int to,cost;};

vector<int> dijkstra(vector<vector<edge> >& G,int s)
{
    int N=G.size();
    vector<int> dist(N,INF); dist[s]=0;
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    Q.push(pii(0,s));

    while(!Q.empty())
    {
	int d=Q.top().first;
	int v=Q.top().second;
	Q.pop();

	if(d>dist[v]) continue;
	for(auto e:G[v]){
	    if(dist[e.to]>d+e.cost){
		dist[e.to]=d+e.cost;
		Q.push(pii(dist[e.to],e.to));
	    }
	}
    }
    return dist;

}

signed main()
{
    int N,M,s; cin>>N>>M>>s;
    vector<vector<edge> > G(N);
    REP(i,M){
	int a,b,c; cin>>a>>b>>c;
	G[a].push_back((edge){b,c});
    }

    vector<int> dist=dijkstra(G,s);
    REP(i,N){
	if(dist[i]==INF) cout<<"INF"<<endl;
	else cout<<dist[i]<<endl;
    }
    
}

