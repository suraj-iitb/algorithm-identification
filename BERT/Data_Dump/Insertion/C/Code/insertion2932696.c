#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
            printf(" ");
        }
    printf("\n");
    for (i = 1; i <= n - 1; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        int s;
        for (s = 0; s < n; s++)
        {
            printf("%d", a[s]);
            if (s < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
