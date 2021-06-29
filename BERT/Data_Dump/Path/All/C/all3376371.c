
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int INF = (int) 2e9 + 1;
    int V, E;
    cin >> V >> E;

    int d[V][V];
    for (int i = 0; i < V; ++i) {
        fill(d[i], d[i] + V, INF);
        d[i][i] = 0;
    }

    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        cin >> d[s][t];
    }

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            if (d[i][k] == INF) continue;
            for (int j = 0; j < V; ++j) {
                if (d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        if (d[i][i] < 0) {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }
    
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (d[i][j] < INF) {
                cout << d[i][j];
            } else {
                cout << "INF";
            }
            if (j != V - 1) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}

