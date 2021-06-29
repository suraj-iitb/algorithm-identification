#include <cstdio>
#include <utility>

using namespace std;

//???????????????????????¢??° write ?????????

void write( int A[], int N ){

    for( int i = 0 ; i < N ; i++ ){

        if( i > 0 ){

            printf(" ");
            
        }

        printf("%d", A[i] );

    }

    printf("\n");

}

//?????????????????? insertion_sort ??????????????????

void selection_sort( int A[], int N ){

    int i, j, minj, count;

    count = 0;

    for( i = 0 ; i < N ; i++ ){

        minj = i;

        for( j = i ; j < N ; j++ ){
        
            if( A[j] < A[minj] ){

                minj = j;

            }

        }
 
        if( i != minj ){

            count++;

        } 

        swap( A[i], A[minj] );

    }    

    write( A, N );
    printf("%d\n", count);

}

//??¬???

int main(){

    int i, n, count;

    scanf("%d", &n);
 
    int A[n];
 
    for( i = 0 ; i < n ; i++ ){
 
        scanf( "%d", &A[i] );
 
    }

    selection_sort( A, n );

    return 0;

}
