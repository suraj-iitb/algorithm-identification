#include<stdio.h>

void Trace(int A[], int N){
	int i;
	for(i=0; i<N; i++){
		if(i>0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}


void insertionSort(int A[], int N){
	int i,j,v;
	for(i=1; i<N; i++){
	    j=i-1;
		v=A[i];/*ｖはA[i]の値を一時保管するための変数*/
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		Trace(A,N);
	}
}

int main(){
	int i,j,N;
	int A[100];
	
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d",&A[i]);
	}
	
	Trace(A,N);
	insertionSort(A,N);
	
	return 0;
}

