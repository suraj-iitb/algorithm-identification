#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

vector<vector<int64>> AllPairsShortestPath(
    const vector<vector<int64>>& cost_matrix) {
  vector<vector<int64>> result = cost_matrix;
  int n = result.size();
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (result[i][k] == INT64_MAX) continue;
        if (result[k][j] == INT64_MAX) continue;
        result[i][j] = min(
            result[i][j],
            result[i][k] + result[k][j]);
      }
    }
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int64>> cost_matrix(n, vector<int64>(n, INT64_MAX));
  for (int i = 0; i < n; i++) {
    cost_matrix[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int s, t;
    int64 d;
    cin >> s >> t >> d;
    cost_matrix[s][t] = d;
  }
  auto result = AllPairsShortestPath(cost_matrix);
  for (int i = 0; i < n; i++) {
    if(result[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) cout << " ";
      if (result[i][j] == INT64_MAX) cout << "INF";
      else cout << result[i][j];
    }
    cout << endl;
  }
}

