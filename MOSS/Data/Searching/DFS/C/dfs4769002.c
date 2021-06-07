#include<stdio.h>
#include<stdlib.h>

#define constraints 101

int n, i, u, k, v_k, time, Adj[constraints][constraints], discovery[constraints], finish[constraints];


void dfs(int i) {
	time++;
	discovery[i] = time;
	for (int j = 0; j < n; j++) {
		if (Adj[i][j] != 0 && discovery[j] == 0) {
			dfs(j);
		}
	}
	time++;
	finish[i] = time;
}

int main() {
	time = 0;
	scanf("%d", &n);

	//scanning / make graph
	for (i = 0; i < n; i++) {
		scanf("%d %d", &u, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &v_k);
			Adj[u - 1][v_k - 1] = 1;
		}
	}

	//dfs
	for (i = 0; i < n; i++) {
		if (discovery[i] == 0) {
			dfs(i);
		}
	}

	//printing
	for (i = 0; i < n; i++) {
		printf("%d %d %d\n", i + 1, discovery[i], finish[i]);
	}

	return 0;
}

