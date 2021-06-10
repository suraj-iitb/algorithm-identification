#include <bits/stdc++.h>
using namespace std;

long long MAX_V = 105;
long long INF = 1e12;

// d[u][v] := 辺 (u, v) のコスト (辺が存在しない場合 INF, d[i][i] := 0 )
vector<vector<long long>> d(MAX_V, vector<long long>(MAX_V));
long long v;


void warshall_floyd() {
    for (long long k = 0; k < v; k++) {
        for (long long i = 0; i < v; i++) {
            for (long long j = 0; j < v; j++) {
                if (d[i][k] == INF || d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
// d[i][i] < 0 なる i があれば負の閉路がある


int main() {
    long long e;
    cin >> v >> e;

    for (long long i = 0; i < v; i++) {
        for (long long j = 0; j < v; j++) {
            d[i][j] = INF;
        }
    }

    for (long long i = 0; i < e; i++) {
        long long s, t, c;
        cin >> s >> t >> c;
        d[s][t] = c;
    }

    for (long long i = 0; i < v; i++) {
        d[i][i] = 0;
    }

    warshall_floyd();

    for (long long i = 0; i < v; i++) {
        if (d[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    for (long long i = 0; i < v; i++) {
        for (long long j = 0; j < v; j++) {
            if (j > 0) cout << ' ';
            if (d[i][j] == INF) cout << "INF";
            else cout << d[i][j];
        }
        cout << endl;
    }
}


