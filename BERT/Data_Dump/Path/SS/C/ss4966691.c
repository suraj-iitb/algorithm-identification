#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
#define vi vector<int>
#define vl vector<long long>
#define vvi vector< vector<int> >
#define vvl vector< vector<ll> >
#define vp vector<P>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPD(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define INF 1e18
#define INFTY 1e9
const int mod = 1000000007;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

template<class T> bool chmax(T &a, const T & b) {
    if (a<b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chmin(T &a, const T & b) {
    if (a>b) {
        a = b;
        return true;
    }
    return false;
}

//cout << fixed << setprecision(10) << y << endl;
vector< vector<Pl> > edge;
vector<ll> dist;
vector<bool> seen;

void dijkstra(int r) {
    priority_queue< Pl, vector<Pl>, greater<Pl> > que;
    dist[r] = 0;
    Pl tmp;
    ll s, d;
    que.push(Pl(dist[r], r));
    while (!que.empty()) {
        tmp = que.top();
        que.pop();
        d = tmp.first;
        s = tmp.second;
        if (seen[s]) continue;
        REP(i, edge[s].size()) {
            Pl e = edge[s][i];
            if (seen[e.second]) continue;
            if (dist[e.second] > d+e.first) {
                dist[e.second] = d + e.first;
                que.push(Pl(dist[e.second], e.second));
            }
        }
        seen[s] = true;
    }
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    edge.resize(n);
    dist.resize(n);
    seen.resize(n);
    REP(i, n) {
        dist[i] = INF;
        seen[i] = false;
    }
    REP(i, m) {
        ll s, t, d;
        cin >> s >> t >> d;
        edge[s].push_back(Pl(d, t));
    }
    dijkstra(r);
    REP(i, n) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
