#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int n, m, s;
vector<int> et[100000];
vector<int> ec[100000];
int minDist[100000];
int INF = 1145141919;

void dijkstra() {
	for (int i = 0; i < n; i++) minDist[i] = INF;
	typedef pair<int, int> P;
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(P(0, s));
	while (!que.empty()) {
		P now = que.top(); que.pop();
		int cst = now.first;
		int v = now.second;
		
		if (minDist[v] <= cst) continue;
		minDist[v] = cst;
		
		for (int i = 0; i < et[v].size(); i++) {
			que.push(P(cst + ec[v][i], et[v][i]));
		}
	}
}

int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		et[s].push_back(t);
		ec[s].push_back(d);
	}
	dijkstra();
	for (int i = 0; i < n; i++) {
		if (minDist[i] == INF) cout << "INF" << endl;
		else cout << minDist[i] << endl;
	}
	return 0;
}
