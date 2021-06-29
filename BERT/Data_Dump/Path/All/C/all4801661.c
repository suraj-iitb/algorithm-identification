#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

long long INF = 100000000000000000;

int main(){
  int V, E;
  cin >> V >> E;
  vector<vector<int> > G(V);
  long long dist[V][V];
  //頂点iからiへの距離は0で初期化
  //それ以外はINFで初期化
  rep(i, V)
    rep(j, V){
    if(i == j)
      dist[i][j] = 0;
    else
      dist[i][j] = INF;
  }
  //グラフ作成
  int s, t;
  rep(i, E){
    cin >> s >> t;
    G[s].push_back(t);
    cin >> dist[s][t];
  }
  //入力終了 (グラフ作成，距離初期化)

  //warshal floyd
  rep(k, V){
    rep(i, V){
      rep(j, V){
	//経路の途中にINFがあればスキップ
	if(dist[i][k] == INF || dist[k][j] == INF)
	  continue;
	//INFがなければ最短距離の更新
	else
	  dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j] );
      }
    }
  }
  
  //負の閉路の検出
  //
  rep(i, V){
    if(dist[i][i] < 0){
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  
  rep(i, V){
    rep(j, V){
      if(dist[i][j] == INF)
	cout << "INF" ;
      else
	cout << dist[i][j] ;
      if(j<V-1)
	cout << " ";
    }
    cout << endl;
  }

  return 0;
}
