#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
typedef long long ll;

static const int MAX = 100;
static const ll INF = 1LL << 32;
ll dist[MAX][MAX];
int n;

void floyd(){
  rep(k,n){
    rep(i,n){
      if(dist[i][k] == INF) continue;
      rep(j,n){
        if(dist[k][j] == INF) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}


int main(){

  int edge, u,v, c;
  cin >> n >> edge;
  rep(i,n){
    rep(j,n){
      dist[i][j] = ((i==j)? 0:INF);
    }
  }
  rep(i,edge){
    cin >> u >> v >> c;
    dist[u][v] = c;
  }

  floyd();

  bool isNegative = false;
  rep(i,n) if(dist[i][i] < 0) isNegative= true;

  if(isNegative){
    cout << "NEGATIVE CYCLE" << endl;
  }else{
    rep(i,n){
      rep(j,n){
        if(j) cout << " ";
        if(dist[i][j] == INF) cout << "INF";
        else cout << dist[i][j];
      }
      cout << endl;
    }
  }


  return 0;
}
