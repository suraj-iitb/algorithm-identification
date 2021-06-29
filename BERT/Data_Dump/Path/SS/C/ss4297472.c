#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct State{
    int at;
    long long cost;
    State(int a, long long c) : at(a), cost(c){}
    bool operator>(const State& s) const{
        return cost > s.cost;
    }
};

struct Edge{
    int to;
    long long cost;
    Edge(int t, long long c) : to(t), cost(c){}
};

using Graph = vector<vector<Edge> >;
const long long INF = 1e15;

void dijkstra(int s, const Graph& G, vector<long long>& minc){
    minc.assign(G.size(), INF);
    priority_queue<State, vector<State>, greater<State> > pq;
    pq.emplace(s, 0);
    minc[s] = 0;

    while(!pq.empty()){
        State cur = pq.top();
        pq.pop();
        if(minc[cur.at] < cur.cost) continue;
        for(const Edge& e : G[cur.at]){
            long long cost = cur.cost + e.cost;
            if(minc[e.to] <= cost) continue;
            minc[e.to] = cost;
            pq.emplace(e.to, cost);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e, r;
    cin >> v >> e  >> r;
    Graph G(v);
    rep(i,e){
		int s, t;
		ll d;
		cin >> s >> t >> d;
		G[s].emplace_back(t, d);
	}
    vector<ll> dist(v, INF);
	dijkstra(r, G, dist);
	rep(i,v){
		if(dist[i] != INF) cout << dist[i] << endl;
		else cout << "INF" << endl;
	}
    return 0;
}
