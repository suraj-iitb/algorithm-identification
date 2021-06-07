/*
 * Problem Description: Linear Search
 * Category:
 * Author: Khan
 * Date: 13th October, 2017
 */

#include <stdio.h>

int binary_search(int A[], int n, int key)
{
    int left = 0;
    int right = n;
    int mid;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(A[mid] == key)
            return 1;
        if(key > A[mid])
            left = mid + 1;
        else if(key < A[mid])
            right = mid;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    //freopen("sample.txt", "r", stdin);
    int i, n, A[1000000], q, key, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &key);
        if(binary_search(A, n, key))
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}
