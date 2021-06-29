#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct edge{
  ll to;
  ll cost;
  edge(ll t,ll w) : to(t),cost(w){}
};
int main(){
  const ll INF=100000000000;
  ll i,j,n,q,r;
  cin >> n >> q >> r;
  vector<vector<edge> > g(n);
  for(i=0;i<q;i++){
    ll s,t,d;
    cin >> s >> t >> d;
    g[s].push_back(edge(t,d));
  }
  vector<ll> ds(n,INF),ns(n,0);
  priority_queue<P,vector<P>,greater<P> > que;
  ds[r]=0,ns[r]=1;
  que.push(P(0,r));
  while(!que.empty()){
    // もしゴールが明確に決められているときは、
    // if(ns[c]==1){
    //   break;
    // }
    //
    P p=que.top();
    que.pop();
    ll v=p.second;
    if(ds[v]!=p.first){
      continue;
    }
    for(i=0;i<g[v].size();i++){
      edge us=g[v][i];
      if(ds[us.to]>ds[v]+us.cost && ns[us.to]==0){
        ds[us.to]=ds[v]+us.cost;
        que.push(P(ds[us.to],us.to));
      }
    }
    ns[v]=1;
  }
  for(i=0;i<n;i++){
    if(ds[i]==INF){
      cout << "INF" << endl;
    }
    else{
      cout << ds[i] << endl;
    }
  }
}
