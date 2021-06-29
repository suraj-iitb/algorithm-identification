#include<stdio.h>

void swap (int *x, int *y) {
	int temp;  
 	temp = *x;
	*x = *y;
	*y = temp;
}

int bubble_sort (int A[], int n, int c) {
	int i,j = 0;
	for (i = 0; i < n - 1; i++){
    	for (j = n - 1; j >= i + 1; j--){ 
			if (A[j] < A[j-1]){
				swap(&A[j], &A[j-1]);
      			c++;
      		}
    	}
	}
	return c;
}

int main (void) {
	int n ,i ,c = 0;
	scanf("%d",&n);
	int A[n];
	for(i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}
	c = bubble_sort(A, n, c);
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
