
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1

int binarySearch(int array[], int length, int key) {
    int left = 0;
    int right = length;
    int mid;
    
    while (left < right) {
        mid = (left + right)/2;
        
        if (key == array[mid])
            return mid;
        if (key > array[mid])
            left = mid +1;
        else
            right = mid;
    }
    
    return NOT_FOUND;
}

int main(int argc, char** argv) {
    int nNumbers;
    
    // set S
    scanf("%d", &nNumbers);
    
    const int nS = nNumbers;
    int S[nS];
    
    for (int iS = 0; iS < nS; iS++)
        scanf("%d", &S[iS]);
    
    // set T
    scanf("%d", &nNumbers);
    
    const int nT = nNumbers;
    int T[nT];
    
    for (int iT = 0; iT < nT; iT++)
        scanf("%d", &T[iT]);
    
    // do the magic
    int nIntersect = 0;
    for (int iT = 0; iT < nT; iT++)
        if (binarySearch(S, nS, T[iT]) != NOT_FOUND) 
            nIntersect++;
    
    printf("%d\n", nIntersect);

    return (EXIT_SUCCESS);
}


