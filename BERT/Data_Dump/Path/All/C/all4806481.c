#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[500][500];

int main() {
    int N, M;
    cin >> N >> M;

    rep(i, N) rep(j, N) dp[i][j] = 10e16;
    // long long の場合はより大きな数で初期化

    rep(i, M) {
        int a, b, t;
        cin >> a >> b >> t;
        dp[a][b] = t;
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }

    rep(i, N) rep(j, N) if (dp[i][j] + dp[j][i] < 0) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    rep(i, N) {
        rep(j, N) {
            if (i == j)
                cout << 0;
            else if (dp[i][j] > 10e15)
                cout << "INF";
            else
                cout << dp[i][j];
            if (j != N - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
}
