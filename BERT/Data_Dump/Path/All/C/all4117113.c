#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

#define IN 2000000000
using namespace std;


int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	int A[101][101];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i == j) {
				A[i][j] = 0;
			}
			else {
				A[i][j] = IN;
			}
		}
	}
	int s, t, d;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &s, &t, &d);
		A[s][t] = d;
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (A[j][i] != IN) {
				for (int k = 0; k < V; k++) {
					if (A[i][k] != IN) {
						A[j][k] = min(A[j][k], A[j][i] + A[i][k]);

					}
				}
			}
		}
	}

	int flag = 0;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (A[i][i] < 0) {
				flag = 1;
			}
		}
	}

	if (flag == 1) {
		printf("NEGATIVE CYCLE\n");
	}
	else {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (A[i][j] == IN) {
					printf("INF");
				}
				else {
					printf("%d", A[i][j]);
				}if (j != V - 1) printf(" ");
				else printf("\n");
			}
		}
	}
	return 0;

}
