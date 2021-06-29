#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define mkp(a,b) make_pair((a),(b))
#define fi first
#define se second

#define INF 10000000000000

int main() {
	int V, E, r;
	vector<vector<pair<long long,long long> > > v; // v[from][] ... fi = to, se = cost
	vector<pair<long long,bool> > cost; // fi = cost, se = flag

	cin >> V >> E >> r;
	v.resize(V);
	cost.resize(V);

	for(int i = 0; i < V; i++) {cost[i].fi = INF; cost[i].se = false;}

	for(int i = 0; i < E; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		v[s].push_back(mkp(t,d));
	}

	priority_queue<pair<long long,long long> , vector<pair<long long,long long> >, greater< pair<long long,long long> > > q; // fi = cost, se = virtex 
	q.push(mkp(0,r));
	cost[r].fi = 0;

	while(!q.empty()) {
		pair<long long,long long> tmp = q.top(); q.pop();
		if(cost[tmp.se].se)
			continue;

		cost[tmp.se].fi = tmp.fi;
		cost[tmp.se].se = true;
		for(int i = 0; i < v[tmp.se].size(); i++) {
			q.push(mkp(cost[tmp.se].fi + v[tmp.se][i].se , v[tmp.se][i].fi));
		}
	}

	for(int i = 0; i < cost.size(); i++) {
		if(cost[i].fi == INF)
			cout << "INF" << endl;
		else
			cout << cost[i].fi << endl;
	}

	return 0;
}
