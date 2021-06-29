#include <stdio.h>

void swap (int *x, int *y) {
	int temp;  
 	temp = *x;
	*x = *y;
	*y = temp;
}

int selectionSort(int A[], int n, int c){
	int i,j,minj;
	for(i = 0; i < n; i++){
		minj = i;
		for(j = i; j < n; j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(i != minj){
			c++;
		}
		swap(&A[i], &A[minj]);
	}
	return c;
}

int main(void){
	int i, n, c = 0;
	scanf("%d" ,&n);
	int A[n];
	for(i = 0; i < n; i++){
		scanf("%d" ,&A[i]);
	}
	c = selectionSort(A,n,c);
	for (i = 0; i < n; i++){
		if(i < n - 1){
			printf("%d ", A[i]);
		}
		else{
			printf("%d\n", A[i]);
		}
 	}
	printf("%d\n" ,c);
	
	return 0;
}
