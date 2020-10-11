#include<stdio.h>
#include<limits.h>

int A[2000000], B[2000000];

void CountingSort(int A[], int B[], int n, int k){
	int i, j;
	int C[k+1];
	for( i = 0; i < k+1; i++ ){ C[i] = 0; }
	for( j = 0; j < n; j++ ){ C[A[j]]++; }
	for( i = 1; i < k+1; i++ ){ C[i] = C[i] + C[i-1]; }
	for( j = n-1; j >= 0; j-- ){
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;
	}
	return;
}

int main(){
	int n, max = INT_MIN, i;
	scanf("%d", &n);
	for( i = 0; i < n; i++ ){
		scanf("%d", &A[i]);
		if( A[i] > max ){ max = A[i]; }
	}
	CountingSort(A, B, n, max);
	printf("%d", B[0]);
	for( i = 1; i < n; i++ ){ printf(" %d", B[i]); }
	printf("\n");
	return 0;
}
