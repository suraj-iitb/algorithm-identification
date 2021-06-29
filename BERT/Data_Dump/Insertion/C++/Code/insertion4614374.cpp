#include <stdio.h>
#define MAX_LEN 100

void printArray(int *array, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d", array[i]);
		if (i != len - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

int array[MAX_LEN];

int main()
{
	int len;
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &array[i]);
	}

	printArray(array, len);

	for (int i = 1; i < len; i++)
	{
		int v = array[i];
		int j = i;
		while ((j > 0) && (array[j - 1] > v))
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = v;
		printArray(array, len);
	}
}
