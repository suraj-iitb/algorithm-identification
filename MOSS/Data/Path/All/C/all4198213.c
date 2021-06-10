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

int n, m;
string s;

int main() {
    cin >> n >> m;

    VVl dm(n, Vl(n, 1e18));
    V<V<P<ll, int>>> edges(n);
    REP(i, m) {
        int s,t,d; cin >> s >> t >> d;
        edges[s].push_back({d, t});
        dm[s][t] = d;
    }

    Vl d(n, 1e18);
    unordered_set<int> toUpdate;
    toUpdate.insert(0);
    d[0] = 0;
    REP(i, n) {
        unordered_set<int> toUpdateBuf(toUpdate);
        toUpdate.clear();
        FOR(j, toUpdateBuf) {
            int node = *j;
            FOR(k, edges[node]) {
                int dist = k->second;
                ll cost = k->first;
                if (d[dist] > d[node] + cost) {
                    d[dist] = d[node] + cost;
                    toUpdate.insert(dist);
                    if (i == n - 1) {
                        cout << "NEGATIVE CYCLE" << endl;
                        return 0;
                    }
                }
            }
        }
        if (toUpdate.empty()) break;
    }

    REP(i, n) dm[i][i] = 0;

    REP(k, n) REP(i, n) REP(j, n) {
        if (dm[i][k] == 1e18 || dm[k][j] == 1e18) continue;
        dm[i][j] = min(dm[i][j], dm[i][k] + dm[k][j]);
    }

    REP(i, n) {
        REP(j, n) {
            if (dm[i][j] == 1e18) {
                std::cout << "INF";
            } else {
                std::cout << dm[i][j];
            }
            if (j != n-1) {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }

    return 0;
}

