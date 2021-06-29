#include <stdio.h>
static const int N = 100;

int Selection_Sort(int a[], int n)
{
    int sw = 0;
    for (int i = 0; i < n; i++)
    {
        int minv = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[minv])
                minv = j;
        }
        if (minv != i)
        {
            int tmp = a[i];
            a[i] = a[minv];
            a[minv] = tmp;
            sw ++;
        }

    }
    return sw;
}
int main()
{
    int n;
    int a[N];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int sw = Selection_Sort(a, n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n%d\n", sw);

    return 0;
}

