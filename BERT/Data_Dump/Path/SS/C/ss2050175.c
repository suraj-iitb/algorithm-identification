#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#define INF 1e+18
using namespace std;

struct Edge{
	int trg;
	long long w;
};

struct vertex{
	int v;
	long long w;
	bool operator < (const vertex &x) const{
		return w < x.w;
	}
	bool operator > (const vertex &x) const{
		return w > x.w;
	}
};

const int MAX_V = 100000;
vector<vector <Edge> > graph(MAX_V);
vector<long long> min_cost(MAX_V,INF);
vector<bool> used(MAX_V,false);

void dijkstra(int s, int V){
	min_cost[s] = 0;

	priority_queue< vertex,vector<vertex>,greater<vertex> > pq;
	pq.push(vertex{s,0});
	while (!pq.empty() ) {
		vertex ver =  pq.top();	
		pq.pop();
		int v = ver.v;
		if ( used[v] ) continue;		
		used[v] = true;
		min_cost[v] = ver.w;

		for (int i = 0; i < graph[v].size(); i++){
			if (!used[graph[v][i].trg]){
				pq.push(vertex{graph[v][i].trg, min_cost[v] + graph[v][i].w});
			}
		}
	}
}	

void print_array(vector<long long>& array, int node){
	for (int i = 0; i < node; i++) {
		if ( array[i] == INF) {
			cout << "INF" << endl;
		}else{
			cout << array[i] << endl;
		}
	}
}

int main (){

	int V,E,r;
	cin >> V >> E >> r;
	int s,t,d;
	for (int i = 0; i < E ; i++) {
		cin >> s >> t >> d;
		graph[s].push_back(Edge{t,d});
	}
	dijkstra(r,V);
	print_array(min_cost,V);

	return 0;
}
