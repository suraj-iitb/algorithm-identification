#include <stdio.h>

void Process(int A[ ], int n){
	int i;
	for(i=0;i<n-1;i++)
		printf("%d ",A[i]);
	printf("%d\n",A[i]);
}

void InsertionSort(int A[ ], int n){
	int i,j,v;
	for(i=1;i<n;i++){
		v = A[i];
		j = i - 1;
		while(j>=0 && A[j]>v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		Process(A, n);

	}
}



int main(void){
	int i,N;
	scanf("%d",&N);
	int A[100];
	for(i=0;i<N;i++)
		scanf("%d",&A[i]);
	Process(A, N);
	InsertionSort(A, N);
	
	
	return 0;


}
