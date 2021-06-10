#pragma region templates
//C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using i8  = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using f32 = float;
using f64 = double;
using vi32  = std::vector<i32>;
using vu32  = std::vector<u32>;
using vi64  = std::vector<i64>;
using vu64  = std::vector<u64>;
using vvi32 = std::vector<vi32>;
using vvu32 = std::vector<vu32>;
using vvi64 = std::vector<vi64>;
using vvu64 = std::vector<vu64>;
using pi32  = std::pair<i32,i32>;
using pi64  = std::pair<i64,i64>;

#define FOR(i,a,b) for(i64 i=(a), i##_len=(b); i<i##_len; ++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) for(i64 i=1LL; i<=static_cast<i64>(n); ++i)
#define RFOR(i,a,b) for(i64 i=(a), i##_len=(b); i>i##_len; --i)
#define RFORS(i,n) RFOR(i,n,0)

#define ALL(obj) (obj).begin(),(obj).end()
#define CLR(ar,val) memset(ar, val, sizeof(ar))
#define SZ(obj) (static_cast<i32>(obj.size()))
#define cauto const auto&
#define pb push_back
#define mp make_pair

const i32 dx[4]={1,0,-1,0};
const i32 dy[4]={0,1,0,-1};
const i32 INF32 = 0x3F3F3F3F;
const i64 INF64 = 0x3F3F3F3F3F3F3F3F;

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

class range {
private:
    struct I {
        i32 x;
        i32 operator*() { return x; }
        bool operator!=(I& lhs) { return x<lhs.x; }
        void operator++() { ++x; }
    };
    I i,n;
public:
    explicit range(int n) : i({0}), n({n}) { }
    range(int i,int n) : i({i}), n({n}) { }
    I& begin() { return i; }
    I& end() { return n; }
};

struct IoSetup {
    IoSetup() {
        std::cin.tie(nullptr);
        std::ios::sync_with_stdio(false);
        std::cout << std::fixed << std::setprecision(10);
        std::cerr << std::fixed << std::setprecision(10);
    }
}iosetup;/// cin,coutを使うときは iosetup をここにつける

template<typename A, typename B> std::istream &operator>>(std::istream &is, std::pair<A, B> &p) { is >> p.first >> p.second;return is; }
template<typename A, typename B> std::ostream &operator<<(std::ostream &os, const std::pair<A, B>& p) { os << p.first << ' ' << p.second;return os; }
template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &v) { for(T& in : v) is >> in; return is; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) { for(i32 i = 0; i < SZ(v); i++) os << v[i] << (i+1 != SZ(v) ? " " : ""); return os; }
#pragma endregion

#pragma region Graph Template

template<typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) { }
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) { }
    edge &operator=(const int& x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};

template<typename T>
using Edges = std::vector<edge<T>>;

template<typename T>
using WeightedGraph = std::vector<Edges<T>>;

using UnWeightedGraph = std::vector<std::vector<int>>;

template<typename T>
using Matrix = std::vector<std::vector<T>>;

#pragma endregion

#pragma region SPFA

template<typename T>
std::vector<T> showrest_path_faster_algorithm(WeightedGraph<T>& g, i32 s) {
    const auto INF = std::numeric_limits<T>::max();
    std::vector<T> dist(SZ(g), INF);
    vi32 pending(SZ(g), 0), times(SZ(g), 0);
    std::queue<i32> que;

    que.emplace(s);
    pending[s] = true;
    ++times[s];
    dist[s] = 0;

    while (!que.empty()) {
        i32 p = que.front(); que.pop();
        pending[p] = false;
        for (auto& e : g[p]) {
            T next_cost = dist[p] + e.cost;
            if (next_cost >= dist[e.to]) continue;
            dist[e.to] = next_cost;
            if (!pending[e.to]) {
                if (++times[e.to] >= SZ(g)) return std::vector<T>();
                pending[e.to] = true;
                que.emplace(e.to);
            }
        }
    }

    return dist;
}

#pragma endregion

i32 main() {
    /* https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A */
    using namespace std;

    i32 v, e, r; cin >> v >> e >> r;

    WeightedGraph<i32> g(v);
    while(e--) {
        i32 a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }
    auto dists = showrest_path_faster_algorithm(g, r);
    if (dists.empty()) cout << "NEGATIVE CYCLE" << endl;
    for (cauto e : dists) {
        if (e == numeric_limits<i32>::max()) cout << "INF" << endl;
        else cout << e << endl;
    }

    return 0;
}
