#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>

using namespace std;
typedef long long ll;

ll V, E, s, t, d;

const ll INF = 1e15;
typedef ll Weight;
struct Edge {  //src:辺の始点,dst:辺の終点,weight:辺の重さ
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : //辺は重さが重いものを"小さい"と定義する
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

//引数 Graph:隣接リスト,dist:各頂点から各頂点までの距離が入る,inter:最短路木の親頂点が入る
//戻値 負閉路が存在しない場合:true,そうでないとき:false
bool shortestPath(const Graph &g, vector<vector<Weight> > &dist, vector<vector<int> > &inter) {
	int n = g.size();
	dist.assign(n, vector<Weight>(n, INF));
	for (int i = 0; i<n; i++) {
		dist[i][i] = 0;
	}
	for (int i = 0; i<n; i++) {
		for (auto f = g[i].begin(); f != g[i].end(); f++) {
			dist[i][f->dst] = f->weight;
		}
	}
	inter.assign(n, vector<int>(n, -1));
	for (int k = 0; k<n; k++) {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (dist[i][k]<INF && dist[k][j]<INF && dist[i][j]>dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					inter[i][j] = k;
				}
			}
		}
	}
	for (int i = 0; i<n; i++) {
		if (dist[i][i]<0) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> V >> E;
	Graph g(V);
	for (int i = 0; i < E; i++) {
		cin >> s >> t >> d;
		g[s].push_back(Edge(s, t, d));
	}
	vector<vector<Weight> >dist;
	vector<vector<int> > inter;
	bool negative_cycle = shortestPath(g, dist, inter);
	if (!negative_cycle) {
		cout << "NEGATIVE CYCLE" << endl;
	}
	else {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V - 1; j++) {
				if (dist[i][j] == INF) {
					cout << "INF ";
				}
				else {
					cout << dist[i][j] << " ";
				}
			}
			if (dist[i][V - 1] == INF) {
				cout << "INF" << endl;
			}
			else {
				cout << dist[i][V - 1] << endl;
			}
		}
	}
	return 0;
}
