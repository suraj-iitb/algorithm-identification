#include <algorithm>
#include <climits>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
class WarshallFloyd {
protected:
	const vector<vector<pair<int, T>>> _adj;
	vector<vector<T>> _d;

protected:
	void to_adj() {
		for (int _i = 0; _i < static_cast<int>(_adj.size()); _i++) {
			_d[_i][_i] = 0;
			for (const pair<int, T>& _j : _adj[_i]) _d[_i][_j.first] = _j.second;
		}
	}

public:
	WarshallFloyd(const vector<vector<pair<int, T>>>& adj) :
		_adj(adj),
		_d(adj.size(), vector<T>(adj.size(), numeric_limits<T>::max()))
	{
		to_adj();
		for (int _k = 0; _k < static_cast<T>(_d.size()); _k++) {
			for (int _i = 0; _i < static_cast<T>(_d.size()); _i++) {
				if (_d[_i][_k] == numeric_limits<T>::max()) continue;
				for (int _j = 0; _j < static_cast<T>(_d.size()); _j++) {
					if (_d[_k][_j] == numeric_limits<T>::max()) continue;
					_d[_i][_j] = min(_d[_i][_j], _d[_i][_k] + _d[_k][_j]);
				}
			}
		}
	}

public:
	bool has_negative_cycle() {
		bool _has_negative_cycle = false;
		for (int _i = 0; _i < static_cast<int>(_d.size()); _i++) {
			if (_d[_i][_i] < 0) {
				_has_negative_cycle = true;
				break;
			}
		}
		return _has_negative_cycle;
	}

public:
	int operator()(const int& i, const int& j) const {
		return _d[i][j];
	}
};

int main() {
	int V, E;
	cin >> V >> E;
	vector<vector<pair<int, int>>> a(V);
	for (int i = 0; i < E; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		a[s].emplace_back(t, d);
	}
	WarshallFloyd<int> warshall_floyd(a);
	if (warshall_floyd.has_negative_cycle()) {
		cout << "NEGATIVE CYCLE" << endl;
		return 0;
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V - 1; j++) {
			if (warshall_floyd(i, j) != INT_MAX) cout << warshall_floyd(i, j);
			else cout << "INF";
			cout << ' ';
		}
		if (warshall_floyd(i, V - 1) != INT_MAX) cout << warshall_floyd(i, V - 1);
		else cout << "INF";
		cout << endl;
	}
}
