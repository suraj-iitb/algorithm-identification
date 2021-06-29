#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

const int MAX_V = 100;

int V, E;
int s, t, d;

ll dp[MAX_V][MAX_V];

int main() {
    cin >> V >> E;
    REP(i, V) {
        REP(j, V) {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }
    REP(i, E) {
        cin >> s >> t >> d;
        dp[s][t] = d;
    }

    REP(k, V) {
        REP(i, V) {
            REP(j, V) {
                if (dp[i][k] != INF && dp[k][j] != INF) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    bool has_negative_cycle = false;
    REP(i, V) {
        if (dp[i][i] < 0) has_negative_cycle = true;
    }
    if (has_negative_cycle) PRINT("NEGATIVE CYCLE");
    else {
        REP(i, V) {
            REP(j, V) {
                if (j == 0) {
                    if (dp[i][j] == INF) printf("INF");
                    else printf("%lld", dp[i][j]);
                }
                else {
                    if (dp[i][j] == INF) printf(" INF");
                    else printf(" %lld", dp[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
