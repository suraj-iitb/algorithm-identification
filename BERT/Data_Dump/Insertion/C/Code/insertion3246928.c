#include <stdio.h>

void insertionSort(int* A, int N){
	int v, j;
	for (int i = 1; i < N; i++)
	{
		v = A[i];
		j = i-1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		
		for(j = 0; j < N; j++){
			printf("%d", A[j]);
			if(j != N-1) printf(" ");
		}
		printf("\n");
	}
}



int main(int argc, char const *argv[])
{
	int N, A[1000];
	scanf("%d", &N);
	int i;
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	for( i = 0; i < N; i++ ){
        printf("%d", A[i]);
        if( i != N-1 ) printf(" ");
    }
    printf("\n");
    insertionSort(A, N);

	return 0;
}
