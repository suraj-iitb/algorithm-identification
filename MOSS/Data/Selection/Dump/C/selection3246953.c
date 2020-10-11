#include <stdio.h>

void selectionSort(int *A, int N){
	int i, minj, j, temp, count=0, m;
	for(i=0;i<N;i++){
		minj = i;
		for(j=i;j<N;j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(i != minj){
			temp = A[i];
			A[i] = A[minj];
			A[minj] = temp;
			count++;
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
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
	selectionSort(A, N);

	
	return 0;
}
