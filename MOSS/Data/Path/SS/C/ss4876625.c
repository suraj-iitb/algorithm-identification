#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
class Dijkstra {
protected:
	const vector<vector<pair<int, T>>>& _adj;
	vector<T> _d;

public:
	Dijkstra(const vector<vector<pair<int, T>>>& adj, const int& s) :
		_adj(adj),
		_d(adj.size(), numeric_limits<T>::max())
	{
		priority_queue<pair<T, int>, vector<pair<T, int>>,
			greater<pair<T, int>>> _pq;
		vector<bool> _c(adj.size());
		_d[s] = 0;
		_pq.emplace(0, s);
		while (!_pq.empty()) {
			const pair<T, int> _f = _pq.top();
			_pq.pop();
			const int _u = _f.second;
			_c[_u] = true;
			if (_d[_u] < _f.first) continue;
			for (int _i = 0; _i < static_cast<int>(_adj[_u].size()); _i++) {
				const int _v = _adj[_u][_i].first;
				if (_c[_v]) continue;
				if (_d[_v] > _d[_u] + _adj[_u][_i].second) {
					_d[_v] = _d[_u] + _adj[_u][_i].second;
					_pq.emplace(_d[_v], _adj[_u][_i].first);
				}
			}
		}
	}

public:
	int operator[](const int& index) const {
		return _d[index];
	}
};

int main() {
	int V, E, r;
	cin >> V >> E >> r;
	vector<vector<pair<int, int>>> a(V);
	for (int i = 0; i < E; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		a[s].emplace_back(t, d);
	}
	const Dijkstra<int> dijkstra(a, r);
	for (int i = 0; i < V; i++) {
		if (dijkstra[i] != INT_MAX) cout << dijkstra[i];
		else cout << "INF";
		cout << endl;
	}
}
