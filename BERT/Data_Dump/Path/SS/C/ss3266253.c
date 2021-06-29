#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <functional>
using namespace std;

typedef long long ll;

int v, e, r;
struct edge{
	int cost;
	int to;
};
vector<edge> edges[100001];


int main(){
	
	
	
	cin >> v >> e >> r;
	for(int i = 0;i < e;i ++){
		int s, t, d;
		cin >> s >> t >> d;
		edge pre = {d, t};
		edges[s].push_back(pre);
	}
	ll ans[100001];
	for(int i = 0;i < 100001;i ++) ans[i] = 2001001001;
	ans[r] = 0;
	
	typedef pair<ll, ll> P;
	priority_queue<P, vector<P>, greater<P> > pq;
	
	pq.push(P(0,r));
	while(!pq.empty()){
		P miria = pq.top();
		pq.pop();
		r = miria.second;
		if(ans[r] < miria.first){
			continue;
		}
		for(int i = 0;i < edges[r].size();i ++){
			if(ans[edges[r][i].to] > ans[r] + edges[r][i].cost){
				pq.push(P(ans[r] + edges[r][i].cost, edges[r][i].to));
				ans[edges[r][i].to] = ans[r] + edges[r][i].cost;
			}
		}
	}
	
	for(int i = 0;i < v;i ++){
		if(ans[i] < 2001001000) cout << ans[i] << endl;
		else cout << "INF" << endl;
	}
	
	return 0;
}
