#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PI;

void solve()
{
	int V, E;
	cin >> V >> E;
	vector< vector<long long int> > D(V + 1, vector<long long int>(V + 1));
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			if (i == j)
			{
				D[i][j] = 0;
			}
			else
			{
				D[i][j] = 1e18;
			}
		}
	}
	for (int i = 0; i < E; ++i)
	{
		int s, t, d;
		cin >> s >> t >> d;
		D[s][t] = d;
	}

	for (int k = 0; k < V; ++k)
	{
		for (int i = 0; i < V; ++i)
		{
			if (D[i][k] == 1e18)
			{
				continue;
			}
			for (int j = 0; j < V; ++j)
			{
				if (D[k][j] == 1e18)
				{
					continue;
				}
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	for (int i = 0; i < V; ++i)
	{
		if (D[i][i] < 0)
		{
			cout << "NEGATIVE CYCLE" << endl;
			return;
		}
	}
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			if (j)
			{
				cout << " ";
			}
			if (D[i][j] == 1e18)
			{
				cout << "INF";
			}
			else
			{
				cout << D[i][j];
			}
		}
		cout << endl;
	}
}

int main()
{
	solve();
	return(0);
}
