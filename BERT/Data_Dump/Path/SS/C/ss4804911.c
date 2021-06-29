#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FSP(x) fixed << setprecision(x)
using namespace std;
using ll = long long;
constexpr ll INF = LLONG_MAX;
constexpr long double PI = acosl(-1);
void Yes() {cout << "Yes\n";}
void No() {cout << "No\n";}
void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}

#include <vector>
#include <queue>
#include <climits>
using edge_to = std::pair<long long, long long>;	// {weight, to}
using edge = std::vector<long long>;				// {weight, from, to}

/*	verified : 2020/07/17
		AOJ, Single Source Shortest Path
		http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
*/

std::vector<edge> edges(0); // 選んだ順に辺を格納　逆順に辿って経路復元
std::vector<long long> dijkstra(
	std::vector<std::vector<edge_to>>& adj_list,
	long long r
) {
	long long V = adj_list.size();
	std::vector<long long> ret(V, LLONG_MAX);
	ret[r] = 0;
	using P = std::pair<long long, edge>;
	std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
	for (auto i : adj_list[r]) {
		pq.push({i.first, {i.first, r, i.second}});
	}
	while (pq.size()) {
		while (pq.size() && ret[pq.top().second[2]] < LLONG_MAX) pq.pop();
		if (pq.empty()) break;
		long long w = pq.top().first; edge e = pq.top().second;
		pq.pop();
		ret[e[2]] = w;
		edges.push_back(e);
		for (auto i : adj_list[e[2]]) {
			if (ret[i.second] < LLONG_MAX) continue;
			long long next_w = ret[e[2]] + i.first;
			edge next_e = {i.first, e[2], i.second};
			pq.push({next_w, next_e});
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//constexpr ll P = 1e9 + 7;
	//constexpr ll P = 998244353;

	ll V, E, r;
	cin >> V >> E >> r;
	vector<vector<edge_to>> adj_list(V);
	for (ll i = 0; i < E; i++) {
		ll s, t, d;
		cin >> s >> t >> d;
		adj_list[s].push_back({d, t});
	}
	vector<ll> dist = dijkstra(adj_list, r);
	for (auto i : dist) {
		if (i == INF) cout << "INF\n";
		else cout << i << '\n';
	}
}
