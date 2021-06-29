#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;
const ll INF = (1LL<<60);

struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
    ll V;
    vector<vector<edge> > G;
    vector<ll> d;

    graph(ll n){
        init(n);
    }

    void init(ll n){
        V = n;
        G.resize(V);
        d.resize(V);
        rep(i,V){
        d[i] = INF;
        }
    }

    void add_edge(ll s, ll t, ll cost){
        edge e;
        e.to = t, e.cost = cost;
        G[s].push_back(e);
    }

    void dijkstra(ll s){
        rep(i,V) d[i] = INF;
        d[s] = 0;
        priority_queue<P,vector<P>, greater<P> > que;
        que.push(P(0,s));
        while(!que.empty()){
            P p = que.top(); que.pop();
            ll v = p.second;
            if(d[v]<p.first) continue;
            for(auto e : G[v]){
                if(d[e.to]>d[v]+e.cost){
                    d[e.to] = d[v]+e.cost;
                    que.push(P(d[e.to],e.to));
                }
            }
        }
    }
};


int main(){
    int V,E,r;
    cin >> V >> E >> r;

    graph g(V);
    rep(i,E){
        int s,t,d; cin >> s >> t >> d;
        g.add_edge(s,t,d);
    }

    g.dijkstra(r);

    rep(i,V){
        if(g.d[i]==INF) cout << "INF" << endl;
        else cout << g.d[i] << endl;
    }
}
