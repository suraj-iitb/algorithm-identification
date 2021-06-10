//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=1e9;
const ll INF=1e18;
typedef pair<int,int> P;
vector<P> G[/*ここにノードの値+5を入れる*/100005];
vector<ll> dis;
/*呼び出しはmain関数内でdijkstra(始点)*/
void dijkstra (int start){
  priority_queue<P,vector<P>,greater<P>> q;
  dis=vector<ll>(/*ここにノードの値+5を入れる*/100005,INF);
  dis[start]=0;
  q.push(P(start,0));
  while(!q.empty()){
    P now=q.top();q.pop();
    int nowv=now.first;
    if(dis[nowv]<now.second)continue;
    for(P next:G[nowv]){
      if(dis[next.first]>dis[nowv]+next.second){
        dis[next.first]=dis[nowv]+next.second;
        q.push(P(next.first,dis[next.first]));
      }
    }
  }
}
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll v,e,r,s,t,d;
  cin >> v >> e >> r;
  for(int i=0; i<e; i++) {
    cin >> s >> t >> d;
    G[s].push_back(P(t,d));
  }
  dijkstra(r);
  for(int i=0; i<v; i++) {
    if(dis[i]==INF) {
      cout << "INF" << "\n";
    }
    else {
      cout << dis[i] << "\n";
    }
  }
}
