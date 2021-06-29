#include <stdio.h>


int insertionSort(int* A, int N){
	int i, v, j, k;
	
	for(k=0;k<N;k++){
		printf("%d", A[k]);
		if(k!=N-1){
			printf(" ");
		}
	}
	printf("\n");
	
	for(i=1;i<=N-1;i++){
		v=A[i];
		j=i-1;
		
		while(j>=0&&A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		
		for(k=0;k<N;k++){
			printf("%d", A[k]);
			if(k!=N-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	
	return 0;
}

int main(){
	int n, i, a[105];
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	
	insertionSort(a, n);
	
	return 0;
}

