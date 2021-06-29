#include <stdio.h>
int main(void){
    // Your code here!
    int N,i,j,tmp;
    scanf( "%d" , &N );
    int a[N];
    int cnt = 0;
    
    for( i = 0 ; i < N ; i++ ){
        scanf( "%d" , &a[i] );
    }
    
    for( i = 0 ; i < N ; i++ ){
        for( j = N - 1 ; i < j ; j-- ){
            if( a[j] < a[j-1] ){
                tmp    = a[j];
                a[j]   = a[j-1];
                a[j-1] = tmp;
                cnt++;
            }
        }
    }

    printf( "%d" , a[0] );
    for( i = 1 ; i < N ; i++ ){
            printf( " %d" , a[i] );
    }
    printf( "\n" );
    
    printf( "%d\n" , cnt );
    
}

