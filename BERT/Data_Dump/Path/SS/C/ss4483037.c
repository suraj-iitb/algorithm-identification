#include <bits/stdc++.h>
using namespace std;


template<typename T>
struct Dijkstra {
    struct Edge {
        int to;
        T cost;
        Edge(int to, T cost) : to(to), cost(cost){}
        bool operator<(const Edge& e) const { return cost > e.cost; }
    };
    vector<vector<Edge>> G;
    vector<T> ds;
    vector<int> bs;
    Dijkstra() = default;
    Dijkstra(int n) : G(n){}
    void addEdge(int u, int v, T c){
        G[u].emplace_back(v, c);
    }
    void build(int s){
        int n = G.size();
        ds.assign(n, numeric_limits<T>::max());
        bs.assign(n, -1);
        priority_queue<Edge> pq;
        ds[s] = 0;
        pq.emplace(s, ds[s]);
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            int v = p.to;
            if(ds[v] < p.cost) continue;
            for(auto e : G[v]){
                if(ds[e.to] > ds[v]+e.cost){
                    ds[e.to] = ds[v]+e.cost;
                    bs[e.to] = v;
                    pq.emplace(e.to, ds[e.to]);
                }
            }
        }
    }
    T operator[](int k){ return ds[k]; }
    vector<int> restore(int to){
        vector<int> res;
        if(bs[to] < 0) return res;
        while(~to) res.emplace_back(to), to = bs[to];
        reverse(begin(res), end(res));
        return res;
    }
};


int V, E, r;
Dijkstra<int> G;


signed main(){
    cin >> V >> E >> r;
    G = Dijkstra<int>(V);
    for(int i = 0;i < E;i++){
        int s, t, d;
        cin >> s >> t >> d;
        G.addEdge(s, t, d);
    }

    G.build(r);
    for(int i = 0;i < V;i++)
        if(G[i] < numeric_limits<int>::max()) cout << G[i] << endl;
        else cout << "INF" << endl;

    return 0;
}
