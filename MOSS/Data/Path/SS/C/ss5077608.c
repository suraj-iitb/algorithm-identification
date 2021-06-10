#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;
struct edge {ll to, cost;};
typedef pair<ll, ll> P; // firstはsからの最短距離, secondは頂点の番号
const ll INF = 1e17;
const int max_n = 101010;

int n;
vector<edge> g[max_n];

void dijkstra(ll s, vector<ll> &d){
	rep(i, n) d[i] = INF;
	d[s] = 0;

	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,s));

	while(!que.empty()){
		P p = que.top();
		que.pop();

		ll v = p.second;
		if(d[v] < p.first) continue; //後から最短パスが見つかった場合、先にqueに入っているものはここではじかれる

		for(ll i = 0; i < g[v].size(); i++){
			edge e= g[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int m, r;
	cin >> n >> m >> r;

	rep(i, m){
		ll a, b, d;
		cin >> a >> b >> d;
		g[a].push_back({b, d});
	}

	vector<ll> dist(n);
	dijkstra(r, dist);

	rep(i, n){
		if(dist[i] == INF){
			cout << "INF" << endl;
		}else{
			cout << dist[i] << endl;
		}
	}



}

