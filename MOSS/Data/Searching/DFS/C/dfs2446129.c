#include <stdio.h>

#define W 0
#define G 1
#define B 2
#define N 100

void dv(int);
void dfs();

int d[N], f[N], c[N];
int time, n;
int g[N][N];

int main(){
	int i, j, u, k, v;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			g[i][j] = 0;
		}
	}
	
	for(i = 0; i < n; i++){
		scanf("%d%d", &u, &k);
		u--;
		for(j = 0; j < k; j++){
			scanf("%d",&v);
			v--;
			g[u][v] = 1;
		}
	}
	dfs();
	return 0;
}

void dfs(){
	int a;
	for(a = 0; a < n; a++){
		c[a] = W;
	}
	time = 0;
	
	for(a = 0; a < n; a++){
		if(c[a] == W) dv(a);
	}
	
	for(a = 0; a < n; a++){
		printf("%d %d %d\n", a+1, d[a], f[a]);
	}
}

void dv(int b){
	int k;
	
	c[b] = G;
	d[b] = ++time;
	
	for(k = 0; k < n; k++){
		if(g[b][k] == 0) continue;
		if(c[k] == W) dv(k);
	}
	
	c[b] = B;
	f[b] = ++time;
}
