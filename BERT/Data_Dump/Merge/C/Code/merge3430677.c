#include <stdio.h>
int S[500000];
int L[250002], R[250002];
int cnt = 0;
#define  SENTINEL 2147483647 
void merge(int *A, int left, int mid, int right)
{
	int n1, n2;
	int i, j, k;
	n1 = mid - left;
	n2 = right - mid;
	for (i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	L[i] = SENTINEL;
	for (i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	R[i] = SENTINEL;
	for (i = 0,j = 0, k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}

}

void mergeSort(int *A, int left, int right)
{
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main()
{
	int i, n;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}
	mergeSort(S, 0, n);
	for (i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", S[i]);
	}
	printf("\n%d\n", cnt);
}
