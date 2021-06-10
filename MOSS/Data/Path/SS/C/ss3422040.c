#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;
typedef long long lint;

// Graph Templates
using Weight = lint;
// using Flow = int;
struct Edge {
    int src, dst;
    Weight weight;
    // Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;
const Weight INF = numeric_limits<Weight>::max() / 8;

// add edge a <--(weight = w)--> b
void add_edge(Graph &g, int a, int b, Weight w) {
    g[a].push_back(Edge(a, b, w));
    g[b].push_back(Edge(b, a, w));
}

// add edge a --(weight = w)--> b
void add_arc(Graph &g, int a, int b, Weight w) { g[a].push_back(Edge(a, b, w)); }

// Dijkstra
// g is graph, s is start
vector<Weight> dijkstra(const Graph &g, int s) {
    // const Weight INF = numeric_limits<Weight>::max() / 8;
    using state = tuple<Weight, int>;
    priority_queue<state> q;
    vector<Weight> dist(g.size(), INF);
    dist[s] = 0;
    q.emplace(0, s);
    while (q.size()) {
        Weight d;
        int v;
        tie(d, v) = q.top();
        q.pop();
        d *= -1;
        /* if(v == t) return d; */
        if (dist[v] < d) continue;
        for (auto &e : g[v]) {
            if (dist[e.dst] > dist[v] + e.weight) {
                dist[e.dst] = dist[v] + e.weight;
                q.emplace(-dist[e.dst], e.dst);
            }
        }
    }
    return dist;
}

int main(){
    int v, e, r;
    int s, t;
    Weight d;
    Graph g;
    vector<Weight> dist;
    cin >> v >> e >> r;
    g.resize(v);
    for (int i=0; i<e; ++i){
        cin >> s >> t >> d;
        add_arc(g, s, t, d);
    }
    dist = dijkstra(g, r);
    for (int i=0; i<(int)dist.size(); ++i){
        if(dist[i] != INF){
            cout << dist[i] << endl;
        }
        else {
            cout << "INF" << endl;
        }
    }
    
    return 0;
}

