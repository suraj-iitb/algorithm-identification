/* 
 * File:   main.c
 * Author: s1252007
 *
 * Created on June 19, 2018, 11:37 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int main(int argc, char** argv) {
    int size, counter= 0;
    int *A;
    
    scanf("%d", &size);
    A = (int *)malloc(sizeof(int) * size);
    for (int ix = 0; ix < size; ++ix) scanf("%d", &A[ix]);
    for ( int c = 0 ; c < ( size - 1 ) ; c++ )
    {
        int position, swap, d;
        position = c;

        for ( d = c + 1 ; d < size ; d++ )
        {
           if ( A[position] > A[d] )
              position = d;
        }
        if ( position != c )
        {
           swap = A[c];
           A[c] = A[position];
           A[position] = swap;
           counter++;
        }
    }
    for (int ix = 0; ix < size; ++ix)
    {
        if (ix > 0) printf(" ");
        printf("%d", A[ix]);
    }
    printf("\n");
    printf("%d\n", counter);
    return (EXIT_SUCCESS);
}



