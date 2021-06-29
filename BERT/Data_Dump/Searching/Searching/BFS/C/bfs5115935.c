#include <stdio.h>
#define N 100

int n, M[N][N];
int d[N], q[N];

void search(int); 

int main(){
	int a, y, k, i, j;
  
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
		M[i][j] = 0;
		}
	}
  
for (i = 0; i < n; i++){
	scanf("%d %d", &a, &k);
	a--;
	for (j = 0; j < k; j++){
		scanf("%d", &y);
		y--;
		M[a][y] = 1;
		}
	}
	search(0);
	return 0;
}


void search(int s) {
	int a, y, i, x = 0, m = 0;
  
	for (i = 0; i < n; i++) {
	d[i] = 101;
	}
  
	q[s] = 0;
	d[s] = 0;
  
	while (x != 1) {
		a = q[m];
		for (y = 0; y < n; y++){
			if (M[a][y] == 0){
				continue;
			}
    		if (d[y] != 101){
    			continue;
    		}
		d[y] = d[a] + 1;
		q[++s] = y;
		}
		if (m == n - 1){
			for (i = 0 ; i < n ; i++){
				if (d[i] == 101){
					d[i] = -1;
				}	
			}
		x = 1;
		}
		m = m + 1;
	}
  
	for (a = 0; a < n; a++){
		printf("%d %d\n", a + 1, d[a]);
	 }
}
