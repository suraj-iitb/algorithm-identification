#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;
using P = pair<ll, ll>;
using Graph = vector<vector<P>>;
const ll INF = 1LL<<60;

ll V, E, r;
Graph G;
vector<ll> dist;

void dijkstra(){
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, r)); // 最短距離, ノード番号
  while(!que.empty()){
    P now = que.top();
    que.pop();
    ll nowDist = now.first;
    ll nowNode = now.second;
    if (nowDist > dist[nowNode]) continue;
    for(P next : G[nowNode]){
      ll nextDir = next.first;
      ll nextWeight = next.second;
      if (dist[nextDir] <= dist[nowNode] + nextWeight) continue;
      dist[nextDir] = dist[nowNode] + nextWeight;
      que.push({dist[nextDir], nextDir});
    }
  }
}

int main(){
  cin >> V >> E >> r;
  G.resize(V);
  ll s, t, d;
  rep(i, E){
    cin >> s >> t >> d;
    G[s].push_back(P(t, d));
  }
  dist.resize(V, INF);
  dist[r] = 0;
  dijkstra();

  for(ll x : dist){
    if (x == INF)
      cout << "INF" << endl;
    else
      cout << x << endl;
  }
  
  return 0;
}
