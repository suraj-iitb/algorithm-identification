#include <stdio.h>

#include <stdlib.h>

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int main() {
	int i, j, mini,flag, count = 0;

	int array_num = 0;
	scanf("%d", &array_num);

	//dynamic scan
	int* array;
	array = (int*)malloc(array_num * sizeof(int));
	for (i = 0; i != array_num; i++) {
		scanf("%d", &array[i]);
	}

	//selection sort
	for (i = 0; i < array_num - 1; i++) {
		flag = 0;
		mini = i;
		for (j = i+1; j < array_num; j++) {
			if (array[j] < array[mini]) {
				mini = j;
				flag = 1;
			}
		}
		if (flag == 1) {
			count++;
			swap(&array[mini], &array[i]);
		}
	}

	for (i = 0; i < array_num; i++) {
		if (i == array_num - 1)printf("%d\n", array[i]);
		else printf("%d ", array[i]);
	}
	printf("%d\n", count);
	free(array);
}

