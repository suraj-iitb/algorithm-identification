#include <iostream>
#include <functional>
#include <queue>

#define INF 1000000000

using namespace std;
class Edge {
public:
    Edge(){};
    Edge(int s, int t, int w) : s {s}, t {t}, w {w} {};
    int s;
    int t;
    int w;
};

class Graph {
public:
    Graph(int v, vector<Edge> es) : n {v}, vs {vector<vector<Edge>>(v)} {
        for(auto e : es){
            vs[e.s].push_back(e);
            vs[e.t].push_back(e);
        }
    };
    vector<int> dijkstra(int st){
        auto ds = vector<int>(n, INF);
        auto que = priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>>([](Edge a, Edge b){
                                                                                    return a.w > b.w;
                                                                                  }, vector<Edge>());
        que.push(Edge(st, st, 0));
        while(que.size()){
            Edge e = que.top();
            que.pop();
            if(ds[e.t] == INF){
                ds[e.t] = e.w;
                for(auto ne : vs[e.t]){
                    que.push(Edge(ne.s, ne.t, ne.w + ds[e.t]));
                }
            }
        }
        return ds;
    };
private:
    int n;
    vector<vector<Edge>> vs;
};
int main(){
    ios_base::sync_with_stdio(false);
    int v, e, r;
    cin >> v >> e >> r;
    auto es = vector<Edge>();
    int s, t, w;
    for(int i = 0; i < e; ++i){
        cin >> s >> t >> w;
        es.push_back(Edge(s, t, w));
    }
    auto gs = Graph(v, es);
    auto ds = gs.dijkstra(r);
    for(auto d : ds){
        if(d == INF){
            printf("INF\n");
        } else {
            printf("%d\n", d);
        }
    }
}
