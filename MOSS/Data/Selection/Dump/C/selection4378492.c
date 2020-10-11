#include <stdio.h>

void swap(int *, int *);

int selectionSort(int [], int);

void printArray(int [], int);

int main()
{
    int n, i, count, arr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    count = selectionSort(arr, n);
    printArray(arr, n);
    printf("%d\n", count);
    return 0;
}

void swap(int *ap, int *bp)
{
    int tmp;
    tmp = *ap;
    *ap = *bp;
    *bp = tmp;
}

int selectionSort(int arr[], int n)
{
    int i, j, min, count = 0;
    for (i = 0; i < n; i++) {
	min = i;
        for (j = i + 1; j < n; j++) {
	    if (arr[j] < arr[min]) {
		min = j;
	    }
	}
	swap(&(arr[i]), &(arr[min]));
	if (i != min)
	    count++;
    }
    return count;
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

