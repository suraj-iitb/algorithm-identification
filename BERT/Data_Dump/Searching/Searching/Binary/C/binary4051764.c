#include <stdio.h>
int binarySearch(int key);
int A[10000000], n;

int main() {
	int i, m, key, result = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	
	scanf("%d", &m);
	for(i = 0; i < m; i ++) {
		scanf("%d", &key);
		if (binarySearch(key)) result ++;
	}
	printf("%d\n", result);
	
	return 0;
}

int binarySearch(int key) {
	int left = 0, right = n;
	int mid;
	while(left < right) {
		mid = (left + right) / 2;
		if (A[mid] == key) return 1;
		else if (key < A[mid]) right = mid;
		else left = mid +1;
	}
	return 0;
}
