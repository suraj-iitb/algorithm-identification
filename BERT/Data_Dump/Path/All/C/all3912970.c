#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;

int V, E;
ll d[101][101];

bool negative_loop;
void wf() {
    for (int k=0; k<V; ++k) {
        for (int i=0; i<V; ++i) {
            for (int j=0; j<V; ++j) {
                if (d[i][k] != 1e10 and d[k][j] != 1e10) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}

int main() {
    cin >> V >> E;
    fill(d[0], d[101], 1e10);
    rep(i, V) d[i][i] = 0;

    rep(i, E) {
        ll s, t, dist;
        cin >> s >> t >> dist;
        d[s][t] = min(d[s][t], dist);
    }

    wf();

    rep(i, V) {
        if (d[i][i] < 0) negative_loop = true;
    }

    if (negative_loop) {
        puts("NEGATIVE CYCLE");
        return 0;
    }

    rep(i, V) {
        rep(j, V) {
            if (j) cout << " ";
            if (d[i][j] == 1e10) cout << "INF";
            else cout << d[i][j];
        }
        cout << endl;
    }



}

