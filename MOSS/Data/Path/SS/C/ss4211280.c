#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

typedef pair<int,int> P;
const int INF = 1e+9;

struct  edge{
	int to;
	int cost;
};

int dist[100005];
vector<edge> G[100005];

void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P>> que;
	dist[s] = 0;
	que.push(make_pair(0,s));
	
	while (!que.empty()){
		auto p = que.top();
		que.pop();
		int v = p.second;
		for (auto nextv: G[v]){
			if(dist[nextv.to] > dist[v] + nextv.cost){
				dist[nextv.to] = dist[v] + nextv.cost;
				que.push(make_pair(dist[nextv.to], nextv.to));
			}
		}
	}
}

int main(){
	int V,E,r;
	cin >> V >> E >> r;
	
	
	rep(i,E){
		int s,t,d;
		cin >> s >> t >> d;
		edge e = {t,d};
		G[s].push_back(e);
	}
	
	rep(i,V){
		dist[i] = INF;
	}
	
	dijkstra(r);
	
	rep(i,V){
		if(dist[i] == INF){
			cout << "INF" << endl;
		}else{
			cout << dist[i] << endl;
		}
	}
	
    return 0;
}


