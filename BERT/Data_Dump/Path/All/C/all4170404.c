#include <bits/stdc++.h>

//単一始点最短経路（負の重みをもつ辺を含む）
//https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, char, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

const ll mod = 1000000007;

const ll INF = 1e15;

struct warshall_floyd {
	static bool solve(vector<vector<ll>>& d) {
		int n = d.size();
		rep(k, n) {
			rep(i, n) {
				rep(j, n) {
					if (d[i][k] != INF && d[k][j] != INF) {
						auto u = d[i][k] + d[k][j];
						if (d[i][j] > u) {
							d[i][j] = u;
						}
					}
				}
			}
		}
		rep(k, n) {
			rep(i, n) {
				rep(j, n) {
					if (d[i][k] != INF && d[k][j] != INF) {
						auto u = d[i][k] + d[k][j];
						if (d[i][j] > u) {
							return false;
						}
					}
				}
			}
		}
		return true;
	}
}; 

int main(void)
{
	int v, e;
	cin >> v >> e;
	vector<vector<ll>> g(v, vector<ll>(v, INF));
	rep(i, v) {
		g[i][i] = 0;
	}
	rep(i, e) {
		ll s, t, d; 
		cin >> s >> t >> d;
		g[s][t] = d;
	}
	bool ok = warshall_floyd::solve(g);
	if (!ok) {
		cout << "NEGATIVE CYCLE" << endl;
		return 0;
	}
	rep(i, v) {
		rep(j, v) {
			if (g[i][j] == INF) {
				cout << "INF";
			}
			else {
				cout << g[i][j];
			}			
			if (j != v - 1) cout << " ";
			else cout << endl;
		}
	}
	return 0;
}

