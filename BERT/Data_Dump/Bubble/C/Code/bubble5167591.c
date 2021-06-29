#include <stdio.h>

int main()
{	
	int N;
	int A[101];
	int i, j, k;
	int min;
	int sc=0;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	
	for(i=0; i<N; i++){
		for(j=N-1; j>i; j--){
			if(A[j]<A[j-1]){
				min=A[j];
				A[j]=A[j-1];
				A[j-1]=min;
				sc++;
			}
		}
	}
	
	for(i=0; i<N; i++){
		printf("%d", A[i]);
		if(i != N-1)
			printf(" ");
	}
	printf("\n%d\n", sc);
	
	return 0;
}
