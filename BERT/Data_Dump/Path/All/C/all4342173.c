#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<long long>>
warshall_floyd(std::vector<std::vector<long long>> dist) {
  const long long LINF = 1000000000000000018LL;
  int n = (int)dist.size();
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (dist[i][k] == LINF) {
        continue;
      }
      for (int j = 0; j < n; j++) {
        if (dist[k][j] == LINF) {
          continue;
        }
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}

int main() {
  const long long LINF = 1000000000000000018LL;
  int v, e;
  cin >> v >> e;
  std::vector<std::vector<long long>> mat(v, std::vector<long long>(v, LINF));
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      mat[j][i] = (i == j ? 0 : LINF);
    }
  }
  while (e--) {
    int s, t, d;
    cin >> s >> t >> d;
    mat[s][t] = d;
  }

  std::vector<std::vector<long long>> dist = warshall_floyd(mat);
  for (int i = 0; i < v; i++) {
    if (dist[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      if (dist[i][j] != LINF) {
        cout << dist[i][j];
      } else {
        cout << "INF";
      }
      cout << (j == v - 1 ? "\n" : " ");
    }
  }
  return 0;
}
