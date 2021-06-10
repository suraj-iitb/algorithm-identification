#include<iostream>
#include<algorithm>
using namespace std;
long long  map[101][101];
long long INF = (1LL<<32);
int n;
int adjust = 0;
void solve(){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[j][i] == INF) continue;
			for (int k = 0; k < n; k++) {
				if(map[i][k] == INF ) continue;
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
}
int main(void) {
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = (i == j) ? 0 : INF;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int a, b,c;
		cin >> a >> b>>c;
		map[a][b] = c;
	}
	solve();
	for (int i = 0; i < n; i++) if (map[i][i] < 0) adjust = 1;
	if (adjust) cout << "NEGATIVE CYCLE" << endl;
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j) cout << " ";
				if (map[i][j] == INF) cout << "INF";
				else { cout << map[i][j]; }
			}
			cout << endl;
		}
	}
}
