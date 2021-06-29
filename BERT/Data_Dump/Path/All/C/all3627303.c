#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;
const int MOD = 1e9 + 7;
int V, E;
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> V >> E;
    ll dp[V][V];
    for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) dp[i][j] = INF;
    for(int i = 0; i < V; i++) dp[i][i] = 0;
    for(int i = 0; i < E; i++)
    {
        ll s, t, d; cin >> s >> t >> d;
        dp[s][t] = d;
    }
    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(dp[i][k] == INF or dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    bool negative = false;
    for(int i = 0; i < V; i++) if(dp[i][i] != 0) negative = true;
    if(negative)
    {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(j) cout << " ";
            if(dp[i][j] >= INF) cout << "INF";
            else cout << dp[i][j];
        }
        cout << endl;
    }
    return 0;
}
