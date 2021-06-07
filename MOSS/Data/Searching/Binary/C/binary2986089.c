#include<stdio.h>
int S[100000];
int ct = 0;
int main() {
	int T[50000];
	int n, q,i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}

	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &T[i]);
	}
	for (i = 0; i < q; i++) {
		binarySearch(T[i],n);
	}
	printf("%d\n", ct);

	return 0;
}

int binarySearch(key, n) {
	int left,right,mid;
	
	left = 0;
	right = n;
	while (left < right) {
		mid = (left + right) / 2;
		if (key == S[mid]) {
			ct++;
			return mid;
		}
		if (key > S[mid]) {
			left = mid + 1;
		}
		else if (key < S[mid]) {
			right = mid;
		}
	}
	return NULL;
}
