#include<stdio.h>
int Adj[100][100] = { 0 };
int Que[101] = { -1 }, d[100] = { -1 };
int main(){
	int n, u, k, v;
	int i, j;
	int id = 0, qin = 0, qout = 0, aid;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &u);
		scanf("%d", &k);
		for (j = 0; j < k; j++) {
			scanf("%d", &v);
			Adj[u - 1][j] = v;
		}
	}
	for (i = 0; i < 101; i++) {
		Que[i] = -1;
		d[i] = -1;
	}
	
	Que[qin++] = id;
	d[id] = 0;
	while (id != -1) {
		qout++;
		for (i = 0; Adj[id][i] != 0; i++) {
			aid = Adj[id][i] - 1;
			if (d[aid] == -1) {
				Que[qin++] = aid;
				d[aid] = d[id] + 1;
			}
		}
		id = Que[qout];
	}
	
	for (i = 0; i < n; i++) {
		printf("%d %d\n", i + 1, d[i]);
	}
	return 0;
}
