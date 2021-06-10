#include <bits/stdc++.h>

using i32 = std::int32_t;
using i64 = std::int64_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using usize = std::size_t;

const i32 INF = 1001001001;
const i64 LINF = 1001001001001001;
const u32 MOD1 = 1000000007;
const u32 MOD2 = 998244353;

template<class E> struct Edge {
    i32 from, to;
    E cost;
};

template<class E> struct Graph {
    std::vector<std::vector<Edge<E>>> edges;
    Graph(const usize& n): edges(n) {}
    std::vector<Edge<E>> operator[](const usize& x) const {
        return edges[x];
    }
    usize size() const {
        return edges.size();
    }
    void add_edge(const i32& from, const i32& to, const E& cost = 1) {
        edges[from].emplace_back((Edge<E>){ from, to, cost });
    }
};

template<typename E> std::vector<E> bellman_ford(const std::vector<Edge<E>>& edges, const usize& V, const i32& s, const E& inf) {
    std::vector<E> dist(V, inf);
    dist[s] = 0;
    for(usize i = 0; i < V; i++) {
        bool update = false;
        for(const auto& e : edges) {
            i32 u = e.from, v = e.to;
            if(dist[u] != inf && dist[v] > dist[u] + e.cost) {
                dist[v] = dist[u] + e.cost;
                update = true;
                if(i == V - 1) return std::vector<E>();
            }
        }
        if(!update) break;
    }
    return dist;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i32 v,e,r;
    std::cin>>v>>e>>r;
    std::vector<Edge<i64>> es;
    for(i32 i=0;i<e;i++){
        i32 s,t,d;
        std::cin>>s>>t>>d;
        es.emplace_back((Edge<i64>){s,t,d});
    }
    std::vector<i64> dist=bellman_ford<i64>(es,v,r,LINF);
    for(i32 i=0;i<v;i++){
        if(dist[i]==LINF)std::cout<<"INF"<<std::endl;
        else std::cout<<dist[i]<<std::endl;
    }
}
