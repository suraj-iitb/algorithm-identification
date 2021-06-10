#include <iostream>
#include <vector>
#include <limits>
using namespace std;

typedef long long ll;
typedef vector<vector<long long> > Matrix;

const ll INF = numeric_limits<long long>::max();
Matrix d;

ll V, E;

void warshall_floyd(){
  for (ll i = 0; i < V; i++) {
    for (ll j = 0; j < V; j++) {
      if (d[j][i]==INF) continue;
      for (ll k = 0; k < V; k++) {
        if (d[i][k]==INF) continue;
        d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  cin >> V >> E;
  d = Matrix(V, vector<ll>(V,INF));
  for (ll i = 0; i < V; i++) d[i][i] = 0;
  for (ll i = 0; i < E; i++) {
    ll s, t, dist;
    cin >> s >> t >> dist;
    d[s][t] = dist;
  }
  warshall_floyd();

  bool negative = false;
  for (ll i = 0; i < V; i++) if (d[i][i] < 0) negative = true;
  if (negative) cout << "NEGATIVE CYCLE" << endl;
  else {
    for (ll i = 0; i < V; i++) {
      for (ll j = 0; j < V; j++) {
        if (d[i][j]==INF) cout << "INF";
        else cout << d[i][j];
        if (j<V-1) cout << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}

