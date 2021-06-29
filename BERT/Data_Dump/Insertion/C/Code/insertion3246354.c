#include <stdio.h>

//挿入ソート
void insertionSort(int A[], const int N)
{
    int i, j;

    for( i = 0; i < N; ++i ){
        int tmp = A[i];
        for( j = i-1; -1 < j && tmp < A[j]; --j ){
            A[j+1] = A[j];
        }
        A[j+1] = tmp;

        //出力
        for( j = 0; j < N; ++j ){
            printf("%d", A[j]);
            if( j != N-1 ) printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    int i;

    //入力
    int N;
    scanf("%d", &N);
    int A[N];
    for( i = 0; i < N; ++i )
        scanf("%d", &A[i]);

    insertionSort(A, N);

    return 0;
}

