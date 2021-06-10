#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF INT64_MAX / 2
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

using namespace std;
//#inculude <bits/stdc++.h>
#define int long long

template <class T>
class WarshallFloyd {
  private:
    T n;
    T _INF;
    vector<vector<T>> g;

    void init() {
        n = g.size();
    }

  public:
    WarshallFloyd(vector<vector<T>> _g, T __INF) : g(_g), _INF(__INF) {
        init();
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (g[i][k] == _INF || g[k][j] == _INF)
                        continue;
                    chmin(g[i][j], g[i][k] + g[k][j]);
                }
    }

    T costs(T i, T j) {
        return g[i][j];
    }
};

signed main() {
    int v, e, s, t, d;
    cin >> v >> e;
    vector<vector<int>> g(v, vector<int>(v, INF));
    rep(i, e) {
        cin >> s >> t >> d;
        g[s][t] = d;
    }
    rep(i, v) g[i][i] = 0;
    WarshallFloyd<int> w(g, INF);
    rep(i, v) {
        if (w.costs(i, i) < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    rep(i, v) {
        rep(j, v) {
            if (w.costs(i, j) == INF)
                cout << "INF";
            else
                cout << w.costs(i, j);
            if (j != v - 1)
                cout << ' ';
            else
                cout << endl;
        }
    }
    return 0;
}
