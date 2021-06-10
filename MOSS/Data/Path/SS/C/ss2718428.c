#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>
#include<string.h>
#include<set>

const int MAXN = 1e5;
const int MAX_E = 5e5;
const long long INF = ((long long)1<<62) - 1;
struct Edge
{
	int vx;
	long long w;

	bool operator < (const Edge& e) {
		return w < e.w;
	}
};

struct NodeInfo {
	int vx;
	long long *d;

	bool operator < (const NodeInfo& node) {
		return (*d) < *(node.d);
	}
};

std::vector<Edge> graph[MAXN];
long long dist[MAXN];
int pre_vx[MAXN];
int visit[MAXN];
int V, E, r;

void init() {
	int n = V;
	while (n--) {
		dist[n] = INF;
	}
	memset(pre_vx, -1, sizeof(pre_vx));
	memset(visit, 0, sizeof(pre_vx));
}

void input() {
	scanf("%d%d%d", &V, &E, &r);
	for (int i = 0; i < E; i++) {
		int s, t, w;
		scanf("%d%d%d", &s, &t, &w);
		graph[s].push_back({ t, w });
	}
}

void dij_sp() {
	dist[r] = 0;
	std::priority_queue< std::pair<long long, int >, std::vector< std::pair<long long, int> >,
		std::greater< std::pair<long long, int> > > pq;
	pq.push(std::make_pair(0, r));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (visit[u]) { continue; }
		if (dist[u] == INF) { return; }
		for (std::vector<Edge>::iterator it = graph[u].begin(); it != graph[u].end(); it++) {
			int v = it->vx;
			if (visit[v]) { continue; }
			if (dist[v] > dist[u] + it->w) {
				dist[v] = dist[u] + it->w;
				pq.push(std::make_pair(dist[v], v));
			}
		}
		//mark visited
		visit[u] = 1;
	}
}

void output() {
	for (int i = 0; i < V; i++) {
		if (i == r) {
			printf("0\n");
		}
		else {
			if (dist[i] == INF) {
				printf("INF\n");
			}
			else {
				printf("%lld\n", dist[i]);
			}
		}
	}
}

/**
*http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
*/
int main() {
	input();
	init();
	dij_sp();
	output();
	return 0;
}
