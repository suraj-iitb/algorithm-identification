#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define REP1(i,n) for(int i=1; i<n; i++)
#define IREP(i,n) for(int i=n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define ALL(c) (c).begin(), (c).end() 
#define INF INT_MAX
using namespace std;

typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) {}
	bool operator < (const Edge &e) const {
		return weight != e.weight ? weight > e.weight :
			src != e.src ? src < e.src : dst < e.dst;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void shortestPath(const Graph &g, int s, vector<Weight> &dist, vector<int> &prev) {
	int n = g.size();
	dist.assign(n,INF);
	dist[s] = 0;
	prev.assign(n,-1);
	priority_queue<Edge> Q;
	for(Q.push(Edge(-2,s,0)); !Q.empty(); ) {
		Edge e = Q.top();
		Q.pop();
		if(prev[e.dst] != -1) continue;
		prev[e.dst] = e.src;
		FOR(f,g[e.dst]) {
			if(dist[f->dst] > e.weight+f->weight) {
				dist[f->dst] = e.weight+f->weight;
				Q.push(Edge(f->src, f->dst, e.weight+f->weight));
			}
		}
	}
}

int main() {
	int V, E, r;
	cin >> V >> E >> r;
	Graph graph(V);
	REP(ie,E) {
		int s, t, d;
		cin >> s >> t >> d;
		graph.at(s).push_back(Edge(s,t,d));
	}
	vector<Weight> dist(V);
	vector<int> prev(V);
	shortestPath(graph, r, dist, prev);
	for(vector<Weight>::iterator it = dist.begin(); it != dist.end(); it++) {
		if(*it != INF) cout << *it << endl;
		else cout << "INF" << endl;
	}
	return 0;
}
