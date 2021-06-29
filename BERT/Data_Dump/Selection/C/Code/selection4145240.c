#include <stdio.h>
int main(void){
    // Your code here!
    int N,i,j,min,tmp;
    scanf( "%d" , &N );
    int cnt = 0;
    int a[N];
    
    for( i = 0 ; i < N ; i++ ){
        scanf( "%d" , &a[i] );
    }

    for( i = 0 ; i < N ; i++ ){
        min = i;
        for( j = i ; j < N ; j++ ){
            if( a[min] > a[j] ){
                min = j;
            }
        }
        if( a[i] != a[min] ){
            cnt++;
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }

    for( i = 0 ; i < N ; i++ ){
        if( i != 0 ){
            printf( " " );
        }
        printf( "%d" , a[i] );
    }
    
    printf("\n");
    printf( "%d\n" , cnt );
    
}

