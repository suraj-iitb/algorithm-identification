#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int V, E, r;
ll dist[100010];
vector<vector<pli>> g;

int main() {
    cin >> V >> E >> r;
    g.resize(V);
    rep(i, E) {
        int s, t; ll d;
        cin >> s >> t >> d;
        g[s].push_back(make_pair(d, t));
    }

    rep(i, V) dist[i] = INF;
    dist[r] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push(make_pair(0, r));

    while (!pq.empty()) {
        pli now = pq.top();
        pq.pop();
        int u = now.second;
        for (auto &e: g[u]) {
            ll cost = e.first;
            int v = e.second;
            if (chmin(dist[v], dist[u] + cost)) {
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    rep(i, V) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

