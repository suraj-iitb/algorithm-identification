#include <stdio.h>

#define N 100 

typedef struct {
    int array[N];
} Array;

int bubble( Array *, int );

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
    ret = bubble( &a, num );

    for( i=0; i < num; i++ ) {
        if( i )
            printf(" ");
        printf( "%d", a.array[i] );
    }
    printf( "\n");
    printf( "%d\n", ret );

    return 0;
}

int bubble( Array *p, int n ) {
    int j = 0,
        flag = 1,
        count = 0,
        store = 0;

    while( flag ) {
        flag = 0;
        for( j=n-1; j >= 1; j-- ) {
            if( p->array[j] < p->array[j-1] ) {
                count += 1;
                store = p->array[j];
                p->array[j] = p->array[j-1];
                p->array[j-1] = store;

                flag = 1;
            }
        }
    }

    return count;
}
