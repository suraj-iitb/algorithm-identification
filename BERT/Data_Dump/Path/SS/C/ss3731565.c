#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <unordered_set>
#include <queue>
using namespace std;

constexpr int INF = 1 << 30;
using P = pair<int, int>;

class Graph {
private:
	const int N, M;
	vector<int> d;
	vector< tuple<int, int, int> > E;
	vector< list< P > > List;
	unordered_set<int> S;
	priority_queue< P, vector<P>, greater<P> > Q;
public:
	Graph(int n, int m) : N(n), M(m), d(n, INF), List(n) {}
	void InputEdge(int s, int t, int d) {
		E.push_back(make_tuple(s, t, d));
		List[s].push_back(make_pair(t, d));
	}
	void BellmanFord(int r);
	void Dijkstra(int r);
};

void Graph::BellmanFord(int r){
	d[r] = 0;
	for (int i = 0; i < N - 1; i++) {
		bool update = false;
		for (int j = 0; j < M; j++) {
			int u = get<0>(E[j]), v = get<1>(E[j]), w = get<2>(E[j]);
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				update = true;
			}
		}
		if (!update)
			break;
	}
	for (int i = 0; i < N; i++) {
		if (d[i] == INF)
			cout << "INF" << endl;
		else
			cout << d[i] << endl;
	}
}

void Graph::Dijkstra(int r) {
	d[r] = 0;
	for (int i = 0; i < N; i++)
		Q.push(make_pair(0, r));
	while (!Q.empty()) {
		int u = Q.top().second;
		Q.pop();
		if (S.find(u) != S.end())
			continue;
		S.insert(u);
		for (auto i = List[u].begin(); i != List[u].end(); ++i) {
			int v = (*i).first;
			if (S.find(v) != S.end())
				continue;
			else {
				int w = (*i).second;
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					Q.push(make_pair(d[v], v));
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (d[i] == INF)
			cout << "INF" << endl;
		else
			cout << d[i] << endl;
	}
}

int main() {
	int n, m, r;
	cin >> n >> m >> r;
	Graph G(n, m);
	for (int i = 0; i < m; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		G.InputEdge(s, t, d);
	}
	G.Dijkstra(r);
}
