#include <stdio.h>

#define DEF_ELEM_MAX 100001

int S[DEF_ELEM_MAX];
int N;
int ans = 0;

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
int binarySearch(int *A, int n, int key)
{
	int mid;
	int left = 0;
	int right = n;

	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] == key) {
			return mid;
		} else if (key < A[mid]) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}
/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	int i;
	int Q;
	int key;

//
	scanf("%d", &N);
	for ( i = 0 ; i < N ; i++ ) {
		scanf("%d", &S[i]);
	}

	scanf("%d", &Q);
	ans = 0;
	for ( i = 0 ; i < Q ; i++ ) {
		scanf("%d", &key);
		if (binarySearch(S, N, key) >= 0) {
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
