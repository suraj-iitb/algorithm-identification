#include<stdio.h>

int main(){
	int i, j, k;
	int N;
	scanf("%d\n", &N);

	int A[N];
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for(i = 0; i < N; i++) {
		if(i == N-1)
			printf("%d\n", A[i]);
		else
			printf("%d ",A[i]);
	}

	//insertionSort(A, N)
	for(i = 1; i < N; i++) {
		int key = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > key) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;

		for(k = 0; k < N; k++) {
			if(k == N-1)
				printf("%d\n", A[k]);
			else
				printf("%d ",A[k]);
		}
	}
    return 0;
}
