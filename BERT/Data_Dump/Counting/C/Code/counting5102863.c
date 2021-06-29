#include <stdio.h>
#include <stdlib.h>

#define MA 2000000
#define MAA 10000

int main()
{

    unsigned short *R, *D;
    int L[MAA + 1];
    int n, i, j;

    scanf("%d", &n);

    R = malloc(sizeof(short) * n + 1);
    D = malloc(sizeof(short) * n + 1);

    for (i = 0; i <= MAA; i++)
    {
        L[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%hu", &R[i + 1]);
        L[R[i + 1]]++;
    }

    for (i = 1; i <= MAA; i++)
    {
        L[i] = L[i] + L[i - 1];
    }

    for (j = 1; j <= n; j++)
    {
        D[L[R[j]]] = R[j];
        L[R[j]]--;
    }

    for (i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            printf(" ");
        }
        printf("%d", D[i]);
    }

    printf("\n");

    return 0;
}
