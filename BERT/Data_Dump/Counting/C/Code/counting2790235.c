
#include <stdio.h>
#include <stdlib.h>
#define MAXVAL  10000

int main(){

    long i, n;
    int *a, *b, c[MAXVAL];

    for( i=0; i<MAXVAL; i++ ) c[i] = 0;

    scanf( "%ld", &n );

    
    a = (int*)malloc(sizeof(int)*n);
    b = (int*)malloc(sizeof(int)*n);

    for( i=0; i<n; i++ ){
        scanf( "%d", &a[i] );
    }


    for( i=0; i<n; i++ ) c[ a[i] ]++;
    for( i=1; i<MAXVAL; i++ ) c[i] = c[i]+c[i-1];

    for( i=n-1; i>=0; i-- ){
        b[ c[a[i]]-1 ] = a[i];
        c[ a[i] ] = c[ a[i] ] - 1;
        //printf( " %ld: %d\n", i , a[i]);
        //for( j=0; j<40; j++ ) printf( "%d%c", c[j], ((40-1)>j)?' ':'\n');
    }

    for( i=0; i<n; i++ ) printf( "%d%c", b[i], ((n-1)>i)?' ':'\n');

    free(b);
    return 0;
}

