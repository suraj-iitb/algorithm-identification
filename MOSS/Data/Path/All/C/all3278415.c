#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const i64 INF = 1LL << 60;

template<typename T> class Matrix {
	vector<vector<T> > data;
public:
	Matrix(int size) {
		data.resize(size);
		for (int i = 0; i < size; i++) data[i].resize(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) data[i][j] = 0;
				else data[i][j] = INF;
			}
		}
	}
	
	inline vector<T> operator[](int index) const { return data[index]; }
	inline vector<T>& operator[](int index) { return data[index]; }
	
	size_t size() {
		return data.size();
	}
};
template<typename T> void warshall_floyd(Matrix<T> &graph) {
	for (int k = 0; k < graph.size(); k++) {
		for (int i = 0; i < graph.size(); i++) {
			for (int j = 0; j < graph.size(); j++) {
				if (graph[i][k] != INF && graph[k][j] != INF) {
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}
}

int main(void) {
	int v, e;
	cin >> v >> e;
	Matrix<i64> g(v);
	for (int i = 0; i < e; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		g[s][t] = d;
	}
	warshall_floyd(g);
	for (int i = 0; i < v; i++) {
		if (g[i][i] < 0) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (g[i][j] < INF) cout << g[i][j];
			else cout << "INF";
			cout << " \n"[j == v - 1];
		}
	}
}
