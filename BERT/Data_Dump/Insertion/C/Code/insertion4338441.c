#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool initArray(int **array, int n);
void insertionSort(int *array, int n);
void printArray(int *array, int n);

bool initArray(int **array, int n) {
    if((*array = malloc(n * sizeof(int))) == NULL) {
        return false;
    }

    return true;
}

void insertionSort(int *array, int n) {
    for(int i = 1; i < n; i++) {
        printArray(array, n);
        int temp = array[i];
        int j = i - 1;
        for(; j >= 0 && array[j] > temp; j--) {
            array[j + 1] = array[j];
        }
        array[j + 1] = temp;
    }
    
    printArray(array, n);
}

void printArray(int *array, int n) {
    for(int i = 0; i < n;) {
        printf("%d", array[i]);
        i++;
        if(i < n) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void) {
    int *array;
    int n;

    scanf("%d", &n);
    
    initArray(&array, n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    insertionSort(array, n);

    free(array);
    return 0;
}
