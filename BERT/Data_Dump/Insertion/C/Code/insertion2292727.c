#include<stdio.h>

void trace(int A[],int N){
	int i;
	for(i=0;i<N;i++){
		if(i>0)printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
}

void sort(int A[],int N){
	int i,j,v;
	for(i=1;i<N;i++){
		v=A[i];
		j=i-1;
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
			A[j+1]=v;
		trace(A,N);
	}
}

int main(void){
	int A[100];
	int N,i,j;
	
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	
	trace(A,N);
	sort(A,N);
	
	return 0;
}
