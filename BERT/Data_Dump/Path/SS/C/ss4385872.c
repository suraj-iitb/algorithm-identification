#include <bits/stdc++.h> 

#define int long long
#define double long double

#define REP(i, b) for(int i = 0; i < (b); i++)
#define REPS(i, b) for(int i = 1; i <= (b); i++)
#define ALL(v) (v).begin(), (v).end()

#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

using pi = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vvb = vector<vb>;

const int INF = 1e14;
const int MOD = 1e9+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

typedef struct
{
    int to;
    int cost;
}edge;


signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int V, E, r; cin >> V >> E >> r;
    vector<vector<edge>> G(V);
    REP(i, E)
    {
        int s, t, d; cin >> s >> t >> d;
        G[s].pb(edge{t, d});
    }

    vi d(V, INF); d[r] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push(mp(d[r], r));
    while(!q.empty())
    {
        pi p = q.top(); q.pop();
        int dist = p.fi, n = p.se;
        if(dist > d[n]) continue;
        for(edge e : G[n])
        {
            if(chmin(d[e.to], dist + e.cost)) q.push(mp(d[e.to], e.to));
        }
    }
    REP(i, d.size()) (d[i] == INF) ? cout << "INF" << endl: cout << d[i] << endl;
}
