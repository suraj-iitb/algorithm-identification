#include <stdio.h>

int main(void) {
	int S[100000], T[50000], n, q, i, count;
	count = 0;

	scanf("%d",&n);
	for (i = 0;i < n;i++)
		scanf("%d", &S[i]);

	scanf("%d",&q);
	for (i = 0;i < q;i++) {
		scanf("%d", &T[i]);
		if (binarySearch(S, T[i], n) == 1) {
			count++;
		}
	}

	printf("%d\n", count);
	return 0;

}

int binarySearch(int s[], int key, int n) {
	int left = 0;
	int right = n;
	int mid;
	s[n] = key;

	while (left < right) {
		mid = (left + right) / 2;
		if (s[mid] == key)
			return 1;
		else if (key < s[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return 0;
}
