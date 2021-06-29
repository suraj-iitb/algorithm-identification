#include<stdio.h>

int n,A[1000],count;

void bubbleSort(){

	int temp;

	count = 0;

	for(int i = 0; i < n; i++){

		for(int j = n-1; j >= i+1; j--){
			if(A[j] < A[j-1]){
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;

				count = count + 1;
			}
		}
	}

	printf("%d",A[0]);
	for(int i = 1; i < n; i++){
		printf(" %d",A[i]);
	}
}


int main(){

	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}

	bubbleSort();
              printf("\n");

	printf("%d\n",count);

	return 0;
}
