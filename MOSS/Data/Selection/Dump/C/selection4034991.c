#include <stdio.h>

void selectionSort(int A[], int n);

int i, j, n, miji, count = 0;

int main()
{
	int A[100];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	
	selectionSort(A, n);
	printf("%d\n", count);
	
	return 0;
}

void selectionSort(int A[], int n){
	int save; 
	 for(i = 0; i <= n-1; i++){
		miji = i;
		for(j = i; j <= n-1; j++){
			if(A[j] < A[miji]) miji = j;
		}
		save = A[i];
		A[i] = A[miji];
		A[miji] = save;
		if(i != miji) count ++;
	}
	
	for(i = 0; i < n-1; i ++){
		printf("%d ", A[i]);
	}
	printf("%d\n",A[i]);
}
