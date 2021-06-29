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
const int INF = (int)1e9;

int v, e, r;
V< V< P<int, int> > > edges;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> v >> e >> r;
    edges.resize(v);
    for (int i = 0; i < e; i++) {
        int s, t, d; cin >> s >> t >> d;
        edges[s].emplace_back(make_pair(t, d));
    }

    V<int> dist(v, INF); dist[r] = 0;
    priority_queue< P<int, int> > que; que.push(make_pair(0, r));
    while (!que.empty()) {
        P<int, int> q = que.top(); que.pop();
        for (P<int, int> e: edges[q.second]) {
            if (dist[e.first] > dist[q.second] + e.second) {
                dist[e.first] = dist[q.second] + e.second;
                que.push(make_pair(-dist[e.first], e.first));
            }
        }
    }

    for (int i = 0; i < v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}

