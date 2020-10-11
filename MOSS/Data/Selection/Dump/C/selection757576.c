#include<stdio.h>

int main(void){
	int min,go,i,j,N,count = 0;
	int A[100];
	
	scanf("%d",&N);
	
	for(i=0;i<N;++i){
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<N;++i){
		min = i;
		for(j=i+1;j<N;++j){
			if(A[j]<A[min]){
				min = j;
			}
		}
		go = A[i];
		A[i] = A[min];
		A[min] = go;
		if(A[i] != A[min])count++;
	}
	
	for(i=0;i<N;++i){
		printf("%d",A[i]);
		if(i<N-1)printf(" ");
	}
	printf("\n%d\n",count);
	return 0;
}
