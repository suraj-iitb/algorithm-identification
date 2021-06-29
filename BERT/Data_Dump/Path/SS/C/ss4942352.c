#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef unsigned int ui;

const ull INF = 2e11;

ui V, E;
vector<vector<pair<ui, ui> > > GraphInfo;
bool Visited[100000];
ull Distance[100000];

void solve(ui startId) {
	ui size, curId, nextId;
	pair<ui, ui> nodeInfo;
	priority_queue<pair<ui, ui>, vector<pair<ui, ui> >, greater<pair<ui, ui> > > nodeList;

	memset(Visited, false, sizeof(Visited));
	fill(Distance, Distance + 100000, INF);

	Distance[startId] = 0;
	nodeList.push({ 0,startId });
	while (!nodeList.empty()) {
		nodeInfo = nodeList.top();
		nodeList.pop();

		curId = nodeInfo.second;
		if (Visited[curId]) {
			continue;
		}
		Visited[curId] = true;

		size = GraphInfo[curId].size();
		for (ui i = 0; i < size; ++i) {
			nextId = GraphInfo[curId][i].first;
			Distance[nextId] = min(Distance[nextId], Distance[curId] + GraphInfo[curId][i].second);
			nodeList.push({ Distance[nextId],nextId });
		}
	}

	for (ui i = 0; i < V; ++i) {
		if (Distance[i] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << Distance[i] << endl;
		}
	}
}

int main() {
	ui s, t, d, r;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	GraphInfo.clear();
	cin >> V >> E >> r;
	GraphInfo.resize(V);
	for (ui i = 0; i < E; ++i) {
		cin >> s >> t >> d;
		GraphInfo[s].push_back({ t,d });
		//GraphInfo[t].push_back({ s,d });
	}
	solve(r);


	return 0;
}
