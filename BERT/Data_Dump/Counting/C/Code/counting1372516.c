// counting sort
#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int	 main(){

	int *A,*B,C[10001],N;
	int i,j;

	scanf("%d",&N);


	A = malloc(sizeof(int)*N+1);
	B = malloc(sizeof(int)*N+1);

	for (i = 1; i <= N; i++){
		scanf("%d",&A[i]);
	}
//////////////////////////////
	for (i = 0; i < MAX; i++){
		C[i] = 0;		
	}

	for (j = 1; j <= N; j++){
		C[A[j]]++;
	}

	for (i = 1; i <= MAX; i++){
		C[i] = C[i] + C[i-1];
	}

	for(j = N; j >= 1; j--){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
///////////////////////////////
	for (i = 1; i <= N; i++){
		if(i > 1) printf(" ");
		printf("%d",B[i]);
	}	
	printf("\n");

	return 0;
}		
