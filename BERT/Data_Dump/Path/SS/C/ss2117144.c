
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;


int n, m;

struct edge
{
	int to, cost;
};
const int INF = 1234567890;
using P = pair<int, int>;//first:cost,second:vertice
int dist[123456];
void dijkstra(vector<edge>graph[], int s)
{
	priority_queue<P, vector<P>, greater<P>>que;
	que.push({ 0,s });
	fill(dist, dist + n, INF);
	dist[s] = 0;
	while (!que.empty())
	{
		auto q = que.top();
		que.pop();
		int thd = q.first;
		int thv = q.second;
		if (thd > dist[thv])
		{
			continue;
		}
		for (auto ed : graph[thv])
		{
			if (dist[ed.to] > ed.cost + thd)
			{
				dist[ed.to] = ed.cost + thd;
				que.push({ dist[ed.to],ed.to });
			}
		}
	}
}

vector<edge>graph[123456];

int main(void)
{
	int s;
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
	}
	dijkstra(graph, s);
	for (int j = 0; j < n; ++j)
	{
		if (dist[j] == INF)printf("INF\n");
		else printf("%d\n", dist[j]);
	}
	return 0;
}
