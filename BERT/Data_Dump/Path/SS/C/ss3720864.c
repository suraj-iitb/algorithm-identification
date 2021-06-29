#include<bits/stdc++.h>
using namespace std;
using Long = long long;

template<typename W>
using Edge = pair<int, W>;

template<typename W>
using WeightedGraph = vector<vector<Edge<W>>>;

// 時間計算量 O( (E+V) log V )
template <typename W>
vector<W> dijkstra(int s, WeightedGraph<W> &G){  
    // s : 始点, G : 隣接リスト G[v1][v2] : (頂点, 重み)
    const W INF = numeric_limits<W>::max();
    // P.first : 距離, P.second : 頂点番号
    using P = pair<W, int>;
    // n : |V|
    int n = G.size();
    // d[i] : 始点からiまでの最短距離
    vector<W> d(n,INF);
    vector<int> b(n,-1);
    priority_queue<P,vector<P>,greater<P> > q;
    d[s] = 0;
    q.emplace(d[s],s);
    while(!q.empty()){
        P p = q.top();q.pop();
        int v = p.second;
        if( d[v]<p.first ) continue;
        for( auto&& e : G[v] ){
            int u = e.first;
            W c = e.second;
            if(d[u] > d[v]+c){
                d[u] = d[v]+c;
                b[u] = v;
                q.emplace(d[u],u);
            }
        }
    }
    return d;
}
//END CUT HERE

int main(){
    int V,E,r;
    int s,t,d;
    cin >> V >> E >> r;
    WeightedGraph<int> G(V);
    for(int i = 0; i < E; i++) {
        cin >> s >> t >> d;
        G[s].emplace_back(t, d);
    }
    auto D = dijkstra(r, G);
    for(int i = 0; i < V; i++) {
        if (D[i] == numeric_limits<int>::max()) {
            cout << "INF" << endl;
        }
        else {
            cout << D[i] << endl;
        }
    }
}
