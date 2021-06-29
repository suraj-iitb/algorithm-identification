#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
const int INF = 1e16;
//using Graph = vector<vector<int>>;

void dijkstra( vector<vector<pair<int, int>>> &G, int s, vector<int> &dist ){ //スタート地点を指定
  //コスト、向かう頂点でpair(コストが小さい順に並ぶ)
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  dist.at(s) = 0;
  que.push(make_pair(0, s));
  while( !que.empty() ){
    pair<int, int> P = que.top();
    que.pop();
    int v = P.second;
    if( dist.at(v) < P.first ) continue;
    for( auto &next : G.at(v) ){
      if( dist.at(next.first) > dist.at(v) + next.second ){
        dist.at(next.first) = dist.at(v) + next.second;
        que.push({dist.at(next.first), next.first});
      }
    }
  }
}

signed main(){
  int V, E, r;
  cin >> V >> E >> r;

  //向かう先の頂点番号、コスト
  vector<vector<pair<int, int>>> G(V);
  vector<int> dist(V, INF);
  for( int i = 0; i < E; i++ ){
    int S, T, D;
    cin >> S >> T >> D;
    G.at(S).push_back({T,D});
  }
  dijkstra(G, r, dist);

  for( int i = 0; i < V; i++ ){
    if( dist.at(i) == INF ) cout << "INF" << endl;
    else cout << dist.at(i) << endl;
  }

 }

