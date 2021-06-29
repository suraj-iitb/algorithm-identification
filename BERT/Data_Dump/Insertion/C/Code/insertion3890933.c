#include<stdio.h>

int sort(int A[], int N);

int main()
{
	int i = 0, N=0;
	int A[1000];

	scanf("%d", &N);

	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}

	sort(A, N);



	return 0;
}

int sort(int A[], int N){
	int i, j, k, tmp;
	for(i = 0; i < N; i++){
		tmp = A[i];
		j = i-1;
		while(j >= 0 && A[j] > tmp){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = tmp;
		for(k = 0; k < N; k++){
			printf("%d", A[k]);
			if(k!=N-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

