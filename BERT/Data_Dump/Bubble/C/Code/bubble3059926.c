/* 
 * File:   main.c
 * Author: s1252007
 *
 * Created on June 19, 2018, 10:55 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int bubbleSort(
    int a[],
    int n
);

int main(int argc, char** argv) {
    int size, counter;
    int *A;
    
    scanf("%d", &size);
    A = (int *)malloc(sizeof(int) * size);
    for (int ix = 0; ix < size; ++ix) scanf("%d", &A[ix]);
    counter = bubbleSort(A, size);
    for (int ix = 0; ix < size; ++ix)
    {
        if (ix > 0) printf(" ");
        printf("%d", A[ix]);
    }
    printf("\n");
    printf("%d\n", counter);
    return (EXIT_SUCCESS);
}

int bubbleSort( int a[], int n )
{
    int counter = 0;
    for( int i = 1; i < n; ++i )
	{
            for( int j = n-1; j >= i; --j )
            {
                if( a[j] < a[j-1] )
                {
                    int copy;
                    copy = a[j];
                    a[j] = a[j-1];
                    a[j-1] = copy;
                    counter++;
                }
            }
	}
    return counter;
}


