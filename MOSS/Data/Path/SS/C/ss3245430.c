#define _CRT_SECURE_NO_WARNINGS
#include"bits/stdc++.h"
#ifdef _DEBUG
#define DBG(n) n
#else
#define DBG(n)
#endif
#define INF         1e9
#define INFLL       1e18
#define EPS         1e-9
#define REP(i,n)    for(ll i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)   for(ll i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)   for(ll i=(n)-1;i>=0;--i)
#define REPR1(i,n)  for(ll i=(n);i>0;--i)
#define REPC(i,obj) for(auto i:obj)
#define ALL(obj)    (obj).begin(),(obj).end()
#define SETP(n)     cout << fixed << setprecision(n)
using namespace std;
using ll = long long;
template<typename T = ll>inline T in() { T ret; cin >> ret; return ret; }

vector<ll>dijkstra(const vector<vector<pair<ll, ll>>>&edge, ll start = 0)
{
	vector<ll>dist(edge.size(), INFLL); dist[start] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, function<bool(const pair<ll, ll>&, const pair<ll, ll>&)>> node_queue([](const pair<ll, ll>&p1, const pair<ll, ll>&p2) {return p1.second > p2.second; });
	node_queue.push(make_pair(start, 0));
	while (!node_queue.empty()) {
		ll tpn_index = node_queue.top().first, tpn_cost = node_queue.top().second; node_queue.pop();
		for (auto i : edge[tpn_index]) {
			ll dst_index = i.first, dst_cost = i.second;
			if (tpn_cost + dst_cost < dist[dst_index]) {
				dist[dst_index] = tpn_cost + dst_cost;
				node_queue.push(make_pair(dst_index, dist[dst_index]));
			}
		}
	}
	return dist;
}
signed main()
{
	ll v = in(), e = in(), r = in();
	vector<vector<pair<ll, ll>>>edge(v);
	REP(i, e) {
		ll s = in(), t = in(), d = in();
		edge[s].push_back(make_pair(t, d));
	}
	vector<ll>cost(move(dijkstra(edge,r)));
	REP(i, v) {
		if (cost[i] == INFLL) {
			cout << "INF" << endl;
		} else {
			cout << cost[i] << endl;
		}
	}
}
