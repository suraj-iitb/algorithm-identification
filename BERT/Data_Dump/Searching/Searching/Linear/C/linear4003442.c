#include <stdio.h>

int linearsearch(int N, int Q, int n[], int q[]){
	int i, j;
	int count = 0;
	for(i = 0; i < Q; i++){
		j = 0;
		n[N - 1] = q[i];
		while(q[i] != n[j]){
			j++;
		}
		if(j != N - 1){
			count++;
		}
	}
	return count;
}

int main(void){
	int N, Q, i;
	int n[10000], q[500];
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &n[i]);
	}
	scanf("%d", &Q);
	for(i = 0; i < Q; i++){
		scanf("%d", &q[i]);
	}
	printf("%d\n", linearsearch(N, Q, n, q));
	return 0;
}
