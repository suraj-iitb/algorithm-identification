#include <bits/stdc++.h>
using namespace std;

const int INF = 1.5e9;

//Graph/Template
template<class T>
struct Edge{
	int from,to;
	T cost;
	Edge(int to,T cost) : to(to),cost(cost){}
	Edge(int from,int to,T cost) : from(from),to(to),cost(cost){}
};

template<class T>
using WeightedGraph = vector<vector<Edge<T>>>;
using Graph = vector<vector<int>>;
template<class T>
using Matrix = vector<vector<T>>;

//Graph/Dijkstra
template<class T>
vector<T> dijkstra(const WeightedGraph<T> &G,int source = 0){
	using P = pair<T,int>;
	vector<T> dist(G.size(),INF);
	priority_queue<P,vector<P>,greater<P>> que;
	dist[source] = 0;
	que.emplace(dist[source],source);
	while(!que.empty()){
		P p = que.top();que.pop();
		int v = p.second;
		if(dist[v] < p.first) continue;
		for(const auto &e : G[v]){
			if(dist[e.to] > dist[v] + e.cost){
				dist[e.to] = dist[v] + e.cost;
				que.emplace(dist[e.to],e.to);
			}
		}
	}
	return dist;
}

signed main(){
	int n,m,r;
	scanf("%d %d %d",&n,&m,&r);
	WeightedGraph<int> G(n);
	for(int i = 0;i < m;i++){
		int s,t,d;
		scanf("%d %d %d",&s,&t,&d);
		G[s].emplace_back(t,d);
	}
	vector<int> dist = dijkstra(G,r);
	for(int i = 0;i < n;i++){
		if(dist[i] == INF) printf("INF\n");
		else printf("%d\n",dist[i]);
	}
}

