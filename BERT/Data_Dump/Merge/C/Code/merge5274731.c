#include <stdio.h>
#define N 500000

int A[N], n, count = 0, P[N];

void mergeSort(int L[], int left, int right)
{
    int i, j, k, mid;
    mid = (left + right) / 2;
    if (left >= right)
        return;
    mergeSort(L, left, mid);
    mergeSort(L, mid + 1, right);

    for (i = left; i <= mid; i++){
        P[i] = L[i];
    }
    for (i = mid + 1, j = right; i <= right; i++, j--){
        P[i] = L[j];
    }
    i = left;
    j = right;
    for (k = left; k <= right; k++){
        if (P[i] <= P[j])
            L[k] = P[i++];
        else
            L[k] = P[j--];
        count++;
    }
}
int main()
{

    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n - 1);

    for (i = 0; i < n - 1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n%d\n", A[n - 1], count);
    return 0;
}

