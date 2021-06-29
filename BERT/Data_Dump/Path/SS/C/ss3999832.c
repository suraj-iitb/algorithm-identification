#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
typedef long long ll;
typedef pair<int64_t,int64_t> pll;
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,-1,-1,1};
#define INF (2147483647)
#define mod (1000000007)
#define limit (7368791)
#define rep(i,a,b) for (int64_t i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define ALL(a) begin(a),end(a)
#define sz(s) (s).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define MAXV 100010

int V,E,r;
vector<vector<pll>> G(MAXV);
vector<int> l(MAXV,INF);

void dijsktra(){
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    l[r]=0;pq.push(mp(0,r));
    while(!pq.empty()){
        int c=pq.top().fi,v=pq.top().se;
        pq.pop();
        if(l[v]<c)continue;
        REP(i,G[v].size()){
            int to=G[v][i].fi,cost=G[v][i].se;
            if(l[to]>l[v]+cost){
                l[to]=l[v]+cost;
                pq.push(mp(l[to],to));
            }
        }
    }
}

void solve()
{
    cin>>V>>E>>r;
    REP(i,E){
        int x,y,d;cin>>x>>y>>d;
        G[x].pb(mp(y,d));
    }
    dijsktra();
    REP(i,V){if(l[i]>=INF)cout<<"INF"<<endl;else cout<<l[i]<<endl;}
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}

