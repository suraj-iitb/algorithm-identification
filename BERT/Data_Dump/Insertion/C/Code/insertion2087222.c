#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* A, int n);

int main(void){
	int n,i;
	int* A;

	scanf("%d",&n);
	A = (int *)malloc(n * sizeof(int));  /* ?????¢?????????????¢???? */
 
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	printf("%d",A[0]);
	for(i=1;i<n;i++)  printf(" %d",A[i]);
	printf("\n");

	insertionSort(A,n);

	free(A);
	return 0;
}

void insertionSort(int* A, int n){
	int i,j, v;
	for(i=1;i<n;i++){
    	v = A[i];
    	j = i - 1;
     	while (j >= 0 && A[j] > v){
    	   	A[j+1] = A[j];
    	   	j--;
    		A[j+1] = v;
 		}
 		printf("%d",A[0]);
 		for(j=1;j<n;j++)  printf(" %d",A[j]);
 		printf("\n");
   	}
}
