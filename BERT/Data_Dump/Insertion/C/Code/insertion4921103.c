#include<stdio.h>

int main(void)
{
    int i, j, k, t;
    int n;
    scanf("%d", &n);
    int a[n];
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        printf("%d", a[i]);
        if (i == n - 1)
            printf("\n");
        else
            printf(" ");
    }

    i = 1;
    while (i < n)
    {
        j = i - 1;
        while (j >= 0)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
            j--;
        }
        for (k=0; k<n; k++)
        {
            printf("%d", a[k]);
            if (k != n - 1)
                printf(" ");
            else
                printf("\n");
        }
        i++;
    }

    return (0);
}
