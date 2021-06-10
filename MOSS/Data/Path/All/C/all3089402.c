#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

const int inf = 2e9;

template<class T> bool warshall_floyd(VV<T>& d) {
  int n = d.size();
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] != inf and d[k][j] != inf) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) if (d[i][i] < 0) return true;
  return false;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> d; assign(d, n, n, inf);
  for (int i = 0; i < n; i++) d[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    d[a][b] = c;
  }
  if (warshall_floyd<int>(d)) cout << "NEGATIVE CYCLE" << '\n';
  else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << (d[i][j] != inf ? to_string(d[i][j]) : "INF") << (j < n - 1 ? ' ' : '\n');
    }
  }
}
