#include <stdio.h>
void print_insertionSort(int a[], int n)
{
    int i, j, v;

    for (i = 1; i < n; i++)
    {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for (int k = 0; k < n - 1; k++)
        {
            printf("%d ", a[k]);
        }
        printf("%d\n", a[n - 1]);
    }
}
int main(void)
{
    int n, k;
    int a[1000];
    scanf("%d", &n);
    for (k = 0; k < n; k++)
    {
        scanf("%d", &a[k]);
    }

    for (k = 0; k < n - 1; k++)
    {
        printf("%d ", a[k]);
    }
    printf("%d\n", a[n - 1]);

    print_insertionSort(a, n);

    return 0;
}

