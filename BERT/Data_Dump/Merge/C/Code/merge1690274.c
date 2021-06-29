#include <stdio.h>

#define INFTY 1000000001
#define MAX 500000

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int cnt=0;

int main(void)
{
	int i, n, S[MAX];
	
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&S[i]);
	}
	
	mergeSort(S, 0, n);
	for(i=0; i<n-1; i++) {
		printf("%d ",S[i]);
	}
	printf("%d\n",S[n-1]);
	printf("%d\n",cnt);
	
	return 0;
}

void merge(int *A, int left, int mid, int right)
{
	int i, j, n1, n2, k;
	int L[MAX/2 +2], R[MAX/2 +2];
	
	n1 = mid - left;
	n2 = right - mid;
	for (i=0; i<n1; i++) {
		L[i] = A[left + i];
	}
	for (i=0; i<n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1] = INFTY;
	R[n2] = INFTY;
	
	i = 0;
	j = 0;
	for (k=left; k<right; k++) {
		if( L[i] <= R[j] ) {
			A[k] = L[i];
			i++;
			cnt++;
		} else {
			A[k] = R[j];
			j++;
			cnt++;
		}
	}
}

void mergeSort(int *A, int left, int right)
{
	int mid;
	if( left + 1 < right ) {
		mid = ( left + right ) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}
