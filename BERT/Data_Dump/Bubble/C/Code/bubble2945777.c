
#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int length) {
    for (int ixArray = 0; ixArray < length; ixArray++) {
        if (ixArray != 0) printf(" ");
        printf("%d", array[ixArray]);
    }
}

int bubbleSort(int array[], int length) {
    int swapCount = 0;
    int temp;
    
    for (int i = 0; i < length; i++)
        for (int j = length - 1; j > i; j--)
            if (array[j] < array[j-1]) {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                swapCount++;
            }
    
    return swapCount;
}

int main(int argc, char** argv) {
    int length;
    scanf("%d", &length);
    
    const int nxArray = length;
    int array[nxArray];
    for (int ixArray = 0; ixArray < nxArray; ixArray++)
        scanf("%d", &array[ixArray]);

//    for (int ixArray = 0; ixArray < nxArray; ixArray++) {
//        if (ixArray != 0) printf(" ");
//        printf("%d", array[ixArray]);
//    }
    
    int nos = bubbleSort(array, nxArray);
    
    printArray(array, nxArray);
    printf("\n");
    printf("%d\n", nos);
    
    

    return (EXIT_SUCCESS);
}


