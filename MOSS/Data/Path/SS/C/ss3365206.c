#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PI;
static const long long int INF = 1e18;

class Edge
{
public:
	int to;
	int cost;
};
vector<Edge> edge[100001];

void solve()
{
	int V, E, r;
	cin >> V >> E >> r;
	for (int i = 0; i < E; ++i)
	{
		int s, t, d;
		scanf("%d %d %d", &s, &t, &d);
		Edge e;
		e.to = t;
		e.cost = d;
		edge[s].push_back(e);
	}
	vector<long long int> D(V);
	for (int i = 0; i < V; ++i)
	{
		D[i] = INF;
	}
	D[r] = 0;
	priority_queue<P, vector<P>, greater<P> > pque;
	pque.push(P(0, r));
	while (!pque.empty())
	{
		P p = pque.top();
		pque.pop();
		int v = p.second;
		if (D[v] < p.first)
		{
			continue;
		}
		for (int i = 0; i < edge[v].size(); ++i)
		{
			Edge e = edge[v][i];
			if (D[e.to] > D[v] + e.cost)
			{
				D[e.to] = D[v] + e.cost;
				pque.push(P(D[e.to], e.to));
			}
		}
	}
	for (int i = 0; i < V; ++i)
	{
		if (D[i] == INF)
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << D[i] << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}
