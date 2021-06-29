#include <iostream>
#include <stdio.h>

#define MAX 500000
#define SENTINEL 2000000000

int S[MAX];
int L[MAX / 2 + 2];
int R[MAX / 2 + 2];
int count = 0;

void merge(int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++)
    {
        L[i] = S[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = S[mid + i];
    }

    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    int i_L = 0;
    int i_R = 0;

    for (int k = left; k < right; k++)
    {
        count++;
        if (L[i_L] <= R[i_R])
        {
            S[k] = L[i_L++];
        }
        else
        {
            S[k] = R[i_R++];
        }
    }
}

void mergeSort(int left, int right)
{
    int mid = (right + left) / 2;

    if (right - left > 1)
    {
        mergeSort(mid, right);
        mergeSort(left, mid);
        merge(left, mid, right);
    }
}

int main()
{
    int n = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }

    mergeSort(0, n);

    // 回答
    for (int i = 0; i < n; i++)
    {
        printf("%d", S[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n%d\n", count);
}
