#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

struct edge {
	int to;
	int cost;
};
typedef pair<int, int> P;
vector<int> d;

template<typename T > class RadixHeapInt64 {
private:
	using uint = unsigned long long;
	vector< pair<uint,T> > v[65];
	ll last, size;
	int bsr(uint x) {
		if (x == 0)return -1;
		return 64 - __builtin_clzll(x);
	}
public:
	RadixHeapInt64() {
		last = size = 0;
	}
	bool empty() {
		return size == 0;
	}
	//p = {priority,value}
	void push(uint priority, const T& value) {
		size++;
		v[bsr(priority ^ last) + 1].emplace_back(priority,value);
	}
	pair<uint,T> pop() {
		if (!v[0].size()) {
			int i = 1;
			while (!v[i].size())i++;
			last = (*min_element(v[i].begin(), v[i].end())).first;
			for (int j = 0; j < v[i].size(); j++) {
				v[bsr(v[i][j].first ^ last) + 1].push_back(v[i][j]);
			}
			v[i].clear();
		}
		size--;
		auto ret = v[0].back();
		v[0].pop_back();
		return ret;
	}
};

void dijkstra(int s, vector<vector<edge>>& g) {
	RadixHeapInt64<int> q;
	d = vector<int>(g.size(), INF);
	d[s] = 0;
	q.push(0, s);

	while (!q.empty()) {
		P p = q.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < g[v].size(); i++) {
			edge e = g[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				q.push(d[e.to], e.to);
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int V, E, s;
	cin >> V >> E >> s;
	vector<vector<edge>> g(V);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back(edge{ b,c });
	}
	for(int i = 0; i < 100; i++)dijkstra(s, g);
	for (int i = 0; i < V; i++) {
		if (d[i] == INF)cout << "INF" << endl;
		else cout << d[i] << endl;
	}
}
