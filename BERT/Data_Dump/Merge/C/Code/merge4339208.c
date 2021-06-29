#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int *leftArray;
int *rightArray;

int cnt;

void merge(int *array, int left, int center, int right) {
    int pl, pr, pa;

    for(pa = left, pl = 0; pa <= center; pa++, pl++) {
        leftArray[pl] = array[pa];
    }

    for(pa = center + 1, pr = 0; pa <= right; pa++, pr++) {
        rightArray[pr] = array[pa];
    }

    int lLen = pl;
    int rLen = pr;
    for(pl = 0, pr = 0, pa = left; pl < lLen && pr < rLen; pa++) {
        array[pa] = (leftArray[pl] < rightArray[pr]) ? leftArray[pl++] : rightArray[pr++];
        cnt++;
    }

    while(pl < lLen) {
        array[pa++] = leftArray[pl++];
        cnt++;
    }

    while(pr < rLen) {
        array[pa++] = rightArray[pr++];
        cnt++;
    }
}

void _mergeSort(int *array, int left, int right) {
    if(left < right) {
        int center = (left + right) / 2;

        _mergeSort(array, left, center);
        _mergeSort(array, center + 1, right);

        merge(array, left, center, right);
    }
}   

bool mergeSort(int *array, int n) {
    if((leftArray = malloc(n * sizeof(int))) == NULL) {
        return false;
    }
    if((rightArray = malloc(n * sizeof(int))) == NULL) {
        free(leftArray);
        return false;
    }

    _mergeSort(array, 0, n - 1);

    free(leftArray);
    free(rightArray);
    return true;
}

bool initArray(int **array, int n) {
    if((*array = malloc(n * sizeof(int))) == NULL) {
        return false;
    }

    return true;
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

    mergeSort(array, n);

    printArray(array, n);

    printf("%d\n", cnt);

    free(array);
    return 0;
}
