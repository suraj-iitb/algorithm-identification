#ifndef GRAPH_DIJKSTRA_HPP
#define GRAPH_DIJKSTRA_HPP

#ifndef GRAPH_GRAPH_HPP
#define GRAPH_GRAPH_HPP

#ifndef COMMON_HPP
#define COMMON_HPP

#ifndef ELIMINATE_SYSTEM_HEADERS

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#endif

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef vector<vi>     vvi;
typedef pair<int, int> pii;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

const int INT_INF = 1001001001;

#endif


struct Edge
{
    int src, dst;
    
    Edge() = default;
    Edge(int src, int dst) : src(src), dst(dst) {}
};

template<class WeightType = int>
struct WeightedEdge : Edge
{
    typedef WeightType Weight;
    Weight weight;
    
    WeightedEdge() = default;
    WeightedEdge(int src, int dst, Weight weight) : Edge(src, dst), weight(weight) {}
    
    bool operator< (const WeightedEdge& e) const {
        return weight < e.weight;
    }
    
    bool operator> (const WeightedEdge& e) const {
        return weight > e.weight;
    }
};

template<class EdgeType = Edge>
struct AdjacentList : public vector<vector<EdgeType>>
{
    typedef EdgeType Edge;
    
    AdjacentList() = default;
    AdjacentList(size_t V) : vector<vector<Edge>>(V) {}
};

#endif


/*
 * time:  O((V+E) log V)
 * space: O(V)
 */
template<class GraphType = AdjacentList<WeightedEdge<>>>
struct Dijkstra
{
    typedef GraphType Graph;
    typedef typename Graph::Edge::Weight Weight;
    
    // -2: start, -1: unreachable
    vi prev;
    vector<Weight> dist;
    
    Weight operator()(const Graph& G, int s, int t = -1)
    {
        prev.assign(G.size(), -1);
        dist.assign(G.size(), numeric_limits<Weight>::max() / 2);
        dist[s] = 0;
        
        typedef WeightedEdge<Weight> Data;
        priority_queue<Data, vector<Data>, greater<Data>> Q;
        Q.emplace(-2, s, 0);
        
        do{
            Data p = Q.top();
            Q.pop();
            
            if(prev[p.dst] != -1) continue;
            prev[p.dst] = p.src;
            
            if(p.dst == t) return p.weight;
            
            for(const auto& e : G[p.dst]){
                Weight w = p.weight + e.weight;
                if(dist[e.dst] > w){
                    dist[e.dst] = w;
                    Q.emplace(e.src, e.dst, w);
                }
            }
        }while(!Q.empty());
        
        return 0;
    }
    
    vi build_path(int v)
    {
        vi path;
        for(; v >= 0; v = prev[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        return path;
    }
};

#endif


int main()
{
    int V, E, r;
    cin >> V >> E >> r;
    
    Dijkstra<>::Graph G(V);
    rep(i, E){
        int s, t, d;
        cin >> s >> t >> d;
        G[s].emplace_back(s, t, d);
    }
    
    Dijkstra<> dijkstra;
    dijkstra(G, r);

    rep(i, V){
        if(dijkstra.prev[i] == -1) cout << "INF" << endl;
        else cout << dijkstra.dist[i] << endl;
    }
}
