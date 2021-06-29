#include <stdio.h>

void disp(int A[],int N){
	int i;
	for(i=0;i<N;i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",A[i]);
	}
			printf("\n");
}

void trace(int A[],int N){
	int i,j,v;
	for(i=1;i<=N-1;i++){
		v=A[i];
		j=i-1;
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
			}
			A[j+1]=v;
		disp(A,N);
		}
}

int main (void){
	
	int i,N;
	scanf("%d",&N);
	
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	disp(A,N);
	trace(A,N);
	return 0;
}
