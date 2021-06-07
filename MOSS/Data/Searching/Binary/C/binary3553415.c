#include<stdio.h>

int binarysearch(int A[], int n, int key) {
	int left = 0;
	int right = n;
	int mid;

	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] == key) {
			return A[mid] == key;
		}
		else if (A[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return 0;

}

int main() {
	//数値の読み込み
	int i, n;
	int A[100000];
	int q, key, sum = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &key);
		if (binarysearch(A, n, key)) {
			sum++;
		}
	}
	printf("%d\n", sum);

	return 0;
}
