#include <stdio.h>

void insertSort(int*, int);

int main()
{
	int arr[1001];
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 0, temp = 0;
	
	scanf(" %d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf(" %d", &temp);
		arr[i] = temp;
	}

	insertSort(arr, num);

	return 0;
}

void insertSort(int arr[], int _size)
{
	int i, j, key,k;

	for (i = 0; i<_size; i++) {
		key = arr[i];
		for (j = i-1; j >= 0; j--) {
			arr[j + 1] = arr[j];
			if (arr[j] < key) break;
		}

		arr[j + 1] = key;

		for (k = 0; k < _size; k++)
		{
			if(k == 0) printf("%d", arr[k]);
			else printf(" %d", arr[k]);

			if (k == _size - 1) printf("\n");
		}
	}


}
