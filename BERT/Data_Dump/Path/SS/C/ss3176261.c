#include <bits/stdc++.h>
//#include<iostream>
using namespace std;
#define int long long

#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007,INF=1e18;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
struct edge{
    int to,cost;
    edge(int to,int cost):to(to),cost(cost){}
};
vector <edge> tree[100010];
ll dist[100010];

int V,E,r;

void dijkstra(int s){
    priority_queue<pint,vpint,greater<pint>> que;
    fill(dist,dist+V,INF);
    dist[s]=0;
    que.push(pint(0,s));
    
    while(!que.empty()){
        pint p=que.top();
        que.pop();
        int v=p.se;
        if(dist[v]<p.fi)continue;
        rep(i,0,tree[v].size()){
            edge e=tree[v][i];
            if(dist[e.to]>dist[v]+e.cost){
                dist[e.to]=dist[v]+e.cost;
                que.push(pint(dist[e.to],e.to));
            }
        }
    }
}


signed main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin>>V>>E>>r;
    rep(i,0,E){
        int a,b,c;
        cin>>a>>b>>c;
        tree[a].pb(edge(b,c));
    }
    dijkstra(r);
    
    rep(i,0,V){
        if(dist[i]==INF)cout<<"INF"<<endl;
        else cout<<dist[i]<<endl;
    }
    
    return 0;
}
