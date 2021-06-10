#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

ll dist[100][100];
ll INF = 1e18;

int main() {
  int v, e;
  cin >> v >> e;
  REP(i, v) REP(j, v) dist[i][j] = (i == j ? 0 : INF);
  REP(i, e) {
    int s, t, d;
    cin >> s >> t >> d;
    dist[s][t] = d;
  }
  REP(k, v) {
    REP(i, v) {
      if (dist[i][k] == INF) continue;
      REP(j, v) {
        if (dist[k][j] == INF) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  bool negative = false;
  REP(i, v) if (dist[i][i] < 0) negative = true;
  if (negative) {
    puts("NEGATIVE CYCLE");
  } else {
    REP(i, v) {
      REP(j, v) {
        if (j) cout << " ";
        if (dist[i][j] == INF) {
          cout << "INF";
        } else {
          cout << dist[i][j];
        }
      }
      cout << "\n";
    }
  }
  return 0;
}
