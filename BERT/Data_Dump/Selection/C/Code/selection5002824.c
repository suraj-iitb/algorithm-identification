#include <stdio.h>

int main()
{
    int n, a[100], cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min = a[i], p;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                p = j;
            }
        }
        if (min != a[i])
        {
            a[i] = a[i] + a[p];
            a[p] = a[i] - a[p];
            a[i] = a[i] - a[p];
            cnt++;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
    printf("%d\n", cnt);
}
