#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007LL
#define REP(i, n) for(int i=0;i<(n);++i)
typedef long long ll;

#define INF 2000000000
int V, E, r;
typedef pair<int, int> P;
struct edge {int to, cost;};
vector<edge> graph[100000];
int d[100000];

void dijkstra(int s){
	fill(d, d+V, INF); d[s] = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(P(0, s));
	while(!que.empty()){
		P a = que.top(); que.pop();
		if(d[a.second] < a.first) continue;
		REP(i, graph[a.second].size()){
			edge e = graph[a.second][i];
			if(d[e.to] > d[a.second]+e.cost){
				d[e.to] = d[a.second]+e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> V >> E >> r;
	REP(i, E){
		int s, t, d; cin >> s >> t >> d;
		graph[s].push_back({t, d});
	}
	dijkstra(r);
	REP(i, V){
		if(d[i] == INF) cout << "INF" << endl;
		else cout << d[i] << endl;
	}

	return 0;
}

