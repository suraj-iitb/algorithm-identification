#include <stdio.h>

void insertionSort(int [], int);

void printArray(int *, int);

int main()
{
    int n, i, arr[100];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", arr + i);
    printArray(arr, n);
    insertionSort(arr, n);
    return 0;
}


void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) {
	key = arr[i];
	j = i - 1;
        while (0 <= j && key < arr[j]) {
	    arr[j + 1] = arr[j];
	    j--;
	};
	arr[j + 1] = key;
        printArray(arr, n);
    }	
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++){
	printf("%d", arr[i]);
	if (i < n - 1) {
	    printf(" ");
        } else {
            printf("\n");
	}
    }
}


