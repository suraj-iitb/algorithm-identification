
#include <stdio.h>
#include <stdlib.h>

#define SENTINEL 1000000001

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", array[i]);
    };
}

void merge(int array[], int left, int mid, int right, int * p_compareCount) {
    int nL = mid - left;
    int nR = right - mid;
    
    int Left[nL + 1], Right[nR + 1];
    int i, j, k;
    
    for (i = 0; i < nL; i++)  Left[i] = array[left + i];
    for (j = 0; j < nR; j++) Right[j] = array[mid  + j];
    
    Left[nL] = Right[nR] = SENTINEL;
    
    for (i = 0, j = 0, k = left; k < right; k++) {
        
        (*p_compareCount)++;
        
        if (Left[i] < Right[j]) 
            array[k] = Left[i++];
        else 
            array[k] = Right[j++];
    }
}

void mergeSort(int array[], int left, int right, int *p_compareCount) {
    if (left + 1 < right) {
        int mid = (left + right)/2;
        mergeSort(array, left, mid, p_compareCount);
        mergeSort(array, mid, right, p_compareCount);
        merge(array, left, mid, right, p_compareCount);
    }
}

int main(int argc, char** argv) {
    int nArray, i;
    scanf("%d", &nArray);
    
    int array[nArray];
    
    for (i = 0; i < nArray; i++) {
        scanf("%d", &array[i]);
    };
    
//    printf("Scanned: ");printArray(array, nArray);printf("\n");
    
    int compareCount = 0;
    
    mergeSort(array, 0, nArray, &compareCount);
    
//    printf("Sorted: ");
    printArray(array, nArray);printf("\n");
    printf("%d\n", compareCount);

    return (EXIT_SUCCESS);
}

