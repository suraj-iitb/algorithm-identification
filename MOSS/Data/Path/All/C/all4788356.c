#include <bits/stdc++.h>
#define ll long long
#define INF 20000000000000000000
using namespace std;

int V,E;
ll d[101][101];

int main() {
  for (int i =0; i<101; i++) {
    for (int j =0; j<101; j++) {
      if (i == j) d[i][j] = 0;
      else d[i][j] = INF;
    }
  }
  
  cin >> V >> E;
  for (int i =0; i<E; i++) {
    int a,b; ll c; cin >> a >> b >> c;
    d[a][b] = c;
  }
  
  for (int k =0; k<V; k++) {
    for (int i =0; i<V; i++) {
      for (int j =0; j<V; j++) {
        if (d[i][k] != INF && d[k][j] != INF) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
      }
    }
  }
  for (int i =0; i<V; i++) {
    if (d[i][i] <0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  for (int i =0; i<V; i++) {
    for (int j =0; j<V; j++) {
      if (j >= 1) cout << " ";
      if (d[i][j] == INF) cout << "INF";
      else cout << d[i][j];
    }
    cout << endl;
  }
}
