#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

class Graph{
    public:
    using PL = pair<ll, ll>;
    const ll INF = 1e15;

    ll size;
    // has dist, to
    vector<vector<PL> > g;
    vector<ll> dist;

    Graph(ll n){
        size = n;
        g = vector<vector<PL> >(size);
        dist = vector<ll>(size);
    }

    void add_edge(ll x, ll y, ll w){
        g[x].push_back(make_pair(w, y));
    }

    void dijkstra(ll s){
        priority_queue<PL, vector<PL>, greater<PL> > PQ;
        fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;
        PQ.push(make_pair(0, s));

        while(!PQ.empty()){
            PL p = PQ.top(); PQ.pop();
            ll v = p.second;
            if(dist[v] < p.first) continue;
            for(PL np: g[v]){
                ll d = np.first;
                ll u = np.second;
                if(dist[u] > dist[v] + d){
                    dist[u] = dist[v] + d;
                    PQ.push(make_pair(dist[u], u));
                }
            }
        }
    }
};

// GRL_1_A: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int v, e, r; cin >> v >> e >> r;
    Graph graph(v);
    for(int i=0;i<e;i++){
        int s, t, d; cin >> s >> t >> d;
        graph.add_edge(s, t, d);
    }
    graph.dijkstra(r);
    for(int i=0;i<v;i++){
        if(graph.dist[i] >= graph.INF)
            cout << "INF" << endl;
        else
            cout << graph.dist[i] << endl;
    }
}
