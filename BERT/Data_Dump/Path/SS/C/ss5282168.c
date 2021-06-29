#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const LL inf = 1LL << 60;
vector<PLI> graph[maxn];
priority_queue<PLI, vector<PLI>, greater<PLI> > pq;
vector<LL> dist(maxn, inf);
int n, m, r;

void dijkstra(){
	dist[r] = 0;
	pq.push(make_pair(0, r));
	while(! pq.empty()){
		PLI p = pq.top();
		pq.pop();
		int nd = p.second;
		LL d = p.first;
		if (d > dist[nd]) continue;
		for (int i = 0; i < graph[nd].size(); i ++){
			int to = graph[nd][i].second;
			LL w = graph[nd][i].first;
			if (w + d < dist[to]){
				dist[to] = w + d;
				pq.push(make_pair(dist[to], to));
			}
		}
	}
}

int main(){
	cin >> n >> m >> r;
	for (int i = 0; i < m; i ++){
		int x, y; LL d;
		cin >> x >> y >> d;
		graph[x].push_back(make_pair(d, y));
	}
	dijkstra();
	for (int i = 0; i < n; i ++){
		if (dist[i] == inf) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
}
