#include <stdio.h>
#define N 101

int n;
int A[N][N];
int d[N];
int Visited[N];

void breadth_search(int c) {
	int i;
	Visited[c] = 1;
	for(i=1; i<=n; i++) {
		if(A[c][i] != 0 && Visited[i] == 0) {
			d[i] = d[c]+1;
			breadth_search(i);
		}
		else if(A[c][i] != 0 && Visited[i] != 0) {
			if((d[c]+1) < d[i]) {
				d[i] = d[c]+1;
				breadth_search(i);
			}
		}
	}
}

int main(void) {
	int i, j, v;
	int id, k;
	
	for(i=0; i<N; i++) {
		d[i] = -1;
		for(j=0; j<N; j++) {
			A[i][j] = 0;
		}
	}
	
	scanf("%d", &n);
	
	d[1] = 0;
	for(i=0; i<n; i++) {
		scanf("%d %d", &id, &k);
		for(j=0; j<k; j++) {
			scanf("%d", &v);
			A[id][v] = 1;
			if(d[id] != -1)d[v] = 0;
		}
	}
	breadth_search(1);
	for(i=1; i<=n; i++) printf("%d %d\n", i, d[i]);
	return 0;
}
