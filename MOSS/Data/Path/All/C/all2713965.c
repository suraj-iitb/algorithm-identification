#include <iostream>
#include <climits>
#include <algorithm>
#define INF (LLONG_MAX>>5)
using namespace std;

int main(){
  int v, e; cin >> v >> e;

  //配列でグラフを表現。配列の初期化
  long long int graph[v][v];
  for(int i=0; i<v; i++){
    for(int j=0; j<v; j++){
      if(i==j) graph[i][j]=0;
      else graph[i][j]=INF;
    }
  }

  int from, to; long long int weight;
  for(int i=0; i<e; i++){
    cin >> from >> to >> weight;
    graph[from][to]=weight;
  }

  for(int k=0; k<v; k++){
    for(int i=0; i<v; i++){
      for(int j=0; j<v; j++){
        graph[i][j] = min(graph[i][k]+graph[k][j], graph[i][j]);
      }
    }
  }

  bool flag=false;
  for(int i=0; i<v; i++) if(graph[i][i]<0) flag=true;

  if(flag) cout << "NEGATIVE CYCLE" << endl;
  if(!flag){
    for(int i=0; i<v; i++){
      for(int j=0; j<v; j++){
        if(graph[i][j]>=(INF>>5)) cout << "INF";
        else cout << graph[i][j];
        if(j!=v-1) cout << " ";
      }
      cout << endl;
    }
  }


  return 0;
}

