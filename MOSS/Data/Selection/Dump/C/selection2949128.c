
#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int length) {
    for (int ixArray = 0; ixArray < length; ixArray++) {
        if (ixArray != 0) printf(" ");
        printf("%d", array[ixArray]);
    }
}

int selectionSort(int array[], int length) {
    int swapCount = 0;
    int temp, minIndex, i, j;

    for (i = 0; i < length; i++) {
    	minIndex = i;
            
    	for (j = i + 1; j < length; j++)
            if (array[j] < array[minIndex])
    		    minIndex = j;

        if (array[i] != array[minIndex]) swapCount++;
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;

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

    int nos = selectionSort(array, nxArray);
    
    printArray(array, nxArray);
    printf("\n");
    printf("%d\n", nos);
 

    return (EXIT_SUCCESS);
}




