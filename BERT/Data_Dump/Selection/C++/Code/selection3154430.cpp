#include<stdio.h>

int selectionSort(int A[],int N){
	int sw=0,i,j,minv,minj;
	for(i=0;i<N;i++){
		minv=A[i];
		minj=i;
		for(j=i+1;j<N;j++){
			if (A[j]<minv){
				minv=A[j];
				minj=j;
			}
		}
		if(minj!=i){
			sw++;
			int tmp=A[i];
			A[i]=A[minj];
			A[minj]=tmp;
		}
	}
	return sw;
}

int main(){
	int A[100],N,i;
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	int sw=selectionSort(A,N);
	printf("%d",A[0]);
	for(i=1;i<N;i++) printf(" %d",A[i]);
	printf("\n%d\n",sw);
	return 0;
}

