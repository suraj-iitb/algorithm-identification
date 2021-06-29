#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;
typedef long long signed int ll;

constexpr int inf = INT32_MAX / 2;

//template <class Tnode>
class djikstra {
private:
	ll* d = nullptr;
	map<int, map<int, ll>> p;
	int sz = 0;
public:
	void add_path(int from, int to, ll cost) {
		p[from][to] = cost;
	}
	void compute(int from,int nodes) {
		sz = nodes;
		if (d != nullptr) delete d;
		d = new ll[nodes];
		auto cmp = [this](int a, int b) {return d[a] > d[b]; };
		priority_queue <ll, vector<ll>, decltype(cmp)> q(cmp);
		for (int i = 0; i < nodes; i++) d[i] = INT64_MAX / 2;
		d[from] = 0;
		q.push(from);
		while (!q.empty()) {
			for (auto& e : p[q.top()]) {
				if (d[e.first] > d[q.top()] + e.second) {
					d[e.first] = d[q.top()] + e.second;
					q.push(e.first);
				}
			}
			q.pop();
		}
	}
	ll operator[](int node) {
		if (node >= sz) return INT64_MAX/2;
		return d[node];
	}
};

int main() {
	djikstra q;
	int v, e, r, s, t, d;
	cin >> v >> e >> r;
	for (int i = 0; i < e; i++) {
		cin >> s >> t >> d;
		q.add_path(s, t, d);
	}
	q.compute(r, v);
	for (int i = 0; i < v; i++) if (q[i] == INT64_MAX / 2) cout << "INF" << endl; else cout << q[i] << endl;
}
