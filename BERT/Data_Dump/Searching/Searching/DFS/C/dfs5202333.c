#include<stdio.h>

#define N 100

int G[N][N];
int f[N];
int d[N];
int c[N];
int n, t=0;

void DFS(int);

int main() {
    int i=0, j;
    int x, k, v;

    scanf("%d", &n);

    while(i<N){
	    for(j=0; j<n; j++){
	      G[i][j] = 0;
	    }
      i++;
    }

    i = 0;
    while(i<n){
	    scanf("%d%d", &x, &k);
	    for(j=0; j<k; j++){
	      scanf("%d", &v);
	      G[x-1][v-1] = 1;
	    }
      i++;
    }

    for(i=0; i<N; i++)
	    c[i] = 0;

    for(i=0; i<n; i++){
	    if(c[i]==0)
        DFS(i);
    }
    for(i=0; i<n; i++){
	    printf("%d %d %d\n", i+1, d[i], f[i]);
    }

    return 0;
}

void DFS(int x){
    int i;
    c[x] = 1;
    t += 1;
    d[x] = t;
    for(i=0; i<n; i++){
	    if(G[x][i]==1 && c[i]==0)
	      DFS(i);
    }
    c[x] = 2;
    t += 1;
    f[x] = t;
    return;
}

