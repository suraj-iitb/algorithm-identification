#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll);
ll mod_fact(ll, ll);
ll mod_inv(ll, ll);
//
struct Edge{
    ll to;
    ll dis;
    Edge(ll to, ll dis) : to(to), dis(dis){};
};
using Graph = vector<vector<Edge>>;
void dijkstra(const Graph&, vector<ll>&, int);

using P = pair<ll, int>;
int main(){
    int V, E, r;
    cin >> V >> E >> r;
    Graph graph;
    graph.resize(V);
    for(int i = 0; i < E; i++){
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].emplace_back(t, d);
    }
    vector<ll> distance(V, INF);
    dijkstra(graph, distance, r);
    for(int i = 0; i < V; i++){
        if(distance[i] != INF){
            cout << distance[i] << "\n";
        }else{
            cout << "INF" << "\n";
        }
    }
}
void dijkstra(const Graph &G, vector<ll> &D, int s){
    D[s] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, s);
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if(D[v] < p.first) continue;
        else{
            for(Edge e : G[v]){
                if(D[e.to] > D[v] + e.dis){
                    D[e.to] = D[v] + e.dis;
                    pq.emplace(D[v] + e.dis, e.to);
                }
            }
        }
    }
}
