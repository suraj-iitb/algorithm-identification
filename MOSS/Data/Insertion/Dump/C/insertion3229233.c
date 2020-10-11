#include <stdio.h>
#include <stdlib.h>

int getNumbersOfElements();
int* creatArrayThroughNumbersOfElemets(int numbersOfElements);
void printArrayElements(int* array, int numbersOfElements);
void insertionSortArrayElemets(int* array, int numbersOfElements);


int main(void)
{
	int N = getNumbersOfElements();
	int *array = creatArrayThroughNumbersOfElemets(N);
	printArrayElements(array, N);
	insertionSortArrayElemets(array, N);
	return 0;
}

int getNumbersOfElements()
{
	int input;
	scanf("%d", &input);
	return input;
}

int* creatArrayThroughNumbersOfElemets(int numbersOfElements)
{
	int *p = (int*) malloc(numbersOfElements * sizeof(int));
	int i;
	for (i = 0; i < numbersOfElements; i++)
		scanf("%d", p + i);
	return p;
}

void printArrayElements(int* array, int numbersOfElements)
{
	int i;
	for (i = 0; i < numbersOfElements - 1; i++)
		printf("%d ", *(array + i));
	printf("%d\n", *(array + i));
}

void insertionSortArrayElemets(int* array, int numbersOfElements)
{
	int i, j, key;
	for (j = 1; j < numbersOfElements; j++)
	{
		key = *(array + j);
		for (i = j - 1; i >= 0 && *(array + i) > key; i--)
		{
			// printf("%d > %d\n", *(array + i), *(array + j) );
			*(array + i + 1) = *(array + i);
		}
		*(array + i + 1) = key;
		printArrayElements(array, numbersOfElements);
	}
}
