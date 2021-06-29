#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = (2e9);
int main(){
  int V, E;
  cin >> V >> E;
  vector< vector<int> > D(V,vector<int>(V,INF));
  for(int i = 0; i < E; ++i){
    int s, t, d;
    cin >> s >> t >> d;
    D[s][t] = d;
  }
  for(int i = 0; i < V; ++i) D[i][i] = 0;
  for(int k = 0; k < V; ++k)
    for(int i = 0; i < V; ++i)
      for(int j = 0; j < V; ++j)
        if(D[i][k] != INF && D[k][j] != INF)
          D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
  for(int i = 0; i < V; ++i){
    if(D[i][i] < 0){
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  for(int i = 0; i < V; ++i){
    for(int j = 0; j < V; ++j){
      if(D[i][j] < INF) cout << D[i][j];
      else cout << "INF";
      if(j < V-1) cout << " ";
      else cout << endl;
    }
  }
  return 0;
}

