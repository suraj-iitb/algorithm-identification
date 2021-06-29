#include<stdio.h>

void showArray(int A[],int N){
	int i;
	for(i=0;i<N-1;i++)
		printf("%d ",A[i]);
	printf("%d\n",A[N-1]);
}

void selectionSort(int A[],int N){
	int i,j,minj;
	int count=0;
	for(i=0;i<N;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		int temp=A[i];
		A[i]=A[minj];
		A[minj]=temp;
		if(i!=minj)count++;
	}
	
	showArray(A,N);
	printf("%d\n",count);
}



int main(void){
		int n;
		int array[101];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);

		selectionSort(array,n);
		
			
		return 0;
}
