#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll INF = 1001001001001001001;

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<ll>> dist(v, vector<ll>(v, INF));
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (i == j) dist[i][j] = 0;
        }
    }
    for (int i = 0; i < e; ++i) {
        ll s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = min(dist[s][t], d);
    }
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] == INF or dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < v; ++i) {
        if (dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (dist[i][j] >= INF) {
                if (j == 0) cout << "INF";
                else cout << " " << "INF";
            } else {
                if (j == 0) cout << dist[i][j];
                else cout << " " << dist[i][j];
            }
        }
        cout << endl;
    }
}

