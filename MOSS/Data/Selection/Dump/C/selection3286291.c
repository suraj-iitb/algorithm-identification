#include <stdio.h>

#define N 100 

typedef struct {
    int array[N];
} Array;

int selection( Array *, int );

int main() {
    int i = 0,
        num = 0,
        inp = 0,
        ret = 0;

    Array a;

    scanf( "%d", &num );
    for( i=0; i < num; i++ ) {
        scanf( "%d", &a.array[i] );
    }
    ret = selection( &a, num );

    for( i=0; i < num; i++ ) {
        if( i )
            printf(" ");
        printf( "%d", a.array[i] );
    }
    printf( "\n");
    printf( "%d\n", ret );

    return 0;
}

int selection( Array *p, int n ) {
    int i,j = 0,
        count = 0,
        store = 0,
        minj = 0;

    for( i=0; i <= n-1; i++ ) {
        minj = i;
        for( j=i; j <= n-1; j++ ) {
            if( p->array[j] < p->array[minj] ) {
                minj = j;
            }
        }

        if(p->array[i] > p->array[minj]) ++count;

        store = p->array[i];
        p->array[i] = p->array[minj];
        p->array[minj] = store;

    }
    return (count);
}

