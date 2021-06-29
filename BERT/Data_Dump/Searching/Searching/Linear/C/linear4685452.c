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
	while (second_array_size--) {
		scanf("%d", &temp);
		for (i = 0; i != first_array_size; i++) {
			if (first_array[i] == temp) {
				answer++;
				break;
			}
		}
	}

	printf("%d\n", answer);
		
	free(first_array);
}
