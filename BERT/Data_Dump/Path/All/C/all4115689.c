#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define N 200
//#define INFTY 1000000000

using namespace std;
static const long long INFTY = (1LL << 32);

long long A[N][N]; //隣接行列
//int c[N][N]; //最短距離の箱
int v;

void warshallFloyd() {
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			if (A[i][k] == INFTY) {
				continue;
			}
			for (int j = 0; j < v; j++) {
				if (A[k][j] == INFTY) {
					continue;
				}
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
			}
		}
	}
}


int main() {
	int e;
	int s, t, d;


	cin >> v >> e;

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			A[i][j] = INFTY;
			//cout << A[i][j] << " ";
		}
		//cout << endl;
	}
	   
	for (int i = 0; i < v; i++) {
		A[i][i] = 0;
	}


	for (int i = 0; i < e; i++) {
		cin >> s >> t >> d;
		A[s][t] = d;
	}


	warshallFloyd();

	bool negative = false;
	for (int i = 0; i < v; i++) {
		if (A[i][i] < 0) negative = true;
	}
	

	if (negative) cout << "NEGATIVE CYCLE" << endl;
	else {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (j != v - 1) {
					if (A[i][j] != INFTY) cout << A[i][j] << " ";
					else cout << "INF" << " ";
				}
				else {
					if (A[i][j] != INFTY) cout << A[i][j] << endl;
					else cout << "INF" << endl;
				}
			}
		}
	}

	return 0;
}
/*
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 7
*/


