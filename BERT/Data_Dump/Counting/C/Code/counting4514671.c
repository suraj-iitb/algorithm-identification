#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void CountingSort(int *A,int *B,int N,int max){
	int m=(max+2);
	int *C=(int*)malloc(sizeof(int)*m);
	for(int i=0;i<m;i++){
		C[i]=0;
	}
	for(int i=0;i<N;i++){
		C[A[i]]++;
		B[i]=0;
	}

	for(int i=1;i<m;i++){
		C[i]+=C[i-1];
	}

	for(int i=(N-1);i>=0;i--){
		B[C[A[i]]-1]=A[i];
		C[A[i]]--;
	}

}

int main(){
	int N;
	int *A,*B;
	int max=0;

	scanf("%d",&N);
	A=(int*)malloc(sizeof(int)*(N+1));
	B=(int*)malloc(sizeof(int)*(N+1));
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		if(max<A[i]){max=A[i];}
	}

	CountingSort(A,B,N,max);
	
	for(int i=0;i<N;i++){
		printf("%d",B[i]);
		if(i==(N-1)){
			printf("\n");
		}else{
			printf(" ");
		}
	}
	
	return 0;
}
