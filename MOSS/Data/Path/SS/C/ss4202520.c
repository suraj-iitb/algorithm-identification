

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename NodeIdx,typename Cost>
vector<Cost> bellman_ford(vector<tuple<NodeIdx,NodeIdx,Cost>> &graph, NodeIdx n_node , NodeIdx start_idx){
    using Edge = tuple<NodeIdx,NodeIdx,Cost> ;
    const Cost INF = numeric_limits<Cost>::max();
    vector<Cost> d(n_node,INF);
    d[start_idx] = 0;
    while(true){
        bool update =false;
        for (const Edge &e : graph){
            if (d[get<0>(e)] != INF && d[get<1>(e)] > d[get<0>(e)] + get<2>(e) ){
                d[get<1>(e)] = d[get<0>(e)] + get<2>(e);
                update =true;
            }
        }
        if (!update) break;
    }
    return d;
    
}


int main(){
    ll V,E,r ;
    cin >> V>> E >> r;
    vector<tuple<ll,ll,ll>> graph;
    for (ll i=0;i<E;i++){
        ll v1,v2,c;
        cin >> v1 >> v2 >> c;
        graph.push_back(make_tuple(v1,v2,c));
    }
    vector<ll> ret = bellman_ford<ll,ll>(graph,V,r);
    for (const auto &c:ret){
        if (c == numeric_limits<ll>::max()) printf("INF\n");
        else printf("%lld\n",c);
    }

}
