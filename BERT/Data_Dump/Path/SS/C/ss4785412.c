#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
//#define int long long
#define INF (lint)(3e18)
#define P pair<int,int>
struct Edge {
	lint to;
	lint cost;
};//to...辺 cost...重み これをそれぞれ隣接グラフとして格納
void dijkstra(const vector<vector<Edge> > &G, lint s, vector<lint> &dis) {//Gは隣接グラフ,sは始点,距離の結果をdisに格納
	lint N = G.size();
	dis.resize(N, INF);
	priority_queue<P, vector<P>, greater<P> > pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
	dis[s] = 0;
	pq.push({dis[s], s});
	while (!pq.empty()) {//
		P p = pq.top();
		pq.pop();
		int v = p.second;
		if (dis[v] < p.first) {  // 最短距離で無ければ無視
			continue;
		}
		for (auto& e : G[v]) {
			if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
				dis[e.to] = dis[v] + e.cost;
				pq.push({dis[e.to], e.to});
			}
		}
	}
	return;
}

int main(void) {
    lint v, e, r; cin >> v >> e >> r;
	vector<vector<Edge> > a(v);
	for (int i = 0; i < e; i++) {
		lint x, y, z; cin >> x >> y >> z;
      a[x].push_back({ y,z });
	}
	vector<lint> b(v, INF);
	dijkstra(a, r, b);
	for (int i = 0; i < v; i++) {
		if (b[i] != INF)
          printf("%lld\n", b[i]);
                else 
			cout << "INF" << endl;
	}

	return 0;
}
