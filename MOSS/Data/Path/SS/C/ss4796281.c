#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
const int MAX=100001;
const ll INF=1LL<<60;
vector<pair<int,ll>>S[MAX];
ll dis[MAX];
int v;
void dijkstra(int u){
  priority_queue<pair<int,ll>>p;
  rep(i,v)dis[i]=INF;
  dis[u]=0;
  p.push(make_pair(u,0));
  while(!p.empty()){
    int a=p.top().first;
    ll b=p.top().second;
    p.pop();
    if(dis[a]<-b)continue;
    rep(i,S[a].size()){
      int c=S[a][i].first;
      ll d=S[a][i].second;
      if(dis[c]>dis[a]+d){
        dis[c]=dis[a]+d;
        p.push(make_pair(c,-dis[c]));
      }
    }
  }
}
int main(){
  int e,r;
  cin>>v>>e>>r;
  rep(i,e){
    int a,b;
    ll c;
    cin>>a>>b>>c;
    S[a].push_back(make_pair(b,c));
  }
  dijkstra(r);
  rep(i,v){
    if(dis[i]==INF)cout<<"INF"<<endl;
    else cout<<dis[i]<<endl;
  }
}
