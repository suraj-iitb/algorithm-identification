#include <stdio.h>
#define N 10000

int d[N];
int f[N];
int count = 1;


void Depth_Search(int u,int n, int A[u][n]) {
	int i;
	d[u] = count;
	for(i=0; i<n; i++) {
		if(A[u][i] == 1) {
			if(d[i+1] == 0) {
				count++;
				Depth_Search(i+1, n, A);
			}
		}
		if(i == n-1) {
			count++;
			f[u] = count;
		}
	}
}

int main(void) {
	int i, j;
	int n, u, k, v;
	
	scanf("%d", &n);
	
	int A[n+1][n];
	
	//初期化
	for(i=1; i<=n; i++) {
		d[i] = 0; f[i] = 0;
		for(j=0; j<n; j++) {
			A[i][j] = 0;
		}
	}
	
	for(i=0; i<n; i++) {
		scanf("%d %d", &u, &k);
		for(j=0; j<k; j++) {
			scanf("%d", &v);
			A[u][v-1] = 1;
		}
	}
	for(i=1; i<=n; i++) {
		if(d[i] == 0) {
			Depth_Search(i, n, A);
			count++;
		}
	}
	
	for(i=1; i<=n; i++) printf("%d %d %d\n", i, d[i], f[i]);
}
