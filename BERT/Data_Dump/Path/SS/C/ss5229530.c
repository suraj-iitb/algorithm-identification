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
using ll = long long;
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
constexpr ll infll = (1LL<<62)-1;
constexpr int inf = (1<<30)-1;
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

/* dijkstra's algorithm */
// calculate costs of SSSP (Single Source Shortest Path)
// time complexity : O((E + v)logV)
// 
// Parameters
// 1. graph (GraphWeighted) : weight of evey edge >= 0
// 2. start_vertex (i32) : idx of start_vertex
// Returns
// 1. min_dist (vec<T>) : min_dist[i] == cost of SSSP (start_vertex -> i)
template<class T>
std::vector<T> Dijkstra(const GraphWeighted<T> &graph, const int_fast32_t start_vertex) {
    constexpr auto infinity = std::numeric_limits<T>::max();
    std::vector<T> min_dist(graph.size(), infinity);

    using P = std::pair<T, int_fast32_t>;  // std::pair< DistFromStartingVertex, IndexOfVertex >
    std::priority_queue<P, std::vector<P>, std::greater<P>> min_heap;
    min_dist[start_vertex] = 0;
    min_heap.emplace(min_dist[start_vertex], start_vertex);

    while(!min_heap.empty()) {
        T dist;
        int_fast32_t index;
        tie(dist, index) = min_heap.top();
        min_heap.pop();
        if(dist > min_dist[index]) continue;

        for(auto &edge : graph[index]) {
            auto new_dist = dist + edge.cost;
            // compare the length of each route and change min_dist[edge.to]
            if(new_dist >= min_dist[edge.to]) continue;
            min_dist[edge.to] = new_dist;
            min_heap.emplace(min_dist[edge.to], edge.to);
        }
    }
    return min_dist;
}


/* Main */
signed main(){
    double StartTimeOfMainFunction = clock();

    // fast io
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // cout << fixed << setprecision(15);  // fix io precision

    i32 v, e, r; cin >> v >> e >> r;
    GraphWeighted<i32> g(v);
    rep(i, e) {
        i32 s, t, d; cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }
    auto dist = Dijkstra(g, r);
    for(auto d : dist) {
        if(d == std::numeric_limits<i32>::max()) {
            cout << "INF" << '\n';
        }
        else cout << d << '\n';
    }

    // printf("Elapsed time: %5.3f ms\n",1000.*((clock()-StartTimeOfMainFunction)/CLOCKS_PER_SEC));
}

