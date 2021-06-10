#include<iostream>
#include<cmath>
using namespace std;
#define M 9999999999999
int v, e, s, t, d;
long long map[101][101];
void f();
int main()
{
	cin >> v >> e;
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			if (i == j) map[i][j] = 0;
			else map[i][j] = M;
	for (int i = 0; i < e; i++)
	{
		cin >> s >> t >> d;
		map[s][t] = d;
	}
	f();
	return 0;
}
void f()
{
	for (int k = 0; k < v; k++)
	{
		for (int i = 0; i < v; i++)
		{
			if (map[i][k] == M)
				continue;
			for (int j = 0; j < v; j++)
			{
				if (map[i][j] > map[i][k] + map[k][j]&&map[i][k]!=M&&map[k][j]!=M)
				{
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}

	for (int i = 0; i < v; i++)
	{
		if (map[i][i] < 0)
		{
			cout << "NEGATIVE CYCLE" << endl;
			return;
		}
	}
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v-1; j++)
		{
			if (map[i][j] == M)
			{
				cout << "INF ";
			}
			else
			{
				cout << map[i][j] << " ";
			}

		}
		if (map[i][v-1] == M)
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << map[i][v-1] << endl;
		}
	}
}
