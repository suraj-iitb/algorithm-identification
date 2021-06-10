#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1LL << 32)
#define PI (acos(-1))
#define MAXN 1010
#define rep(i,n) for (int i = 0; i < (n); ++i)
const ll mod = 1e9+7;

ll d[MAXN][MAXN];
int n, u, v, c, e;

void warshall_floyd() {
    for(int k=0; k<n; ++k) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if (d[i][k] != INF && d[k][j] != INF)  d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
           
int main() {
    cin >> n >> e;

    rep(i, n) {
        rep(j, n) {
            d[i][j] = ( (i==j) ? 0: INF );
        }
    }

    rep(i, e) {
        cin >> u >> v >> c;
        d[u][v] = c;
    }


    warshall_floyd();

    bool negative = false;

    rep(i, n) if (d[i][i] < 0) negative = true;

    if (negative) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i, n) {
            rep(j, n) {
                if (j) cout << " ";
                if (d[i][j] == INF) cout << "INF";
                else cout << d[i][j];
            }
            cout << endl;
        }
    }
}


