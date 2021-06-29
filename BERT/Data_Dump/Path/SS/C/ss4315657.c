// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
#define MAX_V 2000000
#define INF 10000000000
ll d[MAX_V];
struct edge{ll to,cost;};
vector<edge> G[MAX_V];
void dij(ll s){
  priority_queue<P,vector<P>,greater<P>> que;
  fill(d,d+MAX_V,INF);
  d[s]=0;
  que.push(make_pair(0,s));
  while(!que.empty()){
    P p=que.top();
    que.pop();
    ll v=p.second;
    if(d[v]<p.first) continue;
    for(ll i=0;i<G[v].size();i++){
      edge e=G[v][i];
      if(d[e.to]>d[v]+e.cost){
        d[e.to]=d[v]+e.cost;  
        que.push(make_pair(d[e.to],e.to));
      }
    }
  }
}
signed main(){
  init_io();
  ll v,e,r;
  cin >> v >> e >> r;
  ll s,t,di;
  for(int i=0;i<e;i++){
    cin >> s >> t >> di;
    G[s].push_back({t,di});
  }
  dij(r);
  for(int i=0;i<v;i++){
    if(d[i] == INF) cout <<"INF\n";
    else cout <<d[i]<<endl;
  }
}

