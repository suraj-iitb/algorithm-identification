#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/

typedef int Weight;
struct Edge
{
	int from, to; Weight cost;
	bool operator < (const Edge& e) const { return cost < e.cost; }
	bool operator > (const Edge& e) const { return cost > e.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
void add_edge(Graph &g, int from, int to, Weight cost)
{
	g[from].push_back(Edge{ from, to, cost });
}

typedef pair<Weight, Edge> P;

void dijkstra(const Graph& g, Array& dist, int s)
{
	int n = g.size();
	dist.resize(n, INF);
	dist[s] = 0;
	vector<bool> visited(n);
	visited[s] = true;
	priority_queue<P, vector<P>, greater<P>> que;
	for (auto e : g[s])
	{
		que.emplace(e.cost, e);
	}
	while (!que.empty())
	{
		Edge tmp = que.top().second;
		que.pop();
		if (visited[tmp.to]) continue;
		visited[tmp.to] = true;
		dist[tmp.to] = dist[tmp.from] + tmp.cost;
		for (auto e : g[tmp.to])
		{
			que.emplace(dist[tmp.to] + e.cost, e);
		}
	}
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int n, m, s;
	cin >> n >> m >> s;
	Graph g(n);
	REP(i, m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(g, a, b, c);
	}
	Array dist;
	dijkstra(g, dist, s);
	for (auto i : dist)
	{
		if (i >= INF) cout << "INF" << endl;
	 	else cout << i << endl;
	}
	return 0;
}
