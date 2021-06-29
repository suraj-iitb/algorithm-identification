#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 101
#define INFTY 1LL << 32
#define ll long long

using namespace std;

ll dp[N][N];

void floyd (int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (dp[i][k] == INFTY)
        continue;
      for (int j = 0; j < n; j++) {
        if (dp[k][j] == INFTY)
          continue;
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
}

void print (int n) {
  for (int i = 0; i < n; i++) {
    if (dp[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dp[i][j] == INFTY)
        cout << "INF";
      else
        cout << dp[i][j];
      
      if (j < n - 1)
        cout << " ";
    }
    cout << endl;
  }
}

int main () {
  int n, e, a, b, c;

  cin >> n >> e;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = (i == j ? 0 : INFTY);

  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    dp[a][b] = c;
  }

  floyd(n);
  print(n);

  return 0;
}
