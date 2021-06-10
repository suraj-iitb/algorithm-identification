#include<bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
using ll= long long;
using pii=pair<int, int>;
const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

/* dijkstra (pqueを使う)
    計算量：O(|E|log|V|)
    全ての辺のコストが非負のときに使える。
*/
struct edge{int to, cost;};

struct Dijkstra{
    int V, s;
    vector<ll> dist;
    vector<int> prev;
    Dijkstra(const vector<vector<edge>> &adj, int s_) : s(s_){init(adj);}
    void init(const vector<vector<edge>> &adj){
        V=(int)adj.size();
        dist.assign(V, LINF);
        prev.assign(V, -1);
        priority_queue<pii, vector<pii>, greater<pii>> pque;
        dist[s]=0;
        pque.push({dist[s], s});
        while (!pque.empty()) {
            auto p = pque.top();
            pque.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (auto &e : adj[v]) {
                if (dist[e.to] > dist[v] + e.cost) {  
                    dist[e.to] = dist[v] + e.cost;
                    prev[e.to]=v;
                    pque.push({dist[e.to], e.to});
                }
            }
        }
    }
    vector<int> get_path(int t){
        vector<int> path;
        for(; t != -1; t=prev[t]) path.push_back(t);
        reverse(all(path));
        return path;
    }
};





/* dijkstra (隣接行列を用いる)
    計算量：O(|V|^2)
*/
/*
struct edge{int to, cost;};

struct Dijkstra{
    int V, s;
    vector<ll> dist;
    vector<int> prev;
    vector<bool> used; 
    Dijkstra(const vector<vector<int>> &cost, int s_) : s(s_){init(cost);}
    void init(const vector<vector<int>> &cost){
        V=(int)cost.size();
        dist.assign(V, LINF);
        prev.assign(V, -1);
        used.assign(V, 0);
        dist[s]=0;
        while(1){
            int v=-1;
            for(int u=0; u<V; u++){
                if(!used[u] && (v == -1 || dist[u] < dist[v])) v=u;
            }
            if(v == -1) break;
            used[v]=true;
            for(int u=0; u<V; u++){
                if(dist[u] > dist[v]+cost[v][u]){
                    dist[u]=dist[v]+cost[v][u];
                    prev[u]=v;
                }
            }
        }
    }
    vector<int> get_path(int t){
        vector<int> path;
        for(; t != -1; t=prev[t]) path.push_back(t);
        reverse(all(path));
        return path;
    }
};
*/

int main(){
    int V, E, r; cin >> V >> E >> r;
    vector<vector<edge>> adj(V);
    for(int i=0; i<E; i++){
        int s, t, d; cin >> s >> t >> d;
        adj[s].push_back((struct edge){t, d});
    }
    Dijkstra di(adj, r);
    for(int i=0; i<V; i++){
        if(di.dist[i] == LINF) cout << "INF" << endl;
        else cout << di.dist[i] << endl;
    }
    return 0;
}
