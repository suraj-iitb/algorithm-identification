#include<stdio.h>
#define SIZE 100

int main(void)
{
    int i, j, k, tmp, N, A[SIZE];
    
    scanf("%d", &N);
    for ( i=0; i<N; ++i)
        scanf("%d", &A[i]);
    
    for ( i=0; i<N; ++i) {
        tmp = A[i];
        
        for ( j=0; j<i; ++j)
            if ( tmp < A[j])
                break;
        /* j 番に挿入 */
        for ( k=i; k>j; --k)
            A[k] = A[k-1];
        A[j] = tmp;
        
        /* 書き出し */
        for ( j=0; j<N; ++j) {
            printf("%d", A[j]);
            if ( j == N-1)
                putchar('\n');
            else
                putchar(' ');
        }
    }
    return 0;
}
