#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int INF = numeric_limits<int>::max();

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> dp(v, vector<int>(v, INF));
    for (int i = 0; i < v; i++) dp[i][i] = 0;

    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }


    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dp[i][k] != INF && dp[k][j] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < v; i++) {
        if (dp[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (j > 0) {
                cout << " ";
            }
            if (dp[i][j] == INF) {
                cout << "INF";
            } else {
                cout << dp[i][j];
            }
        }
        cout << endl;
    }
}
