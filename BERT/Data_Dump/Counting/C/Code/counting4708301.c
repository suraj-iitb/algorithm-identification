#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 2000001
#define MAX_NUMBER_SIZE 10002

void Counting_sort(int* array, int numbers) {
	int i, counting_array[MAX_NUMBER_SIZE];
	int* temp_array;
	temp_array = (int*)malloc(numbers * sizeof(int));

	//set all values in the counting array to 0
	for (i = 0; i != MAX_NUMBER_SIZE; i++) {
		counting_array[i] = 0;
	}

	//add the values from array to counting array and make temp array for reference
	for (i = 0; i != numbers; i++) {
		temp_array[i] = array[i];
		counting_array[array[i]]++;
	}

	//add from front to back
	for (i = 0; i != MAX_NUMBER_SIZE - 1; i++) {
		counting_array[i + 1] += counting_array[i];
	}

	//assign the ordered values
	for (i = 0; i != numbers; i++) {
		array[counting_array[temp_array[i]]] = temp_array[i];
		counting_array[temp_array[i]]--;
	}

}

int main() {
	int i, j, k, key;
	int array_num = 0;
	scanf("%d", &array_num);

	//dynamic scan
	int* array;
	array = (int*)malloc(array_num * sizeof(int));
	for (i = 0; i != array_num; i++) {
		scanf("%d", &array[i]);
	}

	Counting_sort(array, array_num);

	//printing
	for (i = 1; i < array_num; i++) {
		printf("%d ", array[i]);
	}
	printf("%d\n", array[array_num]);

	return 0;
}

