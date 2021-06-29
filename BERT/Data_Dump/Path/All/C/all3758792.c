#include<iostream>
#include<climits>
using namespace std;
#define MAX 100
static const long long INF = (1LL << 32);
int v, e;
long long dp[MAX][MAX];

void floyd(){
  for ( int k = 0; k < v; k++){
    for ( int i = 0; i < v; i++){
      if ( dp[i][k] == INF) continue;
      for ( int j = 0; j < v; j++){
        if ( dp[k][j] == INF) continue;
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
}

int main(){
  cin >> v >> e;
  int s, t, d;
  //init
  for ( int i = 0; i < v; i++){
    for ( int j = 0; j < v; j++){
      dp[i][j] = ((i == j) ? 0 : INF);
    }
  }

  for ( int i = 0; i < e; i++){
    cin >> s >> t >> d;
    dp[s][t] = d;
  }

  floyd();

  for ( int i = 0; i < v; i++){
    if ( dp[i][i] < 0){
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  for ( int i = 0; i < v; i++){
    for ( int j = 0; j < v; j++){
      if ( j ) cout << " ";
      if ( dp[i][j] == INF) cout  << "INF";
      else cout  << dp[i][j];
    }
    cout << endl;
  }

  return 0;
}
