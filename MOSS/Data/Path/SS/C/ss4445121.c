//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

struct edge{int to,cost;};

vector<ll> dijkstra(int n,vector<vector<edge> > G,int s){
  priority_queue<pii,vector<pii>,greater<pii> > que;
  vector<ll> dist(n,inf);
  dist[s]=0;
  que.push(pii(0,s));
  while(!que.empty()){
    int c,v;
    tie(c,v)=que.top();
    que.pop();
    if(dist[v]<c) continue;
    for(int i=0;i<G[v].size();i++){
      edge e=G[v][i];
      int nc=e.cost;
      int nv=e.to;
      if(dist[nv]>dist[v]+nc){
        dist[nv]=dist[v]+nc;
        que.push(pii(dist[nv],nv));
      }
    }
  }
  return dist;
}

int main(){
  int n,m,s; cin >> n >> m >> s;
  vector<vector<edge> > G(n,vector<edge>(0));
  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    G[a].push_back({b,c});
  }
  vector<ll> dist=dijkstra(n,G,s);
  rep(i,n){
    if(dist[i]!=inf) cout << dist[i] << endl;
    else cout << "INF" << endl;
  }
  
}
