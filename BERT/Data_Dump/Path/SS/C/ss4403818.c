#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using vvp = vector<vector<P>>;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll n, m, r;
    cin >> n >> m >> r;
    
    ll a, b, c;
    vvp e(n);
    REP(i, m) {
        cin >> a >> b >> c;
        e[a].push_back({b, c});
    }

    vll res(n, inf);
    res[r] = 0;

    min_priority_queue<P> que;
    que.push({0, r});
    ll cur, mem;
    while (!que.empty()) {
        mem = que.top().first, cur = que.top().second;
        que.pop();
        for (auto ee : e[cur]) {
            ll to = ee.first, w = ee.second;
            if (chmin(res[to], res[cur] + w)) {
                que.push({res[to], to});
            }
        }
    }
    REP(i, n) {
        if (res[i] == inf) cout << "INF" << endl;
        else cout << res[i] << endl;
    }
    return 0;
}
