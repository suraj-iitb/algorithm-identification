/* 
 * File:   main.c
 * Author: s1252006
 *
 * Created on June 15, 2018, 11:19 AM
 */

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int length) {
    int key, i;
    for (int j = 1; j < length; j++) {
        key = array[j];
        i = j-1;
        while (i >= 0 && array[i] > key) {
            array[i+1] = array[i];
            i = i-1;
        }
        array[i+1] = key;
        
        
        printf("\n");
        for (int ixArray = 0; ixArray < length; ixArray++) {
            if (ixArray != 0) printf(" ");
            printf("%d", array[ixArray]);
        }
        
    }
}


int main(int argc, char** argv) {
    int length;
    scanf("%d", &length);
    
    const int nxArray = length;
    int array[nxArray];
    for (int ixArray = 0; ixArray < nxArray; ixArray++)
        scanf("%d", &array[ixArray]);

    for (int ixArray = 0; ixArray < nxArray; ixArray++) {
        if (ixArray != 0) printf(" ");
        printf("%d", array[ixArray]);
    }
    
    insertionSort(array, nxArray);
    printf("\n");
    
//    for (int ixArray = 0; ixArray < nxArray; ixArray++) {
//        printf("%d ", array[ixArray]);
//    }
    
    

    return (EXIT_SUCCESS);
}


