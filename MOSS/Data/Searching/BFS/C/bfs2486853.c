#include <stdio.h>
#define N 1000
#define inf 1000000

int n,M[N][N];
int d[N];
int Q[2*N], head=0, tail=0;

void enQueue(int);
int deQueue(void);
void BFS(int);

int main(){
	int i, j, u, k, v;
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			M[i][j] = 0;
		}
	}
	
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++){
		scanf("%d%d", &u, &k);
		for(j = 0; j < k; j++){
			scanf("%d", &v);
			M[u][v] = 1;
		}
	}
	
	BFS(1);
	
	for(i = 1; i <= n; i++){
		if(d[i] == inf){
			d[i] = -1;
		}
		printf("%d %d\n", i, d[i]);
	}
	
	return 0;
}

void enQueue(int x){
	Q[tail++] = x;
}

int deQueue(){
	return Q[head++];
}

void BFS(int y){
	int i, j, k;
	enQueue(y);
	for(i = 1; i <= n; i++){
		d[i] = inf;
		d[y] = 0;
	}
	while(head != tail){
		j = deQueue();
		for(k = 1; k <= n; k++){
			if(M[j][k] == 0) continue;
			if(d[k] != inf) continue;
			d[k] = d[j] + 1;
			enQueue(k);
		}
	}
}
