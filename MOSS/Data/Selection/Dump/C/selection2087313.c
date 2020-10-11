#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	int *A = NULL;
	int i,j;
	int temp;
	int minj;
	int count = 0;

	scanf("%d",&n);
	A = (int *)malloc(4*n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<n;i++){
		minj = i;
		for(j=i;j<n;j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(i != minj){
			temp = A[minj];
			A[minj] = A[i];
			A[i] = temp;
			count++;
		}
		
	}
	for(i=0;i<n-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[n-1]);
	printf("%d\n",count);
	free(A);
}
