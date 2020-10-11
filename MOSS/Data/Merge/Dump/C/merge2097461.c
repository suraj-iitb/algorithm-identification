#include<stdio.h>
#include<limits.h>

int compTimes = 0;

void merge(int A[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1+1], R[n2+1];
	int i, j, k;
	for( i = 0; i < n1; i++ ){ L[i] = A[left+i]; }
	for( i = 0; i < n2; i++ ){ R[i] = A[mid+i]; }
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	i = 0;
	j = 0;
	for( k = left; k < right; k++ ){
		compTimes++;
		if( L[i] <= R[j] ){
			A[k] = L[i++];
		}else{
			A[k] = R[j++];
		}
	}
	return;
}

void mergeSort(int A[], int left, int right){
	if( left+1 <  right ){
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
	return;
}

int main(){
	int n, S[500000], i;
	scanf("%d", &n);
	for( i = 0; i < n; i++ ){ scanf("%d", &S[i]); }
	mergeSort(S, 0, n);
	printf("%d", S[0]);
	for( i = 1; i < n; i++ ){ printf(" %d", S[i]); }
	printf("\n");
	printf("%d\n", compTimes);
	return 0;
}
