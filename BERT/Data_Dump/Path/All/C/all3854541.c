#include <bits/stdc++.h>

using namespace std;

const long long int Inf = 10000000000LL;

int main() {
    int v, e;
    cin >> v >> e;
    long long int g[v][v];

    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            g[i][j] = Inf;
        }
        g[i][i] = 0;
    }
    for (int i = 0; i < e; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s][t] = d;
    } 
    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (g[i][k] != Inf && g[k][j] != Inf) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 0; i < v; ++i) {
        if (g[i][i] < 0) {
                cout << "NEGATIVE CYCLE" << endl;
                return 0;
        }
    }

    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (g[i][j] == Inf) {
                cout << "INF";
            } else {
                cout << g[i][j];
            }
            if (j == v - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}
