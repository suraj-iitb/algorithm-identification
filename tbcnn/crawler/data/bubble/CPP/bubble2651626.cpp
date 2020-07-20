#include <cstdio>
#include <algorithm>

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

//Bubble Sort?????????

void bubble_sort( int A[], int N ){

    int flag, j, buffer, number;

    flag = 1;
    number = 0;

    while( flag == 1 ){

        flag = 0;

        for( j = N-1 ; j > 0 ; j-- ){

            if( A[j] < A[j-1] ){

                buffer = A[j];

                A[j] = A[j-1];
            
                A[j-1] = buffer;

                flag = 1;

                number++;

            }

        }

    } 

    write( A, N );
    printf("%d\n", number );

}

int main(){

    int n;

    scanf("%d", &n );

    int A[n];

    for( int i = 0; i < n ; i++ ){

        scanf( "%d" , &A[i]  );

    }

    bubble_sort( A, n);

}
