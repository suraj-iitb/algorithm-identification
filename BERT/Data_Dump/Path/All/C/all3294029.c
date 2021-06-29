#include <bits/stdc++.h>
using namespace std;
const long long INF = 123456789987654321;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	int v, e;
	cin >> v >> e;
	vector<vector<long long>> g(v, vector<long long>(v, INF));
	for(int i = 0; i < v; i++) g[i][i] = 0;
	for(int i = 0; i < e; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		g[s][t] = d;
	}
	for(int i = 0; i < v; i++) {
		for(int j = 0; j < v; j++) {
			for(int k = 0; k < v; k++) {
				if(g[j][i] == INF || g[i][k] == INF) continue;
				g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
			}
		}
	}
	for(int i = 0; i < v; i++) {
		if(g[i][i] < 0) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	for(int i = 0; i < v; i++) {
		for(int j = 0; j < v; j++) {
			if(g[i][j] == INF) {
				cout << "INF";
			}
			else {
				cout << g[i][j];
			}
			if(j == v - 1) {
				cout << '\n';
			}
			else {
				cout << " ";
			}
		}
	}
		
	return 0;	
}

