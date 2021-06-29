#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = (1LL << 31) - 1;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int v,e;
	cin >> v >> e;

	int g[v][v];
	rep(i,v) rep(j,v) g[i][j] = (i == j ? 0 : INF);

	rep(i,e){
		int s,t,d;
		cin >> s >> t >> d;

		g[s][t] = d;
	}

	// warshall floyd

	// g[i][k],g[k][j]それぞれでINF判定をしているのは、負の経路対策
	rep(k,v){
		rep(i,v){
			if(g[i][k] == INF) continue;
			rep(j,v){
				if(g[k][j] == INF) continue;
				if((g[i][k] + g[k][j]) < g[i][j]){
					// cout << i << "," << k << "," << j << "," << (g[i][k] + g[k][j]) << "," << g[i][j] << endl;
					g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
				}
			}
		}
	}

	rep(i,v){
		if(g[i][i] < 0){
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}

	rep(i,v){
		if(g[i][0] == INF) {
			cout << "INF"; 
		}else {
			cout << g[i][0];
		}
		rep(j,v-1){
			if(g[i][j+1] == INF) {
				cout << " INF"; 
			}else{
				cout << " " << g[i][j+1];
			}
		}
		cout << endl;
	}
}
