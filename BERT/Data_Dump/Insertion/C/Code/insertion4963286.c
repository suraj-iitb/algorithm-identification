#include <stdio.h>
#define MAX_N 100

void print_array (int n, int a[])
{
    for (int i = 0; i < n-1; i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n", a[n-1]);
}

int main(void)
{
    int a[MAX_N];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        print_array(n, a);
        int cache = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > cache)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = cache;
    }
    print_array(n, a);
    return 0;
}
