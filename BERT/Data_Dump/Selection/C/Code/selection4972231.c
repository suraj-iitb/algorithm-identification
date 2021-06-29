#include <stdio.h>

int selection_sort(int a[], int n)
{
    int min ;
    int swap = 0;
    int cache;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            cache = a[i];
            a[i] = a[min];
            a[min] = cache;
            swap++;
        }
    }
    return swap;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int a[105];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int swap = selection_sort(a, n);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    printf("%d\n", swap);
    return 0;
}
