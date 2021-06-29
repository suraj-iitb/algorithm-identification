#include <stdio.h>
int binary_search(int a[], int n, int target)
{
    int left = 0;
    int right = n-1;
    while (left <= right)
    {
        if (target == a[(right + left) / 2])
        {
            return 1;
        }
        else if (target < a[(right + left) / 2])
        {
            right = (right + left) / 2 - 1;
        }
        else
        {
            left = (right + left) / 2 + 1;
        }
        
    }
    return 0;
}
int main(void)
{
    int a[100005];
    int b[50005];
    int n, q, cache;
    int C = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < q; i++)
    {
        C += binary_search(a, n, b[i]);
    }
    printf("%d\n", C);
    return 0;
    
    
}
