#include <bits/stdc++.h>

/**
 * 全ノード間の最短距離をもとめる
 * matrix[i][j]には辺e=(i,j)のコスト(辺が存在しない場合はINT_MAX)
 * 負の閉路がある場合は空を返す
 * O(|V|^3)
 */
std::vector<std::vector<int>> warshall_floyd(std::vector<std::vector<int>> matrix) {
    const unsigned long num_node = matrix.size();

    // 自分の距離は0
    for (int i = 0; i < num_node; ++i) {
        matrix.at(i).at(i) = 0;
    }

    for (int m = 0; m < num_node; ++m) {
        for (int s = 0; s < num_node; ++s) {
            for (int e = 0; e < num_node; ++e) {
                // sからeへmを経由して到達可能
                if (matrix.at(s).at(m) != INT_MAX and matrix.at(m).at(e) != INT_MAX) {
                    matrix.at(s).at(e) = std::min(matrix.at(s).at(e), matrix.at(s).at(m) + matrix.at(m).at(e));
                }
            }
        }
    }

    // 負閉路チェック
    for (int u = 0; u < num_node; ++u) {
        if (matrix.at(u).at(u) < 0) {
            return {};
        }
    }

    return matrix;
}

using namespace std;

int main(void) {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> matrix(V, vector<int>(V, INT_MAX));
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        matrix[s][t] = d;
    }

    matrix = warshall_floyd(matrix);
    if (matrix.empty()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (j != 0) {
                cout << " ";
            }
            if (matrix[i][j] == INT_MAX) {
                cout << "INF";
            } else {
                cout << matrix[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
