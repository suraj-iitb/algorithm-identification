#include <stdio.h>
int bsort(int n, int a[])
{
    int cnt = 0; //交換回数

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (a[j - 1] > a[j])
            {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                cnt++;
            }
        }
    }
    return cnt;
}
int main(void)
{
    int n;
    int a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int cnt = bsort(n, a);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n%d\n", a[n - 1], cnt);

    return 0;
}
