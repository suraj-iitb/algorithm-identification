#include <bits/stdc++.h>
const long long MOD = 1000000007;
const int INF = INT_MAX / 2;
const long double PI = 3.1415926;
#define FOR(i, r, n) for(int i=(ll)(r); i<(ll)(n); i++) 
#define REP(i, n) FOR(i, (0), n)
#define ALL(r) r.begin(), r.end()
#define ll long long int
using namespace std;
string s;
vector<ll> v;
vector<pair<ll, ll>> vp;
vector<vector<ll>> vv(110, vector<ll>(50, 0));
vector<tuple<ll, ll, ll>> vt;
set<ll> st;
map<char, ll> mp;

typedef int Weight;
struct Edge
{
	int from, to; Weight cost;
	bool operator < (const Edge& e) const { return cost < e.cost; }
	bool operator > (const Edge& e) const { return cost > e.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph &g, int from, int to, Weight cost)
{
	g[from].push_back(Edge{ from, to, cost });
}

typedef pair<Weight, Edge> P;

int V, limit, nf, E, r, goal;
bool isdone[100005];
vector<Weight> dist(100005, INF);
priority_queue<P, vector<P>, greater<P>> pq;

void dijkstra(Graph &g, int r)
{
	dist[r] = 0;
	isdone[r] = true;
	for (auto e : g[r])
	{
		pq.emplace(e.cost, e);
	}
	while (!pq.empty())
	{
		Edge te = pq.top().second;
		pq.pop();
		if ((dist[te.to] > dist[te.from] + te.cost)&&!isdone[te.to])
		{
			dist[te.to] = dist[te.from] + te.cost;
			isdone[te.to] = true;
			for (auto e : g[te.to])
			{
				pq.emplace(dist[te.to]+e.cost, e);
			}
		}
	}
}

int main()
{
	cin >> V >> E >> r;
	//cin >> V >> limit >> nf >> E >> r >> goal;
	Graph g(V);
	REP(i, E)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		add_edge(g, a, b, c);
	}
	dijkstra(g, r);
	REP(i, V) {
		if (dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
}
