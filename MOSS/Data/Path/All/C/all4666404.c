#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>


using namespace std;

typedef long long ll;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<ll> vll;

typedef pair<int, ll> P;
#define mp(x, y) make_pair(x, y)

typedef queue<int> qi;
typedef queue<string> qs;


#define rep(i, n) for(int i=0; i<(n); ++i)
#define repp(i, a, b) for(int i = (a); i <= (b); i++)
#define repm(i, n) for(int i=n; i >= 0; i--)

#define all(v) v.begin(), v.end()
//sort( all(v) )　などと使える

const ll INF = 1e10;

int V, E;

vector<vector<ll>> dist(110, vector<ll>(110, INF));

int main() {
	cin >> V >> E;

	rep(v, V) dist[v][v] = 0;

	rep(i, E) {
		int s, t; ll d; cin >> s >> t >> d;
		dist[s][t] = d;
	}

	rep(k, V) {
		rep(i, V) {
			rep(j, V) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	bool flag = false;
	rep(v, V) if (dist[v][v] < 0) flag = true;

	if (flag) {
		cout << "NEGATIVE CYCLE" << endl;
		return 0;
	}

	rep(i, V) {
		rep(j, V) {
			if (dist[i][j] >= INF / 2) cout << "INF";
			else cout << dist[i][j];
			if (j != V - 1) cout << " ";
		}
		cout << endl;
	}
}
