#define NOT_FOUND -1
#include <stdio.h>

int binarySearch(int a[], int n, int key){
	int cnt = 0;
	int left = 0;
	int right = n;
	int mid;

	while (left < right) {
		mid = (left + right) / 2;
		if (a[mid] == key) {
			return mid;
		}
		else if (a[mid] > key) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return NOT_FOUND;
}

int main(void) {
	int n, q;
	int cnt = 0;
	int s[100000] = { 0 };
	int t[50000] = { 0 };
	int i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		if (i > 0) {
			if (s[i] < s[i - 1]) {
				printf("a");
				i--;
			}
		}
	}

	scanf("%d", &q);

	for (i = 0; i < q; i++) {
		scanf("%d", &t[i]);
		for (j = 0; j < i; j++) {
			if (t[i] == t[j]) {
				i--;
				break;
			}
		}
	}

	for (i = 0; i < q ;i++) {
		if (binarySearch(s, n, t[i]) >= 0) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}

