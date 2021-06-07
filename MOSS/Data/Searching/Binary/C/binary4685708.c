#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, temp, answer, first_array_size, second_array_size;
	scanf("%d", &first_array_size);

	int* first_array = (int*)malloc(sizeof(int) * first_array_size);
	for (i = 0; i != first_array_size; i++) {
		scanf("%d", &first_array[i]);
	}

	answer = 0;
	scanf("%d", &second_array_size);

	int minimum, maximum, middle;
	while (second_array_size--) {
		scanf("%d", &temp);

		minimum = 0;
		maximum = first_array_size - 1;

		while (minimum <= maximum) {
			middle = (minimum + maximum) / 2;

			if (first_array[middle] == temp) {
				answer++;
				break;
			}

			else if (first_array[middle] > temp) {
				maximum = middle - 1;
			}

			else if (first_array[middle] < temp) {
				minimum = middle + 1;
			}
		}
	}

	printf("%d\n", answer);

	free(first_array);
}

