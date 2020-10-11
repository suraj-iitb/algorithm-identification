#include <stdio.h>  
#include <stdlib.h>
 

void counting_sort(int A[], int k, int n)
{
    int i, j;
    int B[3000000], C[3000000];
    for (i = 0; i <= k; i++)
        C[i] = 0;
    for (j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for (j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    for (i = 1; i <= n; i++)
    if(i==n)printf("%d\n", B[i]);
    else printf("%d ",B[i]);
}

int main()
{
    int n, k = 0;
    int A[3000000];
    int i;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
        if (A[i] > k) {
            k = A[i];
        }
    }
    counting_sort(A, k, n);

    return 0;
}
