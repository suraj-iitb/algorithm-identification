#include<stdio.h>

static const int N = 1000;

void trace(int A[], int n){
	int i;
	for ( i = 1; i <= n; i++ ){
		if ( i > 1 ) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

int main(){
    int n, i, j;
    int k, m, key;
	int A[N+1];
	scanf("%d", &n);

	for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);
    A[0] = 0;
    
	trace(A, n);
    for ( k = 2; k < (n+1); k++){
        key = A[k];
        /* insert A[i] into the sorted sequence A[0,...,j-1] */
        m = k - 1;
        while ((m >= 0) && (A[m] > key)){
            A[m+1] = A[m];
            m--;
        }
        A[m+1] = key;
        trace(A, n);
    }

	return 0;
}
