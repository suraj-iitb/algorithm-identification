#include <stdio.h>


int main()
{
	int N;
	int A[1000];
	int i, j, k;


	scanf("%d", &N);

	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);

	// 表示
	for(i = 0; i < N; i++){
		printf("%d", A[i]);
		if(i != N - 1)
			printf(" ");
		else
			printf("\n");
	}


	// ソート
	for(i = 1; i < N; i++){
		j = i;
		while(j >= 1 && A[j - 1] > A[j]){
			A[j] ^= A[j - 1];
			A[j - 1] ^= A[j];
			A[j] ^= A[j - 1];
			j--;
		}
		// 表示
		for(k = 0; k < N; k++){
			printf("%d", A[k]);
			if(k != N - 1)
				printf(" ");
			else
				printf("\n");
		}
	}

	return 0;
}
