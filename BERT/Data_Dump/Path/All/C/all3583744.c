#include"bits/stdc++.h"
using namespace std;

#define INF (1LL << 32)

void APSP(vector<vector<long long>>& v)
{
	for (int k = 0; k < v.size(); k++)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i][k] == INF) continue;
			for (int j = 0; j < v.size(); j++)
			{
				if (v[k][j] == INF) continue;
				v[i][j] = min(v[i][j], (v[i][k] + v[k][j]));
			}
		}
	}
}

int main(void)
{
	long long V, E, s, t, d;
	cin >> V >> E;

	vector<vector<long long>> v(V, vector<long long>(V, INF));
	for (int i = 0; i < V; i++) v[i][i] = 0;
	for (int i = 0; i < E; i++)
	{
		cin >> s >> t >> d;
		v[s][t] = d;
	}

	APSP(v);

	for (int i = 0; i < V; i++) {
		if (v[i][i] < 0) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (j) cout << " ";
			if (v[i][j] != INF) cout << v[i][j];
			else cout << "INF";
		}
		cout << endl;
	}

	return 0;
}
