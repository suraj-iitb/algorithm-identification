#include <stdio.h>

void bubbleSort(int A[], const int N)
{
    int i;
    int flag = 1, cnt = 0;

    while( flag ){
        flag = 0;

        for( i = N-1; 0 < i; --i )
            if( A[i] < A[i-1] ){
                int tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;

                flag = 1;
                ++cnt;
            }
    }

    for( i = 0; i < N; ++i ){
        if( 0 < i ) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", cnt);
}

int main()
{
    int i;

    int N;
    scanf("%d", &N);
    int A[N];
    for( i = 0; i < N; ++i )
        scanf("%d", &A[i]);

    bubbleSort(A, N);

    return 0;
}
