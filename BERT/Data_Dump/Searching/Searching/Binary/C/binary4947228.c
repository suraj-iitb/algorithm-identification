#include <stdio.h>
#include <stdlib.h>

#define MAX_n 100000
#define MAX_q 50000
int n = MAX_n;
int q = MAX_q;

int binarySearch(int key, int *A);

int main(void)
{
    int count = 0;
    scanf("%d", &n);
    int S[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    int T[q];
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &T[i]);
    }
    for (int i = 0; i < q; i++)
    {
        count += binarySearch(T[i], S);
    }
    printf("%d\n", count);
    return 0;
}

int binarySearch(int key, int *A)
{
    int left = 0;
    int right = n;
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (A[mid] == key)
        {
            return 1;
        }
        else if (key < A[mid])
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
