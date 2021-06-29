#include <stdio.h>
#define N 100

int BubbleSort(int a[], int n)
{
    int swap_times = 0;
    for (int i = 0; i < n-1; i ++)
    {
        for (int j = n-1; j >= i+1; j--)
        {
            if (a[j] < a[j-1])
            {
                int t = a[j];
                a[j] =  a[j-1];
                a[j-1] = t;
                swap_times++;
            }
        }
    }
    return swap_times;
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
    int t = BubbleSort(a, n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n%d\n", t);

    return 0;
}

