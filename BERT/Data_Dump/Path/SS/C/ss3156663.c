#include <bits/stdc++.h>
using namespace std;
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define debug(x) cerr<<#x<<':'<<x<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto x:v)cerr<<x<<' ';cerr<<endl;
#define INF 1000000007
#define LINF 1000000000000000007
#define EPS 1e-9
typedef long long ll;

vector<long long> Dijkstra(long long start,vector<vector<pair<long long,long long>>> adj){
  long long V = adj.size();
  vector<long long> dmin(V,-1);
  priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pque;
  pque.push(make_pair(0,start));
  pair<long long,long long> p;
  while(pque.size()){
    p = pque.top();
    pque.pop();
    if(dmin[p.second] == -1){
      dmin[p.second] = p.first;
      for(auto x:adj[p.second]){
        if(dmin[x.first] == -1)pque.push(make_pair(dmin[p.second]+x.second,x.first));
      }
    }
  }
  return dmin;
}

signed main(){
  long long V,E,r,s,t,d;
  scanf("%lld %lld %lld",&V,&E,&r);
  vector<vector<pair<ll,ll>>> adj(V);
  FOR(i,0,E){
    scanf("%lld %lld %lld",&s,&t,&d);
    adj[s].pb(make_pair(t,d));
  }
  vector<ll> dmin = Dijkstra(r,adj);
  FOR(i,0,V)
  if(dmin[i] != -1){
    printf("%lld\n",dmin[i]);
  }
  else{
    printf("INF\n");
  }
}
