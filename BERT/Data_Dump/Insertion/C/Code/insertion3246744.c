#include<stdio.h>

int main(void) {
    int array[512];
    int num;
    int value;
    int i;
    int j;

    scanf( "%d", &num );
    for ( i = 0 ; i < num ; i++ ) {
        scanf( "%d" , &array[ i ] );
    }

    for ( i = 1 ; i < num  ; i++ ){
        for ( j = 0 ; j < num ; j++ ) {
            printf( "%d", array[j]);
            if ( j < num - 1) {
                printf( " " );
            }
        }

        printf("\n");

        value = array[i];
        j = i - 1;
        for ( j = j ; j >= 0 && ( array[ j ] > value ) ; j-- ) {
            array[ j + 1 ] = array[ j ];

        }
        array[ j + 1 ] = value;
    }

    for ( j = 0 ; j < num ; j++ ) {
        printf("%d", array[ j ] );
        if ( j < num - 1) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}
