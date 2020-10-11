#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INFTY (INT_MAX);
int S[500001];
int L[500001];
int R[500001];
	int N;
	int ans;
/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void merge(int *A, int left, int mid, int right)
{
	int i;
	int j;
	int k;
	int n1 = mid - left;
	int n2 = right - mid;

//  L[0...n1], R[0...n2] ?????????

	for ( i = 0 ; i < n1 ; i++ ) {
		L[i] = A[left + i];
	}

	for ( i = 0 ; i < n2 ; i++ ) {
		R[i] = A[mid + i];
	}

	L[n1] = INFTY;
	R[n2] = INFTY;
	i = 0;
	j = 0;
	for ( k = left ; k < right ; k++ ) {
		ans++;
		if ( L[i] <= R[j] ) {
			A[k] = L[i];
			i = i + 1;
		} else {
			A[k] = R[j];
			j = j + 1;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void mergeSort(int *A, int left, int right)
{
	int mid;
	if (left+1 < right) {
		mid = (left + right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}
/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	int i;
//
	scanf("%d", &N);
	for ( i = 0 ; i < N ; i++ ) {
		scanf("%d", &S[i] );
	}

	mergeSort(S, 0, N);

	for ( i = 0 ; i < N ; i++ ) {
		printf("%d", S[i]);
		if ( i < N-1 ) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	printf("%d\n", ans);

	return 0;
}
