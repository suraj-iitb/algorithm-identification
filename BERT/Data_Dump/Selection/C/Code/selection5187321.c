#include <stdio.h>
#include <stdlib.h>

void printArray(int array[100], int n);
int selectionSort(int array[100], int n);

int main() {
    int n;
    scanf("%i", &n);

    int arr[100];

    int i;
    for(i = 0; i < n; i++)
        scanf("%i", &arr[i]);

    int swaps = selectionSort(arr, n);

    printArray(arr, n);
    printf("\n");
    printf("%i\n", swaps);

}

void printArray(int arr[100], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[n - 1]); 
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t; 
}

int selectionSort(int array[100], int n) {
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        int min = i; 
        for (int j = i; j < n; j++) {
            if (array[j] < array[min]) 
                min = j; 
        }
        if (min != i) {
            swaps++; 
            swap(&array[i], &array[min]);
        }
    } 

    return swaps; 
}
