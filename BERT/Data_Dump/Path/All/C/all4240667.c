#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define int long long

const int N = 105;
const int INF = 1e18;
int dp[N][N];

signed main() {
    int n,m;
    cin >> n >> m;

    rep(i,N) rep(j,N) {
        if(i == j) dp[i][j] = 0;
        else dp[i][j] = INF;
    }
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        dp[a][b] = c;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) {
                if(dp[i][k] != INF && dp[k][j] != INF) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    bool flag = true;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j && dp[i][j] < 0) flag = false;
        }
    }

    if(!flag) cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(dp[i][j] == INF) cout << "INF";
                else cout << dp[i][j];

                if(j == n - 1) cout << endl;
                else cout << " ";
            }
        }
    }

}
