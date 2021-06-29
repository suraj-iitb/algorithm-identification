#include <stdio.h>
#include <stdbool.h>

int A[100010];

bool binarySearch(int A[], int n, int t) {
	int left = 0, right = n;
	while (right != left) {
		int mid = (right + left) / 2;
		if (A[mid] == t) {
			return true;
		}
		else if (A[mid] > t) {
			right = mid;
		}
		else if (A[mid] < t) {
			left = mid + 1;
		}
	}
	return false;
}


int main() {
	int n, q, t, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &A[i]);

	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d", &t);
		sum += binarySearch(A, n, t);
	}

	printf("%d\n", sum);
}

