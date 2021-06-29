#include<stdio.h>
void insertionSort(int A[],int N)
{
	int i,j,v=0;
	for (i=0;i<N; i++){
		printf("%d",A[i]);
		if(i<=N-2){
			    printf(" ");
			}
		}
	    printf("\n");
	for(i=1;i<=N-1;i++){
		v = A[i];
     	j = i - 1;
		while (j >= 0&&A[j] > v){
			A[j+1] = A[j];
      		j--;
		}
			A[j+1]=v;
		for (j = 0; j<N; j++) {
			printf("%d", A[j]);
			if(j<=N-2){
			    printf(" ");
			}
		}
			if(i<=N-1){
		    printf("\n");
			}
	}
}

int main (void) {
	int x;
  int i;
	scanf("%d",&x);

	int array[x];
	
	for (i=0;i<x; i++){
		scanf("%d",&array[i]);
	}

  	insertionSort(array, x);

  return 0;
}
