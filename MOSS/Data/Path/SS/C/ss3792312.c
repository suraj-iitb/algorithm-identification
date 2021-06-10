#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;

typedef long long ll;

bool debug = false;
const int NIL = -1;
const int INF = 1000000000;
const int NUM = 100010;
clock_t START, END;

int V, E, r;

struct HeapNode {
	int d, u;
	bool operator < (const HeapNode& rhs) const {
		return d > rhs.d;
	}
};

struct Edge {
	int from, to, dist;
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};

struct Dijkstra {
	int n, m;
	vector<Edge> edges;
	vector<int> G[NUM];
	bool done[NUM];
	int d[NUM];
	int p[NUM];

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist) {
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s) {
		priority_queue<HeapNode> Q;
		for (int i = 0; i < V; i++)
			d[i] = INF;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push({ 0, s });
		while (!Q.empty()) {
			HeapNode x = Q.top();
			Q.pop();
			int u = x.u;
			if (done[u])
				continue;
			done[u] = true;
			for (int i = 0; i < G[u].size(); i++) {
				Edge& e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist) {
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push({ d[e.to],e.to });
				}
			}
		}
	}
};

Dijkstra solve;

int main(void)
{
	if (debug) {
		START = clock();
		freopen("in29.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	int s, t, d;
	cin >> V >> E >> r;
	solve.init(V);
	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &s, &t, &d);
		solve.AddEdge(s, t, d);
	}
	solve.dijkstra(r);
	for (int i = 0; i < V; i++) {
		if (solve.d[i] == INF)
			cout << "INF" << endl;
		else
			cout << solve.d[i] << endl;
	}
	if (debug) {
		END = clock();
		double endtime = (double)(END - START) / 1000;
		printf("total time = %lf s", endtime);
	}
	return 0;
}
