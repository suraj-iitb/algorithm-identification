#include <stdio.h>

int cnt = 0;

void selectionSort( int *A, int N )
{
    int minj;
    int tmp;
    
    for ( int i = 0; i < N; i++ ) {
        minj = i;
        for ( int j = i + 1; j < N; j++ ) {
            if ( A[j] < A[minj] ) {
                minj = j;
            }
        }
        if ( i != minj ) {
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            cnt++;
        }
    }
}


int main(void)
{
    int N;
    int A[100] = {0};
    
    scanf("%d", &N);
    
    for ( int i = 0; i < N; i++ ) {
        scanf("%d", &A[i]);
    }
    
    selectionSort( A, N );
    
    for ( int i = 0; i < N; i++ ) {
        printf("%d", A[i]);
        if ( i != N - 1 ) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
