#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)2e9;

int v, e;
V< V<int> > edges;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> v >> e;
    edges.resize(v, V<int>(v, INF));
    for (int i = 0; i < v; i++) edges[i][i] = 0;
    for (int i = 0; i < e; i++) {
        int s, t, d; cin >> s >> t >> d;
        edges[s][t] = d;
    }

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (edges[i][k] == INF || edges[k][j] == INF) continue;
                chmin(edges[i][j], edges[i][k] + edges[k][j]);
            }
        }
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            for (int k = 0; k < v; k++) {
                if (edges[i][k] == INF || edges[k][j] == INF) continue;
                if (edges[i][j] > edges[i][k] + edges[k][j]) {
                    cout << "NEGATIVE CYCLE\n";
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << (edges[i][j] == INF ? "INF" : to_string(edges[i][j])) << (j == v - 1 ? '\n' : ' ');
        }
    }

    return 0;
}

