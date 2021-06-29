#include <stdio.h>

void insertionSort(int A[], int N) // N個の要素を含む0-オリジンの配列A
{   
	int v = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 1; i < N; i++) {
		for (k = 0; k < N-1; k++) {
			printf("%d ", A[k]);
		}
		printf("%d\n",A[k]);
		
		v = A[i];
		j = i-1;
		while(j >= 0 && A[j] > v) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
	}
	
	for (k = 0; k < N-1; k++) {
		printf("%d ", A[k]);
	}
	printf("%d\n",A[k]);

}

void Input(int A[], int *N)
{
	int i = 0;
	int ret = 0;
	ret = scanf("%d", N);
	if ( ret == EOF ) {
	    printf("N ERROR\n");
	    return;
	}
	
	for (i = 0; i < (*N)-1; i++) {
		ret = scanf("%d", &A[i]);
		if ( ret == EOF ) {
			printf("A %d ERROR\n", i);
			return;
		}
	}
	ret = scanf("%d", &A[i]);
	if ( ret == EOF ) {
	    printf("A %d ERROR\n", i);
	    return;
	}

    
}


int main()
{
	int A[1000] = { 0 };
	int N = 0;
	
	Input(A, &N);
	
	insertionSort(A, N);
	
	return 0;
}
