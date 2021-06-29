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
	int i,j,v,minj,sum;
	sum = count;
	for(i=0;i<N-1;i++){
		v=A[i];
		for(j=i+1;j<N;j++){
			if(v > A[j]){
				v = A[j];
				minj = j;
			}
		}
		if(A[i] != v){
			A[minj] = A[i];
			A[i] = v;
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
