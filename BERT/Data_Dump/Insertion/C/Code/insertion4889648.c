#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int k, tmp;

    for (int i = 0; i < n; i++)
    {
        k = i;
        while (a[k] < a[k - 1] && k > 0)
        {
            tmp = a[k];
            a[k] = a[k - 1];
            a[k - 1] = tmp;
            k--;
        }

        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                printf("%d", a[j]);
            }
            else
            {
                printf("%d ", a[j]);
            }
        }

        printf("\n");
    }

    return 0;
}
