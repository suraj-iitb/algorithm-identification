#include<stdio.h>

void insertionSort(int A[],int N){
	int i,j,k;
	for(k=0;k<N-1;k++)
		printf("%d ",A[k]);
	
	printf("%d\n",A[N-1]);
	
	for(i=1;i<N;i++){
		int v=A[i];
		j=i-1;			
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(k=0;k<N-1;k++)
			printf("%d ",A[k]);
		printf("%d\n",A[N-1]);
	}
			
}

int main(void){
		int n;
		int array[1001];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);

		insertionSort(array,n);
		
			
		return 0;
}
