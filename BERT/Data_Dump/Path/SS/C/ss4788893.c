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
#define INF 1e9
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
//#define int long long

template <class T>
class Dijkstra {
  private:
    T n, c, v;
    T start;
    const T _INF = numeric_limits<T>::max();
    vector<vector<pair<T, T>>> g; //隣接リスト
    vector<T> cost;
    vector<bool> visited;
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> q;

    void init() {
        q.push(make_pair(0, start));
        cost.resize(n, _INF);
        visited.resize(n, false);
        cost[start] = 0;
    }

  public:
    Dijkstra(T _n, vector<vector<pair<T, T>>> _g, T _start)
        : n(_n), start(_start), g(_g) {
        init();
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            c = top.first;
            v = top.second;
            if (c > cost[v])
                continue;
            visited[v] = true;
            rep(i, g[v].size()) {
                if (!visited[g[v][i].first]) {
                    if (chmin(cost[g[v][i].first], cost[v] + g[v][i].second)) {
                        q.push(make_pair(cost[g[v][i].first], g[v][i].first));
                    }
                }
            }
        }
    }
    T costs(T i) {
        if (cost[i] == _INF)
            return -1;
        return cost[i];
    }
};

signed main() {
    int v, e, r, s, t, d;
    cin >> v >> e >> r;
    vector<vector<pair<int, int>>> g(v);
    while (e--) {
        cin >> s >> t >> d;
        g[s].push_back(make_pair(t, d));
    }
    Dijkstra<int> dijkstra(v, g, r);
    rep(i, v) {
        if (dijkstra.costs(i) == -1)
            cout << "INF" << endl;
        else
            cout << dijkstra.costs(i) << endl;
    }
    return 0;
}

