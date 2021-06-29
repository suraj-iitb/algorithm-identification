#include <stdio.h>

int cnt = 0;

void bubbleSort( int *A, int N )
{
    int flag = 1;
    int tmp;
    int i = 0;

    while ( flag != 0 ) {
        flag = 0;
        for ( int j = N - 1; j >= i + 1; j-- ) {
            if ( A[j] < A[j - 1] ) {
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = 1;
                cnt++;
            }
        }
        i++;
    }
}

int main(void)
{
    int A[100] = {0};
    int N;
    
    scanf("%d", &N);
    
    for ( int i = 0; i < N; i++ ) {
        scanf("%d", &A[i]);
    }
    
    bubbleSort( A, N );
    
    for ( int i = 0; i < N; i++ ) {
        printf("%d", A[i]);
        if ( i == N - 1 ) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
