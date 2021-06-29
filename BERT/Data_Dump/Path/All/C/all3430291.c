#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
#define endl "\n"

#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define even(x) (x) % 2 == 0
#define odd(x) (x) % 2 != 0
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define inp(t, x) t x;cin>>x;
#define ithBit(n, i) ((n)>>(i) & 1)
#define INIT() cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(20)

// these functions return the position of result of Binary Search.
#define LB(s, t, x) (int)(lower_bound(s, t, x) - s)
#define UB(s, t, x) (int)(upper_bound(s, t, x) - s)

namespace {
    #define M_PI 3.14159265358979323846
    const ll MOD_CONST = (ll)(1e9 + 7);
    const ll CFM = (ll)(998244353);
    ll qp(ll a, ll b, int mo)
    {
        ll ans = 1;
        do
        {
            if (b & 1)
                ans = 1ll * ans * a % mo;
            a = 1ll * a * a % mo;
        } while (b >>= 1);
        return ans;
    }
    ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
    ll lcm(ll a, ll b)
    {
        ll temp = gcd(a, b);
        return temp ? (a / temp * b) : 0;
    }
    int mDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int dx8[] = {1, -1, 0, 0, 1, 1, -1, -1}, dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};

    template <typename F>
    class
    #if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
        [[nodiscard]]
    #elif defined(__GNUC__) && __GNUC_PREREQ(3, 4)
        __attribute__((warn_unused_result))
    #endif // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
        FixPoint : F {
            public :
                explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)) {}

            template <typename... Args>
            constexpr decltype(auto)
            operator()(Args &&... args) const {
                return F::operator()(*this, std::forward<Args>(args)...);
    } // namespace
    }
    ; // class FixPoint
    template <typename F>
    static inline constexpr decltype(auto)
    makeFixPoint(F &&f) noexcept
    {
        return FixPoint<F>{std::forward<F>(f)};
    }

    template <typename T>
    vector<T> make_v(size_t a) { return vector<T>(a); }
    template <typename T, typename... Ts>
    auto make_v(size_t a, size_t b, Ts... ts) { return vector<decltype(make_v<T>(b, ts...))>(a, make_v<T>(b, ts...)); }
    template <typename T, typename V>
    typename enable_if<is_class<T>::value == 0>::type
    fill_v(T &t, const V &v) { t = v; }
    template <typename T, typename V>
    typename enable_if<is_class<T>::value != 0>::type
    fill_v(T &t, const V &v) { for (auto &e : t) fill_v(e, v); }

    template <class T>
    bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
    template <class T>
    bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

    inline tuple<ll, ll> rotate45(tuple<ll, ll> point)
    {
        ll x = get<0>(point), y = get<1>(point);
        return tuple<ll, ll>(x + y, x - y);
    }
    inline bool rangeCheck2D(int nx, int ny, int Width, int Height) { return nx >= 0 and nx < Width and ny >= 0 and ny < Height; }
    
    ll i_query(ll x)
    {
        cout << "> " << x << endl;
        fflush(stdout);
        ll ret;
        cin >> ret;
        return ret;
    }
    ll i_query_2(ll i)
    {
        cout << "? " << i << endl;
        fflush(stdout);
        ll ret;
        cin >> ret;
        return ret;
    }
    void i_answer(ll ans, ll d)
    {
        cout << "! " << ans << " " << d << endl;
        fflush(stdout);
    }
} // namespace

namespace {
    #define DUMPOUT cerr 
    #ifndef DEBUG_
    #define dump(...)
    #else
    #define dump(...) DUMPOUT<<"  "; \
    DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl; \
    DUMPOUT<<"    "; \
    dump_func(__VA_ARGS__)
    #endif 
    void dump_func() { DUMPOUT << endl; }
    template <class Head, class... Tail>
    void dump_func(Head&& head, Tail&&... tail)
    {
        DUMPOUT << head;
        if (sizeof...(Tail) == 0) {
            DUMPOUT << " ";
        }
        else {
            DUMPOUT << ", ";
        }
        dump_func(std::move(tail)...);
    }
    template <class T>
    ostream &operator<<(ostream &os, const vector<T> &v)
    {
        for (auto i = begin(v); i != end(v); ++i)
            os << *i << (i == end(v) - 1 ? "" : " ");
        return os;
    }
    template <class T>
    void out2Dvector(vector<T> v) {
        for (const auto& vv : v)
            cout << vv << endl;
    }
    template <class T>
    istream &operator>>(istream &is, vector<T> &v)
    {
        for (auto i = begin(v); i != end(v); ++i)
            is >> *i;
        return is;
    }
    template<typename T, typename U>
    ostream& operator << (ostream& os, pair<T, U>& pair_var) {
        os << "(" << pair_var.first << ", " << pair_var.second << ")";
        return os;
    }
    template<typename T, typename U>
    ostream& operator << (ostream& os, map<T, U>& map_var) {
        os << "{";
        for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
            os << "(" << itr->first << ", " << itr->second << ")";
            itr++;
            if(itr != map_var.end()) os << ", ";
            itr--;
        }
        os << "}";
        return os;
    }
    template<typename T>
    ostream& operator << (ostream& os, set<T>& set_var) {
        os << "{";
        for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
            os << *itr;
            ++itr;
            if(itr != set_var.end()) os << ", ";
            itr--;
        }
        os << "}";
        return os;
    }
}

// lambda expression
// auto f = [](int arg1, double arg2) { return ret; };
// lambda recursion
// auto result = makeFixPoint([&](auto rec, int pos, int v) -> int {
//	   rec(pos, v);
// })(0, 1);
// auto func = makeFixPoint([]() -> int {});
// int ret = func();

// tuple binding
// auto [x, y] = make_tuple(0, 0);

// for pair
// auto [a, b] = pair<int, int>({v1, v2});

// bitset<N> bs(ini_val); // N must be constant
// bs.reset(); // reset all

// usage
/* 
    int N, M, start; cin >> N >> M >> start;
    Dijkstra dj(N);
    REP(i, M) {
        int from, to; ll cost; cin >> from >> to >> cost;
        dj.edges[from].pb(Edge(to, cost));
    }

    auto d = dj.get_shortest_path(start);
*/
class WarshallFloyd {
public:
    vector<vector<ll>> cost;

    WarshallFloyd(int size) {
        cost = make_v<ll>(size, size);
        fill_v(cost, INT64_MAX);
        REP(i, size) cost[i][i] = 0;
	}

    void calc_minimum_cost() {
        REP(k, cost.size()) {
            REP(i, cost.size()) {
                REP(j, cost.size()) {
                    if (cost[i][k] == INT64_MAX) continue;
                    if (cost[k][j] == INT64_MAX) continue;
                    ll newCost = cost[i][k] + cost[k][j];
                    if (cost[i][j] > newCost) {
                        cost[i][j] = newCost;
                    }
                }
            }
        }
    }
};

int main(void)
{
    INIT(); // comment out for Interective Program

    inp(ll, N); inp(ll, M);
    
    WarshallFloyd wf(N);
    REP(i, M) {
        int f, t, c; cin >> f >> t >> c;
        wf.cost[f][t] = c;
    }
    wf.calc_minimum_cost();
    
    REP(i, N)
        if (wf.cost[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }

    
    REP(i, N) {
        REP(j, N-1) {
            ll v = wf.cost[i][j];
            if (v == INT64_MAX) cout << "INF";
            else cout << v;
            cout << " ";
        }
        ll v = wf.cost[i][N-1];
        if (v == INT64_MAX) cout << "INF";
        else cout << v;
        cout << endl;
    }

    return 0;
}
//*/
