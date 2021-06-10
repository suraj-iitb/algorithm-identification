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

#pragma region Warshall-Floyd

template<typename T>
void warshall_floyd(Matrix<T>& g, T INF) {
    for(i32 k = 0; k < SZ(g); k++) {
        for(i32 i = 0; i < SZ(g); i++) {
            for(i32 j = 0; j < SZ(g); j++) {
                if(g[i][k] == INF || g[k][j] == INF) continue;
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

#pragma endregion

i32 main() {
    /* https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C */
    using namespace std;

    i32 V, E; cin >> V >> E;
    Matrix<i32> mat(V, vi32(V, INT_MAX));
    REP(i,V) mat[i][i] = 0;
    REP(i,E) {
        i32 x, y, z;
        cin >> x >> y >> z;
        mat[x][y] = z;
    }
    warshall_floyd(mat, INT_MAX);
    REP(i,V) {
        if (mat[i][i] < 0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    REP(i,V) {
        REP(j,V) {
            if (j > 0) cout << ' ';
            if (mat[i][j] == INT_MAX) cout << "INF";
            else cout << mat[i][j];
        }
        cout << '\n';
    }

    return 0;
}
