#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int inf = 1000000007;
constexpr long long mod = 1000000007LL;
//constexpr long long mod = 998244353LL;
const long double PI = acos(-1);

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

vector<ll> dijkstra(int start, vector<vector<pair<int, ll>>>& graph) {
	vector<ll> dist(graph.size(), INF); dist[start] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; pq.emplace(0, start);
	while (!pq.empty()) {
		ll cost; int idx; tie(cost, idx) = pq.top(); pq.pop();
		if (dist[idx] < cost) continue;
		for (auto next : graph[idx]) if (chmin(dist[next.first], cost + next.second)) pq.emplace(dist[next.first], next.first);
	}
	return dist;
}


int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/

	int V, E, r; scanf("%d %d %d", &V, &E, &r);
	vector<vector<pair<int, ll>>> g(V); //g[i] := iからjまでの距離がd
	for (int i = 0; i < E; i++) {
		int s, t, d; scanf("%d %d %d", &s, &t, &d);
		g[s].emplace_back(t, d);
	}
	auto d = dijkstra(r, g);
	for (int i = 0; i < V; i++) {
		if (d[i] == INF) puts("INF");
		else printf("%lld\n", d[i]);
	}
	return 0;

}
