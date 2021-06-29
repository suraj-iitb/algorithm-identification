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
void t8s_swap(int* l, int* r)
{
	int o = *l;
	*l = *r;
	*r = o;
}


int sort(int* arr, int count)
{
	int sw = 0;

	for (int i=0;i<count;i++)
	{
		int minimum = i;
		for (int j=i+1;j<count;j++)
		{
			if (arr[j] < arr[minimum])
				minimum = j;
		}

		if (arr[minimum] < arr[i]) {
			t8s_swap(&arr[minimum], &arr[i]);
			sw++;
		}
	}

	return sw;
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

	int swapCount = sort(arr, count);
	log(arr, count);
	printf("%d\n", swapCount);
	free(arr);

	return 0;
}
