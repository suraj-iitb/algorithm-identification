#include <stdio.h>

int main(){
    int N, array[100];
    scanf("%d\n",&N);
    for ( int ix = 0 ; ix < N ; ix++)
        scanf("%d ",&array[ix]);
    int counter = 0;
    for ( int ix = 0 ; ix < N ; ix++ ){
        int ixmin = ix;
        for ( int jx = ix ; jx < N ; jx++)
            if ( array[jx] < array[ixmin] ) ixmin = jx;
        if ( ixmin != ix ){
            int temp = array[ixmin];
            array[ixmin] = array[ix];
            array[ix] = temp;
            counter++;
        }
    }
    
    for ( int ix = 0; ix < N; ix++){
        if ( ix != N-1 ) printf("%d ",array[ix]);
        else printf("%d\n",array[ix]);
    }
    printf("%d\n",counter);
    return 0;
}
