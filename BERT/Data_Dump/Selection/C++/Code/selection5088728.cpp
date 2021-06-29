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

void SelectSort(int n, int *a)
{
    int i, j, v, temp;
    int count = 0;
    for(i=0; i<n-1; i++)
    {
        v = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]<a[v])
                v = j;
        }
        if(v!=i)
        {
            temp = a[i];
            a[i] = a[v];
            a[v] = temp;
            count++;
        }
    }
    Trace(n, a);
    printf("%d\n", count);
}

int main(void)
{
    int i, n;
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    SelectSort(n, a);
    return 0;
}
