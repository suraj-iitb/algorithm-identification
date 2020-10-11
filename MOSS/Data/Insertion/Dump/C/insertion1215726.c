/*
 * Insertion Sort.c
 *
 *  Created on: 2015/02/13
 */
#include <stdio.h>

void presentation(int N,int A[]){
	int i;

	for(i=0;i<N-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[N-1]);
}

void swap(int *from,int *to){
	int tmp;

	tmp = *to;
	*to = *from;
	*from  = tmp;
}

void insert_sort(int N,int A[]){
	int i,j;

	presentation(N,A);

	for(i=1;i<N;i++){
		j=i;



		while((j>0) && (A[j-1] > A[j])){
			swap(&A[j-1],&A[j]);

			j--;
		}
	presentation(N,A);
	}

}


int main(void){
	int N,A[100];
	int i;

	scanf("%d",&N);

	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}

	insert_sort(N,A);

	return 0;
}
