#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;

typedef long long ll;

bool debug = false;
const int NIL = -1;
const ll INF = 400000000000;
const int NUM = 101;
clock_t START, END;

ll G[NUM][NUM], v[NUM][NUM];

int main(void)
{
	if (debug) {
		START = clock();
		freopen("in44.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	int V, E, s, t;
	ll d;
	bool negative = false;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> s >> t >> d;
		G[s + 1][t + 1] = d;
		v[s + 1][t + 1]++;
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (!v[i][j]) {
					G[i][j] = INF;
			}
			if (i == j)
				G[i][j] = 0;
		}
	}
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (G[i][i] < 0) {
			negative = true;
			break;
		}
	}
	if (negative)
		cout << "NEGATIVE CYCLE" << endl;
	else {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (j - 1)
					cout << " ";
				if (G[i][j] > 200000000000)
					cout << "INF";
				else
					cout << G[i][j];
			}
			cout << endl;
		}
	}
	if (debug) {
		END = clock();
		double endtime = (double)(END - START) / 1000;
		printf("total time = %lf s", endtime);
	}
	return 0;
}
