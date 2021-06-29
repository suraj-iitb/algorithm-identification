#include <stdio.h>
#define MAX 2000001
#define RANGE 10000

int A[MAX], B[MAX], C[MAX], N;

void Count(int A[], int B[], int k){
	int i, j;
	for(i=0; i<=k; i++){
		C[i] = 0;
	}

	for(j=1; j<=N; j++){
		C[A[j]]++;
	}

	for(i = 1; i<=k; i++){
		C[i] = C[i] + C[i-1];
	}

	for(j=N; j>0; j--){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}

int main(){
	
	scanf("%d", &N);
	int s;
	int k = 0;
	for(s=1; s<=N; s++){
		scanf("%d", &A[s]);
		if(k<A[s]) k = A[s];
	}

	
	Count(A,B,k);

	for(s=1;s<=N;s++){
		if(s!=1) printf(" ");
		printf("%d", B[s]);
	}

	printf("\n");

	return 0;

}
