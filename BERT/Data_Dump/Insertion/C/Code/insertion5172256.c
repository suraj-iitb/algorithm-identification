#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num, key, j; //Initializing
	scanf("%i", &num); //To read number of numbers in the array
	int A[num]; //Initializing an array
	for (int i = 0; i < num; i++)
	{
		scanf("%i",&A[i]);
	} //To read num number of values

	for (int i = 0; i < num; i++)
	{
		if (i > 0)
		{
			key = A[i];
			j = i - 1;
			while (j >= 0 && A[j] > key)
			{
				A[j + 1] = A[j];
				j = j - 1;
			}
			A[j + 1] = key;
		} //Sorting algorithm from the pseudocode given (insertion sort)

		for (int i = 0; i < num; i++)
		{
			if (i == num - 1)
			{
				printf("%i",A[i]);
			}
			else
			{
				printf("%i ",A[i]);
			} //Printing at each stage
		}
		printf("\n"); //Next line provider!
	}
}
