#include <stdio.h>

#include <stdlib.h>


int main() {
	int i, j, k, count = 0;

	int array_num = 0;
	scanf("%d", &array_num);

	//dynamic scan
	int* array;
	array = (int*)malloc(array_num * sizeof(int));
	for (i = 0; i != array_num; i++) {
		scanf("%d", &array[i]);
	}

	for (i = 0; i < array_num - 1; i++) {
		for (j = 0; j != array_num - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				k = array[j];
				array[j] = array[j + 1];
				array[j + 1] = k;
				count++;
			}
		}
	}

	for (i = 0; i < array_num; i++) {
		if (i == array_num - 1)printf("%d\n", array[i]);
		else printf("%d ", array[i]);
	}
	printf("%d\n", count);
}

