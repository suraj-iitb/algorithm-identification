#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define sentinel INT_MAX

int count = 0;

//straight up from the notes

void merge(int* array, int start, int end, int middle) {
	int n1 = middle - start;
	int n2 = end - middle;
	//make 2 arrays Left and Right
	int* Left;
	int* Right;

	Left = (int*)malloc((n1+1) * sizeof(int));
	Right = (int*)malloc((n2 + 1) * sizeof(int));

	for (int i = 0; i < n1; i++) {
		Left[i] = array[start + i];
	}

	for (int i = 0; i < n2; i++) {
		Right[i] = array[middle + i];
	}

	Left[n1] = sentinel;
	Right[n2] = sentinel;

	int i = 0, j = 0;
	for (int k = start; k < end; k++) {
		count++;
		if (Left[i] <= Right[j]) {
			array[k] = Left[i++];
		}
		else {
			array[k] = Right[j++];
		}
	}

}

void merge_sort(int* array, int start, int end) {
	if (start + 1 < end) {
		int middle = (start + end) / 2;
		merge_sort(array, start, middle);
		merge_sort(array, middle, end);
		merge(array, start, end, middle);
	}
}

int main() {
	int i, array_size = 0;
	scanf("%d", &array_size);

	//dynamic scan
	int* array;
	array = (int*)malloc(array_size * sizeof(int));
	for (i = 0; i != array_size; i++) {
		scanf("%d", &array[i]);
	}

	merge_sort(array, 0, array_size);

	for (int i = 0; i < array_size - 1; i++) {
		printf("%d ", array[i]);
	}
	printf("%d\n%d\n", array[array_size - 1],count);
	return 0;
}

