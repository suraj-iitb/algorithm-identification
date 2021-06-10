#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

const ll INF = 1LL<<60;
ll dp[100][100];

int main() {
    int V, E;
    cin >> V >> E;
    rep(i, V) {
        rep(j, V) {
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    } 
    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }

    rep(k, V) {
        rep(i, V) {
            rep(j, V) {
                if(dp[i][k] == INF || dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    rep(i, V) {
        if(dp[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    rep(i, V) {
        rep(j, V) {
            if(j) cout << " ";
            if(dp[i][j] == INF) cout << "INF";
            else cout << dp[i][j];
        }
        cout << endl;
    }

    return 0;
}

