#include <bits/stdc++.h>

using namespace std;

#define reps(i, n, m) for (int i = (int) (n); i < (int) (m); i++)
#define rep(i, n) reps(i, 0, (n))
#define all(v) (v).begin(), (v).end()

using ll = long long;
const ll inf = 1e15;

int main() {
    int V, E; cin >> V >> E;
    int n = V;
    vector<vector<ll>> v(V, vector<ll>(V, inf));
	rep(i, n) v[i][i] = 0;
    rep(i, E) {
        int a, b, c; cin >> a >> b >> c;
        v[a][b] = c;
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
				if (max(v[i][k], v[k][j]) == inf) continue;
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
    rep(i, n) {
        if (v[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    rep(i, n) {
        rep(j, n) {
            if (j) cout << " ";
            if (v[i][j] == inf) cout << "INF";
            else cout << v[i][j];
        }
        cout << endl;
    }
}
