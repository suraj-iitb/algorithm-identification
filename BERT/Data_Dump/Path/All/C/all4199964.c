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

void solve(){
    ll v,e;cin>>v>>e;
    vvl d(v,vl(v,LINF));
    rep(i,v)d[i][i]=0;
    rep(i,e){
        ll s,t,dd;cin>>s>>t>>dd;
        d[s][t]=dd;
    }
    rep(i,v)rep(j,v)rep(k,v){
        chmin(d[j][k],d[j][i]+d[i][k]);
    }
    rep(i,v){
        if(d[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return;
        }
    }
    rep(i,v){
        rep(j,v){
            if(j>0)cout<<" ";
            if(d[i][j]>=LINF/2)cout<<"INF";
            else cout<<d[i][j];
        }
        cout<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}

