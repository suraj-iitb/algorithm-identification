#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[1000];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int e, tmp, j;
    for (int k = 0; k < n; k++)
    {
        printf("%d", a[k]);
        if (k != n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
    for (i = 1; i < n; i++)
    {
        e = a[i];
        j = i - 1;
        while (j >= 0 && e < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = e;
        for (int k = 0; k < n; k++)
        {
            printf("%d", a[k]);
            if (k != n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
