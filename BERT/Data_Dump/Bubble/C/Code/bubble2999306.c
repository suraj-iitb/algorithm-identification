#include <stdio.h>

int BubbleSort ( int* Arr, int Max_order );

int main ( void ) {
    int Max_order = 0;
    int Arr[100] = {};
    int i = 0;
    int count_for_swap = 0;
    
    
    scanf( "%d", &Max_order );
    for ( i = 0; i < Max_order; i++ ) {
        scanf ( "%d ", &Arr[i] );
    }
    
    count_for_swap = BubbleSort ( Arr, Max_order );
    
    for ( i = 0; i < Max_order - 1; i++ ) {
        printf( "%d ", Arr[i] );
    }
    printf( "%d\n", Arr[i] );
    printf( "%d\n", count_for_swap );
    return 0;
}

int BubbleSort ( int* Arr, int Max_order )
{
    int count_for_swap = 0;
    int tmp = 0;
    int i = 0;
    int j = 0;
    
    for ( i = 0; i < Max_order; i++ ) {
        for ( j = Max_order - 1; j > i; j-- ) {
            if ( Arr[j] < Arr[j-1] ) {
                tmp = Arr[j];
                Arr[j] = Arr[j-1];
                Arr[j-1] = tmp;
                count_for_swap++;
            }
        }
    }
    
    return count_for_swap;
}

