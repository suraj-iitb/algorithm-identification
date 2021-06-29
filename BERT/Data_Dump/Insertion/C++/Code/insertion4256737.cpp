#include <stdio.h>
#include <stdlib.h>

int t8s_force_scan_int()
{
	int n;

	if (scanf("%d", &n) == EOF)
	{
		printf("expected int input but got EOF");
		exit(-1);
	}

	return n;
}

int t8s_force_read_int_array(size_t count, int** arr)
{
	*arr = (int*) malloc(count * sizeof(int));

	if (arr == NULL)
		return -1;

	for (int i=0; i<count;i++)
	{
		int n;
		scanf("%d ", &n);
		*(*arr+i) = n;
	}

	return 0;
}

void log(int* arr, int count)
{
	for (int i=0; i<count;i++)
	{
		printf("%d", arr[i]);
		if (i < count-1 )
			printf(" ");
	}
	printf("\n");
}

int main()
{
	size_t count = t8s_force_scan_int();

	int* arr;

	if (t8s_force_read_int_array(count, &arr) < 0)
		exit(-1);

	log(arr, count);
	for (int i=1; i<count;i++)
	{
		int v = arr[i];
		int j = i - 1;
		while (j>=0 && arr[j] > v)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = v;
		log(arr, count);
	}

	free(arr);

	return 0;
}
