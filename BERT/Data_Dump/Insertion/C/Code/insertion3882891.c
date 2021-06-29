#include<stdio.h>

int main (void){
	
	int N, i, j, ii, v;
	
	scanf("%d", &N);
	
	int A[N];
	
	for(i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	
	for(ii=0; ii<N-1; ii++){
		printf("%d ", A[ii]);
	}
	printf("%d\n", A[ii]);
	
	for(i=0+1; i<N; i++){
		
		
		v=A[i];
		j=i-1;
		
		while(0<=j && v<A[j]){
			A[j+1]=A[j];
			j--;
		}
		
		A[j+1]=v;
		
		for(ii=0; ii<N-1; ii++){
			printf("%d ", A[ii]);
		}
		printf("%d\n", A[ii]);
		
	}
	
	return 0;
}


