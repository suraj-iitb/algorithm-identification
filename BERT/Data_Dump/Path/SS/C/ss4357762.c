
#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
typedef long long ll;
const ll BIGMOD = 1e9 + 7;
const int INTINF = 2147483647;
using namespace std;


typedef pair<int, int> P;
struct Edge {
	int to;
	int cost;
	Edge(int t, int c) {
		to = t;
		cost = c;
	}
};

class Dijkstra {
private:
	vector<vector<Edge> > vec;
	priority_queue<P, vector<P>, greater<P> > que;
	vector<int> distances;

	void Solve() {
		while (!this->que.empty()) {
			P p = que.top(); que.pop();
			// 現在参照するノード
			int v = p.second;
			if (this->distances[v] < p.first) continue;
			for (int i = 0; i < this->vec[v].size(); ++i) {
				Edge e = this->vec[v][i];
				if (this->distances[e.to] > this->distances[v] + e.cost) {
					this->distances[e.to] = this->distances[v] + e.cost;
					que.push(P(this->distances[e.to], e.to));
				}
			}
		}
	}

public:
	Dijkstra(vector<vector<Edge> > &v, int start = 0) : vec(v), distances(v.size()) {
		for (int i = 0; i < this->distances.size(); ++i) this->distances[i] = INTINF;
		this->distances[start] = 0;
		this->que.push(P(0, start));
		this->Solve();
	}

	int GetDistances(int dst) {
		return this->distances[dst];
	}
};

int main() {
	int v, e, r;
	cin >> v >> e >> r;
	vector<vector<Edge> > vec(v, vector<Edge>());
	for (int i = 0; i < e; ++i) {
		int s, t, d;
		scanf("%d %d %d", &s, &t, &d);
		vec[s].push_back(Edge(t, d));
	}


	Dijkstra d(vec,r);
	for (int i = 0; i < v; ++i) {
		int ddd = d.GetDistances(i);
		if (ddd == INTINF) cout << "INF" << endl;
		else cout << ddd << endl;
	}
}
