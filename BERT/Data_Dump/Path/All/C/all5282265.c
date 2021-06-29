#include <bits/stdc++.h>
#define maxn 101
using namespace std;
typedef long long LL;
typedef pair<int, LL> PIL;
LL dist[maxn][maxn];
vector<PIL> graph[maxn];
const LL inf = 1LL << 60;
int n, m;

void Floyd_Warshall(){
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j ++){
			if (i != j){
				dist[i][j] = inf;
			}
		}
	}
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < graph[i].size(); j ++){
			PIL to = graph[i][j];
			dist[i][to.first] = to.second;
		}
	}
	for (int k = 0; k < n; k ++){
		for (int i = 0; i < n; i ++){
			for (int j = 0; j < n; j ++){
				if (dist[i][k] != inf && dist[k][j] != inf) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i ++){
		int x, y; LL d;
		cin >> x >> y >> d;
		graph[x].push_back(make_pair(y, d));
	}
	Floyd_Warshall();
	for (int i = 0; i < n; i ++){
		if (dist[i][i] < 0){
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n - 1; j ++){
			if (dist[i][j] == inf) cout << "INF" << " ";
			else cout << dist[i][j] << " ";
		}
		if (dist[i][n - 1] == inf) cout << "INF" << endl;
		else cout << dist[i][n - 1] << endl;
	}
}
