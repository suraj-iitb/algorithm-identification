#include <iostream>
#include <vector>
#include <queue>
#define INF (1LL<<50LL)

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<P> > G;

int main() {
	int v,e,r;
	cin >> v >> e >> r;
	G graph(v);
	for(int i = 0; i < e; i++) {
		int s,t,d;
		cin >> s >> t >> d;
		P p1(t,d);
		//P p2(s,d);
		graph[s].push_back(p1);
		//graph[t].push_back(p2);
	}
	vector<ll> ds(v,INF);
	vector<bool> arrived(v);
	priority_queue<P,vector<P>,greater<P> > q;
	P start(0,r);
	ds[r] = 0;
	q.push(start);
	while(!q.empty()) {
		P p = q.top();	q.pop();
		ll cost = p.first;
		ll now = p.second;
		if(arrived[now]) continue;
		arrived[now] = true;
		//cout << now << "," << cost << endl;
		for(int i = 0; i < graph[now].size(); i++) {
			P e = graph[now][i];
			ll next = e.first;
			ll d = e.second;
			ll new_cost = cost+d;
			if(ds[next]>new_cost) {
				ds[next] = new_cost;
				P new_edge(new_cost,next);
				q.push(new_edge);
			}
		}
	}
	for(int i = 0; i < v; i++) {
		if(ds[i] == INF) cout << "INF" << endl;
		else cout << ds[i] << endl;
	}
}

