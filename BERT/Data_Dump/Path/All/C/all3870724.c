#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll,ll> P;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin() , v.end()
#define inputv(v,n) rep(i,n){\
    ll x;\
    cin>>x;\
    v.push_back(x);\
    }
const ll INF=99999999999999;
const ll MOD=1000000007;
ll c,d,e,f,p,t,ans=0;
 
 
ll n,m,r;
vector<P> gragh[3000];
vl A,B,C;
vector<vl> cost(100,vl(100,INF));
 
void input(void){
    cin>>n>>m;
    rep(i,m){
        cin>>c>>d>>e;
        gragh[c].push_back(make_pair(d,e));
    }
}
 
ll solve(void){
    rep(r,n){
    cost[r][r]=0;
    vl renewed(3000,0);
    rep(k,n){
    rep(i,n){
        rep(j,gragh[i].size()){
            cost[r][gragh[i][j].first]=min(cost[r][i]+gragh[i][j].second,cost[r][gragh[i][j].first]);
        }
    }
    }
 
    rep(i,n){
        rep(j,gragh[i].size()){
            if(cost[r][i]+gragh[i][j].second<cost[r][gragh[i][j].first]&&cost[r][i]+gragh[i][j].second<INF/2){
                cout<<"NEGATIVE CYCLE"<<endl;
                return 0;
            }
        }
    }
    }
 
    rep(i,n){
        rep(j,n){
    	if(cost[i][j]>INF/2)cout<<"INF";
        else cout<<cost[i][j];
        if(j!=n-1)cout<<" ";
        else cout<<endl;
        }
    }
    return 0;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    solve();
}
