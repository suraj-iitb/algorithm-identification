#include <stdio.h>

void swap(int *, int *);

int bubbleSort(int [], int);

void printArray(int [], int);

int main()
{
    int n, i, count, arr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    count = bubbleSort(arr, n);
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

int bubbleSort(int arr[], int n)
{
    int i, j, count = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
	    if (arr[j + 1] < arr[j]) {
		swap(&(arr[j]), &arr[j + 1]);
                count++;
	    }
	}
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

