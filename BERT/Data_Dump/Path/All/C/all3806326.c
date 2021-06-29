#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main() {
    int size_v, size_e;
    cin >> size_v >> size_e;
    int dist[110][110];
    for (int i = 0; i < size_v; i++) {
        for (int j = 0; j < size_v; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < size_v; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < size_e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    for (int k = 0; k < size_v; k++) {
        for (int i = 0; i < size_v; i++) {
            if (dist[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < size_v; j++) {
                if (dist[k][j] == INF) {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    bool have_negacycle = false;
    for (int i = 0; i < size_v; i++) {
        if (dist[i][i] < 0) {
            have_negacycle = true;
        }
    }

    if (have_negacycle == true) {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else {
        for (int i = 0; i < size_v; i++) {
            for (int j = 0; j < size_v; j++) {
                if (j != 0) {
                    cout << " ";
                }
                if (dist[i][j] == INF) {
                    cout << "INF";
                }
                else {
                    cout << dist[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}

