#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int merge(int *A, int left, int mid, int right){
	int i, j, k, c = 0, n1 = mid-left, n2 = right-mid;
	int L[n1+1], R[n2+1];

	for(i = 0; i < n1; i++)
		L[i] = A[left+i];
	L[n1] = INT_MAX;
	for(i = 0; i < n2; i++)
		R[i] = A[mid+i];
	R[n2] = INT_MAX;

	i = 0;
	j = 0;
	for(k = left; k < right; k++){
		c++;
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
	}
	return c;
}

int mergeSort(int *A, int left, int right){
	static int c = 0;
	int mid;

	if(left+1 < right){
		mid = (left + right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		c += merge(A, left, mid, right);
		return c;
	}
}

int main(){
	int n, i, c;
	int *A;

	scanf("%d", &n);
	A = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);

	c = mergeSort(A, 0, n);

	for(i = 0; i < n; i++){
		printf("%d", A[i]);
		if(i < n-1)
			printf(" ");
		else
			printf("\n");
	}
	printf("%d\n", c);

	free(A);
	return 0;
}
