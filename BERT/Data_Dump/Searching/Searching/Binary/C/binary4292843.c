#include<stdlib.h>
#include<stdio.h>

int a[100000], n;
int binarysearch(int a[], int key)
{
    int left = 0;
    int right = n;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == key)
        {
            return 1;
        } else if(a[mid] < key)
        {
            left = mid + 1;
        } else if (a[mid] > key)
        {
            right = mid;
        }
        
    }
    
    return 0;
}

int main()
{
    int q, key, sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &key);
        if(binarysearch(a, key) == 1)
        {
            sum++;
        }
    }
    
    printf("%d\n", sum);

    return 0;
}
