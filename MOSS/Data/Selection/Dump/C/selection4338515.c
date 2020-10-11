#include <stdio.h>
#include <stdlib.h>

#define SWAP(type, a, b) do { type t = a; a = b; b = t; } while(0)

int cnt = 0;

void selectionSort(int *array, int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(array[j] < array[minIdx]) {
                minIdx = j;
            }
        }
        if(i != minIdx) {
            SWAP(int, array[i], array[minIdx]);
            cnt++;
        } // AOJ
    }
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
    int n;

    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));
    if(array == NULL) {
        return 1;
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    selectionSort(array, n);

    printArray(array, n);

    printf("%d\n", cnt);

    return 0;
}
