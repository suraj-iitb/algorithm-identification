#include <stdio.h>

int main( void ) {
    int array[512];
    int temp;
    int num;
    int i;
    int j;
    int times;

    scanf( "%d" , &num );
    i = 0;
    while ( i < num ) {
        scanf("%d" , &array[i] );
        i++ ;
    }

    for ( i = 0 ; i < num - 1 ; i++ ) {
        for ( j = num -1 ; j > i ; j-- ) {
            if ( array[ j ] < array[ j - 1 ] ) {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                times++ ;
            }
        }
    }

    for ( i = 0 ; i < num ; i++) {
        if ( i == num -1) {
            printf("%d\n", array[i]);
        } else {
            printf("%d ", array[i] );
        }
    }

    printf("%d\n", times);

    return 0;
}
