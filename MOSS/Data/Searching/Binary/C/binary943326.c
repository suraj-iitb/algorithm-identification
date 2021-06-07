#include <stdio.h>

#define N 100000

int cnt, n, q;
int s[N], t[N];

void binarySearch(int a) {
	int left, right, mid;

	right = n;
	left = 0;

	while (right >= left) {
		mid = (right + left) / 2;
		if (s[mid] == a) {
			cnt++;
			break;
		} else if (s[mid] > a) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
}

void scanData() {
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	scanf("%d", &q);

	for (i = 0; i < q; i++) {
		scanf("%d", &t[i]);
		binarySearch(t[i]);
	}
}

int main() {

	scanData();
	printf("%d\n", cnt);

	return 0;
}
