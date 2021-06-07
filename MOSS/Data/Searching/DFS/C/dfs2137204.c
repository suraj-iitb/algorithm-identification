#include<stdio.h>
int Adj[100][100] = { 0 };
int Stack[100] = { 0 }, d[100] = { 0 }, f[100] = { 0 };
int main(){
	int n, u, k, v;
	int i, j;
	int id, t = 0, stc, pid, id_check;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &u);
		scanf("%d", &k);
		for (j = 0; j < k; j++) {
			scanf("%d", &v);
			Adj[u - 1][j] = v;
		}
	}
	
	for (id_check = 0; id_check < n; id_check++) {
		if (d[id_check] != 0) {
			continue;
		} else {
			id = id_check;
			t++;
			d[id] = t;
			stc = 0;
			Stack[stc] = id;
			
			while (1) {
				pid = id;
				t++;
				for (i = 0; Adj[id][i] != 0; i++) {
					if (d[ Adj[id][i] - 1 ] == 0) {
						id = Adj[id][i] - 1;
						d[id] = t;
						stc++;
						Stack[stc] = id;
						break;
					}
				}
				if (pid == id) {
					Stack[stc] = 0;
					f[id] = t;
					stc--;
					if (stc < 0) break;
					id = Stack[stc];
				}
			}
		}
	}
	
	for (i = 0; i < n; i++) {
		printf("%d %d %d\n", i + 1, d[i], f[i]);
	}
	return 0;
}
