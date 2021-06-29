#include <stdio.h>

int a[2000001];
int b[2000001];

void CountingSort(int *A, int *B, int k, int n)
{
    int C[10001];
    int i, j;
    
    for (i = 0; i <= k; i++){
        C[i] = 0;
    }

    /* C[i] に i の出現数を記録する */
    for (j = 1; j <= n; j++){
        C[A[j]]++;
    }
    /* C[i] に i 以下の数の出現数を記録する*/
    for (i = 1; i <= k; i++){
        C[i] = C[i] + C[i - 1];
    }
    for (j = n; j > 0; j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main(void)
{
    int n;
    int i;
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    
    CountingSort(a, b, 10000, n);

    for (i = 1; i <= n; i++){
        if (i != 1){
            printf(" ");
        }
        printf("%d", b[i]);
    }
    printf("\n");

    return (0);
}
