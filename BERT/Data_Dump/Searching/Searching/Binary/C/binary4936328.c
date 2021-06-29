#include <stdio.h>

int n;

int binarySearch(int A[], int key)
{
    int left, right, mid;
    left = 0;
    right = n;
    
    while (left < right)
    {
        mid = (left + right) / 2;
        if(A[mid] == key)
        {
            return mid;
        }
        else if(key < A[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}

int main(void)
{
    int A[100000], key;
    int q;
    int i;
    int count=0;
    
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &A[i]);
        //printf("%d ", A[i]);
    }
    
    scanf("%d", &q);
    for(i=0; i<q; i++)
    {
        scanf("%d", &key);
        if(binarySearch(A, key))
        {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}

