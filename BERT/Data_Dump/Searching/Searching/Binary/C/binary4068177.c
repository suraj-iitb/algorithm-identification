#include <stdio.h>

int binarySearch(int n, int A[], int key)
{
	int mid;
	int left = 0;
	int  right = n;
	
	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] == key)
			return 1;
		else if (key < A[mid])
			right = mid;
		else if (key > A[mid])
			left = mid + 1;
	}
	return 0;
}


int main()
{
	int N,Q, S[100000], T[50000], i;
	int  cnt = 0;
	
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &S[i]);
	scanf("%d", &Q);
	for (i = 0; i < Q; i++)
		scanf("%d", &T[i]);
	for (i = 0; i < Q; i++) {
		if (binarySearch(N, S, T[i]) != 0)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}


