#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include "bits/stdc++.h" // define macro "/D__MAI"

using namespace std;
typedef long long int ll;

#define xprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#define debugv(v) {printf("L%d %s > ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) {printf("L%d %s > ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;}
#define debugaa(m,h,w) {printf("L%d %s >\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[y][x]<<" ";}cout<<endl;}}
#define ALL(v) (v).begin(),(v).end()
#define repeat(cnt,l) for(auto cnt=0ll;(cnt)<(l);++(cnt))
#define iterate(cnt,b,e) for(auto cnt=(b);(cnt)!=(e);++(cnt))
#define MD 1000000007ll
#define PI 3.1415926535897932384626433832795
#define EPS 1e-12
template<typename T1, typename T2> ostream& operator <<(ostream &o, const pair<T1, T2> p) { o << "(" << p.first << ":" << p.second << ")"; return o; }
template<typename iterator> inline size_t argmin(iterator begin, iterator end) { return distance(begin, min_element(begin, end)); }
template<typename iterator> inline size_t argmax(iterator begin, iterator end) { return distance(begin, max_element(begin, end)); }
template<typename T> T& maxset(T& to, const T& val) { return to = max(to, val); }
template<typename T> T& minset(T& to, const T& val) { return to = min(to, val); }

mt19937_64 randdev(8901016);
inline ll rand_range(ll l, ll h) {
    return uniform_int_distribution<ll>(l, h)(randdev);
}

#ifdef __MAI
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
#ifdef __VSCC
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
namespace {
#define isvisiblechar(c) (0x21<=(c)&&(c)<=0x7E)
    class MaiScanner {
    public:
        template<typename T> void input_integer(T& var) {
            var = 0;
            T sign = 1;
            int cc = getchar_unlocked();
            for (; cc<'0' || '9'<cc; cc = getchar_unlocked())
                if (cc == '-') sign = -1;
            for (; '0' <= cc&&cc <= '9'; cc = getchar_unlocked())
                var = (var << 3) + (var << 1) + cc - '0';
            var = var*sign;
        }
        inline int c() { return getchar_unlocked(); }
        inline MaiScanner& operator>>(int& var) {
            input_integer<int>(var);
            return *this;
        }
        inline MaiScanner& operator>>(long long& var) {
            input_integer<long long>(var);
            return *this;
        }
        inline MaiScanner& operator>>(string& var) {
            int cc = getchar_unlocked();
            for (; !isvisiblechar(cc); cc = getchar_unlocked());
            for (; isvisiblechar(cc); cc = getchar_unlocked())
                var.push_back(cc);
            return *this;
        }
        template<typename IT> void in(IT begin, IT end) {
            for (auto it = begin; it != end; ++it) *this >> *it;
        }
    };
}
MaiScanner scanner;



class GraphE {
public:
    typedef ll W_T;
    struct Edge {
        int u, v;
        W_T value;
        Edge(int from = 0, int to = 0, W_T value = 0) :u(from), v(to), value(value) {}
        inline int to(int _v) { return _v == v ? u : v; }
    };
    size_t n;
    vector<vector<int>> vertex_to;
    vector<Edge> edges;

    GraphE(int n) :n(n), vertex_to(n) { }

    void resize(size_t _n) {
        n = _n;
        vertex_to.resize(_n);
    }
    void connect(int from, int to, W_T val = 0) {
        vertex_to[from].push_back(edges.size());
        //vertex_to[to].push_back(edges.size());
        edges.emplace_back(from, to, val);
    }
    inline size_t degree(int v) {
        return vertex_to[v].size();
    }
};



// ???????????????????????°??????(ElogV)
// verify: http://arc025.contest.atcoder.jp/submissions/1595109
void dijkstra(const GraphE& g, vector<ll>& dist, int begin, ll inf = 5e15) {
    dist.resize(g.n);
    fill(dist.begin(), dist.end(), inf);

    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, begin);
    dist[begin] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();

        if (dist[u] < d) continue;

        for (int ei : g.vertex_to[u]) {
            auto edge = g.edges[ei];
            int v = edge.to(u);

            if (dist[v] > d + edge.value) {
                dist[v] = d + edge.value;
                pq.emplace(-(d + edge.value), v);
            }
        }
    }
}





ll m, n, kei;


int main() {

    scanner >> n >> m >> kei;

    GraphE g(n);

    repeat(i, m) {
        ll s, t, d;
        scanner >> s >> t >> d;
        g.connect(s, t, d);
    }

    vector<ll> dist(n);
    dijkstra(g, dist, kei);

    for (auto z : dist) {
        if (1e15 < z)
            printf("INF\n");
        else
            printf("%lld\n", z);
    }

    return 0;
}
