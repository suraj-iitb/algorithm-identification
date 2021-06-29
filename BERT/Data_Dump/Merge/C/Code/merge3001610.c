#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int total;

void merge(int *getA, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1], R[n2];
    int i;
    for (i = 0; i < n1; i++)
    {
        L[i] = getA[left + i];
    }
    for (i = 0; i < n2; i++)
    {
        R[i] = getA[mid + i];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int j = 0, k, l;
    i = 0;
    for (k = left; k < right; k++)
    {
        total++;
        if (L[i] <= R[j])
        {
            getA[k] = L[i];
            i = i + 1;
        }
        else
        {
            getA[k] = R[j];
            j = j + 1;
        }
    }
}

void mergeSort(int *getA, int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(getA, left, mid);
        mergeSort(getA, mid, right);
        merge(getA, left, mid, right);
    }
}

int main()
{
    total = 0;
    int n;
    scanf("%d", &n);
    int *A;
    A = malloc((sizeof(int) * n));
    int pre;
    for (pre = 0; pre < n; pre++)
    {
        scanf(" %d", &A[pre]);
    }
    mergeSort(A, 0, n);
    for (pre = 0; pre < n; pre++)
    {
        printf("%d", A[pre]);
        if (pre < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n%d\n", total);
    return 0;
}

// merge(A, left, mid, right)
//   n1 = mid - left;
//   n2 = right - mid;
//   L[0...n1], R[0...n2] を生成
//   for i = 0 to n1-1
//     L[i] = A[left + i]
//   for i = 0 to n2-1
//     R[i] = A[mid + i]
//   L[n1] = INFTY
//   R[n2] = INFTY
//   i = 0
//   j = 0
//   for k = left to right-1
//     if L[i] <= R[j]
//       A[k] = L[i]
//       i = i + 1
//     else
//       A[k] = R[j]
//       j = j + 1

// mergeSort(A, left, right)
//   if left+1 < right
//     mid = (left + right)/2;
//     mergeSort(A, left, mid)
//     mergeSort(A, mid, right)
//     merge(A, left, mid, right)
