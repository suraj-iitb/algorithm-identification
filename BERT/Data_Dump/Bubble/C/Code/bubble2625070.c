#include<stdio.h>

void swap(int *x,int *y){
	int z;
	z = *x;
	*x = *y;
	*y =z;
}

void bubbleSort(int A[], int N){
	int flag=1;
	int count=0;
	int j;
	while(flag==1){
		flag=0;
		for (j=N-1; j>0; j--){
			if(A[j] < A[j-1]){
				swap(&A[j], &A[j-1]);
				count++;
				flag = 1;
			}
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
	bubbleSort(Num,N);
	return 0;
}
