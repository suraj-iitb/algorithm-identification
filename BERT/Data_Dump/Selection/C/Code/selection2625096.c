#include<stdio.h>

void swap(int *x,int *y){
	int z;
	z = *x;
	*x = *y;
	*y =z;
}

void selectionSort(int A[], int N){
	int i,j;
	int minj;
	int count=0;
	for(i=0;i<N;i++){
		minj=i;
		for(j=i; j<N;j++){
			if(A[j]<A[minj]) minj = j;
		}
		if(i != minj){
			swap(&A[i],&A[minj]);
			count++;
		}
	}
	for(j=0; j<N-1; j++){
		printf("%d ",A[j]);
	}
	printf("%d\n",A[j]);
	printf("%d\n",count);
}

int main(void)
{
	int N;
	scanf("%d",&N);
	int Num[N];
	int i;
	for(i=0;i<N;i++) scanf("%d",&Num[i]);
	selectionSort(Num,N);
	return 0;
}
