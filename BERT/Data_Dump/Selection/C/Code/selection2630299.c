#include <stdio.h>
int n;
int count=0;

void Process(int A[ ], int n){
	int i;
	for(i=0;i<n-1;i++)
		printf("%d ",A[i]);
	printf("%d\n",A[i]);
}


void SelectionSort(int A[ ], int n){
	int i,j,temp,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(A[j] < A[min]){
				min = j;
			}
		}
		if(A[i]!=A[min]){
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
		count++;
	}
	}
}


int main(void){
	int i;
	scanf("%d",&n);
	int A[100];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	
	SelectionSort(A, n);
	Process(A, n);

	printf("%d\n",count);
	
	return 0;
}
