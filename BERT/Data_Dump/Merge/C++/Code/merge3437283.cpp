#include <iostream>
#include <cstdio>
using namespace std;

static const int LEN = 500000;
static const int SENTINEL = 2000000000;
int cnt = 0;
int L[LEN/2+1], R[LEN/2+1];

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i != n1; ++i)
    {
        L[i] = A[left + i];
    }

    for (int i = 0; i != n2; ++i)
    {
        R[i] = A[mid + i];
    }

    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    int i = 0;
    int j = 0;

    for (int k = left; k != right; ++k)
    {
        ++cnt;

        if (L[i] <= R[j])
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int A[LEN];
    int n;

    scanf("%d", &n);

    for (int i = 0; i != n; ++i)
    {
       scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n);

    for (int i = 0; i != n; ++i)
    {
       if (i != 0)
       {
           printf(" ");
       }

       printf("%d", A[i]);
    }

    printf("\n");
    printf("%d\n", cnt);

    return 0;
}
