#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = 1e18;
int main(){
  int V, E;
  cin >> V >> E;
  vector<vector<ll>> d(V, vector<ll>(V,INF));
  rep(i,V) d[i][i] = 0;
  rep(i,E) {
    int s, t, c;
    cin >> s >> t >> c;
    d[s][t] = c;
  }

  auto warshllfloyd = [&](){
    bool ok = true;
    for (int k = 0; k < V; k++) {
      for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
    
    rep(i,V) if (d[i][i] < 0) ok = false;

    return ok;
  };

  if (!warshllfloyd()) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    rep(i,V) {
      rep(j,V) {
        if (d[i][j] < INF / 2) cout << d[i][j];
        else cout << "INF";

        if (j < V-1) cout << " ";
        else cout << endl;
      }
    }
  }
  return 0;
} 
