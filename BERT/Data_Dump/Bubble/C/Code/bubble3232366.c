#include <stdio.h>
#include <stdlib.h>

int getNumber();
int* creatArrayWithNumberOfElements(int number);
void bubbleSort(int* array, int number, int* count);
void swap(int* a, int* b);
void printArray(int* array, int number);

int main(void)
{
	int numberOfElements = getNumber();
	int *sequence = creatArrayWithNumberOfElements(numberOfElements);
	int count = 0;
	bubbleSort(sequence, numberOfElements, &count);
	printArray(sequence, numberOfElements);
	printf("%d\n", count);
}

int getNumber()
{
	int input;
	scanf("%d", &input);
	return input;
}

int* creatArrayWithNumberOfElements(int number)
{
	int i;
	int *array = (int*) malloc(number * sizeof(int));
	for (i = 0; i < number; i++)
		scanf("%d", array + i);
	return array;
}

void bubbleSort(int* array, int number, int* count)
{
	int i, j;
	for (i = 0; i < number - 1; i++)
	{
		for (j = number - 1; j > i; j--)
		{
			if (*(array + j) < *(array + j - 1))
			{
				swap(array + j, array + j - 1);
				(*count)++;
				// printf("count = %d\n", *count);
			}
		}
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int* array, int number)
{
	int i;
	for (i = 0; i < number - 1; i++)
	{
		printf("%d ", *(array + i));
	}
	printf("%d\n", *(array + i));
}
