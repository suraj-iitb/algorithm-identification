#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long int ll;
static const ll INF = 1LL << 60;

struct edge{
	int to; ll cost;
};
class Graph{
	public:
	vector<vector<edge> > adj;
	Graph(){}
	Graph(int V){
		adj.resize(V);
	}
	void add_edge(int s, edge e){
		adj[s].push_back(e);
	}
	bool comp(edge &a, edge &b){
		return a.cost < b.cost;
	}
	vector<ll> dijkstra(int s){
		priority_queue<pair<ll, int> , vector<pair<ll, int> > , greater<pair<ll, int> > > pqa;
		vector<ll> dist(adj.size(), INF);
		dist[s] = 0;
		pqa.push(make_pair(0, s));
		while(!pqa.empty()){
			pair<ll, int> p = pqa.top(); pqa.pop();
			int u = p.second;
			if(dist[u] < p.first) continue;
			for(int v = 0; v < adj[u].size(); v++){
				edge e = adj[u][v];
				if(dist[e.to] > dist[u] + e.cost){
					dist[e.to] = dist[u] + e.cost;
					pqa.push(make_pair(dist[e.to], e.to));
				}
			}
		}
		return dist;
	}
};

int main(){
	int V, E, r;
	cin >> V >> E >> r;
	Graph G(V);
	for(int i = 0; i < E; i++){
		int s, t, d;
		cin >> s >> t >> d;
		G.add_edge(s, (edge){t, d});
	}
	vector<ll> dist = G.dijkstra(r);
	for(int i = 0; i < V; i++){
		if(dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}

