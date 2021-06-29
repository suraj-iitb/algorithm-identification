#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint V, e, r;
vector<edge> G[100005];
llint dist[100005];

void dijkstra(vector<edge> G[], llint S, llint dist[])
{
	for(int i = 0; i <= V; i++) dist[i] = inf;
	dist[S] = 0;
	
	priority_queue< P, vector<P>, greater<P> > Q;
	Q.push( make_pair(0, S) );
	
	llint v, d;
	while(Q.size()){
		d = Q.top().first;
		v = Q.top().second;
		Q.pop();
		if(dist[v] < d) continue;
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i].to] > d + G[v][i].cost){
				dist[G[v][i].to] = d + G[v][i].cost;
				Q.push( make_pair(dist[G[v][i].to], G[v][i].to) );
			}
		}
	}
}

int main(void)
{
	cin >> V >> e >> r;
	llint u, v, w;
	for(int i = 1; i <= e; i++){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w));
	}
	
	dijkstra(G, r, dist);
	
	for(int i = 0; i < V; i++){
		if(dist[i] > inf/2) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}
	flush(cout);
	
	return 0;
}

