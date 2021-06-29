/**
*	created: 19.09.2020 00:35:58
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
using ll = long long;
using P = pair<int,int>;
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
template<typename T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> T pow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

// Dijkstra's Algorithm（単一始点最短経路問題）
struct graph {
    struct edge {
        int to, cost;
        edge(int t, int c) : to(t), cost(c) {}
    };
    int n;
    vector<vector<edge>> G;
    vector<int> d, pre;
    graph(int i) : n(i), G(i), d(i,INF), pre(i) {}
    void add_edge(int s, int to, int cost) {
        G[s].push_back(edge(to,cost));
    }
    void dijkstra(int s) {
        rep(i,n) {d[i] = INF; pre[i] = 0;}
        d[s] = 0;
        priority_queue<P, vector<P>, greater<P>> que;
        que.push(P(0,s));
        while(!que.empty()){
            P p = que.top(); que.pop(); int v = p.second;
            if(d[v] < p.first) continue;
            for(auto e : G[v]) if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost; pre[e.to] = v;
                que.push(P(d[e.to],e.to));
            }
        }
    }
};

signed main() {
    int n, m, r; cin >> n >> m >> r;
    graph g(n);
    rep(i,m) {
        int a, b, c; cin >> a >> b >> c;
        g.add_edge(a,b,c);
    }
    g.dijkstra(r);
    rep(i,n) {
        int dist = g.d[i];
        dist == INF ? cout << "INF" << endl : cout << dist << endl;
    }
    return 0;
}
