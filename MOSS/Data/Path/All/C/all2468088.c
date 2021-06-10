#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cstdio>
using namespace std;

typedef long long ll;

const ll INF = 1LL << 32;
ll Map[105][105];
int v, e;
void printAns();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 105; ++i)
	{
		for (int j = 0; j < 105; ++j)
		{
			Map[i][j] = i == j ? 0 : INF;
		}
	}
	int  s, t, d;
	cin >> v >> e;
	for (int i = 0; i < e; ++i)
	{
		cin >> s >> t >> d;
		Map[s][t] = d;
	}
	for (int k = 0; k < v; ++k)
	{
		for (int i = 0; i < v; ++i)
		{
			if (Map[i][k] == INF)
				continue;
			for (int j = 0; j < v; ++j)
			{
				if (Map[k][j] == INF)
					continue;
				Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
			}
		}
	}
	bool negative = false;
	for (int i = 0; i < v; ++i)
		if (Map[i][i] < 0)
			negative = true;
	if (negative)
		cout << "NEGATIVE CYCLE\n";
	else
		printAns();

	return 0;
}

void printAns()
{
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			if (j)
				cout << ' ';
			if (Map[i][j] == INF)
				cout << "INF";
			else
				cout << Map[i][j];
		}
		cout << '\n';
	}
}
