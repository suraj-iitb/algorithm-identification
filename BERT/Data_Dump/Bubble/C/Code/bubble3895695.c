#include <stdio.h>
void bubbleSort(int A[],int N);
int main(void){
	int N;
	scanf("%d",&N);
	int A[N];
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	bubbleSort(A,N);
	
	return 0;
}

void bubbleSort(int A[],int N){
	int count=0,tmp,j;
	int sum;
	for(int i=0;i<N*N;i++){
		for(j=N-1;j>=1;j--){
				if(A[j]<A[j-1]){
					tmp=A[j];
					A[j]=A[j-1];
					A[j-1]=tmp;
					count++;
				}
			}
	}
	for(j=0;j<N;j++){
		if(j>0)printf(" ");
		printf("%d",A[j]);
	}
	printf("\n");
	printf("%d\n",count);
}
