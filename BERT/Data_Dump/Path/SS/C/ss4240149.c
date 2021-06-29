#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
using namespace std;

//ダイクストラ法のテンプレ.graphはコスト付きの隣接リスト(node,costの順にpairに格納).
vector<int> dijkstra(vector<vector<pair<int,int>>> graph, int start){
	int inf = 2001001000;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	vector<int> dist(graph.size(),inf);
	dist[start] = 0;
	que.push(pair<int,int>(0,start));
	while(!que.empty()){
		pair<int,int> now = que.top();
		que.pop();
		int c = now.first, from = now.second;
		// if (dist[from] < c) continue;
		for (int i = 0; i < graph[from].size(); i++){
			int to = graph[from][i].first, cost = graph[from][i].second;
			if (dist[to] > dist[from] + cost){
				dist[to] = dist[from] + cost;
				que.push(pair<int,int>(dist[to],to));
			}
		}
	}
	return dist;
}

int main(){
	int v,e,r; cin >> v >> e >> r;
	vector<vector<pair<int,int>>> graph(v,vector<pair<int,int>>());
	for (int i = 0; i < e;i++){
		int a,b,c; cin >> a >> b >> c;
		graph[a].push_back(pair<int,int>(b,c));
	}
	vector<int> ans = dijkstra(graph,r);
	for (int i=0;i<ans.size();i++){
		if (ans[i] == 2001001000) cout << "INF" << endl;
		else cout << ans[i] << endl;
	}

	return 0;
}


