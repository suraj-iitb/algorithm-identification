#include <stdio.h>

void bubbleSort(int *A, int N){
	int flag = 1, temp, count = 0, m, j;
	while(flag){
		flag = 0;
		for(j=N-1;j>0;j--){
			if(A[j] < A[j-1]){
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				flag = 1;
				count++;
			}
		}
	}
	for(m=0; m<N; m++){
		printf("%d", A[m]);
		if(m < N-1){
			printf(" ");
		}else printf("\n");
	}
	printf("%d\n", count);
}
int main(void){
	int N, i;
	scanf("%d", &N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
	bubbleSort(A, N);

	
	return 0;
}
