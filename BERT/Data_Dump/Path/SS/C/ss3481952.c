#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100001
#define INF 1e+9

int V,E,r;
vector<pair<int, int> > adj[MAX];
int color[MAX];
int d[MAX];

void dijkstra(){
	priority_queue<pair<int, int> > pq;
	for(int i = 0;i < MAX;i++){
		color[i] = 0;
		d[i] = INF;
	}

	d[r] = 0;
	pq.push(make_pair(0,r));
	color[r] = 1;

	while(!pq.empty()){
		pair<int, int> f = pq.top();
		pq.pop();
		int u = f.second;
		color[u] = 2;

		if(d[u] < f.first*(-1)) continue;

		for(int i = 0;i < adj[u].size();i++){
			int v = adj[u][i].first;
			if(color[v] == 2)continue;
			if(d[v] > d[u] + adj[u][i].second){
				d[v] = d[u] + adj[u][i].second;
				pq.push(make_pair(d[v]*(-1), v));
				color[v] = 1;
			}
		}
	}
}

int main(){
	int s,t,di;
	cin >> V >> E >> r;
	for(int i = 0;i < E;i++){
		cin >> s >> t >> di;
		adj[s].push_back(make_pair(t,di));
	}

	dijkstra();

	for(int i = 0;i < V;i++){
		if(d[i] == INF){
			cout << "INF" << endl;
		}
		else{
			cout << d[i] << endl;
		}
	}

	return 0;
}
