
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int marge ( long *A, long l, long m, long r){

    int c=0;

    long n1, n2;
    long *L, *R;
    long i, j, k;


    n1 = m - l; n2 = r - m;
    
    L = (long*)malloc(sizeof(long)*(n1+1));
    R = (long*)malloc(sizeof(long)*(n2+1));

    for( i=0L; i<n1; i++ ) L[i] = A[l+i];
    for( i=0L; i<n2; i++ ) R[i] = A[m+i];

    L[n1] = LONG_MAX;
    R[n2] = LONG_MAX;


    i=0L; j=0L;
    for( k=l; k<r; k++ ){
        if( L[i] <= R[j] ){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        c++;
    }

    free( L );
    free( R );

    return c;
}


int margeSort( long *A, long l, long r ){

    long m; // mid
    int c=0;


    if( l+1L < r ){
        m = ( l + r ) /2L;

        c += margeSort( A, l, m );
        c += margeSort( A, m, r );
        c += marge( A, l, m, r );
    }

    return c;
}




int main(){

    long n;
    long *S;
    long i;
    int c;
    
    scanf( "%ld", &n );

    S = (long*)malloc(sizeof(long)*n);

    for( i=0; i<n; i++ ){
        scanf( "%ld", &S[i] );
    }
    
    c = margeSort( S, 0L, n );

    for( i=0L; i<n; i++ ){
        printf( "%ld%c", S[i], ((i+1)<n)?' ':'\n' );
    }
    printf( "%d\n", c);

    free(S);
    return 0;
}

