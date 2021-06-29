
#include <stdio.h>
#include <stdlib.h>

// 1-origin to 0-origin
int o1(int i) {
    return i-1;
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", array[i]);
    };
}

void countingSort(int Array[], int Brrby[], int length, int upperBound) {
    int Crrcy[upperBound+1];
    int i, j;
    
//    printf("Array:   ");printArray(Array, length);printf(", upperBound: %d\n", upperBound);
    
    for (i = 0; i <= upperBound; i++)
        Crrcy[i] = 0;
    
    for (j = 1; j <= length; j++)
        Crrcy[Array[o1(j)]]++;
    
//    printf("Counted: ");printArray(Crrcy, upperBound+1);printf("\n");
    
    for (i = 1; i <= upperBound; i++)
        Crrcy[i] = Crrcy[i] + Crrcy[i-1];
    
//    printf("Indexed: ");printArray(Crrcy, upperBound+1);printf("\n");
    
    for (j = length; j >= 1; j--) {
        Brrby[o1(Crrcy[Array[o1(j)]])] = Array[o1(j)];
        Crrcy[Array[o1(j)]]--;
    }
    
//    printf("Sorted:  ");printArray(Brrby, length);printf("\n");
}

int main(int argc, char** argv) {
    int nArray, max_num = 0;
    scanf("%d", &nArray);
    
    int array[nArray], brrby[nArray];
    
    for (int iArray = 0; iArray < nArray; iArray++) {
        scanf("%d", &array[iArray]);
        
        if (array[iArray] > max_num)
            max_num = array[iArray];
    }
    
    countingSort(array, brrby, nArray, max_num);
    
    printArray(brrby, nArray);printf("\n");

    return (EXIT_SUCCESS);
}


