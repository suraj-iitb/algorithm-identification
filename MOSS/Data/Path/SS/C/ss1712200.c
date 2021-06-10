#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define INF INT_MAX/2

typedef long long int ll;
typedef int Node;
typedef tuple<Node, Node, ll> Edge;
typedef pair<Node, ll> Cost;

typedef vector<Node> Nodes;
typedef map<Node, vector<Edge> > Edges;
typedef vector<Cost> Costs;

struct Comp {
	bool operator() (Cost a, Cost b) {
		return a.second > b.second;
	}
};

vector<Cost> dijkstra(Nodes V, Edges E, Node r)
{
	map<Node,ll> costs;
	Costs result;
	priority_queue<Cost, vector<Cost>, Comp> que;
	set<Node> done;

	for (Node n : V)
	{
		if (n == r)
		{
			Cost c = Cost(n, 0);
			costs[n] = 0;
			que.push(c);
		}
		else
			costs.insert(Cost(n, INF));
	}

	while (!que.empty())
	{
		Cost c = que.top();
		que.pop();

		if (done.find(c.first) != done.end()) continue;

		done.insert(c.first);
		result.push_back(c);

		for (Edge e : E[c.first])
		{
			Node from = c.first;
			Node to = get<1>(e);
			ll cost = get<2>(e);
			
			ll newcost = c.second + cost;
			if (newcost < costs[to])
			{
				costs[to] = newcost;
				que.push(Cost(to, newcost));
			}
		}
	}

	return result;
}

int main()
{
	int V, E, r;
	cin >> V >> E >> r;

	Nodes nodes;
	rep(i, 0, V) nodes.push_back(i);

	Edges edges;
	rep(i, 0, V) edges[i] = vector<Edge>();
	rep(i, 0, E)
	{
		int s, t, d;
		cin >> s >> t >> d;
		edges[s].push_back(Edge(s, t, d));
		//edges[t].push_back(Edge(t, s, d));
	}

	Costs costs = dijkstra(nodes, edges, r);
	vector<ll> ans(V, INF);
	for (Cost c : costs) ans[c.first] = c.second;

	rep(i, 0, V)
	{
		if (ans[i] == INF)
			cout << "INF" << endl;
		else
			cout << ans[i] << endl;
	}
}
