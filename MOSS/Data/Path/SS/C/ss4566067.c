#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

int main(){
  ll v,e,r;cin>>v>>e>>r;
  vector<vp> g(v);vll dis(v,MOD);
  rep(i,0,e){
    ll s,t,d;cin>>s>>t>>d;
    g[s].push_back(make_pair(t,d));
  }
  priority_queue<P,vector<P>,greater<P> > pq;
  dis[r]=0;
  pq.push(make_pair(dis[r],r));
  while(!pq.empty()){
    P p=pq.top();
    pq.pop();
    ll from=p.second;
    if(dis[from]<p.first)continue;
    for(auto &edge:g[from]){
      if(dis[edge.first]>dis[from]+edge.second){
        dis[edge.first]=dis[from]+edge.second;
        pq.push(make_pair(dis[edge.first],edge.first));
      }
    }
  }
  rep(i,0,v){
    if(dis[i]!=MOD){ out(dis[i]);}
    else{out("INF");}
  }
}


