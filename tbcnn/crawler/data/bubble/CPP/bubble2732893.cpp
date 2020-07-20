#include <stdio.h>

void trace(int A[], int n){
	int i;
	for ( i = 0; i < n; i++ ){
	  if ( i > 0 ) printf(" ");
	  printf("%d", A[i]);
	}
	printf("\n");
}

void bubbleSort(int A[], int N){
	bool flag = 1;
	int j, v, count=0;
	for(int i =0; flag; i++){
		flag = 0;
		for(j=N-1; j >=i+1; j--){
			if (A[j] < A[j-1]){
				v = A[j];
				A[j] = A[j-1];
				A[j-1] = v;
				flag = 1;
				count++;
			}
		}
	}
	trace(A, N);
	printf("%d\n", count);
}

int main(){
	int n, i;
	int A[100];
	scanf("%d", &n);
	for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
	
	bubbleSort(A, n);

	return 0;
}
