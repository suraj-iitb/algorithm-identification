#include <bits/stdc++.h>
using namespace std;
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL << 60;

using Graph = vector<vector<long long>>;

void warshall_floyd(Graph& dp, int N) {
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                if (dp[i][k] < INF && dp[k][j] < INF) {
                    chmin(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
    rep(v, N) {
        if (dp[v][v] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return;
        }
    }
    rep(i, N) {
        rep(j, N) {
            if (j) cout << " ";
            if (i == j) cout << 0;
            else if (dp[i][j] < INF) cout << dp[i][j];
            else cout << "INF";
        }
        cout << endl;
    }
}


int main() {
    int N, M; cin >> N >> M;
    Graph G(N, vector<long long>(N, INF));
    rep(i, M) {
        int s, t, d; cin >> s >> t >> d;
        G[s][t] = d;
    }
    warshall_floyd(G, N);
}

