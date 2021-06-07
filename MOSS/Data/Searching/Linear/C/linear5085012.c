#include <stdio.h>

int SearcH(int A[], int n, int ky)
{

    int i = 0;
    A[n] = ky;
    while (A[i] != ky)
    {
        i++;
    }

    return i != n;
}

int main()
{

    int i, n, A[10000], q, ky, sum = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%d", &ky);
        if (SearcH(A, n, ky))
            sum++;
    }
    printf("%d\n", sum);

    return 0;
}

