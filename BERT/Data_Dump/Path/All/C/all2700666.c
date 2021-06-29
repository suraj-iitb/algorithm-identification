#include <iostream>
#include <cstdio>
#define INF (1ll << 32)
#define int64 long long 
using namespace std;

long long dp[105][105];

void pre (int size) {
  for ( int i = 0 ;i < size; i++) {
    for ( int j = 0;j < size; j++) {
      dp[i][j] = ((i == j) ? 0 : INF );
    }
  }
}

main()
{
  int v, e;
  int s, t, d;
  int p = 0;

  scanf("%d %d", &v, &e);
  pre(v);
  for ( int i = 0; i < e; i++) {
    scanf("%d %d %d", &s, &t, &d);
    dp[s][t] = d;
  }

  // Warshall_Floyd
  for ( int i = 0; i < v ; i++) {
    for ( int j = 0; j < v ; j++) {
      for ( int k = 0; k < v ; k++) {
	if ( dp[j][i] != INF && dp[i][k] != INF ) {
	  dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
	}
      }
    }
  }
  // Warshall_Floyd

  for (int i = 0; i < v; i++) {
    if ( dp[i][i] < 0 ) {
      p = 1;
    }
  }

  if (p) {
    cout << "NEGATIVE CYCLE" << endl;
  } else { 
  
    for ( int i = 0; i < v; i++) {
      for ( int j = 0; j < v; j++) {
	if (j) {
	  cout << " " ;
	}
	
	if ( dp[i][j] == INF ) {
	  cout << "INF";
	} else { 
	  cout << dp[i][j];
	}
      }
      cout << endl;
    }

  }

  return (0);
}

