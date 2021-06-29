#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000


int main (){
	unsigned short *A, *B;
	int C[VMAX+1];
	int n, i, j;
	
	scanf("%d", &n);
	
	A = malloc(sizeof(short)*n + 1);
	B = malloc(sizeof(short)*n + 1);
	
	for (i = 1; i <= n; i++){
		scanf("%d", &A[i]);
	}
	//printf("%d", k);
	
	for (i = 0; i < VMAX; i++){
		C[i] = 0;
	}
	
	for (j = 1; j < n+1; j++){
		C[A[j]]++;
	}
	
	for (i = 1; i < VMAX; i++){
		C[i] = C[i] + C[i-1];
	}
	
	for (j = n; j >= 1; j--){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
		
		//for (i = 1; i < n; i++){
		//	printf("%d ", B[i]);
		//}
		//printf("%d\n", B[n]);
	}
	
	for (i = 1; i < n; i++){
		printf("%d ", B[i]);
	}
	printf("%d\n", B[n]);
	
	return 0;
}

