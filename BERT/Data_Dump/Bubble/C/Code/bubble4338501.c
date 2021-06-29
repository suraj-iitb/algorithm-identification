#include <stdio.h>
#include <stdlib.h>

#define SWAP(type, a, b) do { type t = a; a = b; b = t; } while(0)

int cnt = 0;

void bubbleSort(int *array, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(array[j] > array[j + 1]) {
                SWAP(int, array[j], array[j + 1]);
                cnt++;
            }
        }
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

    bubbleSort(array, n);

    printArray(array, n);

    printf("%d\n", cnt);

    return 0;
}
