#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define rep(i,n) fore(i,0,(n)-1)
#define rfore(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);--i)
#define rrep(i,n) rfore(i,0,(n)-1)
#define all(x) (x).begin(),(x).end()
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

#define N 100005
vp g[N];
void solve(){
    ll v,e,r;cin>>v>>e>>r;
    rep(i,e){
        ll s,t,d;cin>>s>>t>>d;
        g[s].push_back(pl(t,d));
    }
    vl dist(v,LINF);
    dist[r]=0;
    priority_queue<pl,vp,greater<pl> > que;
    que.push(pl(0,r));
    while(!que.empty()){
        pl p1=que.top();que.pop();
        ll d=p1.first,s=p1.second;
        if(dist[s]<d)continue;
        dist[s]=d;
        rep(i,g[s].size()){
            ll t=g[s][i].first,d2=g[s][i].second;
            if(dist[t]<=d+d2)continue;
            dist[t]=d+d2;
            que.push(pl(d+d2,t));
        }
    }
    rep(i,v){
        if(dist[i]==LINF)cout<<"INF"<<endl;
        else cout<<dist[i]<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}

