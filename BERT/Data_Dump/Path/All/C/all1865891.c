#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL


//dx[i],dy[i]???i?????????????§???????????????¢???
//  3
// 2 0
//  1

//??\?????¨?????°
int X, Y;

//xy??§?¨???§?????±???????????¢?´¢
void dfs(int x, int y) {

	/* ?????? */

	//?§????4?????????????????????
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	//?§????4???????????¢?´¢
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx&&nx < X && 0 <= ny&&ny < Y) {
			dfs(nx, ny);
		}
	}
}

//xy??§?¨???§??????????????¢?´¢
//???????????¢
int bfs(int sx, int sy, int gx, int gy) {
	const int MAX = 1; //????????´???

	queue<pii> Q;
	Q.push(pii(sx, sy));

	//???????????¢
	int d[MAX][MAX];
	memset(d, 0x3f, sizeof(d));
	d[sx][sy] = 0;

	//?§????4?????????????????????
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (pii u; !Q.empty();) {
		u = Q.front(); Q.pop();
		if (u == pii(gx, gy))break; //??´??????????????¢?´¢????????????
									//?§????4???????????¢?´¢
		for (int i = 0; i < 4; i++) {
			int nx = u.first + dx[i], ny = u.second + dy[i];
			if (0 <= nx&&nx < X && 0 <= ny&&ny < Y) {
				if (d[nx][ny] != INF)continue; //??¢?´¢???????£???°???
				d[nx][ny] = d[u.first][u.second] + 1;
				Q.push(pii(nx, ny));
			}
		}
	}

	return d[gx][gy];
}

using Weight = ll;//int;
struct Edge {
	int s; //source
	int d; //destination
	Weight w; //weight
	Edge(int s = 0, int d = 0, int w = INF) : s(s), d(d), w(w) {};
};
using Edges = vector<Edge>;
//???????????\: g[u].push_back(Edge(u, v, c));
//????????¨???????????????????????°??????????????\?????????????????????
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

//?????¢?´¢, ??¢?´¢???, ??¢?´¢???
enum { WHITE, GRAY, BLACK };

//???????§?????????????(???????????????) Single Source Shortest Path
//Dijkstra O( |E|log|V| )
//dist: ?§????????????????????????§??????????????¢
//prev: ???????????¨????????????
void dijkstra(Graph g, int s, vector<Weight> &dist, vector<int> &prev) {
	typedef tuple<Weight, int, int> State; //?§?????????????????°?????????? ??? ???
	priority_queue<State, vector<State>, greater<State> >PQ;
	vector<int> color(g.size(), WHITE);
	dist.assign(g.size(), INF); //distance
	prev.assign(g.size(), -1);
	dist[s] = 0; PQ.push(State(0, s, -1)); color[s] = GRAY; //?§????
	while (!PQ.empty()) {
		Weight d; int v; int u;
		tie(d, v, u) = PQ.top(); PQ.pop(); //dist???????°??????¨??????????´????????????????
		if (dist[v] < d) continue; //?????§???????????§???????????°??????
		color[v] = BLACK;
		prev[v] = u;
		for (auto e : g[v]) { //??£??\????????????????????¨????????????		
			if (color[e.d] == BLACK)continue; //??¢?´¢????????????
			if (dist[e.d] > dist[v] + e.w) {
				dist[e.d] = dist[v] + e.w;
				PQ.push(State(dist[e.d], e.d, v));
				color[e.d] = GRAY;
			}
		}
	}
}

//???????§?????????????(???????????????) Single Source Shortest Path
//Bellman Ford O(|V||E|)
//dist: ?§????????????????????????§??????????????¢
//prev: ???????????¨????????????
//?????????: ???????????????:true ??????:false
bool bellman_ford(Graph g, int s, vector<Weight> &dist, vector<int> &prev) {
	return false;
}

//?§?????????????????????§??????????????????
//???????????????????????°?????????????§??????????????????§?????????????????¢????????????
vector<int> getPath(int s, int g, vector<int> prev) {
	vector<int> path;
	path.push_back(g);
	for (int i = g; i != s; ) path.push_back(i = prev[i]);
	reverse(path.begin(), path.end());
	return path;
}

//??¨????????????????????? All Pairs Shortest Path
//Warshall Floyd O(|V|^3)
//?????????: ???????????????:true ??????:false
bool warshall_floyd(Graph g, Matrix &dist) {
	bool negative_cycle = false;
	int n = g.size();
	dist.assign(n, Array(n, INFL));
	for (int i = 0; i < n; i++) dist[i][i] = 0;
	for (int i = 0; i < n; i++)
		for (auto e : g[i])
			dist[e.s][e.d] = min(dist[e.s][e.d], e.w);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (dist[j][i] != INFL&&dist[i][k] != INFL)
					dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	for (int i = 0; i < n; i++)
		if (dist[i][i] != 0)
			negative_cycle = true;
	return negative_cycle;
}

//???????????????
void printPath(vector<int> path) {
	cout << "Path: ";
	for (auto p : path) cout << p << " ";
	cout << endl;
}

int main() {
	int V, E; cin >> V >> E;
	Graph g(V + 1);
	for (int i = 0; i < E; i++) {
		int s, t, d; cin >> s >> t >> d;
		g[s].push_back(Edge(s, t, d));
	}
	Matrix dist;
	if (warshall_floyd(g, dist)) {
		cout << "NEGATIVE CYCLE" << endl;
	}
	else {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (j != 0)cout << " ";
				if (dist[i][j] == INFL)cout << "INF";
				else cout << dist[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
