#include<iostream>
#include<vector>
#define INF 2147483647
using namespace std;

int v, e, A[100][100];

bool Warshall() {
	for (int l = 0; l < v - 1; l++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				for (int k = 0; k < v; k++) {
					if (A[i][k] != INF && A[k][j] != INF && A[i][j] > A[i][k] + A[k][j]) {
						A[i][j] = A[i][k] + A[k][j];
					}
				}
			}
		}
	}

	for (int i = 0; i < v; i++) {
		if (A[i][i] < 0) return 0;
	}

	return 1;
}

int main() {
	int s, t, d;
	cin >> v >> e;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (i == j) A[i][i] = 0;
			else A[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		cin >> s >> t >> d;
		A[s][t] = d;
	}

	if (Warshall() == 0) cout << "NEGATIVE CYCLE" << endl;
	else {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (A[i][j] == INF) cout << "INF";
				else cout << A[i][j];

				if (j == v-1) cout << endl;
				else cout << " ";
			}
		}
	}
	
}
