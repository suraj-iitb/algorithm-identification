#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n;
long long d[N][N];

void floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] == INT_MAX || d[k][j] == INT_MAX) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int e, u, v, c;
    cin >> n >> e;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = i == j ? 0 : INT_MAX;
        }
    }

    for (int i = 0; i < e; i++) {
        cin >> u >> v >> c;
        d[u][v] = c;
    }

    floyd();

    bool negative = false;
    for (int i = 0; i < n; i++) {
        if (d[i][i] < 0) {
            negative = true;
            break;
        }
    }

    if (negative) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) cout << " ";
                if (d[i][j] == INT_MAX) cout << "INF";
                else cout << d[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
