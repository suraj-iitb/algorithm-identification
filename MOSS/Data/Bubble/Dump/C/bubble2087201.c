#include <stdio.h>
#include <stdlib.h>

int main(){
	int j;
	int n;
	int *A = NULL;
	int flag;
	int temp;
	int count = 0;

	scanf("%d",&n);
	A = (int *)malloc(4*n);
	for(j=0;j<n;j++){
		scanf("%d",&A[j]);
	}

	flag = 1;
	while(flag){
		flag = 0;
		for(j=n-1;j>0;j--){
			if(A[j]<A[j-1]){
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				flag = 1;
				count++;
			}
		}
	}
	for(j=0;j<n-1;j++){
		printf("%d ", A[j]);
	}
	printf("%d\n",A[n-1]);
	printf("%d\n",count);
	free(A);
}
