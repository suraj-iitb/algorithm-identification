#include <stdio.h>
#define N 1000000000
#define M 500000

int cnt = 0, s[M];

void merge(int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left, n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];

    for (i = 0; i < n1; i++)
        L[i] = s[left + i];
    for (i = 0; i < n2; i++)
        R[i] = s[mid + i];
    L[n1] = R[n2] = N;
    i = j = 0;
    for (k = left; k < right; k++)
    {
        cnt++;
        if(L[i] <= R[j])
            s[k] = L[i++];
        else
            s[k] = R[j++];
    }
}

void mergesort(int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergesort(left, mid);
        mergesort(mid, right);
        merge(left, mid, right);
    }
}

int main()
{
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);
    mergesort(0, n);
    for (i = 0; i < n - 1; i++)
        printf("%d ", s[i]);
    printf("%d\n", s[i]);
    printf("%d\n", cnt);
    return 0;
}

