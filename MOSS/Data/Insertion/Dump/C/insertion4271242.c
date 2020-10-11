#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* list, int size, int* count);

int main() {
	int n, * a, count = 0;
	scanf("%d", &n);
	a = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	insertionSort(a, n, &count);

	return 0;
}

void insertionSort(int* list, int size, int* count) {
	for (int k = 0; k < size; k++)
		printf("%d%c", list[k], k != size - 1 ? ' ' : '\n');
	for (int i = 1; i < size; i++) {
		int key = list[i], j = i - 1;
		while (j > -1 && key < list[j])
			list[j + 1] = list[j--], * count += 1;
		list[j + 1] = key;
		for (int k = 0; k < size; k++)
			printf("%d%c", list[k], k != size - 1 ? ' ' : '\n');
	}
}
