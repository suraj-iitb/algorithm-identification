#include <stdio.h>
#include <stdlib.h>

void printArray(int array[100], int n);
int bubbleSort(int array[100], int n);

int main() {
    int n;
    scanf("%i", &n);

    int arr[100];

    int i;
    for(i = 0; i < n; i++)
        scanf("%i", &arr[i]);

    int swaps = bubbleSort(arr, n);

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

int bubbleSort(int array[100], int n) {
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i + 1; j--) {
            if (array[j] < array[j - 1]) {
                swaps++;
                swap(&array[j], &array[j - 1]);
            }
        }
    } 

    return swaps; 
}
