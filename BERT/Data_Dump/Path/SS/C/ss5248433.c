#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) ((long long)(x).size())
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using vc = vector<char>;
using pll = pair<ll, ll>;
template<class T> void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T> void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T, class U> bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U> bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T> bool even(T n) { return ! (n & 1); }
template<class T> bool odd(T n) { return n & 1; }
template<class T> ll rup(T a, T b) { return a % b ? a / b + 1 : a / b; }
template<class T> ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T> ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;
ll intpow(ll a, ll n, ll _mod=numeric_limits<ll>::max()) { ll p=1; while (n) { if (n&1) p=p*a%_mod; a=a*a%_mod; n>>=1; } return p; } 
ll modc(ll a, char op, ll b, ll _mod=mod)
{
        a %= _mod; b %= _mod; ll res = 1;
        switch (op) {
        case '+': res = (a + b) % _mod; break;
        case '-': res = (a - b) % _mod; break;
        case '*': res = a * b % _mod; break;
        case '/': res = modc(a, '*', modc(b, '^', _mod-2, _mod), _mod); break;
        case '^': res = intpow(a, b, _mod); break;
        case 'P': rep(i, a-b+1, a+1) res = modc(res, '*', i, _mod); break;
        case 'C': res = modc(modc(a, 'P', b, _mod), '/', modc(b, 'P', b, _mod)); break;
        } 
        if (res < 0) { res += _mod; } return res;
}

/**
 * Dijkstra
 */
template <typename T>
struct dijkstra_graph
{
public:
        using Vertex = std::pair<T, long long>;
        using Edge = std::pair<T, long long>;
        long long N;
        std::vector<std::vector<Edge>> G;
        std::vector<T> d;
        std::vector<long long> p;
        const long long _inf = 1LL << 60;

        dijkstra_graph(long long n)
        : N(n + 1),
        G(n + 1),
        d(n + 1),
        p(n + 1)
        {}

        void add_edge(long long from, long long to, T cost)
        {
                G[from].emplace_back(Edge(to, cost));
        }
        
        std::vector<T> search(long long s)
        {
                std::fill(d.begin(), d.end(), _inf);
                std::fill(p.begin(), p.end(), -1);
                d[s] = 0;
                std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex>> pq;
                pq.push(Vertex(s, 0));

                while (pq.size()) {
                        long long v = pq.top().first;
                        long long dd = pq.top().second;
                        pq.pop();

                        if (d[v] < dd) continue;
                        for (auto e : G[v]) {
                                long long nv = e.first;
                                long long c = e.second;
                                if (d[nv] > d[v] + c) {
                                        d[nv] = d[v] + c;
                                        p[nv] = v;
                                        pq.push(Vertex(nv, d[nv]));
                                }
                        }
                }

                return d;
        }

        T dist(long long i) const
        {
                return d.at(i);
        }

        std::vector<long long> shortest_path(long long t)
        {
                std::vector<long long> res;
                long long cur = t;
                while (cur != -1) {
                        res.emplace_back(cur);
                        cur = p[cur];
                }
                std::reverse(res.begin(), res.end());
                return res;
        }
};
/**
 * End
 */

// const ll VMAX = 100010;        // Set
// using Vertex = pair<ll, ll>;  // (dist, id)
// class Edge
// {
// public:
//         ll to;
//         ll cost;
//         Edge() : to{0}, cost{0} {}
//         Edge(ll a, ll b) : to{a}, cost{b} {}
// };

// vector<vector<Edge> > G(VMAX);
// vll dist(VMAX, inf);
// vll pre(VMAX, -1);

// void dijkstra(long long s)
// {
//         std::fill(dist.begin(), dist.end(), 1LL<<60);
//         dist[s] = 0;
//         std::priority_queue<Vertex, vector<Vertex>, greater<Vertex> > pq;
//         pq.push(Vertex{0, s});

//         while (not pq.empty()) {
//                 auto v = pq.top(); pq.pop();
//                 long long v_id = v.second;
//                 long long v_dist = v.first;

//                 if (dist[v_id] < v_dist) continue;
//                 for (auto e: Graph[v_id]) {
//                         if (dist[e.to] > dist[v_id] + e.cost) {
//                                 dist[e.to] = dist[v_id] + e.cost;
//                                 pre[e.to] = v_id;
//                                 pq.push(Vertex{dist[e.to], e.to});
//                         }
//                 }
//         }
// }

// std::vector<long long> shortest_path_to(long long t)
// {
//         std::fill(pre.begin(), pre.end(), -1);
//         std::vector<long long> res;
//         long long cur = t;
//         while (cur != -1) {
//                 res.emplace_back(cur);
//                 cur = pre[cur];
//         }
//         std::reverse(res.begin(), res.end());
//         return res;
// }


int main()
{
        int V, E, r;
        cin >> V >> E >> r;
        dijkstra_graph<long long> di(V);

        rep(i, 0, E) {
                int s, t, d;
                cin >> s >> t >> d;
                di.add_edge(s, t, d);
        }

        // auto ans = di.search(r);
        auto ans = di.search(r);
        rep(i, 0, V) {
                ll x = di.dist(i);
                x == inf ? (cout << "INF" << endl) : (cout << x << endl);
        }
}

