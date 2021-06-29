#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

#define MAX 100001
#define INF INT_MAX

#define WHITE 0
#define GRAY 1
#define BLACK 2

int num_v, num_e, start;

vector<pair<int, int> > adj[MAX];
int color[MAX];
int dis[MAX];

void dijkstra(){
	priority_queue<pair<int, int> > pq;
	for(int i = 0; i < MAX; i++){
		color[i] = WHITE;
		dis[i] = INF;
	}

	dis[start] = 0;
	pq.push(make_pair(0,start));
	color[start] = GRAY;

	while(!pq.empty()){
		pair<int, int> f = pq.top();
		pq.pop();
		int u = f.second;
		color[u] = BLACK;

		if(dis[u] < f.first*(-1)) continue;

		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].first;
			if(color[v] == 2) continue;
			if(dis[v] > dis[u] + adj[u][i].second){
				dis[v] = dis[u] + adj[u][i].second;
				pq.push(make_pair(dis[v]*(-1), v));
				color[v] = 1;
			}
		}
	}
}

int main(){
	cin >> num_v >> num_e >> start;
	for(int i = 0;i < num_e;i++){
    int s = 0, t = 0, d = 0;
		cin >> s >> t >> d;
		adj[s].push_back(make_pair(t,d));
	}

	dijkstra();

	for(int i = 0;i < num_v;i++) (dis[i] == INF) ? cout << "INF" << endl : cout << dis[i] << endl;

	return 0;
}

