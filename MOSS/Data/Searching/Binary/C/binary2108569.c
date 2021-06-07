#define NOT_FOUND 200000

#include <stdio.h>

int binarySearch(int n, int key, int *s);

int main(void) {
	int n = 0;
	int s[100000] = {};
	int q = 0;
	int t[50000] = {};
	int k = 0;				//?????´????????°.

	int i = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);

	scanf("%d", &q);
	for (i = 0; i < q; i++)
		scanf("%d", &t[i]);

	for (i = 0; i < q; i++) {
		if (binarySearch(n, t[i], s) != NOT_FOUND)
			k++;
	}

	printf("%d\n", k);

	return 0;
}

int binarySearch(int n, int key, int *s) {
	int left = 0;
	int right = n;
	int mid = 0;

	while (left < right) {
		mid = (left + right) / 2;
		if (s[mid] == key)
			return mid;
		else if (key < s[mid])
			right = mid;
		else
			left = mid + 1;
	}

	return NOT_FOUND;
}
