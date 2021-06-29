#include <bits/stdc++.h>

using namespace std;

struct WarshallFloyd {
    WarshallFloyd() {};

    WarshallFloyd(int n) : n(n) { init(); };

    const long long inf = 1001001001010001001ll;
    int n;
    bool NC = false;
    vector<vector<long long>> d;

    void init() {
        d = vector<vector<long long>>(n, vector<long long>(n, inf));
        for (int i = 0; i < n; ++i) d[i][i] = 0;
    }

    void add_edge(int u, int v, long long c) {
        d[u][v] = c;
    }

    bool build() {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (d[i][k] == inf) continue;
                for (int j = 0; j < n; ++j) {
                    if (d[k][j] == inf) continue;
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        bool f = false;
        for (int i = 0; i < n; ++i) {
            if (d[i][i] < 0) f = true;
        }

        return NC = f;
    }

    long long shortestPath(int u, int v) {
        return d[u][v];
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    auto wf = WarshallFloyd(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;

        wf.add_edge(u, v, c);
    }

    if (wf.build()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (wf.shortestPath(i, j) == wf.inf) {
                cout << "INF";
            } else {
                cout << wf.shortestPath(i, j);
            }
            cout << ((j + 1 == n) ? "\n" : " ");
        }
    }
}
