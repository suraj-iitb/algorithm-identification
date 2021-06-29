#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<long>> dp(n, vector<long>(n, 1e15));
    while (m--)
    {
        int s, t;
        long d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }
    for (int k = 0; k < n; k++)
    {
        dp[k][k] = 0;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
    for (int k = 0; k < n; k++)
    {
        if (dp[k][k] < 0)
        {
            cout << "NEGATIVE CYCLE\n";
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] >= 1e12)
            {
                cout << "INF";
            }
            else
            {
                cout << dp[i][j];
            }
            cout << " \n"[j == n - 1];
        }
    }
}

int main()
{
    solve();
    return 0;
}

