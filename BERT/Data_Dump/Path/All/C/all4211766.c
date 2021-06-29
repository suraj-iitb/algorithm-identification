#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e16;
 
int main(){ 
  int V, E;
  cin >> V >> E;

  vector<vector<int64_t>> dist(110, vector<int64_t>(110, INF));
  for(int i=0; i<V; i++) dist[i][i] = 0;

  for(int i=0; i<E; i++){
    int s, t, d; cin >> s >> t >> d;
    dist[s][t] = d;
  }

  for(int k=0; k<V; k++){
    for(int i=0; i<V; i++){
      for(int j=0; j<V; j++){
        if(dist[i][k] != INF && dist[k][j] != INF){
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  for(int i=0; i<V; i++){
    if(dist[i][i] < 0){
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  for(int i=0; i<V; i++){
    for(int j=0; j<V; j++){
      if(dist[i][j] == INF) cout << "INF";
      else cout << dist[i][j];
      if(j != V-1) cout << " ";
    }
    cout << endl;
  }
}
