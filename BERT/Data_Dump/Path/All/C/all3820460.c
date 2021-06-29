#include <bits/stdc++.h>
using namespace std;

struct edge { int to, cost; };

typedef pair<long long, int> plli;
int main() {
  int n, m;
  cin>>n>>m;

  long long d[n][n];
  long long inf = 2*1e9;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (i == j) {
        d[i][j] = 0;
      } else {
        d[i][j] = inf;
      }
    }
  }
  for (int i=0; i<m; i++) {
    int s, t, dist;
    cin>>s>>t>>dist;
    d[s][t] = dist;
  }
  for (int k=0; k<n; k++) {
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (d[i][k] != inf && d[k][j] != inf) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  }
  for (int i=0; i<n; i++) {
    if (d[i][i] < 0) {
      cout<<"NEGATIVE CYCLE"<<endl;
      return 0;
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      long long dij = d[i][j];
      if (dij == inf) {
        cout<<"INF";
      } else {
        cout<<dij;
      }
      if (j != n - 1) {
        cout<<" ";
      }
    }
    cout<<endl;
  }
}
