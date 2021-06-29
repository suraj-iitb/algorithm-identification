#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N], d[N], f[N], tt;
int nt[N];
int top = 0, stack[100]; 

void push(int x){
	stack[++top] = x;
}

int pop(){
	top--;
	return stack[top+1];
}

// uに隣接するvを番号順に収得
int next ( int u) {
	int v;
	for ( v = nt[u]; v < n; v++ ) {
		nt[u] = v + 1;
		if ( M[u][v] ) return v;
	}
	return -1;
}

// スタックを用いた深さ優先探索
void dfs_visit ( int r) {
	int i;
	for ( i = 0; i < n; i++) nt[i] = 0;

	push(r);
	color[r] = GRAY;
	d[r] = ++tt;

	while (top != 0) {
		int u = stack[top];
		int v = next(u);
		if ( v != -1) {
			if ( color[v] == WHITE) {
				color[v] = GRAY;
				d[v] = ++tt;
				push(v);
			}
		} else {
			pop();
			color[u] = BLACK;
			f[u] = ++tt;
		}
	}

}

void dfs() {
	int i;
	int u;

	// 初期化
	for ( i = 0; i < n; i++) {
		color[i] = WHITE;
		nt[i] = 0;
	}

	// 未訪問のuを始点として深さ優先探索
	for ( u = 0; u < n; u++) {
		if ( color[u] == WHITE ) dfs_visit(u);
	}
	for ( i = 0; i < n; i++) {
		printf("%d %d %d\n",i + 1, d[i], f[i]);
	}

}

int main () {
	int i, j;
	int u, k, v;

	scanf("%d",&n);
	for ( i = 0; i < n; i++) {
		for ( j = 0; j < n; j++) M[i][j] = 0;
	}

	for ( i = 0; i < n; i++) {
		scanf("%d%d",&u,&k);
		u--;
		for (j = 0; j < k; j++) {
			scanf("%d",&v);
			v--;
			M[u][v] = 1;
		}
	}

	dfs();

	return 0;
}
