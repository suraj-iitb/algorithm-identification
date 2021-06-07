#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int n, q;
    scanf("%d", &n);

    int S[n + 1];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);

    int j, ans = 0;

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &S[n]);

        j = 0;

        while (S[j] != S[n])
        {
            j++;
        }

        if (j != n)
        {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
