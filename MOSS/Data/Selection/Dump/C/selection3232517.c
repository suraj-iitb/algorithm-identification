#include <stdio.h>
#include <stdlib.h>

int getNumberOfElements();
int* creatArrayThroughNumberOfElements(int numberOfElements);
void selectionSort(int* array, int number, int* count);
void printArray(int* array, int number);
void swap(int* a, int* b);

int main(void)
{
	int numberOfElements = getNumberOfElements();
	int* sequence = creatArrayThroughNumberOfElements(numberOfElements);
	int count = 0;

	selectionSort(sequence, numberOfElements, &count);
	printArray(sequence, numberOfElements);
	printf("%d\n", count);
	return 0;
}

int getNumberOfElements()
{
	int input;
	scanf("%d", &input);
	return input;
}

int* creatArrayThroughNumberOfElements(int numberOfElements)
{
	int* array = (int*) malloc(numberOfElements * sizeof(int));
	int i;
	for (i = 0; i < numberOfElements; i++)
		scanf("%d", array + i);
	return array;
}

void selectionSort(int* array, int number, int* count)
{
	int now;
	int subOfMinInUnsearchedElements;
	int i, j;
	for (i = 0; i < number - 1; i++)
	{
		subOfMinInUnsearchedElements = i;
		for (j = i + 1; j < number; j++)
		{
			if (*(array + j) < *(array + subOfMinInUnsearchedElements))
			{
				subOfMinInUnsearchedElements = j;
			}
		}
		if (i != subOfMinInUnsearchedElements)
		{
			swap(array + i, array + subOfMinInUnsearchedElements);
			(*count)++;
		}
	}
}	

void printArray(int* array, int number)
{
	int i;
	for (i = 0; i < number - 1; i++)
		printf("%d ", *(array + i));
	printf("%d\n", *(array + i));
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
