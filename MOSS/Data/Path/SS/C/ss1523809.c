#include <bits/stdc++.h>
using namespace std;

template <typename Cost>
class Dijkstra {
private:
	struct Edge {
		int src, dst;
		Cost cost;
		bool operator < (const Edge &rhs) const {
			return cost > rhs.cost;
		}
	};
	
public:
	Dijkstra(int n) : g(n), INF(numeric_limits<Cost>::max()){}
	
	void addEdge(int src, int dst, Cost cost){
		g[src].push_back({src, dst, cost});
	}
	
	void solve(int s){
		const int n = g.size();
		
		d.assign(n, INF);
		p.assign(n, -1);
		
		priority_queue<Edge> pq;
		auto push = [&](int src, int dst, Cost sum){
			if (d[dst] > sum){
				d[dst] = sum;
				pq.push({src, dst, sum});
			}
		};
		auto pop = [&](){
			Edge e = pq.top(); pq.pop();
			p[e.dst] = e.src;
			return e;
		};
		
		push(-1, s, 0);
		while (!pq.empty()){
			Edge c = pop();
			for (Edge &e : g[c.dst]){
				push(c.dst, e.dst, c.cost + e.cost);
			}
		}
	}
	
	bool reach(int v){
		return d[v] != INF;
	}
	
	Cost dist(int v){
		return d[v];
	}
	
	vector<int> path(int v){
		vector<int> res;
		for (int u = v; ~p[u]; u = p[u]){
			res.push_back(u);
		}
		reverse(begin(res), end(res));
		return res;
	}

private:
	const Cost INF;
	vector<vector<Edge>> g;
	vector<Cost> d;
	vector<int> p;
};


int main()
{
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	
	Dijkstra<int> solver(n);
	
	for (int i = 0; i < m; i++){
		int s, t, d;
		scanf("%d %d %d", &s, &t, &d);
		
		solver.addEdge(s, t, d);
	}
	
	solver.solve(r);
	
	for (int i = 0; i < n; i++){
		if (solver.reach(i)) printf("%d\n", solver.dist(i));
		else puts("INF");
	}
}
