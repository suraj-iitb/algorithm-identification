#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const unsigned int INFTY = 1 << 31;

int n;
bool *visited;
vector<pair<unsigned int,unsigned int> > *Graph;
unsigned int *d;

//本题不包含负权路径，使用狄克斯特拉算法
/*void dijkstra(int u) {
	priority_queue<pair<int,int> > PQ;

	for (int i=0; i<n; i++) {
		d[i] = INFTY;
		visited[i] = false;
	}

	d[u] = 0;
	PQ.push(make_pair(0,u));

	while (!PQ.empty()) {
		pair<int,int> f = PQ.top();
		PQ.pop();
		int u = f.second;
		
		visited[u] = true;
		
		if (d[u] < f.first * -1) {
			continue;
		}
		const vector<pair<int,int> > & n_points = Graph[u];

		for (int i = 0; i<n_points.size(); i++) {
			pair<int,int> p = n_points[i];
			int & v = p.first;
			int & w = p.second;
			if (!visited[v] && d[v] > d[u] + w) {
				d[v] = d[u] + w;
				PQ.push(make_pair(-1*d[v],v));
			}
		}
	}
}*/

void dijkstra(int u) {
	for (int i=0; i<n; i++) {
		d[i] = INFTY;
		visited[i] = false;
	}
	d[u] = 0;
	priority_queue<pair<int,unsigned int> >PQ;
	PQ.push(make_pair(0,u));
	while (!PQ.empty()) {
		u = PQ.top().second;
		PQ.pop();

		visited[u] = true;

		const vector<pair<unsigned int,unsigned int> > & n_points = Graph[u];
		for (int i=0; i<n_points.size(); i++) {
			pair<unsigned int,unsigned int> f = n_points[i];
			unsigned int & v = f.first;
			unsigned int & w = f.second;
			if (!visited[v] && d[v] > d[u] + w) {
				d[v] = d[u] + w;
				PQ.push(make_pair(-1*d[v],v));
			}
		}
	}
}

int main() {
	int e,r;
	cin >> n >> e >> r;
	Graph = new vector<pair<unsigned int,unsigned int> >[n];
	visited = new bool[n];
	d = new unsigned int[n];
	
	for (int i=0; i<e; i++) {
		unsigned int s,t,d;
		cin >> s >> t >> d;
		Graph[s].push_back(make_pair(t,d));
	}
	dijkstra(r);
	for (int v=0;v<n;v++) {
		if (d[v] == INFTY) {
			cout << "INF" << endl;
		} else {
			cout << d[v] << endl;
		}
	}
	delete[] Graph;
	delete[] visited;
	delete[] d;
	return 0;
}
