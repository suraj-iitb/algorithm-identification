#include <stdio.h>

int A[100001], n;
int binary_search(int key)
{
	int left = 0;
	int right = n;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] == key)
			return 1;
		else if (A[mid] > key)
			right = mid;
		else
			left = mid + 1;
	}

	return 0;
}

int main()
{
	int i, n1, key;
	int sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &n1);
	for (i = 0; i < n1; i++) {
		scanf("%d", &key);
		sum += binary_search(key);
	}
	printf("%d\n", sum);
	return 0;
}

