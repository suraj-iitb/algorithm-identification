#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = (1LL << 55);

template<class T>
void chmin (T &a, T b) {
    if (a > b) a = b;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> g(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++) g[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][k] == INF or g[k][j] == INF) continue;
                chmin(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    bool neg = false;
    for (int i = 0; i < n; i++) neg |= (g[i][i] < 0);

    if (neg) {
        cout << "NEGATIVE CYCLE" << '\n';
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == INF) cout << "INF" << (j + 1 == n ? '\n' : ' ');
                else cout << g[i][j] << (j + 1 == n ? '\n' : ' ');
            }
        }
    }

    return 0;
}
