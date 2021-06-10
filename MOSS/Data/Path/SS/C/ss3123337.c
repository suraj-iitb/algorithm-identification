#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
typedef pair<int, int> P;
vector<pair<int, int> > g[100000];
int main(void){
	int v, e, r;
	cin >> v >> e >> r;
	for(int i = 0; i < e; i++){
		int s, t, d;
		cin >> s >> t >> d;
		g[s].push_back(P(t, d));
	}
	priority_queue<P, vector<P>, greater<P> > que;
	int leng[v];
	fill(leng, leng + v, INF);
	leng[r] = 0; que.push(P(0, r));
	while(!que.empty()){
		P a = que.top(); que.pop();
		int cost = a.first, p = a.second;
		if(leng[p] < cost) continue;
		for(int i = 0; i < g[p].size(); i++){
			int to = g[p][i].first, to_cost = cost + g[p][i].second;
			if(leng[to] > to_cost) leng[to] = to_cost, que.push(P(leng[to], to));
		}
	}
	for(int i = 0; i < v; i++){
		if(leng[i] == INF) cout << "INF" << endl;
		else cout << leng[i] << endl;
	}
	return 0;
}
