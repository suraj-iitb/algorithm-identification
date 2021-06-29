#include "stdio.h"

void insertionSort(int A[],int N){
	for(int i=0;i<N;++i){
		if(i==0) printf("%d",A[i]);
		else printf(" %d",A[i]);
	}
	printf("\n");
	for(int i=1;i<N;++i){
		int v=A[i];
		int j=i-1;
		while(j>=0&&A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(int j=0;j<N;++j){
			if(j==0) printf("%d",A[j]);
			else printf(" %d",A[j]);
		}
		printf("\n");
	}
}

int main(){
	int N; scanf("%d",&N);
	int A[100];
	for(int i=0;i<N;++i) scanf("%d",&A[i]);
	
	insertionSort(A,N);
	return 0;
}
