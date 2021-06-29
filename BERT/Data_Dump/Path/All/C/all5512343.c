#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll INF = 1LL << 60;
int main() {
    ll V, E;
    cin >> V >> E;
    ll dp[110][110] = {0};
    for (ll i = 0; i < V; i++) {
        for (ll j = 0; j < V; j++) {
            dp[i][j] = INF;
            if (i == j) dp[i][j] = 0;
        }
    }
    for (ll i = 0; i < E; i++) {
        ll s, t, d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }
    for (ll k = 0; k < V; k++) {
        for (ll i = 0; i < V; i++) {
            for (ll j = 0; j < V; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (ll i = 0; i < V; i++) {
        if (dp[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    for (ll i = 0; i < V; i++) {
        for (ll j = 0; j < V; j++) {
            if (j) cout << " ";
            if (dp[i][j] > INF / 2)
                cout << "INF";
            else
                cout << dp[i][j];
        }
        cout << endl;
    }
}

