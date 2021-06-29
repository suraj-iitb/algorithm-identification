#include <iostream>
#include <cstdio>

#define INF 1000000000

int counter = 0;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1];
    int R[n2 + 1];
    for(int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for(int i = 0; i < n2; i++)
        R[i] = A[mid + i];
    L[n1] = INF;
    R[n2] = INF;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++)
    {
        counter++;
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int A[], int left, int right)
{
    if(left + 1 < right)
    {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    merge_sort(A, 0, n);

    for(int i = 0; i < n - 1; i++)
        printf("%d ", A[i]);
    printf("%d\n", A[n - 1]);
    printf("%d\n", counter);
}
