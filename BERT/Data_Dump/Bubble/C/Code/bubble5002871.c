#include <stdio.h>

int main()
{
    int n, temp, a[105];
    int swap;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap++;
            }
        }
    }for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
        printf("%d", a[i]);
        }
        else
        printf(" %d", a[i]);

    }
    printf("\n");
    printf("%d\n", swap);
}
