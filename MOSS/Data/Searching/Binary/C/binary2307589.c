#include <stdio.h>

#define N 100000
#define Q 50000

int binarySearch(int *A, int key, int length) {
	int mid;
	int left = 0;
	int right = length;

	while (left < right) {
		mid = (left + right) / 2;

		if (key == A[mid]) return 1;
		if (key > A[mid]) left = mid + 1;
		else if (key < A[mid]) right = mid;
	}

	return 0;
}

int main() {
	int n,q,i;
	int num = 0;
	int s[N], t[Q];

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &s[i]);
	scanf("%d", &q);
	for (i = 0; i < q; i++) scanf("%d", &t[i]);

	for (i = 0; i < q; i++) num += binarySearch(s, t[i], n);

	printf("%d\n", num);

	return 0;
}
