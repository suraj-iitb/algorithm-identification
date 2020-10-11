#include<stdio.h>

int bubbleSort(int A[], int N){
	int temp = 0;
	int times = 0;
	int btimes = -1;
	int i = 0;
	while( times > btimes ){
		btimes = times;
		for( i = N-1; i > 0; i-- ){
			if( A[i] < A[i-1] ){
				temp = A[i];
				A[i] = A[i-1];
				A[i-1] = temp;
				times++;
			}
		}
	}
	return times;
}



int main(){
	int N = 0;;
	int A[1000];
	int i = 0;
	int re = 0;
	scanf("%d", &N);
	for( i = 0; i < N; i++ ){ scanf("%d", &A[i]); }
	re = bubbleSort(A, N);
	printf("%d", A[0]);
	for( i = 1; i < N; i++ ){
		printf(" %d", A[i]);
	}
	printf("\n");
	printf("%d\n", re);
	return 0;
}
