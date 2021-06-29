#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////

struct edge{ ll to,cost; };
ll V;
vector<edge> G[500010];
ll d[500010];

void dijkstra(ll s){
    fill(d,d+500010,inf);
    d[s]=0;
    priority_queue<l_l,vector<l_l>,greater<l_l>> que;
    que.push(l_l(0,s));
    
    while(!que.empty()){
        l_l p=que.top();que.pop();
        ll v=p.second;
        if(d[v]<p.first)continue;
        if(G[v].size()>0){
            rep(i,0,G[v].size()-1){
                edge e=G[v][i];
                if(d[e.to]>d[v]+e.cost){
                    d[e.to]=d[v]+e.cost;
                    que.push(l_l(d[e.to],e.to));
                }
            }
        }
    }
    
}


int main(){
    ll n;cin>>n;
    ll m;cin>>m;
    ll r;cin>>r;
    
    ll a[m],b[m],c[m];
    V=m;
    if(m>0){
        rep(i,1,m){
            cin>>a[i]>>b[i]>>c[i];
            edge e;
            e.to=b[i];e.cost=c[i];
            G[a[i]].pb(e);
        }
    }
    dijkstra(r);
    rep(i,0,n-1){
        if(d[i]==inf)cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
    
    return 0;
}

