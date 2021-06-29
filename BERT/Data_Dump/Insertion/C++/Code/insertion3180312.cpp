#include<stdio.h>

void trace(int N, int A[]){
	for(int i=0;i<N;i++){
		if (i>0) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
}

void insertionSort(int N,int A[]){
	int i,v,j;
	for(i=1;i<N;i++){
		v=A[i];
		j=i-1;
		while (j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		trace(N,A);
	}
}

int main(){
	int N, i, A[100];
	scanf("%d",&N);
	for (i=0;i<N;i++) scanf("%d",&A[i]);
	
	trace(N,A);
	insertionSort(N,A);
	
	return 0;
}

