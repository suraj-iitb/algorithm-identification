#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include <queue>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int max_n = 100000;
const int max_m = 100000;
using namespace std;
typedef pair<int,int> P;
const int maxv = 100000;
const ll inf = 1LL<<60;

struct edge{
    int to;
    ll cost;
    edge(int a, ll b){
        to = a;
        cost = b;
    }
};

template<class Abel> struct Dijkstra{
    priority_queue<P,vector<P>,greater<P> > que;
    vector<vector<edge> > G;
    vector<ll> d;
    vector<int> prev;
    Dijkstra(){
        G.resize(maxv);
        d.resize(maxv,inf);
        prev.resize(maxv);
        //d[s] = 0;
        //que.push(P(0,s)); //.first = startからの距離　second = 現在地点
    }
    
    void dijkstra(int s){
        d[s] = 0;
        que.push(P(0,s));
        while(!(que.empty())){
            P p = que.top(); que.pop();
            int v = p.second;
            if(d[v] < p.first)continue;
            for(int i = 0; i < G[v].size(); i++){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    prev[e.to] = v;
                    que.push(P(d[e.to], e.to));
                }
            }

        }
    }
};

int main(){
    //cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
    int V,E,r; cin >>V>>E>>r;
    Dijkstra<ll> dij;
    REP(i,E){
        int s,t; ll d;
        cin>>s>>t>>d;
        dij.G[s].push_back(edge(t,d));
    }
    dij.dijkstra(r);
    REP(i,V){
        if(dij.d[i] == inf) cout << "INF" << endl;
        else cout <<dij.d[i]  << endl;
    }
}
