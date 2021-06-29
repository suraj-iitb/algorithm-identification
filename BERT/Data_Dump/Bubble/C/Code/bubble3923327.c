#include <stdio.h>
#include <stdbool.h>

int bubbleSort(int A[],int N){
	int tag;
	int sw=0;
	bool flag=1;
	for(int i=0;flag;i++){
		flag=0;
		for(int j=N-1;j>=i+1;j--){
			if(A[j]<A[j-1]){
				tag=A[j];
				A[j]=A[j-1];
				A[j-1]=tag;
				flag=1;
				sw++;
			}
		}
	}
	return sw;
}

int main(void){
	int N,sw;
	int A[100];
	
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	sw=bubbleSort(A,N);
	
	for(int i=0;i<N;i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",A[i]);
	}
	
	printf("\n");
	printf("%d\n",sw);
	return 0;
}