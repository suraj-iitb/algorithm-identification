#include <stdio.h>

int binarySearch(int, int *, int);

int main(void)
{
	int n, S[100000], q, T[50000], i, C = 0;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &S[i]);
	scanf("%d", &q);
	for (i = 0; i < q; i++)
		scanf("%d", &T[i]);
	for (i = 0; i < q; i++) {
		if (binarySearch(n, S, T[i]) != -1)
			C++;
	}
	printf("%d\n", C);
	return 0;
}

int binarySearch(int n, int *A, int key)
{
	int left = 0, mid, right = n;
	
	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] == key)
			return mid;
		else if (key < A[mid])
			right = mid;
		else if (key > A[mid])
			left = mid + 1;
	}
	return -1;
}
