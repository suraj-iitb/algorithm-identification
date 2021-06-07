#include<stdlib.h>
#include<stdio.h>

int search(int a[], int n, int key)
{
    int i = 0;
    a[n] = key;
    while (a[i] != key)
    {
        i++;
    }
    return i != n;
}

int main()
{
    int a[10000 + 2], n, q, key, sum = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &key);
        if(search(a, n, key))
        {
            sum++;
        }
    }

    printf("%d\n", sum);
    
    return 0;
}
