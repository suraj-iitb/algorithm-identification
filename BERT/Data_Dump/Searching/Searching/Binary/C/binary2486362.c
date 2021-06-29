#include <stdio.h>
 
int A[1000000], n;
 
int binarySearch(int key)
{
    int left = 0, right = n, mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (key == A[mid])return mid;
        else if (key < A[mid])right = mid;
        else left = mid + 1;
    }

    return 0;
}
 
int main()
{
    int i,q,k,result;
 
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);

    for (i = 0; i < q; i++)
    {
        scanf("%d", &k);
        if (binarySearch(k))result++;
    }

    printf("%d\n",result);
    
    return 0;
}
