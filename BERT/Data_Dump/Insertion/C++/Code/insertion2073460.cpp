#include <stdio.h>

// ?????????????´???????????????????
void trace(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		// ??£??\????????????????????????????????????????????????
		if (i > 0) printf(" ");
		printf("%d", arr[i]);
	}
	printf("\n");
}

// ?????\?????????
void insertionSort(int arr[], int n) {
	int index, beforeIndex, target;
	for (index = 1; index < n; index++) {
		target = arr[index];
		beforeIndex = index - 1;
		while (beforeIndex >= 0 && arr[beforeIndex] > target) {
		    arr[beforeIndex + 1] = arr[beforeIndex];
		    beforeIndex--;
		}
		arr[beforeIndex + 1] = target;
		trace(arr, n);
	}
}

int main() {
	int n, i, j;
	int arr[100];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	trace(arr, n);
	insertionSort(arr, n);

	return 0;
}
