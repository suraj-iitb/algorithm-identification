#include <stdio.h>

void InsertionSort(int A[], int N);

int main(void){
	
	int n;
	scanf("%d",&n);
	
	int a[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	InsertionSort(a, n);
	
	return 0;

}

void InsertionSort(int A[], int N)
{

	int i,j,k,v;
	
	for(i=1;i<N;i++){
		
		for(k=0;k<N-1;k++){
			printf("%d ",A[k]);
		}
		printf("%d",A[k]);
		printf("\n");
		
		v = A[i];
		j = i-1;
		
		while (j >= 0 && A[j] > v){
		
			A[j+1] = A[j];
			j--;
		
		}
		
		A[j+1] = v;
	
	}
	
	for(k=0;k<N-1;k++){
		printf("%d ",A[k]);
	}
	printf("%d",A[k]);
	printf("\n");

}
