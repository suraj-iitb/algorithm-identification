#include<stdio.h>

void trance(int A[], int N, int count){
	int i;
	for( i =0; i < N; i++ ){
		if( i > 0 ) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n",count);
}

int bubbleSort(int A[], int N, int count){
	int i,v;
	int sum;
	sum = count;
	for(i=N-1;i>0;i--){
		if(A[i]<A[i-1]){
			v=A[i];
			A[i]=A[i-1];
			A[i-1]=v;
			sum++;
		}
	}
	return sum;
}

int main(void){
	int i,A[100],N,count=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		count = bubbleSort(A,N,count);
	}
	trance(A,N,count);
	return 0;
}
