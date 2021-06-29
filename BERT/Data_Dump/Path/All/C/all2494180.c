#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define INF 100000000000000000
using namespace std;

typedef vector<vector<ll> > graph;
graph dist;
int flag = 1;

void warshall_floyd(int n){
  for(int i = 0; i < n; i++){ //?????±????????????
    for(int j = 0; j < n; j++){ //????§???????
      for(int k = 0; k < n; k++){ //??????
        if(dist[j][i] != INF && dist[i][k] != INF) dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
      if(dist[j][j] < 0) flag = 0; //dist[j][j]?????? = ?????????????????????
    }
  }
}

int main(){

  int v, e;
  cin >> v >> e;
  dist = graph(v, vector<ll>(v, INF));
  for(int i = 0; i < v; i++) dist[i][i] = 0;

  int from, to;
  ll cost;
  for(int i = 0; i < e; i++){
    cin >> from >> to >> cost;
    dist[from][to] = cost;
  }
  warshall_floyd(v);
  if(flag){
    for(int i = 0; i < v; i++){
      for(int j = 0; j < v; j++){
        if(dist[i][j] == INF) cout << "INF" << ((j == v-1) ? "\n" : " ");
        else cout << dist[i][j] << ((j == v-1) ? "\n" : " ");
      }
    }
  }else{
    cout << "NEGATIVE CYCLE" << endl;
  }
  return 0;
}
