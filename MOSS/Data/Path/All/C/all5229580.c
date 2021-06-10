#include <bits/stdc++.h>

#define debug(x) cout <<"DEBUG "<< #x << ": " << (x) << '\n'
#define rep(i,n) for(int_fast32_t i = 0; i < ((int_fast32_t)(n)); i++)   // 0-indexed up
#define rep1(i,n) for(int_fast32_t i = 1; i <= ((int_fast32_t)(n)); i++) // 1-indexed up
#define rrep(i,n) for(int_fast32_t i = ((int_fast32_t)(n)-1); i >= 0; i--)  // 0-indexed down
#define rrep1(i,n) for(int_fast32_t i = ((int_fast32_t)(n)); i >= 1; i--)   // 1-indexed down
#define all(x) (x).begin(),(x).end()

using namespace std;

template<typename T>
using vec = vector<T>;
using i32 = int_fast32_t;
using i64 = int_fast64_t;
using u32 = uint_fast32_t;
using u64 = uint_fast64_t;
using ll = i64;
using ld = long double;
using vi = vec<int_fast32_t>;
using vl = vec<int_fast64_t>;
using vld = vec<ld>;
using vvi = vec<vi>;
using PII = pair<int_fast32_t, int_fast32_t>;

template<class T>
using maxheap = std::priority_queue<T>;
template<class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T,class U>
inline bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T,class U>
inline bool chmin(T &a, const U &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

// ostream expension
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for(i32 i = 0; i < v.size(); ++i) {
        os << (i ? ", " : "") << v[i];
    }
    os << "]";
    return os;
}

const ld Pi = std::acos(-1.0L);
constexpr i64 infll = (1LL<<62)-1;
constexpr i32 inf = (1<<30)-1;
const int mod = 1000000007;
// const int mod = 998244353;


/* Class & Function */
/* template of graph representation */
// represent edge of weighted graph
template<typename T>
struct Edge {
    int_fast32_t src;  // idx of the source vertex
    int_fast32_t to;  // idx of the vertex this edge reaches
    T cost;  // weight

    Edge(int_fast32_t to, T cost)
        : src(-1), to(to), cost(cost) {}
    Edge(int_fast32_t src, int_fast32_t to, T cost)
        : src(src), to(to), cost(cost) {}
};

template<typename T = int_fast32_t>
using GraphWeighted = std::vector<std::vector<Edge<T>>>;  // weighted graph
using Graph = std::vector<std::vector<int_fast32_t>>;  // graph
template<typename T = int_fast32_t>
using Matrix = std::vector<std::vector<T>>;  // adjacency matrix

/* warshall-floyd's algorithm */
// calculate costs of APSP (All Pairs Shortest Path)
// time complexity : O(V^3)
//
// Parameters
// 1. graph (Matrix<T>) : the adjacency matrix of the weighted graph.
// 2. unconnected_param (T) : the value in adjacency matrix representing unconnected path
// Returns
// 1. costs (vector<vector<T>>)
// : 2d-array containing costs of APSP
//   (costs[frm][to] == cost of "frm -> to")
//   if there is a negative cycle include "k", then costs[k][k] < 0
template<class T>
std::vector<std::vector<T>> WarshallFloyd(const Matrix<T> &graph, T unconnected_param) {
    using i32 = int_fast32_t;
    constexpr auto infinity = std::numeric_limits<T>::max();
    std::vector<std::vector<T>> costs = graph;
    // init costs
    for (i32 i = 0; i < graph.size(); ++i) {
        for (i32 j = 0; j < graph.size(); ++j) {
            if (graph[i][j] == unconnected_param) costs[i][j] = infinity;
            else costs[i][j] = graph[i][j];
        }
    }
    // calc
    for (i32 inter = 0; inter < costs.size(); ++inter) {
        for (i32 frm = 0; frm < costs.size(); ++frm) {
            for (i32 to = 0; to < costs.size(); ++to) {
                if (costs[frm][inter] == infinity ||
                    costs[inter][to] == infinity) {
                    continue;
                }
                costs[frm][to] = std::min<T>(costs[frm][to], costs[frm][inter] + costs[inter][to]);
            }
        }
    }
    return costs;
}

/* Main */
signed main(){
    double StartTimeOfMainFunction = clock();

    // fast io
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // cout << fixed << setprecision(15);  // fix io precision

    i32 v, e; cin >> v >> e;
    Matrix<i32> graph(v, vi(v, inf));
    rep(k, v) graph[k][k] = 0;
    rep(i, e) {
        i32 s, t, d; cin >> s >> t >> d;
        graph[s][t] = d;
    }

    auto dists = WarshallFloyd(graph, inf);
    bool ngcycle = 0;
    rep(k, v) {
        if(dists[k][k] < 0) ngcycle = 1;
    }
    if(ngcycle) {
        cout << "NEGATIVE CYCLE" << '\n';
    }
    else {
        rep(i, v) rep(j, v) {
            if (dists[i][j] == std::numeric_limits<i32>::max()) cout << "INF";
            else cout << dists[i][j];
            cout << (j == v-1 ? '\n' : ' ');
        }
    }

    // printf("Elapsed time: %5.3f ms\n",1000.*((clock()-StartTimeOfMainFunction)/CLOCKS_PER_SEC));
}

