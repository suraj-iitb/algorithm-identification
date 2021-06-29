#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
const long long inf =  (1LL<<32);
int main() {
	int v, e;
	cin >> v >> e;
	vector < vector<long long> > g(v, vector<long long>(v, inf));
	rep(i, e) {
		int s, t, d;
		cin >> s >> t >> d;
		g[s][t] = d;
	}
	rep(i, v)g[i][i] = 0;
	
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			if (g[i][k] == inf)continue;
			for (int j = 0; j < v; j++) {
				if (g[k][j] == inf)continue;
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

			}
		}
	}
	bool ifnegative = false;
	rep(i, v){
		if (g[i][i] < 0){
			ifnegative = true;
			break;
		}
	}
	if (ifnegative) {
		cout << "NEGATIVE CYCLE" << endl;
	}
	else {
	rep(i, v) {
		rep(j, v) {
			if (j)cout << " ";
			if (g[i][j] == inf)cout << "INF";
			else cout << g[i][j];

		}
		cout << endl;
	}
	}
}
