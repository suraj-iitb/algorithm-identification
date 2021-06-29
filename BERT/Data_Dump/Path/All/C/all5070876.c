#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()
template<class T>bool chmax(T& a, const T& b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T& a, const T& b) { if (b<a) { a=b; return 1;} return 0;}

const ll INF = 1LL << 60;
int main() {
    int V, E; cin >> V >> E;
    vector<vector<ll>> dp(V, vector<ll>(V, INF));
    rep(i, E) {
        ll a, b, w; cin >> a >> b >> w;
        dp[a][b] = w;
    }
    rep(i, V) dp[i][i] = 0;

    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    bool flg = false;
    rep(i, V) {
        if (dp[i][i] < 0) flg = true;
    }
    if (flg) cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (j != 0) cout << " ";
                if (dp[i][j] > INF/2) cout << "INF";
                else cout << dp[i][j];
            }
            cout << endl;
        }
    }
}
