#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;
const long double PI=3.14159265358979;

vector<ll> Dijkstra(vector<vector<pair<ll,ll>>> x,ll y){
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
  pair<ll,ll> p={0,y};
  q.push(p);
  vector<ll> ans(x.size(),MOD);
  while(!q.empty()){
    pair<ll,ll> fe=q.top();
    q.pop();
   // cout<<fe.first<<" "<<fe.second<<endl;
    if(fe.first>ans[fe.second]){
      continue;
    }
    ans[fe.second]=fe.first;
    for(int i=0;i<x[fe.second].size();i++){
      pair<ll,ll> le=x[fe.second][i];
      if(fe.first+le.first<ans[le.second]){
        ans[le.second]=fe.first+le.first;
        le.first=ans[le.second];
        q.push(le);
      }
    }
  }
  return ans;
}

  


int main() {
  ll V,E,r;
  cin>>V>>E>>r;
  vector<vector<pair<ll,ll>>> G(V,vector<pair<ll,ll>>(0));
  for(int i=0;i<E;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    pair<ll,ll> P={c,b};
    G[a].push_back(P);
  }
  vector<ll> ans=Dijkstra(G,r);
  for(int i=0;i<ans.size();i++){
    if(ans[i]==MOD){
      cout<<"INF"<<endl;
      continue;
    }
    cout<<ans[i]<<endl;
  }
 // cout<<G[2][0].second;
}
