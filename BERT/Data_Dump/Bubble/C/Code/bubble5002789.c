#include <stdio.h>
int n, a[105], sps = 0, temp;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                sps++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d", a[i]);
        }
        else
            printf("%d ", a[i]);
    }
    printf("\n");
    printf("%d\n", sps);
}

