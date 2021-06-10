#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll INF = 2e12;

class Edge {
public:
	int s, t, d;

	Edge(int s, int t, int d) {
		this->s = s;
		this->t = t;
		this->d = d;
	}
};

int V, E;
vector<Edge> GraphInfo;
ll Distance[100];

bool solve(int startId) {

	fill(Distance, Distance + 100, INF);

	Distance[startId] = 0;
	for (int k = 1; k < V; ++k) {
		for (int i = 0; i < E; ++i) {
			if (Distance[GraphInfo[i].s] == INF) {
				continue;
			}
			Distance[GraphInfo[i].t] = min(Distance[GraphInfo[i].t], Distance[GraphInfo[i].s] + GraphInfo[i].d);
		}
	}

	for (int i = 0; i < E; ++i) {
		if (Distance[GraphInfo[i].s] == INF) {
			continue;
		}
		if (Distance[GraphInfo[i].t] > Distance[GraphInfo[i].s] + GraphInfo[i].d) {
			return true;
		}
	}

	for (int i = 0; i < V; ++i) {
		if (Distance[i] == INF) {
			cout << "INF";
		}
		else {
			cout << Distance[i];
		}
		cout << (i == V - 1 ? '\n' : ' ');
	}

	return false;
}

int main() {
	int s, t, d;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	GraphInfo.clear();
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		cin >> s >> t >> d;
		GraphInfo.push_back(Edge(s, t, d));
	}
	for (int r = 0; r < V; ++r) {
		if (solve(r)) {
			cout << "NEGATIVE CYCLE" << endl;
			break;
		}
	}

	return 0;
}
