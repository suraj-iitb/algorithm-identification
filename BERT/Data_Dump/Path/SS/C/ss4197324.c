#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template<typename T> using V = std::vector<T>;
using Vi = V<int>;
using VVi = V<V<int>>;
using Vl = V<ll>;
using VVl = V<V<ll>>;
using Vs = V<string>;

template<typename T1, typename T2> using P = std::pair<T1, T2>;
using Pii = P<int, int>;
using Pll = P<ll, ll>;
using Pdd = P<double, double>;

template<typename T1, typename T2> using M = std::map<T1, T2>;
using Mii = M<int, int>;
using Msi = M<string, int>;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s);i>=(int)(e);--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

const double PI = acos(-1);
const ll MOD = 1e9+7;

int n, m, r;
string s;

int main() {
    cin >> n >> m >> r;
    V<V<Pii>> edges(n);
    REP(i, m) {
        int s,t,d; cin >> s >> t >> d;
        edges[s].push_back({d, t});
    }

    Vi d(n, 1e9);
    priority_queue<Pii, V<Pii>, greater<Pii>> q;
    q.push({0, r});
    d[r] = 0;
    while (!q.empty()) {
        int cost = q.top().first, node = q.top().second;
        q.pop();
        if (cost > d[node]) continue;
        FOR(i, edges[node]) {
            int c = cost + i->first, v = i->second;
            if (d[v] > c) {
                d[v] = c;
                q.push({c, v});
            }
        }
    }
    FOR(i, d) {
        if (*i == 1e9) {
            std::cout << "INF" << '\n';
        } else {
            std::cout << *i << '\n';
        }
    }

    return 0;
}

