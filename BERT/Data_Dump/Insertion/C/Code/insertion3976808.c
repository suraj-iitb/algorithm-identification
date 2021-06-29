#include<stdio.h>

void trace(int A[],int N){
	int i;
	for (i=0;i<N;i++){
		if(i>0)printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");		 
}
void insertionsort(int A[],int N){
	int i,j,t;
	for(i=0;i<N;i++){
		t=A[i];
		j=i;
		while(j>0&&A[j-1]>t){
			A[j]=A[j-1];
			j--;
		}
	A[j]=t;
	trace(A,N);
	}
}

int main(){
	int N,i,j;
	int A[100];
	
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	
	insertionsort(A,N);
	return 0;
}

