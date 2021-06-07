#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define N 100
int head = 0, tail = 0, que[N], M[N][N] = {0}, n;
int INF = (1 << 21);

void bfs(void);
void push(int);
int pop(void);
int isEmpty(void);

int main(void){
	int u, k, v, i, j;

	for(i = 0; i < N; i++){
		que[i] = -1;
	}

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &u);
		u--;
		scanf("%d", &k);
		for(j = 0; j < k; j++){
			scanf("%d", &v);
			v--;
			M[u][v] = 1;
		}
	}

	bfs();

	return 0;
}

void bfs(){
	int d[N], i = 0, u, v;
	while( i < N){
		d[i++] = INF;
    }

	d[0] = 0;
	push(0);

	while(!isEmpty()){
		u = pop();
		for(i = 0; i < n; i++){
			if(M[u][i] == 0) continue;
			if(d[i] != INF) continue;
			d[i] = d[u] + 1;
			push(i);
		}
	}

	for(i = 0; i < n; i++){
		printf("%d %d\n", i + 1, (d[i] == INF ? -1 : d[i]));
	}
}

void push(int a){
	que[tail++] = a;
}

int pop(){
	 int ret = que[head];
	 que[head++] = -1;
	 return ret;
}

int isEmpty(){
	return (head == tail);
}
