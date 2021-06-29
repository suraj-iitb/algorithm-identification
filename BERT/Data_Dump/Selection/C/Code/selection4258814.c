#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int selectionSort(int* list, int size);

int main() {
	int n, * a;
	scanf("%d", &n);
	a = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	int count = selectionSort(a, n);

	for (int i = 0; i < n; i++)
		printf("%d%c", *(a + i), i < n - 1 ? ' ' : '\n');
	printf("%d\n", count);

	return 0;
}

int selectionSort(int* list, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		int min = INT_MAX, index = i, temp = 0;
		for (int j = i; j < size; j++) {
			if (list[j] < min) {
				min = list[j];
				index = j;
			}
		}
		if (index != i) {
			temp = list[i];
			list[i] = list[index];
			list[index] = temp;
			count++;
		}
	}
	return count;
}
