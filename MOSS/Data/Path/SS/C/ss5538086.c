#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define int long long
using namespace std;
typedef pair<int, int> P;

#define INF 1e18
int N;
struct edge{ int to, cost; };

// 引数１.スタート地点。引数２.有向辺の集合
// Q: first...sからの暫定距離。second...頂点
// 古い優先度のものは、22行目(if)ですべてはじかれる
vector<int> dijkstra(int s, vector<edge>* E){
	priority_queue<P, vector<P>, greater<P>> Q;
	vector<int> dist(N, INF);
	Q.emplace(0, s);
	dist[s] = 0;
	while(!Q.empty()){
		auto cu = Q.top(); Q.pop();
		for(edge e : E[cu.second]){
			if(dist[e.to] > dist[cu.second] + e.cost){
				dist[e.to] = dist[cu.second] + e.cost;
				Q.emplace(dist[e.to], e.to);
			}
		}
	}
	return dist;
}

int32_t main(){
	int K, r;
	cin >> N >> K >> r;
	vector<edge> E[N];
	rep(i, K){
		int a, b, c;
		cin >> a >> b >> c;
		edge e;
		e.to = b;
		e.cost = c;
		E[a].push_back(e);
	}
	auto dist = dijkstra(r, E);
	rep(i, N){
		dist[i] == INF ? cout << "INF" : cout << dist[i];
		cout << endl;
	}
	return 0;
}
