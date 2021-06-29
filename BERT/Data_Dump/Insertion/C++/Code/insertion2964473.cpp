#include <stdio.h>

int main() {
	int n, key, j;

	scanf("%d", &n);

	int arr[n];

	for (int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d", arr[0]);
	for (int x=1; x<n; x++) {
		printf(" %d", arr[x]);
	}
	printf("\n");

	for (int i=1; i<=n-1;i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;

		printf("%d", arr[0]);
		for (int x=1; x<n; x++) {
			printf(" %d", arr[x]);
		}
		printf("\n");
	}
}

