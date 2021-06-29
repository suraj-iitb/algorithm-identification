#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdint.h>
#include <queue>
#include <bitset>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

#define PI (3.14159265358979323846)
#define INF (2147483647)
#define INF_LL (9223372036854775807)
#define DIV_NUM (1000000007)

// ダイクストラ法　O(ElogV)
// 配列dに基点sからの最短距離を返す
// グラフのコストに負の値が含まれる場合は使えない
#define MAX_E (500000)
#define MAX_V (100000)
int V, E; // V:頂点数、E:辺数
struct edge { int to, cost; }; // 辺の構造
vector<vector<edge>> G; // 隣接配列でグラフを保持
int d[MAX_V];
typedef pair<int, int> P; // firstは最短距離、secondは頂点の番号

void shortest_path(int s) {
	priority_queue<P, vector<P>, greater<P>> que;
	fill(d, d + V, INF);
	d[s] = 0;
	que.push(P(0, s)); // 頂点sからスタート

	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first) continue; // 他に最短路が見つかっていれば何もしない
		for (int i = 0; i < G[v].size(); i++) {
			// vから繋がる頂点を一通り計算
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				// 最短経路が見つかれば値を追加し次のキューに追加
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main() {

	cin >> V >> E;
	int r;
	cin >> r;

	G.resize(V);
	for (int i = 0; i < E; i++) {
		int v;
		cin >> v;
		edge tmp;
		cin >> tmp.to >> tmp.cost;
		G[v].push_back(tmp); // 有向グラフ
	}

	shortest_path(r);
	for (int i = 0; i < V; i++) {
		if (d[i] < INF) cout << d[i] << endl;
		else cout << "INF" << endl;
	}

	return 0;

}

