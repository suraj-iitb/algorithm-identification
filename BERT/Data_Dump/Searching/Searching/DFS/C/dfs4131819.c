#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
int color[101], A[101][101], d[101], f[101], nt[101], time = 0;
int S[101],s = 1;
void dfs(int);
void dfsvisit(int,int);
void pop(void);
int next(int,int);
void push(int);
int empty(int,int);
void initstack(int);
int top(int);

int  main() {
	int i,j,n, u, v, k;
	scanf("%d",&n);
	initstack(n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			A[i][j] = 0;
		}
	}

	for (i = 1; i <= n; i++) {
		scanf("%d", &u);
		scanf("%d", &k);
		for (j = 1; j <= k; j++) {
			scanf("%d", &v);
			A[u][v] = 1;
		}
	}
	dfs(n);
}
void dfs(int n) {
	int i,u;
	for (i = 1; i <= n; i++) {
		color[i] = WHITE;
		nt[i] = 0;
	}
	for (u = 1; u <= n; u++) {
		if (color[u] == WHITE) {
			dfsvisit(u,n);
		}
	}
	for (i = 1; i <= n;i++) {
		printf("%d %d %d\n",i,d[i],f[i]);
	}
}
void dfsvisit(int u,int n) {
	int i,v;
	for (i = 1; i <= n; i++) {
		nt[i] = 0;
	}
	push(u);
	color[u] = GRAY;
	d[u] = ++time;

	while (empty(u, n)) {
		u = top(n);
		if (u == -1)break;
		v = next(u, n);
		if (v != -1) {
			if (color[v] == WHITE) {
				color[v] = GRAY;
				d[v] = ++time;
				push(v);
			}
		}
		else {
			pop();
			color[u] = BLACK;
			f[u] = ++time;
		}
	}
}
void initstack(int n) {
	int i;
	for (i = 1; i <= n; i++) {
		S[i] = -1;
	}
}
void pop() {
	//printf("pop = %d\n", S[s-1]);
	S[s-1] = -1;
	s--;
}
int next(int u,int n) {
	int i;
	for (i = nt[u]; i <= n;i++) {
		nt[u] = i+1;
		if (A[u][i]) {
			//printf("i = %d\n",i);
			return i;
		}
	}
	return -1;
}
void push(int u) {
	S[s] = u;
	s++;
}
int empty(int u,int n) {
	int i,flag = 0;
	for(i = 1; i <= n; i++) {
		if (S[i] > -1) {
			flag = 1;
		}
	}
	return flag;
}
int top(int n) {
	int i;
	for (i = n; i > 0;i--) {
		if (S[i] > 0) {
			//printf("top = %d\n",S[i]);
			return S[i];
		}
	}
	return -1;
}
