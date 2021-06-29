#include <stdio.h>

void Trace(int n, int *a)
{
    for(int i=0; i<n; i++)
    {
        if(i!=n-1)
            printf("%d ", a[i]);
        else
            printf("%d\n", a[i]);
    }
}

void InsertSort(int n, int *a)
{
    int i, j, v;
    for(i=1; i<n; i++)
    {
        v = a[i];
        j = i-1;
        while(a[j]>v && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        Trace(n, a);
    }
}

int main(void)
{
    int i, n;
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    Trace(n, a);
    InsertSort(n, a);
    return 0;
}
