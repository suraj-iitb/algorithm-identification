#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



class Dijkstra {
public:
    struct edge { ll v, dist; };

    struct state {
        ll v, cost;
        bool operator>(const state s) const { return cost > s.cost; }
    };

    const ll INF = (1LL << 60);
    ll N;
    ll MOD = 1e9+7;
    vector< vector<edge> > E;

    Dijkstra(ll n): N(n), E(n) {}

    //有効グラフの時はこっち。u→vに距離dで結ぶ
    void add_directed_edge(ll u, ll v, ll d) {
        E[u].push_back((edge) { v, d });
    }

    //無向グラフの時はこっち。uとvを双方向に距離dで結ぶ
    void add_undirected_edge(ll u, ll v, ll d) {
        E[u].push_back((edge) { v, d });
        E[v].push_back((edge) { u, d });
    }

    //Sを始点として、他の頂点への最短経路を探す
    vector<pair<ll,ll>> shortest_path(ll S) {
        vector<pair<ll,ll>> dp(E.size(), {INF,0});
        priority_queue<state, vector<state>, greater<state> > q;
        q.push((state) { S, 0 });
        dp[S].first = 0;
        dp[S].second = 1;
        while(!q.empty()) {
            ll v = q.top().v, cost = q.top().cost;
            q.pop();
            if(dp[v].first < cost) continue;
            for(int i=0;i < E[v].size() ; i++) {
                ll nv = E[v][i].v, ncost = cost + E[v][i].dist;
                if(dp[nv].first > ncost){
                    dp[nv].first = ncost;
                    dp[nv].second = dp[v].second;
                    q.push((state) { nv, ncost });
                }
                else if(dp[nv].first == ncost){
                    dp[nv].second += dp[v].second;
                    dp[nv].second %= MOD;
                }
            }
        }
        return dp;
    }
};



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    ll n,m,r;
    cin>>n>>m>>r;
    Dijkstra d(n);
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        d.add_directed_edge(a,b,c);
    }
    vector<pair<ll,ll>> v = d.shortest_path(r);
    for(int i=0;i<n;i++){
        if(v[i].first == (1LL<<60)){
            cout << "INF\n";
            continue;
        }
        cout << v[i].first << "\n";
    }

}
