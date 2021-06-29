#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
/////////////////////////////////////////////////////////////////////////////////

template<typename T>
void WarshallFloyd(vector<vector<T>> &G, T inf) {
    
    int N = G.size();
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            if (G[i][k] == inf) continue;
            for (int j = 0; j < N; ++j) {
                if (G[k][j] == inf) continue;
                G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N,M; cin >> N >> M;
    vector<vector<ll>> G(N, vector<ll>(N,1e18));
    rep(i,N) G[i][i] = 0;
    rep(i,M) {
        ll s,t,d; cin >> s >> t >> d;
        G[s][t] = d;
    }

    WarshallFloyd<ll>(G,1e18);
    rep(i,N) {
        if (G[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    rep(i,N) {
        rep(j,N) {
            if (j > 0) cout << " ";
            if (G[i][j] == 1e18) cout << "INF";
            else cout << G[i][j];
        }
        cout << endl;
    }
}

/*
  verified on 2020/02/09
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp
*/
