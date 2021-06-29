#include <iostream>
#include <vector>
using namespace std;
long long inf = 1LL << 60;

void chmin(long long &a, long long b)
{
    if (a > b)
    {
        a = b;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dp(n, vector<long long>(n, inf));

    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;

        dp[a][b] = w;
    }

    for (int v = 0; v < n; ++v)
    {
        dp[v][v] = 0;
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    bool mugen = false;
    for (int v = 0; v < n; ++v)
    {
        if (dp[v][v] < 0)
        {
            mugen = true;
        }
    }

    if (mugen)
    {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j)
                { // 1以上
                    cout << " ";
                }
                if (dp[i][j] < inf / 2)
                {
                    cout << dp[i][j];
                }
                else
                {
                    cout << "INF";
                }
            }
            cout << endl;
        }
    }
}
