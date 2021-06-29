
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1

int linearSearch(int array[], int length, int key) {
    for (int i = 0; i < length; i++)
        if (array[i] == key)
            return i;
    
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
        if (linearSearch(S, nS, T[iT]) != NOT_FOUND) 
            nIntersect++;
    
    printf("%d\n", nIntersect);

    return (EXIT_SUCCESS);
}


