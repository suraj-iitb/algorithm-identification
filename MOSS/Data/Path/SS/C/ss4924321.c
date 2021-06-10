#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << "\n";
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (ll i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (ll i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;

template <typename T>
struct Dijkstra {
    struct Edge {
        int to;
        T c;
    };

    int V;
    vector<vector<Edge>> e;
    vector<T> d;
    typedef pair<T, int> PP;

    Dijkstra(int V): V(V) {
        e.resize(V);
        d.resize(V);
    }

    void add_edge(int from, int to, T cost) {
        e[from].pb({to, cost});
    }

    T query(int dest) {
        return d[dest];
    }

    void operator()(int s) {
        priority_queue<PP, vector<PP>, greater<>> q;

        REP(i, V) d[i] = INF; // check!!!!
        d[s] = 0;
        q.push({0, s});

        while(!q.empty()) {
            PP n = q.top(); q.pop();
            int v = n.se;
            if (d[v] < n.fi) continue;

            REP(i, e[v].size()) {
                Edge cur = e[v][i];
                T cost = d[v] + cur.c;
                if (d[cur.to] > cost) {
                    d[cur.to] = cost;
                    q.push({cost, cur.to});
                }
            }
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, e, r; cin >> n >> e >> r;

    Dijkstra<ll> graph(n);

    REP(i, e) {
        int s, t, d;
        cin >> s >> t >> d;

        graph.add_edge(s, t, d);
    }

    graph(r);

    REP(i, n) {
        ll d = graph.query(i);
        if (d == INF) print("INF");
        else print(d);
    }

}
