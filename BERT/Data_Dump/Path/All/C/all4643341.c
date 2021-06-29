#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Graph {
	int N;
	vector<vector<P>> edge;

public:
	Graph(int N) : N(N), edge(N) {}
	void add(int s, int t, int d) {
		edge[s].emplace_back(t, d);
	}
	void ans() {
		vector<vector<int>> D(N, vector<int>(N, INT_MAX));
		REP(i, N) {
			D[i][i] = 0;
			for (auto &p : edge[i]) {
				int j, d;
				tie(j, d) = p;
				D[i][j] = d;
			}
		}
		REP(k, N) {
			REP(i, N) {
				REP(j, N) {
					if (D[i][k] < INT_MAX && D[k][j] < INT_MAX) {
						D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
					}
				}
			}
		}
		REP(i, N) {
			if (D[i][i] < 0) {
				cout << "NEGATIVE CYCLE" << endl;
				return;
			}
		}
		REP(i, N) {
			REP(j, N) {
				if (D[i][j] < INT_MAX) {
					cout << D[i][j];
				} else {
					cout << "INF";
				}
				if (j < N - 1) cout << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int V, E;
	cin >> V >> E;
	Graph graph(V);
	REP(i, E) {
		int s, t, d;
		cin >> s >> t >> d;
		graph.add(s, t, d);
	}
	graph.ans();

	return 0;
}
