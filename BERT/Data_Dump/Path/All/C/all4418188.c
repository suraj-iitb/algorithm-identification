#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <map>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Graph = vector<vector<T>>;

const int INT_BIG = (1<<28);
const ll LL_BIG = 1ll<<61;

void printFixedDouble(double d, int fix) {
    cout << std::fixed;
    cout << std::setprecision(fix) << d << endl;
}

int main() {
    int nodeNum, linkNum;
    cin >> nodeNum >> linkNum;
    Graph<ll> dp(nodeNum, vector<ll>(nodeNum, LL_BIG));
    rep(i, linkNum) {
        ll s, t, d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }

    rep(i, nodeNum) {
        dp[i][i] = 0;
    }

    rep(k, nodeNum) {
        rep(i, nodeNum) {
            rep(j, nodeNum) {
                if (dp[i][k] != LL_BIG && dp[k][j] != LL_BIG)
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
            if (dp[i][i] != 0) {
                cout << "NEGATIVE CYCLE" << endl;
                return 0;
            }
        }
    }

    rep(i, nodeNum) {
        rep(j, nodeNum) {
            if (j != 0) cout << " ";
            
            if (dp[i][j] == LL_BIG) {
                cout << "INF";
            } else {
                cout << dp[i][j];
            }
        }
        cout << endl;
    }
}
