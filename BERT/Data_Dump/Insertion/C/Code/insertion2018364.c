#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void disp_array(int *array, int size)
{
		int i;

		for(i = 0; i < size - 1; i++)
				printf("%d ", array[i]);
		printf("%d", array[i]);
}

void sort(int *array, int size) 
{
		int i, j;

		for(i = 1; i < size; i++) {
				int target_value;
				target_value = array[i];
				j = i - 1;
				while(j >= 0 && array[j] > target_value) {
						array[j + 1] = array[j];
						j--;
				}
				array[j + 1] = target_value;
				disp_array(array, size);
				printf("\n");
		}

}

int main(void) {
		int *array, array_size = 0;
		int i;

		scanf("%d", &array_size);
		array = malloc(sizeof(int) * array_size);
		for(i = 0; i < array_size; i++)
				scanf("%d", &array[i]);
		disp_array(array, array_size);
		printf("\n");
		sort(array, array_size);

		return 0;
}
