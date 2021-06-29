#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;
#define ll long long

const ll INF = 7+(1e+10);
typedef ll Weight;
struct Edge {  //src:辺の始点,dst:辺の終点,weight:辺の重さ
  ll src, dst;
  Weight weight;
  Edge(ll src, ll dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : //辺は重さが重いものを"小さい"と定義する
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

//引数 Graph:隣接リスト,dist:各頂点から各頂点までの距離が入る,inter:最短路木の親頂点が入る
//戻値 負閉路が存在しない場合:true,そうでないとき:false
bool shortestPath(const Graph &g,vector<vector<Weight> > &dist,vector<vector<ll> > &inter) {
  ll n = g.size();
  dist.assign(n,vector<Weight>(n,INF));
  for(ll i=0;i<n;i++){
    dist[i][i]=0;
  }
  for(ll i=0;i<n;i++){
    for(auto f=g[i].begin();f!=g[i].end();f++){
      dist[i][f->dst]=f->weight;
    }
  }
  inter.assign(n, vector<ll>(n,-1));
  for(ll k=0;k<n;k++){
    for(ll i=0;i<n;i++){
      for(ll j=0;j<n;j++){
        if(dist[i][k]<INF && dist[k][j]<INF && dist[i][j]>dist[i][k]+dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
          inter[i][j] = k;
        }
      }
    }
  }
  for(ll i=0;i<n;i++){
    if(dist[i][i]<0){
      return false;
    }
  }
  return true;
}
void buildPath(const vector<vector<ll> > &inter,ll s,ll t,vector<ll> &path) {
  ll u = inter[s][t];
  if (u < 0) path.push_back(s);
  else buildPath(inter, s, u, path), buildPath(inter, u, t, path);
}
vector<ll> buildPath(const vector<vector<ll> > &inter,ll s,ll t) {
  vector<ll> path;
  buildPath(inter, s, t, path);
  path.push_back(t);
  return path;
}


int main(){
  ll v,e;
  cin>>v>>e;
  Graph g(v);
  ll s,t,d;
  for(ll i=0;i<e;i++){
    cin>>s>>t>>d;
    g[s].push_back(Edge(s,t,d));
  }
  vector<vector<Weight> >dist;
  vector<vector<ll> > inter;
  bool ans=shortestPath(g,dist,inter);
  if(!ans){
    cout<<"NEGATIVE CYCLE"<<endl;
    return 0;
  }
  for(ll i=0;i<v;i++){
    if(dist[i][0]>=INF)cout<<"INF";
    else cout<<dist[i][0];
    for(ll j=1;j<v;j++){
      if(dist[i][j]>=INF)cout<<" "<<"INF";
      else cout<<" "<<dist[i][j];
    }
    cout<<endl;
  }
}

