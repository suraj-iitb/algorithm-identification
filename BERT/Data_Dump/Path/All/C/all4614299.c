//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v, e;
    cin >> v >> e;
    vvi dist(v, vi(v, INT_MAX));
    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    rep(i, v) {
        dist[i][i] = 0;
    }

    rep(k, v) {
        rep(i, v) {
            rep(j, v) {
                if(dist[i][k] == INT_MAX or dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    rep(i, v) {
        if(dist[i][i]) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    rep(i, v) {
        rep(j, v) {
            cout << (dist[i][j] == INT_MAX?"INF":to_string(dist[i][j])) << (j == v-1?'\n':' ');
        }
    }

}
