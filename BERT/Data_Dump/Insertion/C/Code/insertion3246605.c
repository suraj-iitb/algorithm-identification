#include <stdio.h>

int main(void){
	int N, i, j, v, m;
	scanf("%d", &N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
			for(m=0; m<N; m++){
			printf("%d", A[m]);
			if(m < N-1){
				printf(" ");
			}else printf("\n");
		}
	for(i=1;i<N;i++){
		v = A[i];
		j = i -1;
		while(j>=0 && A[j] > v){
			A[j+1] = A[j];
			j--;
			A[j+1] = v;
		}
		for(m=0; m<N; m++){
			printf("%d", A[m]);
			if(m < N-1){
				printf(" ");
			}else printf("\n");
		}
	}
	return 0;
}
