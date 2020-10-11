#include<stdio.h>

int bubblesort(int A[], int N){
	int flag = 1;
	int i,count = 0,j,x;
	for(i = 0; flag; i++){
		flag = 0;
		for(j =  N - 1; j >= i + 1; j--){
			if(A[j] < A[j - 1]){
				x = A[j];
				A[j] = A[j - 1];
				A[j - 1] = x;
				flag = 1;
				count++;
			}
		}
	}
	return count;
}

int main(void){
	int A[100];
	int N,count = 0,i,j;
	
	scanf("%d",&N);
	for(i = 0;i < N;i++){
		scanf("%d",&A[i]);
	}
	count = bubblesort(A,N);
	
	for(i = 0; i < N; i++){
		if(i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n",count);
	
	return 0;

}
